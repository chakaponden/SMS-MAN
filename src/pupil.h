#ifndef PUPIL_H
#define PUPIL_H
#include <QObject>


// class Pupil = pupil, that learning at school
class Pupil :  public QObject
{
    Q_OBJECT
    QString *FName;			// FName
    QString *LName;			// LName
    QString *MName;			// MName
    QString *Phone;         // Phone number
public:
    Pupil();
    Pupil(const Pupil& obj);
    Pupil(const Pupil* obj);
    Pupil operator *(Pupil &obj);
    Pupil(QString *newF, QString *newL, QString *newM, QString *newPhone);
    Pupil(const char *newF, const char *newL, const char *newM, const char *newPhone);
                            // constructors

    void setFName(QString *str);
    void setLName(QString *str);
    void setMName(QString *str);
    void setPhone(QString *str);
    void setFName(const char *str);
    void setLName(const char *str);
    void setMName(const char *str);
    void setPhone(const char *str);
    void setAll(const char *str1, const char *str2, const char *str3, const char *str4);
    void setAll(QString *str1, QString *str2, QString *str3, QString *str4);

    QString* getFName(void);
    QString* getLName(void);
    QString* getMName(void);
    QString* getPhone(void);


    void freeAll(void);
                            // free all fields

    bool operator==(const Pupil &obj);
                            // operator ==
    const Pupil& operator =(const Pupil &obj);
    // operator =
    friend QDataStream& operator<<(QDataStream &out, Pupil &obj);
    // output Pupil to QDataStream
    friend Pupil* inPupil(QDataStream &in, Pupil *obj2);
    // input from QDataStream to Pupil*

    /*
      need to add signals & slots for GUI
    */
    virtual ~Pupil(void);
};

#endif // PUPIL_H
