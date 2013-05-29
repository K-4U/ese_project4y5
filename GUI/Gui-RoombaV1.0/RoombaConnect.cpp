#include "RoombaConnect.h"
#include "../resources/jsoncommand.h"

namespace client{

    clsServerConn::clsServerConn(const QString hostName, const int port,
            QObject *parent)
        :QObject(parent)
        ,hostName(hostName)
        ,port(port)
        ,depth(0)
        ,log(LOGTAGS_SERVER)
        ,isConnected(false)
        ,isConnecting(false)
        ,inString(false)
    {
        this->buffer = new QString();

        this->sock = new QTcpSocket(this);

        this->sock->connect(this->sock, SIGNAL(readyRead()), this,
                SLOT(readData()));
        this->sock->connect(this->sock, SIGNAL(connected()), this,
                SLOT(srvConnected()));
        this->sock->connect(this->sock, SIGNAL(disconnected()), this,
                SLOT(srvDisconnected()));
    }

    void clsServerConn::doConnect(){
        this->connectTimer->singleShot(MAX_CONNECT_TIMEOUT_IN_MS, this, SLOT(connectTimeout()));
        this->isConnecting = true;
        this->isConnected = false;
        this->sock->connectToHost(this->hostName,this->port);


        this->log << "Connecting" << endl;
    }

    void clsServerConn::doDisconnect(){
        this->isConnected = false;
        this->isConnecting = false;
        this->sock->disconnectFromHost();

        this->log << "Disconnected" << endl;
    }

    void clsServerConn::sendCommand(jsonCommand &toSend){
        //this->log << "Sending json object: " << docToSend->toJson() << endl;
        this->log << "Sending JSON: " << toSend << endl;
        QByteArray bAToSend;
        bAToSend.append(toSend.toJsonString());
        this->sock->write(bAToSend);
    }

    void clsServerConn::srvConnected(){
        this->log << "Connected!" << endl;
        this->isConnecting = false;
        this->isConnected = true;
        emit this->connected();
    }


    void clsServerConn::srvDisconnected(){
        this->log << "Disconnected" << endl;
        this->isConnecting = false;
        this->isConnected = false;
        emit this->disconnected();
    }

    void clsServerConn::handleEventRequest(jsonCommand &comm){
        //Let them flow, all the chats!
        QList<QVariant> events = comm.getData("events").toList();
        foreach(QVariant myEvent, events){
            this->handleEventReceived(myEvent.toMap());
        }
    }

    void clsServerConn::handleEventReceived(QVariantMap data){
        clsEvent myEvent(data);
        switch(myEvent.getType()){
 //           case EVENTTYPE_SERVERMSG:
 //               emit this->serverMessageReceived(new eventServerMessage(data));
 //               break;
            default:
                break; //ERROR!
        }

    }


    bool clsServerConn::checkForJsonCommand(QByteArray toAdd, jsonCommand &comm){
        bool ret = false;
        foreach(char b, toAdd){
            if (!inString){
                if(b == '{' || b == '['){
                    depth++;
                }else if(b == '}' || b == ']'){
                    depth--;
                }
            }
            if (b=='"'){
                inString = !inString;
            }
            this->buffer->append(b);

            if(depth == 0){
                //Clear the buffer.
                if(comm.getCommand() == JSONCOMMAND_NONE){
                    ret = true;
                    comm = new jsonCommand(*this->buffer);
                    this->log << "Data received: \t" << this->buffer << endl;
                    this->buffer->clear();
                }
            }
        }
        return ret;
    }

    void clsServerConn::readData(){
        jsonCommand comm(JSONCOMMAND_NONE);
        if(this->checkForJsonCommand(this->sock->readAll(), comm)){
            switch (comm.getCommand()) {
                case JSONCOMMAND_EVENT:
                    this->handleEventReceived(comm.getData("event").toMap());
                    break;
                case JSONCOMMAND_SENSORDATARECEIVED:
                    this->handleEventReceived(comm.getData("SensorData").toMap());
                    break;
                default:
                    break;
            }
        }
    }

    void clsServerConn::connectTimeout(){
        if(this->isConnecting && this->isConnected == false){
            this->sock->abort();
            emit this->sgnConnectTimeout();
        }

    }

}
