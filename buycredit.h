#ifndef BUYCREDIT_H
#define BUYCREDIT_H
class cashierpage;

#include <cashierpage.h>
#include <users.h>
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class buyCredit;
}

class buyCredit : public QDialog
{
    Q_OBJECT

public:
    double page_ip;

    explicit buyCredit(QWidget *parent = 0);

    ~buyCredit();    

    void setBuyCreditPageUIbyIP();

private slots:
    void on_pushButton_clicked();

private:
    Ui::buyCredit *ui;
    cashierpage * cashpage;
};

#endif // BUYCREDIT_H
