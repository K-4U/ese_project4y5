#ifndef JSONCOMMAND_H
#define JSONCOMMAND_H

#include <QObject>
#include <QVariantMap>

#include "json.h"
#include "clslog.h"

/*!
 * \brief Contains functions used for more projects
 * \author Koen Beckers (K-4U)
 */
namespace K4U{
enum jsonCommands{
	JSONCOMMAND_NONE = 0x00,
	JSONCOMMAND_PING = 0x01,
	JSONCOMMAND_EVENT,
    JSONCOMMAND_GETEVENTS,
    JSONCOMMAND_MANUAL,
    JSONCOMMAND_NEWMODE,
    JSONCOMMAND_SETMOTORBRUSHVACUUM,
    JSONCOMMAND_READMOTOR,
    JSONCOMMAND_SETMOTOR,
    JSONCOMMAND_DRIVEFORWARD,
    JSONCOMMAND_DRIVEBACKWARD,
    JSONCOMMAND_DRIVELEFT,
    JSONCOMMAND_DRIVERIGHT,
    JSONCOMMAND_STOPDRIVEFORWARD,
    JSONCOMMAND_STOPDRIVEBACKWARD,
    JSONCOMMAND_STOPDRIVELEFT,
    JSONCOMMAND_STOPDRIVERIGHT
};

/*!
 * \brief The jsonCommand class
 * \author Koen Beckers (K-4U)
 *
 * Example command:
 * \code
	{
		"command": "OWNCHAT",
		"data": {
			"message":"Derp"
			}
	}
 * \endcode
 */
class jsonCommand{
public:
	/*!
	 * \brief jsonCommand constructor taking a JSON string
	 * \param json A QString containing JSON
	 */
    jsonCommand(QString json);
	/*!
	 * \brief jsonCommand constructor taking a QVariantMap entry
	 * \param parent The QVariantMap containing JSON data
	 * This will mostly be used when a JSON entry has been parsed by the JSON parser
	 */
    jsonCommand(QVariantMap parent);
	/*!
	 * \brief jsonCommand constructor initializing an empty command
	 * \param command The command type to set
	 */
    jsonCommand(jsonCommands command);

	/*!
	 * \brief getCommand
	 * \return A jsonCommands object containing the current command type
	 */
    jsonCommands getCommand() const;
	/*!
	 * \brief getCommandString
	 * \return A QString containing the current command type
	 */
    QString getCommandString() const;

    void setCommand(const jsonCommands& newCommand);
    void setCommandInt(QString command);

	/*!
	 * \brief Gets an item from the internal data map
	 * \param key The key to get
	 * \return A QVariant Object containing the data
	 */
    QVariant getData(const QString key);

	/*!
	 * \brief Gets all data items
	 * \return A QVariantMap containg all the data
	 */
    QVariantMap getData() const;

	/*!
	 * \brief Sets a new internal data map
	 * \param newData The new map to set
	 */
    void setData(const QVariantMap& newData);

	/*!
	 * \brief Adds data to the internal data map
	 * \param key The key to add the data under
	 * \param data The data to add
	 */
    void addToData(const QString key, const QVariant &data);


    friend clsLog& operator<<(clsLog& log, jsonCommand &command);
    friend clsLog& operator<<(clsLog& log, const jsonCommand &command);

	jsonCommand operator= (jsonCommand* other);

	/*!
	 * \brief Transforms this object to a nice JSON string
	 * \return The JSON string
	 */
    QString toJsonString() const;
private:
    jsonCommands command;
    QVariantMap data;
};

}
#endif // JSONCOMMAND_H
