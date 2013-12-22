#ifndef LESSON_H
#define LESSON_H

#include <QObject>
#include <QTime>


// class Lesson = contain Start Time of Lesson, Id Teacher, that learning and Id Subject
class Lesson
{

    quint8 Id;                  // Id (number in schedule)
    QTime StartTime;			// StartTime lesson
    quint16 IdSubject;			// Id Subject
    quint16 IdTeacher;			// Id Teacher
public:
    Lesson(void);
    Lesson(quint8& newId, quint16& newIdSubject, quint16& newIdTeacher, QTime& newStartTime);
    Lesson(quint8& newId);
                                // constructors
    void setAll(quint8& newId, quint16& newIdSubject, quint16& newIdTeacher, QTime& newStartTime);
    void setSubject(quint16& newIdSubject);
    void setTeacher(quint16& newIdTeacher);
    void setStartTime(QTime& newStartTime);
    void setId(quint8& newId);

    quint16& getSubject(void);
    quint16& getTeacher(void);
    QTime& getTimeQTime(void);
    quint8& getId(void);
    void reset(void);       // clear all fields

    virtual ~Lesson(void);
    
signals:
    
public slots:
    
};

#endif // LESSON_H
