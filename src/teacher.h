#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>
#include <QDataStream>

// class Teacher = data about man, who learn pupils
class Teacher : public QObject
{
    Q_OBJECT
    QString *FName;			// FName
    QString *LName;			// LName
    QString *MName;			// MName
public:
    Teacher();
    Teacher(const Teacher& obj);
    Teacher(const Teacher* obj);
    Teacher operator *(Teacher &obj);
    Teacher(QString *newF, QString *newL, QString *newM);
    Teacher(const char *newF, const char *newL, const char *newM);

    void setFName(QString *str);
    void setLName(QString *str);
    void setMName(QString *str);
    void setFName(const char *str);
    void setLName(const char *str);
    void setMName(const char *str);
    void setAll(const char *str1, const char *str2, const char *str3);
    void setAll(QString *str1, QString *str2, QString *str3);

    QString* getFName(void);
    QString* getLName(void);
    QString* getMName(void);

    void freeAll(void);     // free all fields


    bool operator==(const Teacher &obj);
    const Teacher& operator =(const Teacher &obj);
	// operator =
	friend QDataStream& operator<<(QDataStream &out, Teacher &obj);
	// output Teacher to QDataStream
    friend Teacher* inTeacher(QDataStream &in, Teacher *obj2);
	// input from QDataStream to Teacher*

    /*
      need to add signals & slots for GUI
    */
    virtual ~Teacher(void);
};

#endif // TEACHER_H
