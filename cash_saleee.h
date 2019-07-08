#ifndef CASH_SALEEE_H
#define CASH_SALEEE_H

class cashierpage;

#include <saleitem.h>
#include <cashierpage.h>
#include <QDialog>
#include <QTimer>

namespace Ui {
class cash_saleee;
}

class cash_saleee : public QDialog
{
    Q_OBJECT

public:
    double page_ip;

    explicit cash_saleee(QWidget *parent = 0);

    ~cash_saleee();

    void setCashSalePageUIbyIP();

private slots:
    void on_pushButton_clicked();

    void on_bid_Button_clicked();

    void saleGeneral_salePage_func();

    void cashSale_refresher_func();

private:
    Ui::cash_saleee *ui;
    cashierpage * cashpage;
    QTimer * saleGeneral_salePage_timer;
    QTimer * cashSale_refresher_timer;
};

#endif // CASH_SALEEE_H
