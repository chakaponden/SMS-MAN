
#ifndef FUNC_H
#define FUNC_H

#include <QDataStream>

// other func

QString* inQString(QDataStream &in, QString *str)
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


QDataStream& outQString(QDataStream &out, const QString &str)
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
                ch = str[i].digitValue();
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

#endif // FUNC_H
