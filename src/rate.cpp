#include "rate.h"

Rate::Rate()
{
    values = 0;
    IdSubject = 0;
}


Rate::Rate(quint16& IdSubject)
{
    this->IdSubject = IdSubject;
    values = 0;
}

bool Rate:: del_by_Num(quint8& Num)
{
    quint8 size = this->values->size();
    if(size > Num)
    {
        this->values->remove(Num);
        return true;
    }
    return false;
}

bool Rate:: del_by_Value(quint8& Value)
{
    quint8 size = this->values->size();
    quint8 *tmp = new quint8();
    for(quint8 i = 0; i < size; i++)
    {
        tmp = &this->values->operator [](i);
        if(*tmp == Value)
        {
            this->values->remove(i);
            return true;
        }
    }
    return false;
}

void Rate:: add_Value(quint8& Value)
{
    int new_size = (int)this->values->size();
    this->values->resize(new_size+1);           // false warning
    this->values->insert(new_size,Value);
}

void Rate:: setIdSubject(quint16& IdSubject)
{
    this->IdSubject = IdSubject;
}

uint Rate::get_size(void)
{
    if(this->values)
        if(!this->values->isEmpty())
            return this->values->size();
    return 0;
}

QVector <quint8>* Rate:: get_all_values(void)
{
    if(this->values)
        if(!(this->values->isEmpty()))
                return this->values;
    return (QVector <quint8>*)false;
}

quint16& Rate:: getIdSubject(void)
{
    return this->IdSubject;
}

bool Rate:: exist_value(quint8& Value)
{
    quint8 size = this->values->size();
    quint8 *tmp = new quint8();
    for(quint8 i = 0; i < size; i++)
    {
        tmp = &this->values->operator [](i);
        if(*tmp == Value)
            return true;
    }
    return false;
}

void Rate:: free_All(void)
{
    IdSubject = 0;
    if(this->values)
        this->values->clear();
    this->values = 0;
}

bool Rate::isEmpty(void)
{
    return this->values->isEmpty();
}

bool Rate::isNull(void)
{
    return this->values;
}


Rate:: ~Rate(void)
{
    this->free_All();
}
