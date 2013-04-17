#ifndef EVENTCHAT_H
#define EVENTCHAT_H
#include "../clsevent.h"

namespace shared{
    namespace events{
        /*!
         * \brief Class containing a chatEvent
         * \author Koen Beckers (K-4U)
         */
        class eventChat : public clsEvent
        {
            public:
                /*!
                 * \brief eventChat constructor taking a userId and a message
                 * \param userId The DB-ID of the user that sent the message
                 * \param message The message that was sent
                 */
                eventChat(int userId, QString message);

                /*!
                 * \brief Initializer function that accepts data immediately.
                 * \param data A QVariantMap containing the event data, parsed from JSON
                 * Mostly used on the receiving end.
                 */
                eventChat(QVariantMap data);

                /*!
                 * \brief Gets the DB-ID of the user that sent the message
                 * \return The DB-ID of the user that sent the message
                 */
                int getUser() const;
                /*!
                 * \brief Gets the chat message
                 * \return The chat message
                 */
                QString getMessage() const;
        };
    }
}
#endif // EVENTCHAT_H
