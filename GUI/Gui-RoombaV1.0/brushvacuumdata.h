#ifndef BRUSHVACUUMDATA_H
#define BRUSHVACUUMDATA_H

#include "../resources/clsevent.h"
#include <QVariant>

namespace shared{
    namespace events{

    class eventBrushVacuumData : public clsEvent
        {
            public:
                eventBrushVacuumData(int mainBrush, int sideBrush, int vacuum);
                eventBrushVacuumData(QVariantMap brushVacuumData);
                int mainBrush() const;
                int sideBrush() const;
                int vacuum() const;
        };
    }
}

#endif // BRUSHVACUUMDATA_H
