#ifndef LOGGINGDATA_H
#define LOGGINGDATA_H

#include "../resources/clsevent.h"
#include <QVariant>

namespace shared{
    namespace events{

    class eventLogging : public clsEvent
        {
            public:
                eventLogging(QString time, QString entry);
                eventLogging(QVariantMap data);
                QString getTime() const;
                QString getEntry() const;
        };
    }
}

#endif // LOGGINGDATA_H
