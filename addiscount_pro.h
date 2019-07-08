#ifndef ADDISCOUNT_PRO_H
#define ADDISCOUNT_PRO_H

#include <managerpage.h>
#include <productmain.h>
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class addiscount_pro;
}

class addiscount_pro : public QDialog
{
    Q_OBJECT

public:
    explicit addiscount_pro(QWidget *parent = 0);
    ~addiscount_pro();

private slots:
    void on_addbutton_discountpro_clicked();

private:
    Ui::addiscount_pro *ui;
    managerpage * managpage;
};

#endif // ADDISCOUNT_PRO_H
