#include "eventuserchangestatus.h"

namespace shared {
	namespace events {

		eventUserChangeStatus::eventUserChangeStatus(const int userId,
													 const QString newStatus,
													 const QString oldStatus) {
			ourType = EVENTTYPE_USER_STATUS;
			this->addToData("userId",userId);
			this->addToData("newStatus",newStatus);
			this->addToData("oldStatus",oldStatus);
		}

		eventUserChangeStatus::eventUserChangeStatus(QVariantMap data)
			:clsEvent(data)
		{ }

		int eventUserChangeStatus::getUserId() const {
			return this->data["userId"].toInt();
		}

		QString eventUserChangeStatus::getNewStatus() const {
			return this->data["newStatus"].toString();
		}

		QString eventUserChangeStatus::getOldStatus() const {
			return this->data["oldStatus"].toString();
		}
	}
}
