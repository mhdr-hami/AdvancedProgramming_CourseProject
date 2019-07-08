#ifndef CASHIERPAGE_H
#define CASHIERPAGE_H
class MainWindow;
class basket;
class buyCredit;
class cash_saleee;

#include <basket.h>
#include <buycredit.h>
#include <mainwindow.h>
#include <saleitem.h>
#include <users.h>
#include <productmain.h>
#include <basket_product.h>
#include <cash_saleee.h>
#include <QMessageBox>
#include <QDate>
#include <QDateTime>
#include <QTimer>
#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class cashierpage;
}

class cashierpage : public QDialog
{
    Q_OBJECT

public:
    explicit cashierpage(QWidget *parent = 0);

    ~cashierpage();    

    double page_ip;    

    void setCashPageUIbyIP();

public slots:
    void digitaltimer_func();

private slots:
    void on_cashier_logout_clicked();

    void on_cashier_input_searchline_textChanged(const QString &arg1);

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_cashier_searchbutton_clicked();

    void on_cashier_addBaslket_clicked();

    void on_cashier_show_basket_clicked();

    void on_cashier_buyCredit_clicked();

    void cashcheck_func();

    void on_salebutton_clicked();

private:
    Ui::cashierpage *ui;
    MainWindow * mainpage;
    basket * baspage;
    buyCredit * buycrpage;
    QTimer * cashcheck_timer;
    QTimer * digitaltimer_refresher;
    cash_saleee * cashsalepage;

};

#endif // CASHIERPAGE_H
