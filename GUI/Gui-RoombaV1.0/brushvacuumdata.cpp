#include "brushvacuumdata.h"

namespace shared{
    namespace events{

        eventBrushVacuumData::eventBrushVacuumData(bool mainBrush, bool sideBrush, bool vacuum)
        {
            ourType = EVENTTYPE_BRUSHVACUUMDATA;
            this->addToData("MainBrush", mainBrush);
            this->addToData("SideBrush", sideBrush);
            this->addToData("Vacuum", vacuum);
        }

        eventBrushVacuumData::eventBrushVacuumData(QVariantMap data)
        :clsEvent(data)
        { }

        bool eventBrushVacuumData::mainBrush() const
        {
            return this->getData("MainBrush").toBool();
        }

        bool eventBrushVacuumData::sideBrush() const
        {
            return this->getData("SideBrush").toBool();
        }

        bool eventBrushVacuumData::vacuum() const
        {
            return this->getData("Vacuum").toBool();
        }
    }
}
