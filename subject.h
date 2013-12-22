#ifndef SUBJECT_H
#define SUBJECT_H

#include "teacher.h"
#include <QHash>


// class Subject = Subject, that pupils learn
class Subject : public QObject
{
    Q_OBJECT
    QString *Name;                          // name of Subject
    QHash <quint16, Teacher> *teachList;	// QHash of teachers, that teaching pupils by this subject
public:
    Subject(void);
    Subject(const QString &str);
    Subject(const char *str);
    Subject(const Subject* obj);
	// constructor copy
    Subject(const Subject& obj);
	// constructor copy

    void setName(QString &str);
    void setName(const char *str);


    QString* getName(void);    

    quint8 addCopyUk(Teacher &obj);
    quint8 addCopyData(Teacher &obj);
    quint8 addCopyData(Teacher &obj, quint16 key);
	// add Teacher to this Subject
    quint8 del(quint16 key);
	// delete Teacher by key
    quint8 del(QHash<quint16, Teacher>::iterator hashIterator);
	// delete Teacher by Iterator in Hash
    Teacher* search(QHash<quint16, Teacher>::iterator hashIterator);
	// search Teacher by Iterator
    Teacher* search(quint16 key);
	// search Teacher by key

    void freeAll(void);
    // free all of QHash

    bool operator==(const Subject &obj);
    const Subject& operator =(const Subject &obj);
	// operator =

    friend QDataStream& operator<<(QDataStream &out, Subject &obj);
	// output Subject to QDataStream
    friend Subject* inSubject(QDataStream &in, Subject *obj);
	// input from QDataStream to Subject *

    /*
      need to add signals & slots for GUI
    */

    virtual ~Subject(void);
};
#endif // SUBJECT_H

