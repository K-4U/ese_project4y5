#include "currentactiondata.h"

namespace shared{
    namespace events{

    eventCurrentActionData::eventCurrentActionData(int currentAction)
        {
            ourType = EVENTTYPE_CURRENTACTIONDATA;
            this->addToData("CurrentAction", currentAction);
        }

    eventCurrentActionData::eventCurrentActionData(QVariantMap data)
        :clsEvent(data)
        { }

    int eventCurrentActionData::currentAction() const
        {
            return this->getData("CURRENTACTION").toInt();
        }
    }
}
