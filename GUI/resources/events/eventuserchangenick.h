#ifndef EVENTUSERCHANGENICK_H
#define EVENTUSERCHANGENICK_H
#include "../clsevent.h"

namespace shared {
	namespace events {
		/*!
		 * \brief Class containing a user who changes his nick-event (nick|status)
		 * \author Koen Beckers (K-4U)
		 */
		class eventUserChangeNick : public clsEvent
		{
		public:
			/*!
			 * \brief eventUserChangeNick constructor taking only a userId
			 * \param userId The DB-ID of the user that changed nick
			 * \param newNick The new nickname of the user
			 * \param oldNick The old nickname of the user
			 */
			eventUserChangeNick(const int userId, const QString newNick,
								  const QString oldNick);

			/*!
			 * \brief Constructor function that accepts data immediately.
			 * \param data A QVariantMap containing the event data, parsed from JSON
			 * Mostly used on the receiving end.
			 */
			eventUserChangeNick(QVariantMap data);

			/*!
			 * \brief Gets the DB-ID of the user that changed nick
			 * \return The DB-ID of the user that changed status
			 */
			int getUserId() const;

			/*!
			 * \brief Gets the new nick of the user
			 * \return The new nick of the user
			 */
			QString getNewNick() const;

			/*!
			 * \brief Gets the old nick of the user
			 * \return The old nick of the user
			 */
			QString getOldNick() const;
		};
	}
}

#endif // EVENTUSERCHANGENICK_H
