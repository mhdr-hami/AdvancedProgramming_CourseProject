#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H
class managerpage;

#include <managerpage.h>
#include <productmain.h>
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class addproduct;
}

class addproduct : public QDialog
{
    Q_OBJECT

public:
    explicit addproduct(QWidget *parent = 0);
    ~addproduct();

private slots:
    void on_newproaddthisbutton_clicked();

private:
    Ui::addproduct *ui;
    managerpage * managpage;
};

#endif // ADDPRODUCT_H
