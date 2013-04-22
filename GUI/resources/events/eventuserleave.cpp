#include "eventuserleave.h"

namespace shared {
    namespace events {

        eventUserLeave::eventUserLeave(const int userId){
            ourType = EVENTTYPE_USER_LEFT;
            this->addToData("userId", userId);
        }

		eventUserLeave::eventUserLeave(QVariantMap data)
			:clsEvent(data)
		{ }

        int eventUserLeave::getUserId() const{
            return this->getData("userId").toInt();
        }

    }
}
