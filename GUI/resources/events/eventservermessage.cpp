#include "eventservermessage.h"

namespace shared{
	namespace events{

		eventServerMessage::eventServerMessage(QString message, level lvl){
			ourType = EVENTTYPE_SERVERMSG;
			this->addToData("message", message);
			this->addToData("level",lvl);
		}

		eventServerMessage::eventServerMessage(QVariantMap data)
			:clsEvent(data)
		{ }

		QString eventServerMessage::getMessage() const{
			return this->getData("message").toString();
		}

		level eventServerMessage::getLevel() const {
			return (level)this->getData("level").toInt();
		}


	}
}
