#ifndef CLSEVENT_H
#define CLSEVENT_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QDateTime>
#include "clslog.h"

using namespace K4U;
namespace shared{

    namespace events{
        /*!
         * \brief The eventTypes enum
         */
        enum eventTypes{
            EVENTTYPE_NONE = 0x00, /*!< When all you need is an empty event */
            EVENTTYPE_CHAT, /*!< For when a chatmessage has been received */
            EVENTTYPE_USER_LEFT, /*!< For when a user left the channel */
            EVENTTYPE_USER_STATUS, /*!< For when a user updated his or her status */
			EVENTTYPE_USER_JOIN, /*!< For when a user joins the channel */
			EVENTTYPE_USER_NICK, /*!< For when a user updates his or her nick */
            EVENTTYPE_SERVERMSG, /*!< For when the server wants to tell something to the client */
            EVENTTYPE_SENSORDATA
        };


        /*!
         * \brief The main event class
         * \author Koen Beckers (K-4U)
         */
        class clsEvent
        {
            public:
                /*!
                 * \brief Empty initializer function
                 */
                explicit clsEvent();
                /*!
                 * \brief Initializer function that accepts data immediately.
                 * \param data A QVariantMap containing the event data, parsed from JSON
                 * Mostly used on the receiving end.
                 */
                explicit clsEvent(QVariantMap data);

                /*!
                 * \brief Adds data to the events data map
                 * \param key The key to add the data under
                 * \param data The data to add
                 */
                void addToData(const QString &key, const QVariant data);

                /*!
                 * \brief Converts the current data to a QVariant for sending with JSON
                 * \return The event as a QVariant object
                 */
                QVariant toVariant() const;

                /*!
                 * \brief Get data from the events data map
                 * \param key The key to retrieve
                 * \return A QVariant containing the data
                 */
                QVariant getData(QString key) const;

                /*!
                 * \brief Gets this events type
                 * \return An eventTypes object containing the eventType
                 */
                eventTypes getType() const;

                /*!
                 * \brief Gets the time on which the event was created
                 * \return The time on which the event was created
                 */
                QTime getTime() const;

            protected:
                /*!
                 * \brief The events data map
                 */
                QVariantMap data;
                eventTypes ourType;
                QDateTime timeOfEvent;

                /*!
                 * \brief Gets the event type as a string
                 * \return The event type as a string
                 */
                QString getEventType() const;

                /*!
                 * \brief Sets the event type as a string
                 * \param eventString The eventType as a string
                 */
                void setEventType(const QString eventString);

                clsLog log;
        };
    }
}
#endif // CLSEVENT_H
