#include "eventuserchangenick.h"

namespace shared {
	namespace events {

		eventUserChangeNick::eventUserChangeNick(const int userId,
													 const QString newNick,
													 const QString oldNick) {
			ourType = EVENTTYPE_USER_NICK;
			this->addToData("userId",userId);
			this->addToData("newNick",newNick);
			this->addToData("oldNick",oldNick);
		}

		eventUserChangeNick::eventUserChangeNick(QVariantMap data)
			:clsEvent(data)
		{ }

		int eventUserChangeNick::getUserId() const {
			return this->data["userId"].toInt();
		}

		QString eventUserChangeNick::getNewNick() const {
			return this->data["newNick"].toString();
		}

		QString eventUserChangeNick::getOldNick() const {
			return this->data["oldNick"].toString();
		}
	}
}
