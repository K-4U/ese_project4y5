#include "loggingdata.h"

namespace shared{
    namespace events{

        eventLogging::eventLogging(QString time, QString entry)
        {
            ourType = EVENTTYPE_LOGGINGDATA;
            this->addToData("Time", time);
            this->addToData("Entry", entry);
        }

        eventLogging::eventLogging(QVariantMap loggingData)
            :clsEvent(loggingData)
        { }

        QString eventLogging::getTime() const
        {
            return this->getData("Time").toString();
        }

        QString eventLogging::getEntry() const
        {
            return this->getData("Entry").toString();
        }
    }
}
