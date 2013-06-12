#ifndef LOGGINGDATA_H
#define LOGGINGDATA_H

#include "../resources/clsevent.h"
#include <QVariant>
#include <QVector>

namespace shared{
    namespace events{

    class eventLogging : public clsEvent
        {
            public:
                struct logEntry{
                    QString time;
                    QString entry;
                };
                eventLogging(QString time, QString entry);
                eventLogging(QVariantMap data);
                QVector<logEntry> getEntries() const;
        };
    }
}

#endif // LOGGINGDATA_H
