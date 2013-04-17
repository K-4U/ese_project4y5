#ifndef EVENTUSERLEAVE_H
#define EVENTUSERLEAVE_H
#include "../clsevent.h"

namespace shared {
    namespace events {
        /*!
         * \brief Class containing a user PART event
         * \author Koen Beckers (K-4U)
         */
        class eventUserLeave : public clsEvent
        {
            public:
                /*!
                 * \brief eventUserLeave constructor taking only a userId
                 * \param userId The DB-ID of the user that left
                 */
                eventUserLeave(const int userId);

                /*!
                 * \brief Initializer function that accepts data immediately.
                 * \param data A QVariantMap containing the event data, parsed from JSON
                 * Mostly used on the receiving end.
                 */
                eventUserLeave(QVariantMap data);

                /*!
                 * \brief Gets the DB-ID of the user that left
                 * \return The DB-ID of the user that left
                 */
                int getUserId() const;
        };

    }
}

#endif
