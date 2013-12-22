#ifndef TIMETABLE_H
#define TIMETABLE_H

#include "lesson.h"
#include <QVector>

// class Timetable = list of all Lessons at current Day
class Timetable// : public QObject
{
    // Q_OBJECT

    QVector <Lesson> *lessList;	// Vector of lessons
                                // num of lessons = (size of QVector <Lesson> *lessList)
public:
    Timetable(void);

    bool setIdSubject(quint8& Id, quint16& newIdSubject);
    bool setIdTeacher(quint8& Id, quint16& newIdTeacher);
    bool setStartTime(quint8& Id, QTime& StartTime);
                                // set Start time of lesson
    bool setId(quint8& old_Id, quint8& new_Id);

    bool insert(quint8& Id, QTime& StartTime, quint16& IdSubject, quint16& IdTeacher);
                                // add Lesson
    bool insert(quint8& Id);
                                // add Lesson
    bool insert(Lesson& add_less);
                                // add Lesson

    bool del_byId(quint8& Id);
                                // delete Lesson
    bool del_byNum(uint& Num);
    void clearAll(void);
                                // free all Lessons
    bool isEmpty(void);
    bool isNull(void);

    quint16 get_IdSubject(quint8& Id);
    quint16 get_IdTeacher(quint8& Id);
    QTime* get_StartTime(quint8& Id);

    bool check_exist(quint8& Id);
                            // check if Lesson with Id exist in QVector <Lesson> *lessList
    qint8 get_Num_byId(quint8& Id);
                            // get Num(index) of Lesson in QVector <Lesson> *lessList by Lesson Id
    Lesson* get_objLesson_byId(quint8& Id);
                            // get Lesson by Id
    Lesson* get_objLesson_byNum(uint& Num);
                            // get Lesson by Num(index) in QVector <Lesson> *lessList

    uint get_size(void);
                            // get Lesson count in QVector <Lesson> *lessList = size QVector <Lesson> *lessList
    bool resize(uint& new_size);
                            // resize after delete obj Lesson

    virtual ~Timetable(void);
    
signals:
    
public slots:
    
};

#endif // TIMETABLE_H
