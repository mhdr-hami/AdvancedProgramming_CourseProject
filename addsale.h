#ifndef ADDSALE_H
#define ADDSALE_H

#include <saleitem.h>
#include <productmain.h>
#include <managerpage.h>
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class addSale;
}

class addSale : public QDialog
{
    Q_OBJECT

public:
    explicit addSale(QWidget *parent = 0);
    ~addSale();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addSale *ui;
    managerpage * managpage;
};

#endif // ADDSALE_H
