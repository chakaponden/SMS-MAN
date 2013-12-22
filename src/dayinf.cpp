#include "dayinf.h"

DayInf::DayInf()
{
    this->dayList = 0;
}


DayInf::DayInf(QDate& new_Date)
{
    this->Date = new_Date;
}


void DayInf:: setDate(QDate& new_Date)
{
    this->Date = new_Date;
}


QVector <DayRate>* DayInf:: get_all_Pupils_day(void)
{
    return this->dayList;
}


QVector <Rate>* DayInf:: get_all_marks_Pupil(quint16& IdPupil)
{
    if(this->dayList)
        if(!this->dayList->isEmpty())
        {
            DayRate *tmp = new DayRate();
            quint32 size = this->dayList->size();
            for(quint32 i = 0; i < size; i++)
            {
                tmp = &this->dayList->operator [](i);
                if(tmp->getIdPupil() == IdPupil)
                    return tmp->getRatelist();
            }
        }
    return (QVector <Rate>*)false;
}

QVector <quint8>* DayInf::get_Subj_Marks(quint16& IdPupil, quint16& IdSubject)
{
    if(this->dayList)
        if(!this->dayList->isEmpty())
        {
            DayRate *tmp = new DayRate();
            quint32 size = this->dayList->size();
            for(quint32 i = 0; i < size; i++)
            {
                tmp = &this->dayList->operator [](i);
                if(tmp->getIdPupil() == IdPupil)
                    if(tmp->exist_get_Subj(IdSubject))
                    {
                        Rate *tmp_Rate = new Rate();
                        tmp_Rate = tmp->exist_get_Subj(IdSubject);
                        return tmp_Rate->get_all_values();
                    }
            }
        }
    return (QVector <quint8>*)false;

}

void DayInf::free_All(void)
{
    if(this->dayList)
        if(!this->dayList->isEmpty())
            this->dayList->clear();
    this->dayList = 0;
}

bool DayInf::isEmpty(void)
{
    return this->dayList->isEmpty();
}

bool DayInf::isNull(void)
{
    return this->dayList;
}


DayInf:: ~DayInf(void)
{
    this->free_All();
}
