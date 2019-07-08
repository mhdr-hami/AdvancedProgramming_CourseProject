#ifndef MANAGERPAGE_H
#define MANAGERPAGE_H
class MainWindow;
class addproduct;
class allproducts;
class adddiscount_code;
class addiscount_pro;
class showcategory;
class editproducts;
class man_users;
class addSale;

#include <QDialog>
#include <allproducts.h>
#include <addproduct.h>
#include <adddiscount_code.h>
#include <addiscount_pro.h>
#include <showcategory.h>
#include <editproducts.h>
#include <man_users.h>
#include <mainwindow.h>
#include <addsale.h>
#include <managers.h>
#include <users.h>
#include <QMessageBox>
#include <QDate>
#include <QDateTime>
#include <QTimer>

namespace Ui {
class managerpage;
}

class managerpage : public QDialog
{
    Q_OBJECT

public:
    explicit managerpage(QWidget *parent = 0);
    ~managerpage();

public slots:
    void digitaltimer_func();

    void manager_check_func();

    void time_file_fixer_func();

private slots:
    void on_manager_logout_clicked();

    void on_man_showPro_clicked();

    void on_man_addPro_clicked();

    void on_man_adddiscode_clicked();

    void on_man_adddispro_clicked();

    void on_man_showCATEG_clicked();

    void on_man_edditPro_clicked();

    void on_man_users_clicked();

    void on_man_addsalebutton_clicked();

private:
    Ui::managerpage *ui;
    allproducts * allpropage;
    MainWindow * mainpage;
    addproduct * addpropage;
    adddiscount_code * adddiscodepage;
    addiscount_pro * adddispropage;
    showcategory * showcatpage;
    editproducts * editpropage;
    man_users * man_uspage;
    addSale * addsalpage;
    QTimer * digitaltimer_refresher;
    QTimer * manager_check;
    QTimer * sale_general_timer;
    QTimer * time_file_fixer;
};

#endif // MANAGERPAGE_H
