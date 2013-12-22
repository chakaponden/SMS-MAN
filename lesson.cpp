#include "lesson.h"

Lesson::Lesson(void) //: QObject(0)
{
    IdSubject = IdTeacher = 0;
    Id = 0;
}

Lesson::Lesson(quint8& newId)// : QObject(0)
{
    Id = newId;
}


Lesson::Lesson(quint8& newId, quint16& newIdSubject, quint16& newIdTeacher, QTime& newStartTime) //: QObject(0)
{
    IdSubject = newIdSubject;
    IdTeacher = newIdTeacher;
    StartTime = newStartTime;
    Id = newId;
}


void Lesson::setAll(quint8& newId, quint16& newIdSubject, quint16& newIdTeacher, QTime& newStartTime)
{
    IdSubject = newIdSubject;
    IdTeacher = newIdTeacher;
    StartTime = newStartTime;
    Id = newId;
}


void Lesson::setSubject(quint16& newIdSubject)
{
    IdSubject = newIdSubject;
}


void Lesson::setTeacher(quint16& newIdTeacher)
{
    IdTeacher = newIdTeacher;
}


void Lesson::setStartTime(QTime& newStartTime)
{
    StartTime = newStartTime;
}

void Lesson::setId(quint8& newId)
{
    Id = newId;
}

quint16& Lesson::getSubject(void)
{
    return this->IdSubject;
}

quint16& Lesson::getTeacher(void)
{
    return this->IdTeacher;
}

QTime& Lesson::getTimeQTime(void)
{
    return this->StartTime;
}


quint8& Lesson::getId(void)
{
    return this->Id;
}

void Lesson::reset(void)
{
    IdSubject = IdTeacher = 0;
    Id = 0;
    StartTime.restart();
}

Lesson::~Lesson(void)
{
    //StartTime.
    IdSubject = IdTeacher = 0;
    Id = 0;
}
