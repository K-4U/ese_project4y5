#include "sensordata.h"

namespace shared{
    namespace events{

        eventSensor::eventSensor(int sensorID, int value)
        {
            ourType = EVENTTYPE_SENSORDATA;
            this->addToData("SensorID", sensorID);
            this->addToData("Value", value);
        }

        eventSensor::eventSensor(QVariantMap data)
            :clsEvent(data)
        { }

        int eventSensor::getID() const
        {
            return this->getData("SensorID").toInt();
        }

        int eventSensor::getValue() const
        {
            return this->getData("Value").toInt();
        }
    }
}
