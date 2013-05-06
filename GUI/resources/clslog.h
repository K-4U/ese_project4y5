#ifndef CLSLOG_H
#define CLSLOG_H
#include <QDebug>
#include <QDateTime>
#include <string>
#include <iostream>
#include <QStringList>

namespace K4U {
enum logTags{
    LOGTAGS_UNKNOWN = 0xFF,
    LOGTAGS_ROOMBA = 0x00,
    LOGTAGS_MAIN,
    LOGTAGS_EVENT,
    LOGTAGS_SERVER
};

/*!
 * \brief Custom logging class
 * \author Koen Beckers (K-4U)
 * Because std::out doesn't allow for QT-objects, i wrote my own parser on top of this.
 * It also allows tags and date, so that you can allways see where the debug came from
 */
class clsLog{
public:
	/*!
	 * \brief clsLog constructor
	 * \param tag The tag to use while printing
	 */
    clsLog(logTags tag);

	/*!
	 * \brief Used for end line
	 */
    clsLog& operator<<(clsLog& (*manip)(clsLog&));

    clsLog& operator << (QString msg);
    clsLog& operator << (const QString *msg);
    clsLog& operator << (const char* msg);
    clsLog& operator << (int msg);
    clsLog& operator << (clsLog *log);
    clsLog& operator << (bool msg);
    clsLog& operator << (QVariantMap &map);
    clsLog& operator << (const QVariantMap &map);
    clsLog& operator << (const QVariant &msg);
    clsLog& operator << (QVariant &msg);
    clsLog& operator << (QByteArray &bArr);
    clsLog& operator << (const QByteArray &bArr);



    void doEndl();
	/*!
	 * \brief Sets a custom prefix, used for when more than one object uses the same log tag
	 * \param prefix The prefix to show
	 */
    void setPrefix(QString prefix);
private:
    bool isFirst;
    logTags tag;

    void prefix();
    std::string getTag();
    QString prf;
};

clsLog& endl(clsLog& log);


}

#endif // CLSLOG_H
