#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QDebug>
#include <QDateTime>

enum Status {Not_Send, Error, Queued, Sent, Delivered, Expired, Rejected, Unknown };
// message state = не отправлено, в очереди, отправлено, доставлено, просрочено, отклонено, неизвестно

// class Message = Message, that be send
class Message :  public QObject
{
    Q_OBJECT

    qlonglong Id;               // message Id/Error code
    quint16 IdKlass;            // Id Klass
    quint16 IdPupil;            // Id Pupil
    QDateTime DateTimeSent;     // date and time, when sms status has last update
    quint8 Sending;             // additional field (later will be use)
    QString *recipient;         // number without '+' (example = "375291246045")
    QString *mess;              // message
    Status stat;                // message status

    static QString Login;       // login
    static QString Pass;        // password
    static QString SendUrl;     // url for send
    static QString StatUrl;     // url for status


private:
    void setDateTimeSent(void); // set date and time,
                                // when sms has been send    
public:
    Message();

    static void setLogin(QString *newLogin);
    static void setPass(QString *newPass);
    static void setSendUrl(QString *newSendUrl);
    static void setStatUrl(QString *newSendUrl);

    static void setLogin(const char *newLogin);
    static void setPass(const char *newPass);
    static void setSendUrl(const char *newSendUrl);
    static void setStatUrl(const char *newStatUrl);

    static void defaultLogin(void);
    static void defaultPass(void);
    static void defaultUrls(void);
    // static metods = initialize on create any object, or without it

    static QString& getLogin(void);
    static QString& getPass(void);
    static QString& getSendUrl(void);
    static QString& getStatUrl(void);


    void setMess(QString *newMess);
    void setMess(const char *newMess);
    // set Message
    void setRecipient(const char *newMess);
    void setRecipient(QString *newMess);
    void setIdKlass(quint16 newIdKlass);
    // set Id Klass of Pupil
    void setIdPupil(quint16 newIdPupil);
    // set Id Pupil, marks of whom are send
    void setSending(quint8 newSending);
    // indicator of that this Message must be Send in mailing

    QDateTime& getDateTimeSent(void);
    // get time, when Message has been send (last Update)
    QString* getMess(void);
    QString* getRecipient(void);
    quint16& getIdKlass(void);
    quint16& getIdPupil(void);
    quint8& getSending(void);
    Status& getStat(void);
    // det Message Status
    QDate& getDateSent(void);
    // get Date, when Message has been sent
    QTime& getTimeSent(void);
    // get Time, when Message has been sent

    void send(void);            // send sms
    void setStat(void);         // update sms status

    void clearMess(void);
    void clearRecipient(void);
    void clearSending(void);    // must be Send in mailing = OFF
    void clearStat(void);       // set Stat to <Not_Send>
    void reset(void);           // clear all fields
    virtual ~Message(void);
private slots:
    void replyFinishSend(QNetworkReply*);
    // when server send answer about sending message
    void replyFinishStat(QNetworkReply*);
    // when server send answer about message status


};

#endif // MESSAGE_H
