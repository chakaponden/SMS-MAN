#include "klass.h"

Klass::Klass() : QObject(0)
{
    this->Boss = 0;
    this->Id = 0;
    this->Name = 0;
    this->pupList = 0;
    Timetable tmp;
    this->tabList.fill(tmp,7);      // initialize 7 days with 0
}

Klass::Klass(const QString &str1, const QString &str2, quint16& Id): QObject(0)
{
    this->Name = new QString (str1);
    this->Boss =new QString (str2);
    this->Id = Id;
    this->pupList = 0;
    Timetable tmp;
    this->tabList.fill(tmp,7);      // initialize 7 days with 0
}


Klass::Klass(const char *str1, const char *str2, quint16& Id): QObject(0)
{
    this->Name = new QString(str1);
    this->Boss = new QString(str2);
    this->Id = Id;
    this->pupList = 0;
    Timetable tmp;
    this->tabList.fill(tmp,7);      // initialize 7 days with 0
}

void Klass:: setName(QString &str)
{
    if(Name)
        Name->~QString();
    this->Name = new QString(str);
}


void Klass:: setName(const char *str)
{
    if(Name)
        Name->~QString();
    this->Name = new QString(str);
}

void Klass:: setBoss(QString &str)
{
    if(Boss)
        Boss->~QString();
    this->Boss = new QString(str);
}


void Klass:: setBoss(const char *str)
{
    if(Boss)
        Boss->~QString();
    this->Boss = new QString(str);
}


QString* Klass:: getName(void)
{
    return this->Name;
}

QString* Klass:: getBoss(void)
{
    return this->Boss;
}


quint8 Klass:: DayInf_addCopyUk(DayInf &obj)
{
    if(infList == 0)
        this->infList = new QHash <quint32, DayInf>();
    for(quint32 i = 1; i < 65535; i++)
    {
        if(!(infList->contains(i)))
        {
            DayInf aa(obj);
            infList->insert(i,aa);
            return 0;     // ok
        }
    }
    return 1;           // error - hash is full
                        // there are no free avalible keys
                        // all [1, 65534] keys are busy
}

quint32 Klass:: DayInf_size(void)
{
    if(this->infList)
    {
        if(this->infList->isEmpty())
            return 0;
        return this->infList->size();
    }
    return 0;
}

quint8 Klass:: DayInf_addCopyData(DayInf &obj)
{
    if(!infList)
        this->infList = new QHash <quint32, DayInf>();
    for(quint32 i = 1; i < 65535; i++)
    {
        if(!(infList->contains(i)))
        {
            DayInf aa = obj;
            infList->insert(i,aa);
            return 0;     // ok
        }
    }
    return 1;           // error - hash is full
                        // there are no free avalible keys
                        // all [1, 65534] keys are busy
}

quint8 Klass:: DayInf_addCopyData(DayInf &obj, quint32 key)
{
    if(!infList)
        this->infList = new QHash <quint32, DayInf>();
    if(!(infList->contains(key)))
    {
        DayInf aa = obj;
        infList->insert(key,aa);
        return 0;     // ok
    }
    return 1;           // error - hash is full
                        // there are no free avalible keys
                        // all [1, 65534] keys are busy
}


quint8 Klass:: DayInf_del(quint32 key)
                            // delete element according to
                            // key
{
    if(key != 0 && infList->contains(key))
    {
        infList->remove(key);
        return 0;           // ok
    }
    return 1;               // error - there are no elements according quint16 key
                            // or key = 0
}


quint8 Klass:: DayInf_del(QHash<quint32, DayInf>::iterator hashIterator)
                            // delete element according to
                            // iterator
{
    if(hashIterator.key())
    {
        infList->erase(hashIterator);
        return 0;           // ok
    }
    return 1;               // error, because item's key = 0
}


DayInf* Klass:: DayInf_search(quint32 key)
{
    if(infList->contains(key))
        return &(infList->operator [](key));
    return 0;
}


DayInf* Klass:: DayInf_search(QHash<quint32, DayInf>::iterator hashIterator)
{
    return &(hashIterator.value());
}



void Klass:: DayInf_freeAll(void)
{
    if(infList)
         infList->clear();
     delete (infList);
     infList = 0;
}




quint8 Klass:: Pupil_addCopyUk(Pupil &obj)
{
    if(pupList == 0)
        this->pupList = new QHash <quint16, Pupil>();
    for(quint16 i = 1; i < 65535; i++)
    {
        if(!(pupList->contains(i)))
        {
            Pupil aa(obj);
            pupList->insert(i,aa);
            return 0;     // ok
        }
    }
    return 1;           // error - hash is full
                        // there are no free avalible keys
                        // all [1, 65534] keys are busy
}

quint16 Klass:: Pupil_size(void)
{
    if(this->pupList)
    {
        if(this->pupList->isEmpty())
            return 0;
        return this->pupList->size();
    }
    return 0;
}

quint8 Klass:: Pupil_addCopyData(Pupil &obj)
{
    if(!pupList)
        this->pupList = new QHash <quint16, Pupil>();
    for(quint16 i = 1; i < 65535; i++)
    {
        if(!(pupList->contains(i)))
        {
            Pupil aa = obj;
            pupList->insert(i,aa);
            return 0;     // ok
        }
    }
    return 1;           // error - hash is full
                        // there are no free avalible keys
                        // all [1, 65534] keys are busy
}

quint8 Klass:: Pupil_addCopyData(Pupil &obj, quint16 key)
{
    if(!pupList)
        this->pupList = new QHash <quint16, Pupil>();
    if(!(pupList->contains(key)))
    {
        Pupil aa = obj;
        pupList->insert(key,aa);
        return 0;     // ok
    }
    return 1;           // error - hash is full
                        // there are no free avalible keys
                        // all [1, 65534] keys are busy
}


quint8 Klass:: Pupil_del(quint16 key)
                            // delete element according to
                            // key
{
    if(key != 0 && pupList->contains(key))
    {
        pupList->remove(key);
        return 0;           // ok
    }
    return 1;               // error - there are no elements according quint16 key
                            // or key = 0
}


quint8 Klass:: Pupil_del(QHash<quint16, Pupil>::iterator hashIterator)
                            // delete element according to
                            // iterator
{
    if(hashIterator.key())
    {
        pupList->erase(hashIterator);
        return 0;           // ok
    }
    return 1;               // error, because item's key = 0
}


Pupil* Klass:: Pupil_search(quint16 key)
{
    if(pupList->contains(key))
        return &(pupList->operator [](key));
    return 0;
}


Pupil* Klass:: Pupil_search(QHash<quint16, Pupil>::iterator hashIterator)
{
    return &(hashIterator.value());
}



void Klass:: Pupil_freeAll(void)
{
    if(pupList)
         pupList->clear();
     delete (pupList);
     pupList = 0;
}

bool Klass:: Timetable_exist_Day(quint8& NumDay)
{
    if((bool)&this->tabList)
    {
        if(!this->tabList.isEmpty())
        {
            if((bool)&(this->tabList.at(NumDay)))
                return true;
        }
    }
    return false;

}

bool Klass:: Timetable_del_Day(quint8& NumDay)
{
    if(this->Timetable_exist_Day(NumDay))
    {
        Timetable *tmp = new Timetable();
        tmp = &this->tabList.operator [](NumDay);
        tmp->del_byNum((uint&)NumDay);
        return true;
    }
    return false;
}

bool Klass:: Timetable_del_Lesson(quint8& NumDay, quint8& NumLesson)
{
    if(this->Timetable_exist_Day(NumDay))
    {
        Timetable *tmp = new Timetable();
        tmp = &this->tabList.operator [](NumDay);
        if(tmp->check_exist(NumLesson))
        {
            tmp->del_byNum((uint&)NumLesson);
            return true;
        }
    }
    return false;
}

bool Klass:: Timetable_add_Day(quint8& NumDay, Timetable& addDay)
{
    if(!(this->Timetable_exist_Day(NumDay)))
    {
        this->tabList.insert((int)NumDay, addDay);
        return true;
    }
    return false;
}

bool Klass:: Timetable_add_Lesson(quint8& NumDay, Lesson& addLesson)
{
    if(this->Timetable_exist_Day(NumDay))
    {
        Timetable *tmp = new Timetable();
        tmp = &this->tabList.operator [](NumDay);
        if(!(tmp->check_exist(addLesson.getId())))
        {
            tmp->insert(addLesson);
            return true;
        }
    }
    return false;
}

Timetable* Klass:: Timetable_get_Day(quint8& NumDay)
{
    if(this->Timetable_exist_Day(NumDay))
    {
        Timetable *tmp = new Timetable();
        tmp = &this->tabList.operator [](NumDay);
        return tmp;
    }
    return (Timetable*)false;
}

Lesson* Klass:: Timetable_get_LessonbyNum(quint8& NumDay, quint8& NumLesson)
{
    if(this->Timetable_exist_Day(NumDay))
    {
        Timetable *tmp = new Timetable();
        tmp = &this->tabList.operator [](NumDay);
        if(tmp->get_size() > NumLesson)
            return tmp->get_objLesson_byNum((uint&)NumLesson);
    }
    return (Lesson*)false;
}

Lesson* Klass:: Timetable_get_LessonbyId(quint8& NumDay, quint8& IdLesson)
{
    if(this->Timetable_exist_Day(NumDay))
    {
        Timetable *tmp = new Timetable();
        tmp = &this->tabList.operator [](NumDay);
        if(tmp->check_exist(IdLesson))
            return tmp->get_objLesson_byId(IdLesson);
    }
    return (Lesson*)false;
}



Klass:: ~Klass(void)
{
    if(Boss)
        Boss->~QString();
    if(Name)
        Name->~QString();
    Boss = 0;
    Name = 0;
    this->Id = 0;
    this->Pupil_freeAll();
    this->DayInf_freeAll();
    if((bool)&this->tabList)
    {
        if(!(this->tabList.isEmpty()))
            this->tabList.clear();
    }
}
