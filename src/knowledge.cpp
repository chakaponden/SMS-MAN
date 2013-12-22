#include "knowledge.h"


Knowledge::Knowledge(void): QObject(0)
{
    this->File = 0;
    this->knowList = 0;
}


Knowledge::Knowledge(QString *str): QObject(0)
{
    this->File = new QString (*str);
    this->knowList = 0;
}


Knowledge::Knowledge(const char *str): QObject(0)
{
    this->File = new QString(str);
    this->knowList = 0;
}


void Knowledge:: setFile(QString *str)
{
    if(File)
        File->~QString();
    this->File = new QString (*str);
}


void Knowledge:: setFile(const char *str)
{
    if(File)
        File->~QString();
    this->File = new QString(str);
}


QString* Knowledge:: getFile(void)
{
    return this->File;
}


quint8 Knowledge:: addCopyData(QString &str)
{
    if(!knowList)
        this->knowList = new QHash <quint16, Subject>();
    for(quint16 i = 1; i < 65535; i++)
    {
        if(!(knowList->contains(i)))
        {
            Subject s(str);
            knowList->insert(i,s);
            return 0;     // ok
        }
    }
    return 1;           // error - hash is full
                        // there are no free avalible keys
                        // all [1, 65534] keys are busy
}


quint8 Knowledge:: addCopyData(const char *str)
{
    if(!knowList)
        this->knowList = new QHash <quint16, Subject>();
    for(quint16 i = 1; i < 65535; i++)
    {
        if(!(knowList->contains(i)))
        {
            Subject s(str);
            knowList->insert(i,s);
            return 0;     // ok
        }
    }
    return 1;           // error - hash is full
                        // there are no free avalible keys
                        // all [1, 65534] keys are busy

}


quint8 Knowledge:: addCopyUk(Subject &obj)
{
    if(!knowList)
        this->knowList = new QHash <quint16, Subject>();
    for(quint16 i = 1; i < 65535; i++)
    {
        if(!(knowList->contains(i)))
        {
            Subject aa(obj);
            knowList->insert(i,aa);
            return 0;     // ok
        }
    }
    return 1;           // error - hash is full
                        // there are no free avalible keys
                        // all [1, 65534] keys are busy
}


quint8 Knowledge:: addCopyData(Subject &obj)
{
    if(!knowList)
        this->knowList = new QHash <quint16, Subject>();
    Subject aa;
    for(quint16 i = 1; i < 65535; i++)
    {
        if(!(knowList->contains(i)))
        {
            aa = obj;
            knowList->insert(i,obj);
            return 0;     // ok
        }
    }
    return 1;           // error - hash is full
                        // there are no free avalible keys
                        // all [1, 65534] keys are busy
}


quint8 Knowledge:: addCopyUk(Subject &obj, quint16 key)
{
    if(knowList == 0)
        this->knowList = new QHash <quint16, Subject>();
    if(!(knowList->contains(key)))
    {
        Subject aa(obj);
        knowList->insert(key,aa);
        return 0;      // ok
    }
    return 1;           // error - hash is full
                        // there are no free avalible keys
                        // all [1, 65534] keys are busy
}


quint8 Knowledge:: addCopyData(Subject &obj, quint16 key)
{
    if(!knowList)
        this->knowList = new QHash <quint16, Subject>();
    if(!(knowList->contains(key)))
    {
        Subject aa(obj);
        knowList->insert(key,aa);
        return 0;      // ok
    }
    return 1;           // error - hash is full
                        // there are no free avalible keys
                        // all [1, 65534] keys are busy	
}


quint8 Knowledge:: del(quint16 key)
                            // delete element according to
                            // key
{
    if(key != 0 && knowList->contains(key))
    {
        knowList->remove(key);
        return 0;           // ok
    }
    return 1;               // error - there are no elements according quint16 key
                            // or key = 0
}


quint8 Knowledge:: del(quint16 keySubj, quint16 keyTeacher)
                            // delete teacher in subject according to
                            // keys
{
    if(keySubj != 0 && knowList->contains(keySubj))
    {

        Subject *obj = &(knowList->operator [](keySubj));
        return obj->del(keyTeacher);
    }
    return 1;               // error - there are no elements according quint16 key
                            // or key = 0
}


quint8 Knowledge:: del(QHash<quint16, Subject>::iterator hashIterator)
                            // delete element according to
                            // iterator
{
    if(hashIterator.key())
    {
        knowList->erase(hashIterator);
        return 0;           // ok
    }
    return 1;               // error, because item's key = 0
}


Teacher* Knowledge:: search(quint16 keySubj, quint16 keyTeacher)
{
    if(knowList->contains(keySubj))
    {
            Subject *s;
            s = &(knowList->operator [](keyTeacher));
            return (s->search(keyTeacher));
    }
    return 0;
}


Subject* Knowledge:: search(quint16 keySubj)
{
    if(knowList->contains(keySubj))
        return &(knowList->operator [](keySubj));
    return 0;
}


void Knowledge:: freeAll(void)
{
	if(knowList)
        knowList->clear();
    delete (knowList);
    knowList = 0;
}


quint8 Knowledge:: load(void)
{
    if(File)
    {
        QFile file(*File);
        if(file.open(QIODevice::ReadOnly))
        {			
            QDataStream in(&file);  
            this->freeAll();

			    quint16 num;
				in >> num;
				if(!num)
				{
					this->knowList = 0;
					return 0;       // ok
				}
				quint16 i;
				Subject *obj2 = new Subject;
				while(num)
				{
					in >> i;
					obj2 = inSubject(in, obj2);
					this->addCopyData(*obj2, i);
					num--;
				}
				obj2->~Subject();///////////////            
            file.close();
            return 0;           // ok
        }
        return 2;               // error - file could not be open
    }
    return 1;                   // error - QString *File (filename) = 0
}

void Knowledge:: remove(void)
{
    QFile file(*File);
    file.remove();
}


quint8 Knowledge:: save(void)
{
    if(File)
    {
        QString tmpFile(*File);
        tmpFile += "tmp";
        QFile file(tmpFile);
        if(file.open(QIODevice::WriteOnly))
        {
            file.resize(0);
            file.reset();
            QDataStream out(&file);
            out << *this;          
            file.close();
            file.setFileName(*File);
            file.remove();
            file.setFileName(tmpFile);
            file.rename(tmpFile,*File);
            return 0;           // ok
        }
        return 2;               // error - file could not be open
    }
    return 1;                   // error - QString *File (filename) = 0

}


Knowledge:: ~Knowledge(void)
{
    if(File)
        File->~QString();
    File = 0;
    if(knowList)
        knowList->clear();
    delete (knowList);
    knowList = 0;
}


QDataStream& operator<<(QDataStream &out, Knowledge &obj)
{
    if(obj.knowList)
    {
        quint16 num = obj.knowList->size();
        out << num;			
        if(num)
        {
            QHashIterator <quint16,Subject> it(*obj.knowList);
            Subject a;
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
// output Knowledge to QDataStream

