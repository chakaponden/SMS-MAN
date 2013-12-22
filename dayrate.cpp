#include "dayrate.h"

DayRate::DayRate()
{
    this->rateList = 0;
    this->IdPupil = 0;
}


DayRate::DayRate(quint16& IdPupil)
{
    this->IdPupil = IdPupil;
    this->rateList = 0;
}

quint8 DayRate:: size(void)
{
    if(this->rateList)
        if(!this->isEmpty())
            return (quint8)this->rateList->size();
    return 0;
}

QVector <Rate>* DayRate::getRatelist(void)
{
    return this->rateList;
}

bool DayRate:: del_allMarks_Subj(quint16& IdSubject)
{
    Rate *tmp = 0;
    tmp = this->exist_get_Subj(IdSubject);
    if(tmp)
    {
        if(!tmp->isNull())
        {
            if(!tmp->isEmpty())
            {
                int tmp_size = tmp->get_size();
                tmp_size--;
                for(;tmp_size >= 0; tmp_size--)
                    tmp->del_by_Num((quint8&)tmp_size);
                return true;
            }
        }
    }
    return false;
}

QVector <quint8> * DayRate:: get_allSubj_marks(quint16& IdSubject)
{
    Rate *tmp = 0;
    tmp = this->exist_get_Subj(IdSubject);
    if(tmp)
    {
        tmp->get_all_values();
    }
    return (QVector <quint8> *)false;
}



bool DayRate:: add_mark_toSubj(quint8& Value, quint16& IdSubject)
{
    Rate *tmp = 0;
    tmp = this->exist_get_Subj(IdSubject);
    if(tmp)
    {
        tmp->add_Value(Value);
        return true;
    }
    return false;
}

bool DayRate:: del_Lastmark_fromSubj(quint16& IdSubject)
{
    Rate *tmp = 0;
    tmp = this->exist_get_Subj(IdSubject);
    if(tmp)
    {
        if(!tmp->isNull())
        {
            if(!tmp->isEmpty())
            {
                quint8 tmp_size = tmp->get_size();
                tmp_size--;
                tmp->del_by_Num(tmp_size);
                return true;
            }
        }
    }
    return false;
}

Rate * DayRate:: exist_get_Subj(quint16& IdSubject)
{
    quint8 size = this->rateList->size();
    Rate *tmp = new Rate();
    for(quint8 i = 0; i < size; i++)
    {
        tmp = &this->rateList->operator [](i);
        if(tmp->getIdSubject() == IdSubject)
            return tmp;
    }
    return (Rate *)false;
}

bool DayRate:: exist_mark(quint8& Value, quint16& IdSubject)
{
    Rate *tmp = 0;
    tmp = this->exist_get_Subj(IdSubject);
    if(tmp)
    {
        if(tmp->exist_value(Value))
            return true;
    }
    return false;
}

void DayRate:: setIdPupil(quint16& IdPupil)
{
    this->IdPupil = IdPupil;
}


quint16& DayRate:: getIdPupil(void)
{
    return this->IdPupil;
}

void DayRate:: free_All(void)
{
    IdPupil = 0;
    if(this->rateList)
        this->rateList->clear();
    this->rateList = 0;
}

bool DayRate::isEmpty(void)
{
    return this->rateList->isEmpty();
}

bool DayRate::isNull(void)
{
    return this->rateList;
}


DayRate:: ~DayRate(void)
{
    this->free_All();
}
