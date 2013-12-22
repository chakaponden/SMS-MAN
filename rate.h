#ifndef RATE_H
#define RATE_H
#include <QObject>
#include <QVector>

// class Rate = pupil's marks by only one Subject (by IdSubject)
class Rate// : public QObject
{
    quint16 IdSubject;              // Subject
    QVector <quint8> *values;       // QVector of marks
public:
    Rate();
    Rate(quint16& IdSubject);

    bool del_by_Num(quint8& Num);   // del mark by index(Num) in QVector
    bool del_by_Value(quint8& Value);
                                    // del mark by Value
    void add_Value(quint8& Value);
                                    // add mark (to the end)
    void setIdSubject(quint16& IdSubject);

    QVector <quint8>* get_all_values(void);
                                    // get all marks
    quint16& getIdSubject(void);
    bool exist_value(quint8& Value);
                                    // check if mark = value is exist

    uint get_size(void);            // get marks count = size of QVector
    bool resize(uint& new_size);    // resize QVector after delete mark
    bool isEmpty(void);
    bool isNull(void);
    void free_All(void);            // free all marks
    virtual ~Rate(void);
};

#endif // RATE_H
