#ifndef CURRENTACTIONDATA_H
#define CURRENTACTIONDATA_H

#include "../resources/clsevent.h"
#include <QVariant>

namespace shared{
    namespace events{

    class eventCurrentActionData : public clsEvent
        {
            public:
                eventCurrentActionData(int currentAction);
                eventCurrentActionData(QVariantMap currentActionData);
                int currentAction() const;
        };
    }
}



#endif // CURRENTACTIONDATA_H
