#ifndef USERS_H
#define USERS_H
#include <QString>
#include <QList>
#include <QTextStream>
#define user_file "C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Document\\Users.txt"

class user_main
{
public:
    QString name,password;
    double ip,money,coming_money,basket_money;
    user_main(QString name,QString password,double ip,double money,double coming_money, double basket_money)
    {
        this->name = name;
        this->password = password;
        this->ip = ip;
        this->money = money;
        this->coming_money = coming_money;
        this->basket_money = basket_money;
    }
    user_main()
    {}
};

class user_table : public QList<user_main>
{
public:
    user_table()
    {
        load();
    }
    void load ()
    {
        QFile file (user_file) ;
        file.open(QFile::Text|QFile::ReadOnly) ;
        QTextStream fst (&file);
        while (!fst.atEnd())
        {
            QStringList sl = fst.readLine().split(',');
            if(sl.size()!=6)
                continue ;
            double ip = sl[2].toDouble();
            double mon = sl[3].toDouble();
            double com_mon = sl[4].toDouble();
            double bas_mon = sl[5].toDouble();

            user_main * newuser = new user_main(sl[0],sl[1],ip,mon,com_mon,bas_mon);
            this->push_back(* newuser);
        }

    }
    void save()
    {
        QFile file (user_file) ;
        file.open(QFile::Text|QFile::WriteOnly) ;
        QTextStream fst (&file);
        for ( user_table::iterator itr = begin() ; itr != end() ; ++ itr )
        {
            fst << itr->name << ","
                << itr->password << ","
                << itr->ip << ","
                << itr->money<< ","
                << itr->coming_money<<","
                << itr->basket_money <<endl ;
        }
        file.close();
    }

    ~ user_table()
    {
        save();
    }

};

#endif // USERS_H
