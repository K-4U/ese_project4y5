#ifndef EVENTUSERCHANGESTATUS_H
#define EVENTUSERCHANGESTATUS_H
#include "../clsevent.h"

namespace shared {
	namespace events {
		/*!
		 * \brief Class containing a user who changes his status-event (nick|status)
		 * \author Koen Beckers (K-4U)
		 */
		class eventUserChangeStatus : public clsEvent
		{
		public:
			/*!
			 * \brief eventUserChangeStatus constructor taking only a userId
			 * \param userId The DB-ID of the user that left
			 * \param newStatus The new status of the user
			 * \param oldStatus The old status of the user
			 */
			eventUserChangeStatus(const int userId, const QString newStatus,
								  const QString oldStatus);

			/*!
			 * \brief Constructor function that accepts data immediately.
			 * \param data A QVariantMap containing the event data, parsed from JSON
			 * Mostly used on the receiving end.
			 */
			eventUserChangeStatus(QVariantMap data);

			/*!
			 * \brief Gets the DB-ID of the user that changed status
			 * \return The DB-ID of the user that changed status
			 */
			int getUserId() const;

			/*!
			 * \brief Gets the new status of the user
			 * \return The new status of the user
			 */
			QString getNewStatus() const;

			/*!
			 * \brief Gets the old status of the user
			 * \return The old status of the user
			 */
			QString getOldStatus() const;
		};
	}
}


#endif // EVENTUSERCHANGESTATUS_H
