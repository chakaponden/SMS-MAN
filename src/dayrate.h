#ifndef DAYRATE_H
#define DAYRATE_H
#include <QObject>
#include <QVector>
#include "rate.h"

// class DayRate = contains all marks by all Subjects, that Pupil get at this Day
class DayRate
{
    quint16 IdPupil;            // Pupil
    QVector <Rate> *rateList;   // QVector of marks by Subject (see in)
public:
    DayRate();
    DayRate(quint16& IdPupil);  // constructors

    bool del_allMarks_Subj(quint16& IdSubject);
                                // delete all marks in Subject
    QVector <quint8> * get_allSubj_marks(quint16& IdSubject);
    bool add_mark_toSubj(quint8& Value, quint16& IdSubject);
                                // get all Subject marks
    bool del_Lastmark_fromSubj(quint16& IdSubject);
                                // delete last mark in Subject
    Rate * exist_get_Subj(quint16& IdSubject);
                                // get QVector <Rate> *rateList element, or false, if it is not exist
    bool exist_mark(quint8& Value, quint16& IdSubject);
                                // check, if this mark exist in this Subject
    void setIdPupil(quint16& IdPupil);

    quint8 size(void);          // get count Subject in this Day = size of QVector <Rate> *rateList

    QVector <Rate> *getRatelist(void);
                                // get QVector <Rate> *rateList
    quint16& getIdPupil(void);
    void free_All(void);        // free QVector <Rate> *rateList

    bool isEmpty(void);
    bool isNull(void);
    virtual ~DayRate(void);
};

#endif // DAYRATE_H
