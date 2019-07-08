#ifndef BASKET_H
#define BASKET_H
class cashierpage;

#include <cashierpage.h>
#include <users.h>
#include <basket_product.h>
#include <productmain.h>
#include <codes.h>
#include <QMessageBox>
#include <QList>
#include <QDialog>

namespace Ui {
class basket;
}

class basket : public QDialog
{
    Q_OBJECT

public:
    double page_ip;

    explicit basket(QWidget *parent = 0);
    ~basket();           

    void setBasketPageUIbyIP();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::basket *ui;
    cashierpage * cashpage;
};

#endif // BASKET_H
