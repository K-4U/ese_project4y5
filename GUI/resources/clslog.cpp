#include "clslog.h"

using namespace std;

namespace K4U{

clsLog::clsLog(logTags tag)
    :isFirst(true)
    ,tag(tag)
{}


clsLog &clsLog::operator <<(clsLog &(*manip)(clsLog &)){
    return manip(*this);
}

clsLog &clsLog::operator <<(bool msg){
    if(msg == true){
        std::cout << "True";
    }else{
        std::cout << "False";
    }
    return *this;
}

clsLog &clsLog::operator <<(QVariantMap &map){
    foreach(QString key, map.keys()){
        *this << key << "\t"
                  << map[key] << endl;
    }
    return *this;
}

clsLog &clsLog::operator <<(const QVariantMap &map){
    foreach(const QString key, map.keys()){
        *this << key << "\t"
                  << map[key] << endl;
    }
    return *this;
}

clsLog &clsLog::operator <<(const QVariant &msg){
    *this << msg.toString();

    return *this;
}

clsLog &clsLog::operator <<(QVariant &msg){
    *this << msg.toString();

    return *this;
}

clsLog &clsLog::operator <<(QByteArray &bArr){
    *this << QString(bArr);
    return *this;
}

clsLog &clsLog::operator <<(const QByteArray &bArr){
    *this << QString(bArr);
    return *this;
}


clsLog &endl(clsLog &log){
    log.doEndl();
    return log;
}

void clsLog::doEndl(){
    std::cout << std::endl;
    isFirst = true;
}

void clsLog::setPrefix(QString prefix){
    this->prf = prefix;
}

void clsLog::prefix(){
    if(isFirst == true){
        isFirst = false;
        QDateTime dateTime = QDateTime::currentDateTime();
        QString dateTimeString = dateTime.toString();

        std::cout << "[" << this->getTag() << "]\t";
        std::cout << dateTimeString.toStdString() << "\t";
        if(this->prf != ""){
            std::cout << this->prf.toStdString() << "\t";
        }else{
            std::cout << "\t";
        }
        std::cout << "\t";
    }
}

clsLog& clsLog::operator <<(QString msg){
    this->prefix();
    std::cout << msg.toStdString();

    return *this;
}

clsLog &clsLog::operator <<(const QString *msg){
    this->prefix();
    std::cout << msg->toStdString();

    return *this;
}

clsLog& clsLog::operator <<(const char *msg){
    this->prefix();
    std::cout << msg;

    return *this;
}

clsLog& clsLog::operator <<(int msg){
    this->prefix();
    std::cout << msg;

    return *this;
}


std::string clsLog::getTag(){
    string ret = "";
    switch(this->tag){
        case LOGTAGS_ROOMBA:
            ret = "ROOMBA";
            break;
        case LOGTAGS_MAIN:
            ret = "MAIN";
            break;
        case LOGTAGS_SERVER:
            ret = "SERVER";
            break;
		case LOGTAGS_EVENT:
			ret = "EVNT";
			break;
        default:
            ret = "UNK";
            break;
    }
    return ret;
}


}
