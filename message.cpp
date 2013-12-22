#include "message.h"

QString DEFLOGIN("Chajka");
QString DEFPASS("ai75Wkj7");
QString DEFSENDURL("https://sys.sms-assistent.ru/api/v1/send_sms/plain");
QString DEFSTATURL("https://sys.sms-assistent.ru/api/v1/statuses/plain");


QString Message::Login;
QString Message::Pass;
QString Message::SendUrl;
QString Message::StatUrl;

Message::Message(void) : QObject(0)
{
    this->defaultLogin();
    this->defaultPass();
    this->defaultUrls();
    this->Id = 0;
    this->IdKlass = 0;
    this->IdPupil = 0;
    this->mess = 0;
    this->recipient = 0;
    this->Sending = 0;
    this->stat = Not_Send;
}

void Message:: setLogin(QString *newLogin)
{
    Login = *newLogin;
}

void Message:: setPass(QString *newPass)
{
    Pass = *newPass;
}

void Message:: setSendUrl(QString *newSendUrl)
{
    SendUrl = *newSendUrl;
}

void Message:: setStatUrl(QString *newStatUrl)
{
    StatUrl = *newStatUrl;
}

void Message:: setLogin(const char *newLogin)
{
    Login = newLogin;
}

void Message:: setPass(const char *newPass)
{
    Pass = newPass;
}

void Message:: setSendUrl(const char *newSendUrl)
{
    SendUrl = newSendUrl;
}

void Message:: setStatUrl(const char *newStatUrl)
{
    StatUrl = newStatUrl;
}

void Message:: defaultLogin(void)
{
    Login = DEFLOGIN;
}

void Message:: defaultPass(void)
{
    Pass = DEFPASS;
}

void Message:: defaultUrls(void)
{
    SendUrl = DEFSENDURL;
    StatUrl = DEFSTATURL;
}

QString& Message:: getLogin(void)
{
    return Login;
}

QString& Message:: getPass(void)
{
    return Pass;
}

QString& Message:: getSendUrl(void)
{
    return SendUrl;
}

QString& Message:: getStatUrl(void)
{
    return StatUrl;
}

QString* Message:: getMess(void)
{
    return this->mess;
}

QString* Message:: getRecipient(void)
{
    return this->recipient;
}

quint16& Message:: getIdKlass(void)
{
    return this->IdKlass;
}

quint16& Message:: getIdPupil(void)
{
    return this->IdPupil;
}

quint8& Message:: getSending(void)
{
    return this->Sending;
}

Status& Message:: getStat(void)
{
    return this->stat;
}

void Message:: setMess(const char *newMess)
{
    this->clearMess();    
    QString tmpMess(newMess);
    QStdWString postRequest = tmpMess.toStdWString();
    QString FFA;
    FFA = (QString::fromStdWString(postRequest));
    QString *tmp = new QString(FFA);
    mess = tmp;
}

void Message:: setMess(QString *newMess)
{
    this->clearMess();
    QStdWString postRequest = newMess->toStdWString();
    QString FFA;
    FFA = (QString::fromStdWString(postRequest));
    QString *tmp = new QString(FFA);
    mess = tmp;
}

void Message:: setRecipient(const char *newMess)
{
    this->clearRecipient();
    this->recipient = new QString(newMess);
}

void Message:: setRecipient(QString *newMess)
{
    this->clearRecipient();
    this->recipient = new QString(*newMess);
}

void Message:: setIdKlass(quint16 newIdKlass)
{
    this->IdKlass = newIdKlass;
}

void Message:: setIdPupil(quint16 newIdPupil)
{
    this->IdPupil = newIdPupil;
}

void Message:: setSending(quint8 newSending)
{
    this->Sending = newSending;
}

void Message:: clearMess(void)
{
    if(mess)
        mess->~QString();
    mess = 0;
}

void Message:: clearRecipient(void)
{
    if(recipient)
        recipient->~QString();
    recipient = 0;
}

void Message:: clearSending(void)
{
    this->Sending = 0;
}

void Message:: clearStat(void)
{
    this->stat = Not_Send;
}


void Message:: reset(void)
{
    this->Id = 0;
    this->IdKlass = 0;
    this->IdPupil = 0;
    this->clearMess();
    this->clearRecipient();
    this->clearSending();
    this->clearStat();
}

void Message:: send(void)
{
    QString messQString = "&user=" + Login +"&password=" + Pass +"&recip"
            "ient=" + *recipient + "&message=" + *mess + "&sender=sms-dnevnik";
    QByteArray messByte;
    messByte.append(messQString);

    QNetworkAccessManager *pManager = new QNetworkAccessManager;
    QNetworkRequest *request = new QNetworkRequest(QUrl(SendUrl));
    request->setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    pManager->post(*request, messByte);
    connect(pManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinishSend(QNetworkReply*)));
}

QDateTime& Message:: getDateTimeSent(void)
{
    return this->DateTimeSent;
}

QDate& Message:: getDateSent(void)
{
    QDate *tmp = new QDate(this->DateTimeSent.date());
    return *tmp;
}

QTime& Message:: getTimeSent(void)
{
    QTime *tmp = new QTime(this->DateTimeSent.time());
    return *tmp;
}

void Message:: setStat(void)
{
    if(this->Id > 0)
    {

        QString tmpId;
        QString aa;
        tmpId = aa.setNum(this->Id);
        QString messQString = "&user=" + Login +"&password=" + Pass +"&id=" + tmpId;
        QByteArray messByte;
        messByte.append(messQString);

        QNetworkAccessManager *pManager = new QNetworkAccessManager;
        QNetworkRequest *request = new QNetworkRequest(QUrl(StatUrl));
        request->setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

        pManager->post(*request, messByte);
        connect(pManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinishStat(QNetworkReply*)));
    }
    this->stat = Error;
}


void Message::setDateTimeSent(void)
{
    if(this->Id > 0)
    {
        this->DateTimeSent = QDateTime::currentDateTime();
        this->clearSending();        
    }
}


Message:: ~Message(void)
{
    this->Id = 0;
    this->IdKlass = 0;
    this->IdPupil = 0;
    this->clearMess();
    this->clearRecipient();
    this->clearSending();
    this->clearStat();
}



// private slots


void Message::replyFinishStat(QNetworkReply *reply)
{
    QString answer = reply->readAll();
    char ch = answer[0].toAscii();
    switch(ch)
    {
    case 'Q':
    {

        this->stat = Queued;
        break;
    }
    case 'S':
    {
        this->stat = Sent;
        break;
    }
    case 'D':
    {
        this->stat = Delivered;
        break;
    }
    case 'E':
    {
        this->stat = Expired;
        break;
    }
    case 'R':
    {
        this->stat = Rejected;
        break;
    }
    case 'U':
    {
        this->stat = Unknown;
        break;
    }
    }
    setDateTimeSent();
}


void Message::replyFinishSend(QNetworkReply *reply)
{
    QString answer = reply->readAll();
    this->Id = answer.toLongLong();
    setDateTimeSent();    
    setStat();
    //sleep(60); for debug
    setStat();

}
