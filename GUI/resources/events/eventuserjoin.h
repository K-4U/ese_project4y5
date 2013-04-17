#ifndef EVENTUSERJOIN_H
#define EVENTUSERJOIN_H
#include "../clsevent.h"

namespace shared{
    namespace events{
        /*!
         * \brief Class containing a user JOIN event
         * \author Koen Beckers (K-4U)
         */
        class eventUserJoin : public clsEvent
        {
            public:
                /*!
                 * \brief eventUserJoin constructor taking a userId and a message
                 * \param userId The DB-ID of the user that joined
                 * \param user A QVariantMap of the user that joined
                 */
                eventUserJoin(const int userId, QVariantMap user);

                /*!
                 * \brief Initializer function that accepts data immediately.
                 * \param data A QVariantMap containing the event data, parsed from JSON
                 * Mostly used on the receiving end.
                 */
                eventUserJoin(QVariantMap data);

                /*!
                 * \brief Gets the DB-ID of the user that joined
                 * \return The DB-ID of the user that joined
                 */
                int getUserId() const;

                /*!
                 * \brief Gets a QVariantMap of the user that joined
                 * \return A QVariantMap of the user that joined
                 */
                QVariantMap getUser() const;

        };
    }
}


#endif // EVENTUSERJOIN_H
