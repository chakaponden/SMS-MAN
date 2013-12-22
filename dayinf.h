#ifndef DAYINF_H
#define DAYINF_H
#include <QObject>
#include <QDate>
#include <QVector>
#include "dayrate.h"


// class DayInf = Day, that contains all marks of all Pupils, that they get at this Day
class DayInf
{
    QDate Date;                     // date
    QVector <DayRate> *dayList;     // all marks of all Pupils, that they get at this Day

public:
    DayInf();
    DayInf(QDate& new_Date);        // constructors

    void setDate(QDate& new_Date);
    QVector <DayRate>* get_all_Pupils_day(void);
                                    // get QVector <DayRate> *dayList
    QVector <Rate>* get_all_marks_Pupil(quint16& IdPupil);
                                    // get all Pupil's marks
    QVector <quint8>* get_Subj_Marks(quint16& IdPupil, quint16& IdSubject);
                                    // get all Pupil's marks by this Subject
    void free_All(void);            // free QVector <DayRate> *dayList
    bool isEmpty(void);
    bool isNull(void);

    virtual ~DayInf(void);
};

#endif // DAYINF_H
