#include "jsoncommand.h"

namespace K4U{

jsonCommand::jsonCommand(QString json){
    QVariant data = QtJson::parse(json);
    QVariantMap parent = qvariant_cast<QVariantMap>(data);
    this->setCommandInt(parent["command"].toString());
    this->data = parent["data"].toMap();
}


jsonCommand::jsonCommand(QVariantMap parent)
{
    this->command = (jsonCommands) parent["command"].toInt();
    this->data = parent["data"].toMap();
}

jsonCommand::jsonCommand(jsonCommands command)
    :command(command)
{ }


jsonCommands jsonCommand::getCommand() const{
    return this->command;
}

QString jsonCommand::getCommandString() const{
    QString ret = "";
    switch(this->command){
        case JSONCOMMAND_PING:
            ret = "PING";
            break;
        case JSONCOMMAND_EVENT:
            ret = "EVENT";
            break;
        case JSONCOMMAND_NONE:
            ret = "NONE";
            break;
        case JSONCOMMAND_GETEVENTS:
            ret = "GETEVENTS";
            break;
        case JSONCOMMAND_MANUAL:
            ret = "MANUAL";
            break;
    }
    return ret;
}

void jsonCommand::setCommandInt(QString command){
    jsonCommands set = JSONCOMMAND_NONE;
    if(command == "PING"){
        set = JSONCOMMAND_PING;
    }else if(command == "EVENT"){
        set = JSONCOMMAND_EVENT;
    }else if(command == "GETEVENTS"){
        set = JSONCOMMAND_GETEVENTS;
    }else if(command == "MANUAL"){
        set = JSONCOMMAND_MANUAL;
    }
    this->command = set;
}

void jsonCommand::setCommand(const jsonCommands &newCommand){
    this->command = newCommand;
}


QVariantMap jsonCommand::getData() const{
    return this->data;
}

QVariant jsonCommand::getData(const QString key){
    return this->data[key];
}


void jsonCommand::setData(const QVariantMap &newData){
    this->data = newData;
}

void jsonCommand::addToData(const QString key, const QVariant &data){
    this->data.insert(key,data);
}

QString jsonCommand::toJsonString() const{
    QVariantMap vmRet;
    vmRet["command"] = this->getCommandString();
    vmRet["data"] = QVariant(this->getData());

    return QtJson::serialize(QVariant(vmRet));
}

clsLog& operator <<(clsLog &log, jsonCommand &command){
    log << "JSON command: " << command.getCommandString();
    log << " Data: " << endl << command.getData() << endl;
    return log;
}


clsLog& operator <<(clsLog &log, const jsonCommand &command){
    log << "JSON command: " << command.getCommandString();
    log << " Data: " << endl << command.getData() << endl;
	return log;
}

jsonCommand jsonCommand::operator =(jsonCommand *other){
	this->command = other->command;
	this->data = other->data;
	return *this;
}

}
