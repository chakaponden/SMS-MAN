#include "subject.h"

extern QDataStream& outQString(QDataStream &out, const QString &str);
extern QString* inQString(QDataStream &in, QString *str);


Subject::Subject() : QObject(0)
{
    Name = 0;
    teachList = 0;
}


Subject::Subject(const QString &str): QObject(0)
{
    this->Name = new QString (str);
    teachList = 0;
}


Subject::Subject(const char *str): QObject(0)
{
    this->Name = new QString(str);
    teachList = 0;
}


Subject::Subject(const Subject& obj): QObject(0) // constructor copy
{
    /* delete (Name);               // error memory
    if(teachList)
        teachList->clear();
    delete (teachList);*/
    if(obj.Name)
        Name = new QString(*obj.Name);
    else
        Name = 0;
        if(obj.teachList)
        {
            this->teachList = new QHash <quint16, Teacher>();
            quint16 num = obj.teachList->size();
            if(num)
            {
                QHashIterator <quint16,Teacher> it(*obj.teachList);
                Teacher a;
                while (it.hasNext())
                {
                    it.next();
                    num = it.key();
                    a = it.value();
                    this->teachList->insert(num,a);
                }
            }

        }
        else
            this->teachList = 0;
}


Subject::Subject(const Subject* obj): QObject(0) // constructor copy
{
    /* delete (Name);               // error memory
    if(teachList)
        teachList->clear();
    delete (teachList);*/
    if(obj->Name)
        Name = new QString(*obj->Name);
    else
        Name = 0;
        if(obj->teachList)
        {
            this->teachList = new QHash <quint16, Teacher>();
            quint16 num = obj->teachList->size();
            if(num)
            {
                QHashIterator <quint16,Teacher> it(*obj->teachList);
                Teacher a;
                while (it.hasNext())
                {
                    it.next();
                    num = it.key();
                    a = it.value();
                    this->teachList->insert(num,a);
                }
            }

        }
        else
            this->teachList = 0;
}


void Subject:: setName(QString &str)
{
    if(Name)
        Name->~QString();
    this->Name = new QString(str);
}


void Subject:: setName(const char *str)
{
    if(Name)
        Name->~QString();
    this->Name = new QString(str);
}


QString* Subject:: getName(void)
{
    return this->Name;
}


quint8 Subject:: addCopyUk(Teacher &obj)
{
    if(teachList == 0)
        this->teachList = new QHash <quint16, Teacher>();
    for(quint16 i = 1; i < 65535; i++)
    {
        if(!(teachList->contains(i)))
        {
            Teacher aa(obj);
            teachList->insert(i,aa);
            return 0;     // ok
        }
    }
    return 1;           // error - hash is full
                        // there are no free avalible keys
                        // all [1, 65534] keys are busy
}


quint8 Subject:: addCopyData(Teacher &obj)
{
    if(!teachList)
        this->teachList = new QHash <quint16, Teacher>();
    for(quint16 i = 1; i < 65535; i++)
    {        
        if(!(teachList->contains(i)))
        {
            Teacher aa = obj;
            teachList->insert(i,aa);
            return 0;     // ok
        }
    }
    return 1;           // error - hash is full
                        // there are no free avalible keys
                        // all [1, 65534] keys are busy
}

quint8 Subject:: addCopyData(Teacher &obj, quint16 key)
{
    if(!teachList)
        this->teachList = new QHash <quint16, Teacher>();
    if(!(teachList->contains(key)))
    {
        Teacher aa = obj;
        teachList->insert(key,aa);
        return 0;     // ok
    }
    return 1;           // error - hash is full
                        // there are no free avalible keys
                        // all [1, 65534] keys are busy
}


quint8 Subject:: del(quint16 key)
                            // delete element according to
                            // key
{
    if(key != 0 && teachList->contains(key))
    {
        teachList->remove(key);
        return 0;           // ok
    }
    return 1;               // error - there are no elements according quint16 key
                            // or key = 0
}


quint8 Subject:: del(QHash<quint16, Teacher>::iterator hashIterator)
                            // delete element according to
                            // iterator
{
    if(hashIterator.key())
    {
        teachList->erase(hashIterator);
        return 0;           // ok
    }
    return 1;               // error, because item's key = 0
}


Teacher* Subject:: search(quint16 key)
{
    if(teachList->contains(key))
        return &(teachList->operator [](key));
    return 0;
}


Teacher* Subject:: search(QHash<quint16, Teacher>::iterator hashIterator)
{
    return &(hashIterator.value());
}


bool Subject:: operator==(const Subject &obj)
{
    return(Name == obj.Name &&
           teachList == obj.teachList);
}


const Subject& Subject::operator =(const Subject &obj)// copy only uk
{
    if(&obj == this)
        return *this;
    if(Name)
        Name->~QString();
    if(teachList)
        teachList->clear();
    delete (teachList);
    Name = new QString(*obj.Name);
    if(obj.teachList)
    {
        this->teachList = new QHash <quint16, Teacher>();
        quint16 num = obj.teachList->size();
        if(num)
        {
            QHashIterator <quint16,Teacher> it(*obj.teachList);
            Teacher a;
            while (it.hasNext())
            {
                it.next();
                num = it.key();
                a = it.value();
                this->teachList->insert(num,a);
            }
        }

    }
    else
        this->teachList = 0;
    return *this;
}

void Subject:: freeAll(void)
{
    if(teachList)
         teachList->clear();
     delete (teachList);
     teachList = 0;
     if(Name)
         Name->~QString();
     Name = 0;
}

Subject::~Subject(void)
{

    this->freeAll();
}


Subject* inSubject(QDataStream &in, Subject *obj)
{

    if(obj)
        obj->freeAll();
    obj->Name = inQString(in,obj->Name);
    quint16 num = 0;
    in >> num;
    if(!num)
    {
       obj->teachList = 0;
       return obj;   // ok
    }
    quint16 i = 0;
    Teacher *obj2 = new Teacher;
    while(num)
    {
        in >> i;
        inTeacher(in, obj2);
        obj->addCopyData(*obj2, i);
        num--;
     }
	obj2->~Teacher();//////////////////////////
    return obj;           // ok
}
// input from QDataStream to Subject *


QDataStream& operator<<(QDataStream &out, Subject &obj)
{

    outQString(out,*obj.Name);
    if(obj.teachList)
    {
        quint16 num = obj.teachList->size();
        out << num;
        if(num)
        {
            QHashIterator <quint16,Teacher> it(*obj.teachList);
            Teacher a;
            quint16 key;
            while (it.hasNext())
            {
                it.next();
                key = it.key();
                a = it.value();
                out << key;
                out << a;
            }
        }
    }
    else
        out << (quint16)0;
    return out;
}
// output Subject to QDataStream


