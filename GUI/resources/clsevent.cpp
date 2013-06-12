#include "clsevent.h"

namespace shared{
    namespace events{
        clsEvent::clsEvent()
            :log(LOGTAGS_EVENT)
        {
            this->timeOfEvent = QDateTime::currentDateTime();
        }

        clsEvent::clsEvent(QVariantMap data)
            :log(LOGTAGS_EVENT)
        {
            this->data = data["data"].toMap();//Makes sense?
            this->setEventType(data["type"].toString());
            this->timeOfEvent = data["dateTime"].toDateTime();
        }

        void clsEvent::addToData(const QString &key, const QVariant data){
            this->data.insert(key, data);
        }

        QVariant clsEvent::toVariant() const{
            QVariantMap ret;
            ret["type"] = this->getEventType();
            ret["dateTime"] = this->timeOfEvent;
            ret["data"] = QVariant(this->data);

            return QVariant(ret);
        }

        QVariant clsEvent::getData(QString key) const{
            return this->data[key];
        }

        eventTypes clsEvent::getType() const{
            return this->ourType;
        }


        QTime clsEvent::getTime() const{
            return this->timeOfEvent.time();
        }

        void clsEvent::setEventType(const QString eventString){
            eventTypes ret = EVENTTYPE_NONE;
            if(eventString == "CHAT"){
                ret = EVENTTYPE_CHAT;
            }else if(eventString == "USER_JOIN"){
                ret = EVENTTYPE_USER_JOIN;
            }else if(eventString == "USER_LEFT"){
                ret = EVENTTYPE_USER_LEFT;
            }else if(eventString == "USER_STATUS"){
                ret = EVENTTYPE_USER_STATUS;
			}else if(eventString == "USER_NICK"){
				ret = EVENTTYPE_USER_NICK;
			}else if(eventString == "SERVERMSG"){
				ret = EVENTTYPE_SERVERMSG;
            }else if(eventString == "SENSORDATA"){
                ret = EVENTTYPE_SENSORDATA;
            }else if(eventString == "BRUSHVACUUMDATA"){
                ret = EVENTTYPE_BRUSHVACUUMDATA;
            }else if(eventString == "CURRENTACTIONDATA"){
                ret = EVENTTYPE_CURRENTACTIONDATA;
            }else if(eventString == "LOGGINGDATA"){
                ret = EVENTTYPE_LOGGINGDATA;
            }
            this->ourType = ret;
        }

        QString clsEvent::getEventType() const{
            QString ret = "";
            switch(this->ourType){
                case EVENTTYPE_CHAT:
                    ret = "CHAT";
                    break;
                case EVENTTYPE_USER_JOIN:
                    ret = "USER_JOIN";
                    break;
                case EVENTTYPE_USER_LEFT:
                    ret = "USER_LEFT";
                    break;
                case EVENTTYPE_USER_STATUS:
                    ret = "USER_STATUS";
                    break;
				case EVENTTYPE_USER_NICK:
					ret = "USER_NICK";
					break;
				case EVENTTYPE_SERVERMSG:
					ret = "SERVERMSG";
					break;
                case EVENTTYPE_NONE:
                    ret = "NaN";
                    break;
                case EVENTTYPE_SENSORDATA:
                    ret = "SENSORDATA";
                    break;
                case EVENTTYPE_BRUSHVACUUMDATA:
                    ret = "BRUSHVACUUMDATA";
                    break;
                case EVENTTYPE_CURRENTACTIONDATA:
                    ret = "CURRENTACTIONDATA";
                    break;
                case EVENTTYPE_LOGGINGDATA:
                    ret = "LOGGINGDATA";
                    break;
            }
            return ret;
        }


    }
}
