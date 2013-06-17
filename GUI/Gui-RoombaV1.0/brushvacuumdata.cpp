#include "brushvacuumdata.h"

namespace shared{
    namespace events{

        eventBrushVacuumData::eventBrushVacuumData(int mainBrush, int sideBrush, int vacuum)
        {
            ourType = EVENTTYPE_BRUSHVACUUMDATA;
            this->addToData("MainBrush", mainBrush);
            this->addToData("SideBrush", sideBrush);
            this->addToData("Vacuum", vacuum);
        }

        eventBrushVacuumData::eventBrushVacuumData(QVariantMap data)
        :clsEvent(data)
        { }

        int eventBrushVacuumData::mainBrush() const
        {
            return this->getData("MainBrush").toInt();
        }

        int eventBrushVacuumData::sideBrush() const
        {
            return this->getData("SideBrush").toInt();
        }

        int eventBrushVacuumData::vacuum() const
        {
            return this->getData("Vacuum").toInt();
        }
    }
}
