#ifndef BRUSHVACUUMDATA_H
#define BRUSHVACUUMDATA_H

#include "../resources/clsevent.h"
#include <QVariant>

namespace shared{
    namespace events{

    class eventBrushVacuumData : public clsEvent
        {
            public:
                eventBrushVacuumData(bool mainBrush, bool sideBrush, bool vacuum);
                eventBrushVacuumData(QVariantMap brushVacuumData);
                bool mainBrush() const;
                bool sideBrush() const;
                bool vacuum() const;
        };
    }
}

#endif // BRUSHVACUUMDATA_H
