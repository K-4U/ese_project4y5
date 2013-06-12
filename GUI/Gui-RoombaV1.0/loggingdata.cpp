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

        QVector<eventLogging::logEntry> eventLogging::getEntries() const{
            QVector<eventLogging::logEntry> ret;
            foreach(QVariant logEntry, this->getData("Logs").toList()){
                eventLogging::logEntry tEntry;
                QVariantMap logMapEntry = logEntry.toMap();
                tEntry.time = logMapEntry["Time"].toString();
                tEntry.entry = logMapEntry["Entry"].toString();
                ret.append(tEntry);
            }

            return ret;
        }
/*
        QString eventLogging::getTime() const
        {
            return this->getData("Time").toString();
        }

        QString eventLogging::getEntry() const
        {
            return this->getData("Entry").toString();
        }*/
    }
}
