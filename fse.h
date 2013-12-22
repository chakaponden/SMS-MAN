#ifndef dayrate_H
#define dayrate_H
#include <QObject>
#include <QDate>
#include <QVector>
#include "rate.h"

class dayrate
{
    QDate Date;
    QVector <Rate> *dayList;

public:
    dayrate();
    dayrate(QDate& new_Date);
    bool del_by_Num(quint8& Num);
    bool del_by_Value(quint8& Value);
    void add_Value(quint8& Value);
    QVector <quint8>* get_all_values(void);
    bool exist_value(quint8& Value);
    uint get_size(void);
    bool resize(uint& new_size);
    bool isEmpty(void);
    bool isNull(void);
    void free_All(void);
    virtual ~dayrate(void);

};

#endif // dayrate_H
