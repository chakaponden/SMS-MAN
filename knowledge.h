#ifndef KNOWLEDGE_H
#define KNOWLEDGE_H

#include "subject.h"
#include <QFile>


// class Knowledge = base of all Subject (and Teachers, associated with any Subject)
class Knowledge : public QObject
{
    Q_OBJECT
    QHash <quint16, Subject> *knowList;	// QHash of subjects
    QString *File;                      // filename to save/load
public:
    Knowledge(void);
    Knowledge(QString *str);	
    Knowledge(const char *str);

    void setFile(QString *str);
    void setFile(const char *str);
    void remove(void);
    // remove file

    QString* getFile(void);

    quint8 addCopyData(Subject &obj);
	// add Subject
    quint8 addCopyUk(Subject &obj);
    quint8 addCopyData(Subject &obj, quint16 key);
	// add Subject with specific key
    quint8 addCopyUk(Subject &obj, quint16 key);
    quint8 addCopyData(QString &str);
	// add new Subject, specify only Name = parametr str 
    quint8 addCopyData(const char *str);
	// add new Subject, specify only Name = parametr str 

    quint8 del(quint16 key);
	// del Subject by key
    quint8 del(quint16 keySubj, quint16 keyTeacher);
	// del Teacher by keySubject and keyTeacher
    quint8 del(QHash<quint16, Subject>::iterator hashIterator);
	// del Subject by Iterator
    void freeAll(void);

    Teacher* search(quint16 keySubj, quint16 keyTeacher);
	// get Teacher by keySubject and keyTeacher
    Subject* search(quint16 keySubj);
	// get Subject by key

    quint8 load(void);
	// load from File
    quint8 save(void);   
	// save to File

    friend QDataStream& operator<<(QDataStream &out, Knowledge &obj);
	// output Knowledge to QDataStream

    /*
      need to add signals & slots for GUI
    */

    virtual ~Knowledge(void);
};

#endif // KNOWLEDGE_H
