#ifndef PRODUCTMAIN_H
#define PRODUCTMAIN_H
#include <QString>
#include <QList>
#include <QFile>
#include <QTextStream>
#define my_pros "C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Document\\Products.txt"


class Productmain
{
public:
    QString name,factory,category,license;
    int quantity,discount;
    double price;
    Productmain(QString name,QString factory,QString category,QString license, int quantity,double price, int discount)
    {
        this->name = name;
        this->factory = factory;
        this->category = category;
        this->license = license;
        this->quantity = quantity;
        this->price = price;
        this->discount = discount;
    }
    Productmain()
    {}
};
class product_table : public QList<Productmain>
{
public:
    product_table ()
    {
        load () ;
    }
    void load ()
    {
        QFile file (my_pros) ;
        file.open(QFile::Text|QFile::ReadOnly) ;
        QTextStream fst (&file);
        while (!fst.atEnd())
        {
            QStringList sl = fst.readLine().split(',');
            if(sl.size()!=7)
                continue ;
            int quan = sl[4].toInt();
            double pri = sl[5].toDouble();
            int disc = sl[6].toInt();
            Productmain * mahsool = new Productmain(sl[0],sl[1],sl[2],sl[3],quan,pri,disc);
            this->push_back(* mahsool);
        }

    }
    void save()
    {
        QFile file (my_pros) ;
        file.open(QFile::Text|QFile::WriteOnly) ;
        QTextStream fst (&file);
        for ( product_table::iterator itr = begin() ; itr != end() ; ++ itr )
        {
            fst << itr->name << ","
                << itr->factory << ","
                << itr->category << ","
                << itr->license << ","
                << itr->quantity << ","
                << itr->price << ","
                << itr->discount << endl ;
        }
        file.close();
    }

    ~ product_table()
    {
        save();
    }

};

#endif // PRODUCTMAIN_H
