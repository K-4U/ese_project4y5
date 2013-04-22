#include "eventchat.h"

namespace shared{
    namespace events{

        eventChat::eventChat(int userId, QString message){
            ourType = EVENTTYPE_CHAT;
			this->addToData("userId",userId);
            this->addToData("message", message);
        }

		eventChat::eventChat(QVariantMap data)
			:clsEvent(data)
		{ }

        int eventChat::getUser() const{
			return this->getData("userId").toInt();
        }

        QString eventChat::getMessage() const{
            return this->getData("message").toString();
        }


    }
}
