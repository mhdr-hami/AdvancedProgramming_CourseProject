#ifndef BASKET_PRODUCT_H
#define BASKET_PRODUCT_H

#include <QString>
#include <QList>
#include <QFile>
#include <QTextStream>
#define my_basket "C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Document\\Basket.txt"


class basketproduct_main
{
public:
    QString name;
    int quantity;
    double price,sum,buyer_ip;
    basketproduct_main(QString name, int quantity,double price, double sum, double buyer_ip)
    {
        this->name = name;
        this->quantity = quantity;
        this->price = price;
        this->sum = sum;
        this->buyer_ip = buyer_ip;
    }
    basketproduct_main()
    {}
};
class basketproduct_table : public QList<basketproduct_main>
{
public:
    basketproduct_table ()
    {
        load () ;
    }
    void load ()
    {
        QFile file (my_basket) ;
        file.open(QFile::Text|QFile::ReadOnly) ;
        QTextStream fst (&file);
        while (!fst.atEnd())
        {
            QStringList sl = fst.readLine().split(',');
            if(sl.size()!=5)
                continue ;
            int quan = sl[1].toInt();
            double pri = sl[2].toDouble();
            double sum = sl[3].toDouble();
            double ip = sl[4].toDouble();
            basketproduct_main * newbaspro = new basketproduct_main(sl[0],quan,pri,sum,ip);
            this->push_back(* newbaspro);
        }

    }
    void save()
    {
        QFile file (my_basket) ;
        file.open(QFile::Text|QFile::WriteOnly) ;
        QTextStream fst (&file);
        for ( basketproduct_table::iterator itr = begin() ; itr != end() ; ++ itr )
        {
            fst << itr->name << ","
                << itr->quantity << ","
                << itr->price << ","
                << itr->sum << ","
                << itr->buyer_ip << endl ;
        }
        file.close();
    }

    ~ basketproduct_table()
    {
        save();
    }

};

#endif // BASKET_PRODUCT_H
