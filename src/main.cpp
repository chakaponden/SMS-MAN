
#include "message.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication v(argc, argv);
    Message a;
    a.setRecipient("375291514815");
    a.setMess("Кэндруч-макэндруч!!!");
    a.send();
    qDebug() << (QString)(*a.getMess());
    /*
    //qDebug() << this->DateTimeSent.toString("yyyy-MM-ddTHH:MM:SS");
    QString a = send("375445338912", "тебя ищет физица! давай быстрей к ней!");

    Lesson a;
    QTime b;
    b.setHMS(0,0,0,0);
    QString s;
    s = b.toString("hh:mm:ss");*/

/*
    Knowledge *k = new Knowledge("ABC.txt");
    k->load();
    Subject *s = new Subject("Highter Mathematics");

    QString *a = new QString("Mary");
    QString *b = new QString("Rastaman");
    QString *c = new QString("Petrovith");
    Teacher *t = new Teacher(a,b,c);

    s->addCopyData(*t);     // 2 teachers in subj
    s->addCopyData(*t);
    k->addCopyData(*s);     // k[0] = 2 teachers

    s->addCopyData(*t);
    t->setFName("ALLA");
    t->setLName("GAVRILOVNA");
    t->setMName("KUZMITCH");
    s->addCopyData(*t);
    s->addCopyData(*t);
    s->addCopyData(*t);
    s->addCopyData(*t);
    s->setName("Kaka");     // 5 teachers in subj

    k->addCopyData(*s);     // k[1] = 7 teachers
    k->addCopyData(*s);     // k[2] = 7 teachers
    s->addCopyData(*t);
    k->addCopyData(*s);     // k[3] = 8 teachers

    k->del(2);              // del subject with key = 2
    k->del(3,1);            // del teacher with key = 1
                            // in subject with key = 3
    // k[0] = 2 teachers
    // k[1] = 6 teachers
    // k[2] = 8 teachers

    //k->remove();
    k->remove();
    k->save();
    k->~Knowledge();

    delete (s);
    delete (t);
    delete (a);
    delete (b);
    delete (c);
*/
    return v.exec();
    return 1;
}
