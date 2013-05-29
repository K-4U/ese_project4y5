#ifndef SENSORDATA_H
#define SENSORDATA_H

#include "../resources/clsevent.h"
#include <QVariant>

namespace shared{
    namespace events{

    class eventSensor : public clsEvent
        {
            public:
                eventSensor(int sensorID, int value);
                eventSensor(QVariantMap data);
                int getID() const;
                int getValue() const;
        };
    }
}




#endif // SENSORDATA_H
