#include "teacher.h"
#include "func.h"

Teacher::Teacher(): QObject(0)
{
    FName = 0;
    MName = 0;
    LName = 0;
}


Teacher::Teacher(const Teacher& obj) : QObject(0) // constructor copy
{
    FName = new QString (*obj.FName);
    LName = new QString (*obj.LName);
    MName = new QString (*obj.MName);
}


Teacher::Teacher(const Teacher* obj): QObject(0)  // constructor copy
{
    FName = new QString (*obj->FName);
    LName = new QString (*obj->LName);
    MName = new QString (*obj->MName);
}


Teacher::Teacher(QString *newF,
                 QString *newL, QString *newM): QObject(0)
                                     // constructor initial
{
    FName = new QString (*newF);
    LName = new QString (*newL);
    MName = new QString (*newM);
}


Teacher::Teacher(const char *newF,
                 const char *newL, const char *newM): QObject(0)

{
    FName = new QString (newF);
    LName = new QString (newL);
    MName = new QString (newM);
}


void Teacher:: setFName(const char *str)
{
    if(FName)
        FName->~QString();
    FName = new QString (str);
}


void Teacher:: setLName(const char *str)
{
     if(LName)
        LName->~QString();
    LName = new QString (str);
}


void Teacher:: setMName(const char *str)
{
    if(MName)
        MName->~QString();
    MName = new QString (str);
}


void Teacher:: setFName(QString *str)
{
    if(FName)
        FName->~QString();
    FName = new QString (*str);
}


void Teacher:: setLName(QString *str)
{
    if(LName)
        LName->~QString();
    LName = new QString (*str);
}


void Teacher:: setMName(QString *str)
{
    if(MName)
        MName->~QString();
    MName = new QString (*str);
}


void Teacher:: setAll(QString *str1, QString *str2, QString *str3)
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
}


void Teacher:: setAll(const char *str1, const char *str2, const char *str3)
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
}


QString* Teacher:: getFName(void)
{
    return this->FName;
}


QString* Teacher:: getLName(void)
{
    return this->LName;
}


QString* Teacher:: getMName(void)
{
    return this->MName;
}


bool Teacher:: operator==(const Teacher &obj)///!!!
{
    return(FName == obj.FName &&
           LName == obj.LName &&
           MName == obj.MName);
}


Teacher Teacher:: operator *(Teacher &obj)///!!!
{
    Teacher a(obj);
    return a;
}


const Teacher& Teacher::operator =(const Teacher &obj)///!!!
{
    if(&obj == this)
        return *this;
    if(FName)
        FName->~QString();
    if(MName)
        MName->~QString();
    if(LName)
        LName->~QString();
    FName = new QString (*obj.FName);
    LName = new QString (*obj.LName);
    MName = new QString (*obj.MName);
    return *this;
}

void Teacher:: freeAll(void)
{
    if(FName)
        FName->~QString();
    if(MName)
        MName->~QString();
    if(LName)
        LName->~QString();
    FName = 0;
    MName = 0;
    LName = 0;
}

Teacher:: ~Teacher(void)
{
    if(FName)
        FName->~QString();
    if(MName)
        MName->~QString();
    if(LName)
        LName->~QString();
    FName = 0;
    MName = 0;
    LName = 0;
}


Teacher* inTeacher(QDataStream &in, Teacher *obj2)
{
    if(obj2)
        obj2->freeAll();
	obj2->FName = inQString(in,obj2->FName);
    obj2->LName = inQString(in,obj2->LName);
    obj2->MName = inQString(in,obj2->MName);
    return obj2;
}
// input from QDataStream to Teacher*


QDataStream& operator<<(QDataStream &out, Teacher &obj)
{
    outQString(out,*(obj.FName));
    outQString(out,*(obj.LName));
    outQString(out,*(obj.MName));
    return out;
}
// output Teacher& to thread QDataStream

