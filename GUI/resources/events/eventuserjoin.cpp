#include "eventuserjoin.h"

namespace shared{
    namespace events{
        eventUserJoin::eventUserJoin(const int userId, QVariantMap user){
			ourType = EVENTTYPE_USER_JOIN;
            this->addToData("userId", userId);
            this->addToData("user",QVariant(user));
        }

		eventUserJoin::eventUserJoin(QVariantMap data)
			:clsEvent(data)
		{ }

        int eventUserJoin::getUserId() const{
            return this->getData("userId").toInt();
        }

        QVariantMap eventUserJoin::getUser() const{
            return this->getData("user").toMap();
        }
    }
}
