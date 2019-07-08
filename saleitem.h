#ifndef SAILITEM_H
#define SAILITEM_H
#include <QString>
#include <QList>
#include <QFile>
#include <QTextStream>
#define my_sales "C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Document\\Sales.txt"

class saleItem
{
public:
    QString item_name,bestbidder,license;
    int time,bestbid;
    saleItem(QString item_name,QString bestbidder,QString license, int time, int bestbid)
    {
        this->item_name = item_name;
        this->bestbidder = bestbidder;
        this->license = license;
        this->time = time;
        this->bestbid = bestbid;
    }
    saleItem()
    {}
};
class sale_table : public QList<saleItem>
{
public:
    sale_table()
    {
        load();
    }
    void load()
    {
        QFile file (my_sales) ;
        file.open(QFile::Text|QFile::ReadOnly) ;
        QTextStream fst (&file);
        while (!fst.atEnd())
        {
            QStringList sl = fst.readLine().split(',');
            if(sl.size()!=5)
                continue ;
            int tim = sl[3].toInt();
            int bb = sl[4].toInt();
            saleItem * newsale = new saleItem(sl[0],sl[1],sl[2],tim,bb);
            this->push_back(*newsale);
        }
    }
    void save()
    {
        QFile file (my_sales) ;
        file.open(QFile::Text|QFile::WriteOnly) ;
        QTextStream fst (&file);
        for ( sale_table::iterator itr = begin() ; itr != end() ; ++ itr )
        {
            fst << itr->item_name << ","
                << itr->bestbidder << ","
                << itr->license << ","
                << itr->time << ","
                << itr->bestbid << endl ;
        }
        file.close();
    }

    ~sale_table()
    {
        save();
    }

};

#endif // SAILITEM_H
