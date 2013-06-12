#ifndef ROOMBACONNECT_H
#define ROOMBACONNECT_H

#include <QDebug>
#include <QtCore>
#include <QObject>
#include <QTcpSocket>
#include <QTextStream>
#include <QTime>
#include "../resources/clslog.h"
#include <QTimer>
//#include "ircuser.h"
#include "../resources/jsoncommand.h"
#include "../resources/json.h"
#include "../resources/clsevent.h"
#include "sensordata.h"
#include "loggingdata.h"


#define MAX_CONNECT_TIMEOUT_IN_MS 5000

using namespace shared;
using namespace shared::events;
namespace client{

    /*!
     * \brief Class that has a connection to the server
     */
    class clsServerConn : public QObject
    {
        Q_OBJECT
        public:
            /*!
             * \brief Constructor taking a hostname and port
             * \param hostName The hostname to connect to
             * \param port The port to connect on
             * \param parent The parent widget, Not allways used
             * \note This only initializes the socket, it does not connect!
             */
            explicit clsServerConn(const QString hostName, const int port,
                    QObject *parent = 0);

            /*!
             * \brief Actually connect
             */
            void doConnect();
            /*!
             * \brief Send a JSON command to the server
             * \param toSend jsonCommand that should be sent
             */
            void sendCommand(jsonCommand &toSend);

            void doDisconnect();


        private:
            /*!
             * \brief Adds data to buffer and checks for json commands
             * \param toAdd The bytes to add
             * \param comm Pointer to a jsonCommand to be filled
             * \return true if a jsonCommand was detected
             * Constantly looks for a JSON command in the buffer
             * This is done with the depth.
             * Every time a { or [ is detected, depth is raised.
             * Every time a } or ] is detected, depth is decreased.
             * When depth is 0, there should be a complete json command!
             */
            bool checkForJsonCommand(QByteArray toAdd, jsonCommand &comm);

            /*!
             * \brief Event request has been done by us, and data has been returned
             * \param comm The jsonCommand containing all the events
             */
            void handleEventRequest(jsonCommand &comm);

            /*!
             * \brief Event has been received by the client. Parse it
             * \param data A QVariantMap containing all the data
             */
            void handleEventReceived(QVariantMap data);

        signals:
            /*!
             * \brief Emitted when the client has a succesfull connection to the server
             */
            void connected();
            /*!
             * \brief Emitted when the client lost connection to the server
             */
            void disconnected();

            /*!
             * \brief Triggered when the server wants us to know something
             * \param theMessage The message it sends
             */
            void sensorDataReceived(eventSensor *theMessage);

            /*!
             * \brief Triggered when it cannot connect.
             */
            void sgnConnectTimeout();

            void logsReceived(QVector<eventLogging::logEntry>);
        public slots:
            void srvDisconnected();
            void srvConnected();
            void readData();
            void connectTimeout();

        private:
            QString hostName;
            int port;

            QTcpSocket *sock;
            QString *buffer;
            int depth;

            clsLog log;

            QTimer *connectTimer;
            bool isConnected;
            bool isConnecting;
            bool inString;
            bool isDisconnected;


            void handleLogs(eventLogging *event);
    };
}

#endif // ROOMBACONNECT_H
