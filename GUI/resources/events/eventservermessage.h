#ifndef EVENTSERVERMESSAGE_H
#define EVENTSERVERMESSAGE_H
#include "../clsevent.h"

namespace shared {
	enum level{
		SERVERMESSAGE_LEVEL_ERROR = 0x01,
		SERVERMESSAGE_LEVEL_INFO
	};
	namespace events {
		/*!
		 * \brief Class that contains data for when the server wants to say something
		 * \author Koen Beckers (K-4U)
		 */
		class eventServerMessage : public clsEvent
		{
		public:
			/*!
			 * \brief eventServerMessage constructor taking a message
			 * \param message The message that was sent
			 */
			eventServerMessage(QString message, level lvl);

			/*!
			 * \brief Initializer function that accepts data immediately.
			 * \param data A QVariantMap containing the event data, parsed from JSON
			 * Mostly used on the receiving end.
			 */
			eventServerMessage(QVariantMap data);

			/*!
			 * \brief Gets the message
			 * \return The message
			 */
			QString getMessage() const;

			/*!
			 * \brief Gets the level of the message
			 * \return The level of the message
			 */
			level getLevel() const;
		};
	}
}

#endif // EVENTSERVERMESSAGE_H
