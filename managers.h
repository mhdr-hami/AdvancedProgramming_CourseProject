#ifndef MANAGERS_H
#define MANAGERS_H
#include <QString>
#include <QList>
#include <QTextStream>
#define man_file "C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Document\\Managers.txt"

class manager_main
{
public:
    QString name;
    QString password;
    QString onoff;
    manager_main(QString name,QString password,QString onoff)
    {
        this->name = name;
        this->password = password;
        this->onoff = onoff;
    }
    manager_main()
    {}
};
class manager_table : public QList<manager_main>
{
public:
    manager_table()
    {
        load();
    }
    void load ()
    {
        QFile file (man_file) ;
        file.open(QFile::Text|QFile::ReadOnly) ;
        QTextStream fst (&file);
        while (!fst.atEnd())
        {
            QStringList sl = fst.readLine().split(',');
            if(sl.size()!=3)
                continue ;
            manager_main * newmanager = new manager_main(sl[0],sl[1],sl[2]);
            this->push_back(* newmanager);
        }

    }
    void save()
    {
        QFile file (man_file) ;
        file.open(QFile::Text|QFile::WriteOnly) ;
        QTextStream fst (&file);
        for ( manager_table::iterator itr = begin() ; itr != end() ; ++ itr )
        {
            fst << itr->name << ","
                << itr->password << ","
                << itr->onoff << endl ;
        }
        file.close();
    }

    ~ manager_table()
    {
        save();
    }
};

#endif // MANAGERS_H
