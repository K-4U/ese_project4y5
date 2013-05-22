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
        case JSONCOMMAND_MODECHANGED:
            ret = "MODECHANGED";
            break;
        case JSONCOMMAND_SETMAINBRUSH:
            ret = "SETMAINBRUSH";
            break;
        case JSONCOMMAND_SETSIDEBRUSH:
            ret = "SETSIDEBRUSH";
            break;
        case JSONCOMMAND_READBRUSHES:
            ret = "READBRUSHES";
            break;
        case JSONCOMMAND_SETVACUUM:
            ret = "SETVACUUM";
            break;
        case JSONCOMMAND_READVACUUM:
            ret = "READVACUUM";
            break;
        case JSONCOMMAND_READMOTOR:
            ret = "READMOTOR";
            break;
        case JSONCOMMAND_SETMOTOR:
            ret = "SETMOTOR";
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
    }else if(command == "MODECHANGED"){
        set = JSONCOMMAND_MODECHANGED;
    }else if(command == "SETMAINBRUSH"){
        set = JSONCOMMAND_SETMAINBRUSH;
    }else if(command == "SETSIDEBRUSH"){
        set = JSONCOMMAND_SETSIDEBRUSH;
    }else if(command == "READBRUSHES"){
        set = JSONCOMMAND_READBRUSHES;
    }else if(command == "SETVACUUM"){
        set = JSONCOMMAND_SETVACUUM;
    }else if(command == "READVACUUM"){
        set = JSONCOMMAND_READVACUUM;
    }else if(command == "READMOTOR"){
        set = JSONCOMMAND_READMOTOR;
    }else if(command == "SETMOTOR"){
        set = JSONCOMMAND_SETMOTOR;
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
