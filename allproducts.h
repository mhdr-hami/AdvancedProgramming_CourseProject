#ifndef ALLPRODUCTS_H
#define ALLPRODUCTS_H
class managerpage;

#include <managerpage.h>
#include <productmain.h>
#include <QTextStream>
#include <QFile>
#include <QDialog>

namespace Ui {
class allproducts;
}

class allproducts : public QDialog
{
    Q_OBJECT

public:
    explicit allproducts(QWidget *parent = 0);
    ~allproducts();

private slots:
    void on_allpro_mainpage_clicked();

private:
    Ui::allproducts *ui;
    managerpage * managpage;
};

#endif // ALLPRODUCTS_H
