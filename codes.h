#ifndef CODES_H
#define CODES_H
#include <QString>
#include <QList>
#include <QFile>
#include <QTextStream>
#define my_codes "C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Document\\Discount_codes.txt"

class codemain
{
public:
    QString code_name;
    double percent;
    codemain(QString code_name,double percent)
    {
        this->code_name = code_name;
        this->percent = percent;
    }
    codemain()
    {}
};
class code_table : public QList<codemain>
{
public:
    code_table()
    {
        load();
    }
    void load()
    {
        QFile file (my_codes) ;
        file.open(QFile::Text|QFile::ReadOnly) ;
        QTextStream fst (&file);
        while (!fst.atEnd())
        {
            QStringList sl = fst.readLine().split(',');
            if(sl.size()!=2)
                continue ;
            double perc = sl[1].toDouble();
            codemain * newcode = new codemain(sl[0],perc);
            this->push_back(*newcode);
        }
    }
    void save()
    {
        QFile file (my_codes) ;
        file.open(QFile::Text|QFile::WriteOnly) ;
        QTextStream fst (&file);
        for ( code_table::iterator itr = begin() ; itr != end() ; ++ itr )
        {
            fst << itr->code_name << ","
                << itr->percent << endl ;
        }
        file.close();
    }

    ~code_table()
    {
        save();
    }

};

#endif // CODES_H
