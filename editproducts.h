#ifndef EDITPRODUCTS_H
#define EDITPRODUCTS_H
class managerpage;

#include <managerpage.h>
#include <productmain.h>
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class editproducts;
}

class editproducts : public QDialog
{
    Q_OBJECT

public:
    explicit editproducts(QWidget *parent = 0);
    ~editproducts();

private slots:
    void on_editpro_searchbutton_clicked();

    void on_editpro_editbutton_clicked();

    void on_editpro_mainpagebutton_clicked();

    void on_editpro_deletebutton_clicked();

private:
    Ui::editproducts *ui;
    managerpage * managpage;
};

#endif // EDITPRODUCTS_H
