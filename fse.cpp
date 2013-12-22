#include "dayrate.h"

dayrate::dayrate(void)// : QObject(0)
{
    this->lessList = 0;
}

bool dayrate::setIdSubject(quint8& Id, quint16& newIdSubject)
{
    quint8 size = this->lessList->size();
    Lesson *tmp = new Lesson();
    for(qint8 i = 0; i < size; i++)
    {
        tmp = &this->lessList->operator [](i);
        if(tmp->getId() == Id)
        {
            tmp->setSubject(newIdSubject);
            return true;
        }
    }
    return false;
}

bool dayrate::setIdTeacher(quint8& Id, quint16& newIdTeacher)
{
    quint8 size = this->lessList->size();
    Lesson *tmp = new Lesson();
    for(qint8 i = 0; i < size; i++)
    {
        tmp = &this->lessList->operator [](i);
        if(tmp->getId() == Id)
        {
            tmp->setTeacher(newIdTeacher);
            return true;
        }
    }
    return false;
}

bool dayrate::setStartTime(quint8& Id, QTime& StartTime)
{
    quint8 size = this->lessList->size();
    Lesson *tmp = new Lesson();
    for(qint8 i = 0; i < size; i++)
    {
        tmp = &this->lessList->operator [](i);
        if(tmp->getId() == Id)
        {
            tmp->setStartTime(StartTime);
            return true;
        }
    }
    return false;
}

bool dayrate::setId(quint8& old_Id, quint8& new_Id)
{
    quint8 size = this->lessList->size();
    Lesson *tmp = new Lesson();
    for(qint8 i = 0; i < size; i++)
    {
        tmp = &this->lessList->operator [](i);
        if(tmp->getId() == old_Id)
        {
            tmp->setId(new_Id);
            return true;
        }
    }
    return false;
}

bool dayrate::insert(quint8& Id, QTime& StartTime, quint16& IdSubject, quint16& IdTeacher)
{
    quint8 size = this->lessList->size();
    Lesson *tmp = new Lesson();
    for(qint8 i = 0; i < size; i++)
    {
        tmp = &this->lessList->operator [](i);
        if(tmp->getId() == Id)
            return false;
    }
    tmp->~Lesson();
    Lesson tmp_init(Id, IdSubject, IdTeacher, StartTime);
    this->lessList->insert(size, tmp_init);
    return true;
}

bool dayrate::insert(quint8& Id)
{
    quint8 size = this->lessList->size();
    Lesson *tmp = new Lesson();
    for(qint8 i = 0; i < size; i++)
    {
        tmp = &this->lessList->operator [](i);
        if(tmp->getId() == Id)
            return false;
    }
    tmp->~Lesson();
    Lesson tmp_init(Id);
    this->lessList->insert(size, tmp_init);
    return true;
}

bool dayrate::insert(Lesson& add_less)
{
    quint8 size = this->lessList->size();
    Lesson *tmp = new Lesson();
    quint8 tmp_Id = add_less.getId();
    for(qint8 i = 0; i < size; i++)
    {
        tmp = &this->lessList->operator [](i);
        if(tmp->getId() == tmp_Id)
            return false;
    }
    tmp->~Lesson();
    this->lessList->insert(size, add_less);
    return true;
}

bool dayrate::del_byId(quint8& Id)
{
    quint8 size = this->lessList->size();
    Lesson *tmp = new Lesson();
    for(qint8 i = 0; i < size; i++)
    {
        tmp = &this->lessList->operator [](i);
        if(tmp->getId() == Id)
        {
            this->lessList->remove(i);
            return true;
        }
    }
    return false;
}

bool dayrate::del_byNum(uint& Num)
{
    quint8 size = this->lessList->size();
    if(size > Num)
    {
        if((bool)&this->lessList->operator [](Num))
        {
            this->lessList->remove(Num);
            return true;
        }
    }
    return false;

}

void dayrate::clearAll(void)
{
    if(this->lessList)
        this->lessList->clear();
}

bool dayrate::isEmpty(void)
{
    return this->lessList->isEmpty();
}

bool dayrate::isNull(void)
{
    return this->lessList;
}

quint16 dayrate::get_IdSubject(quint8& Id)
{
    quint8 size = this->lessList->size();
    Lesson *tmp = new Lesson();
    qint8 i = 0;
    for(; i < size; i++)
    {
        tmp = &this->lessList->operator [](i);
        if(tmp->getId() == Id)
            return tmp->getSubject();
    }
    return false;
}

quint16 dayrate::get_IdTeacher(quint8& Id)
{
    quint8 size = this->lessList->size();
    Lesson *tmp = new Lesson();
    qint8 i = 0;
    for(; i < size; i++)
    {
        tmp = &this->lessList->operator [](i);
        if(tmp->getId() == Id)
            return tmp->getTeacher();
    }
    return false;
}

QTime* dayrate::get_StartTime(quint8& Id)
{
    quint8 size = this->lessList->size();
    Lesson *tmp = new Lesson();
    qint8 i = 0;
    for(; i < size; i++)
    {
        tmp = &this->lessList->operator [](i);
        if(tmp->getId() == Id)
            return &(tmp->getTimeQTime());
    }
    return (QTime*)false;
}

bool dayrate::check_exist(quint8& Id)
{
    quint8 size = this->lessList->size();
    Lesson *tmp = new Lesson();
    for(quint8 i = 0; i < size; i++)
    {
        tmp = &this->lessList->operator [](i);
        if(tmp->getId() == Id)
            return true;
    }
    return false;
}

qint8 dayrate::get_Num_byId(quint8& Id)
{
    quint8 size = this->lessList->size();
    Lesson *tmp = new Lesson();
    qint8 i = 0;
    for(; i < size; i++)
    {
        tmp = &this->lessList->operator [](i);
        if(tmp->getId() == Id)
            return i;
    }
    i = -1;
    return i;
}

Lesson* dayrate::get_objLesson_byId(quint8& Id)
{
    quint8 size = this->lessList->size();
    Lesson *tmp = new Lesson();
    for(quint8 i = 0; i < size; i++)
    {
        tmp = &this->lessList->operator [](i);
        if(tmp->getId() == Id)
            return tmp;
    }
    return (Lesson*)false;
}

Lesson* dayrate::get_objLesson_byNum(uint& Num)
{
    quint8 size = this->lessList->size();
    if(size > Num)
        return &(this->lessList->operator [](Num));
    else
        return (Lesson*)false;
}

uint dayrate::get_size(void)
{
    return this->lessList->size();
}

bool dayrate::resize(uint& new_size)
{
    this->lessList->resize(new_size);
    if((uint)this->lessList->size() == new_size)
        return true;
    return false;
}

dayrate::~dayrate(void)
{
    this->clearAll();
}
