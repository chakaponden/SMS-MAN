#include "pupil.h"
#include <QDataStream>

// other func

QString* inQStringP(QDataStream &in, QString *str)
{
//    if(str)
//        str->~QString();
    quint16 size;
    in >> size;
    if(size)
    {
        if(str)
            str->~QString();
        str = new QString();
        quint16 i = 0;
        quint8 ch;
        while(size)
        {
            in >> ch;
            str->insert(i,ch);
            i++;
            size--;
        }
    }
    else
        str = 0;
    return str;
}
// input from QDataStream to QString*


QDataStream& outQStringP(QDataStream &out, const QString &str)
{
    quint16 size = 0;
    if(&str)
    {
        size = str.size();
        out << size;
        if(size)
        {
            quint16 i = 0;
            quint8 ch;
            while(size)
            {
                ch = str[i].toAscii();
                out << ch;
                i++;
                size--;
            }
        }
    }
    else
        out << size;
    return out;
}
// output QString& to thread QDataStream


Pupil::Pupil(): QObject(0)
{
    FName = 0;
    MName = 0;
    LName = 0;
    Phone = 0;
}


Pupil::Pupil(const Pupil& obj) : QObject(0) // constructor copy
{
    FName = new QString (*obj.FName);
    LName = new QString (*obj.LName);
    MName = new QString (*obj.MName);
    Phone = new QString (*obj.Phone);
}


Pupil::Pupil(const Pupil* obj): QObject(0)  // constructor copy
{
    FName = new QString (*obj->FName);
    LName = new QString (*obj->LName);
    MName = new QString (*obj->MName);
    Phone = new QString (*obj->Phone);
}


Pupil::Pupil(QString *newF,
                 QString *newL, QString *newM, QString *newPhone): QObject(0)
                                     // constructor initial
{
    FName = new QString (*newF);
    LName = new QString (*newL);
    MName = new QString (*newM);
    Phone = new QString (*newPhone);
}


Pupil::Pupil(const char *newF,
                 const char *newL, const char *newM, const char *newPhone): QObject(0)

{
    FName = new QString (newF);
    LName = new QString (newL);
    MName = new QString (newM);
    Phone = new QString (newPhone);
}


void Pupil:: setFName(const char *str)
{
    if(FName)
        FName->~QString();
    FName = new QString (str);
}


void Pupil:: setLName(const char *str)
{
     if(LName)
        LName->~QString();
    LName = new QString (str);
}


void Pupil:: setMName(const char *str)
{
    if(MName)
        MName->~QString();
    MName = new QString (str);
}

void Pupil:: setPhone(const char *str)
{
    if(Phone)
        Phone->~QString();
    Phone = new QString (str);
}

void Pupil:: setFName(QString *str)
{
    if(FName)
        FName->~QString();
    FName = new QString (*str);
}


void Pupil:: setLName(QString *str)
{
    if(LName)
        LName->~QString();
    LName = new QString (*str);
}


void Pupil:: setMName(QString *str)
{
    if(MName)
        MName->~QString();
    MName = new QString (*str);
}

void Pupil:: setPhone(QString *str)
{
    if(Phone)
        Phone->~QString();
    Phone = new QString (*str);
}


void Pupil:: setAll(QString *str1, QString *str2, QString *str3, QString *str4)
{
    if(FName)
        FName->~QString();
    FName = new QString (*str1);
    if(LName)
        LName->~QString();
    LName = new QString (*str2);
    if(MName)
        MName->~QString();
    MName = new QString (*str3);
    if(Phone)
        Phone->~QString();
    Phone = new QString (*str4);
}


void Pupil:: setAll(const char *str1, const char *str2, const char *str3, const char *str4)
{
    if(FName)
        FName->~QString();
    FName = new QString (str1);
    if(LName)
        LName->~QString();
    LName = new QString (str2);
    if(MName)
        MName->~QString();
    MName = new QString (str3);
    if(Phone)
        Phone->~QString();
    Phone = new QString (str4);
}


QString* Pupil:: getFName(void)
{
    return this->FName;
}


QString* Pupil:: getLName(void)
{
    return this->LName;
}


QString* Pupil:: getMName(void)
{
    return this->MName;
}

QString* Pupil:: getPhone(void)
{
    return this->Phone;
}

bool Pupil:: operator==(const Pupil &obj)///!!!
{
    return(FName == obj.FName &&
           LName == obj.LName &&
           MName == obj.MName &&
           Phone == obj.Phone);
}


Pupil Pupil:: operator *(Pupil &obj)///!!!
{
    Pupil a(obj);
    return a;
}


const Pupil& Pupil::operator =(const Pupil &obj)///!!!
{
    if(&obj == this)
        return *this;
    if(FName)
        FName->~QString();
    if(MName)
        MName->~QString();
    if(LName)
        LName->~QString();
    if(Phone)
        Phone->~QString();
    FName = new QString (*obj.FName);
    LName = new QString (*obj.LName);
    MName = new QString (*obj.MName);
    Phone = new QString (*obj.Phone);
    return *this;
}

void Pupil:: freeAll(void)
{
    if(FName)
        FName->~QString();
    if(MName)
        MName->~QString();
    if(LName)
        LName->~QString();
    if(Phone)
        Phone->~QString();
    FName = 0;
    MName = 0;
    LName = 0;
    Phone = 0;
}

Pupil:: ~Pupil(void)
{
    this->freeAll();
}


Pupil* inPupil(QDataStream &in, Pupil *obj2)
{
    if(obj2)
        obj2->freeAll();
    obj2->FName = inQStringP(in,obj2->FName);
    obj2->LName = inQStringP(in,obj2->LName);
    obj2->MName = inQStringP(in,obj2->MName);
    obj2->Phone = inQStringP(in,obj2->Phone);
    return obj2;
}
// input from QDataStream to Pupil*


QDataStream& operator<<(QDataStream &out, Pupil &obj)
{
    outQStringP(out,*(obj.FName));
    outQStringP(out,*(obj.LName));
    outQStringP(out,*(obj.MName));
    outQStringP(out,*(obj.Phone));
    return out;
}
// output Pupil& to thread QDataStream

