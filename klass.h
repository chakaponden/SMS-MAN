#ifndef KLASS_H
#define KLASS_H

#include <QObject>
#include "pupil.h"
#include "subject.h"
#include "timetable.h"
#include "dayinf.h"


// class Klass = contains all Pupils, Klass schedule and marks, that associated with any pupil
class Klass : public QObject
{
    Q_OBJECT
    quint16 Id;                         // klass Id
    QString *Name;                      // Name of Klass (example = "7B")
    QString *Boss;                      // Boss = class teacher, form master
    QHash <quint16, Pupil> *pupList;	// QHash of pupils
    QVector <Timetable> tabList;        // QVector of 7-days lesson (schedule)
    QHash <quint32, DayInf> *infList;   // Days (contains marks - see in)

public:
    Klass(void);
    Klass(quint16& Id);
    Klass(const QString &str1, const QString &str2, quint16& Id);
    Klass(const char *str1, const char *str2, quint16& Id);
    // constructors

    void setName(QString &str);
    void setName(const char *str);
    void setBoss(QString &str);
    void setBoss(const char *str);


    QString* getName(void);
    QString* getBoss(void);

    quint8 Pupil_addCopyUk(Pupil &obj);
    quint8 Pupil_addCopyData(Pupil &obj);
    quint8 Pupil_addCopyData(Pupil &obj, quint16 key);
    // add Pupil to this Klass
    quint8 Pupil_del(quint16 key);
    // delete Pupil by key
    quint8 Pupil_del(QHash<quint16, Pupil>::iterator hashIterator);
    // delete Pupil by Iterator in Hash
    Pupil* Pupil_search(QHash<quint16, Pupil>::iterator hashIterator);
    // search Pupil by Iterator
    Pupil* Pupil_search(quint16 key);
    // search Pupil by key
    quint16 Pupil_size(void);
    // get count of Pupils (number of Pupils)
    void Pupil_freeAll(void);
    // free all Pupils

    quint8 DayInf_addCopyUk(DayInf &obj);
    quint8 DayInf_addCopyData(DayInf &obj);
    quint8 DayInf_addCopyData(DayInf &obj, quint32 key);
    // add DayInf to this Klass
    quint8 DayInf_del(quint32 key);
    // delete DayInf by key
    quint8 DayInf_del(QHash<quint32, DayInf>::iterator hashIterator);
    // delete DayInf by Iterator in Hash
    DayInf* DayInf_search(QHash<quint32, DayInf>::iterator hashIterator);
    // search DayInf by Iterator
    DayInf* DayInf_search(quint32 key);
    // search DayInf by key
    quint32 DayInf_size(void);
    // get count of Days (number of Days)
    void DayInf_freeAll(void);
    // free all Days

    bool Timetable_del_Day(quint8& NumDay);
    // del Day in schedule
    bool Timetable_del_Lesson(quint8& NumDay, quint8& NumLesson);
    // del Lesson in schedule

    bool Timetable_add_Day(quint8& NumDay, Timetable& addDay);
    // add Day in schedule
    bool Timetable_add_Lesson(quint8& NumDay, Lesson& addLesson);
    // del Lesson in schedule

    Timetable* Timetable_get_Day(quint8& NumDay);
    // get Day from schedule

    Lesson* Timetable_get_LessonbyNum(quint8& NumDay, quint8& NumLesson);
    // get Lesson from schedule by index (Num)
    Lesson* Timetable_get_LessonbyId(quint8& NumDay, quint8& IdLesson);
    // get Lesson from schedule by Id Lesson

    bool Timetable_exist_Day(quint8& NumDay);
    // check if Day with number (index) quint8& NumDay is exist in schedule




/*
    // operator =

    friend QDataStream& operator<<(QDataStream &out, Klass &obj);
    // output Klass to QDataStream
    friend Klass* Pupil_inKlass(QDataStream &in, Klass *obj);
    // input from QDataStream to Klass *
*/
    /*
      need to add signals & slots for GUI
    */
    virtual ~Klass(void);
    
signals:
    
public slots:
    
};

#endif // KLASS_H
