#ifndef ADDDISCOUNT_CODE_H
#define ADDDISCOUNT_CODE_H
class managerpage;

#include <managerpage.h>
#include <QDialog>
#include <codes.h>
#include <QMessageBox>

namespace Ui {
class adddiscount_code;
}

class adddiscount_code : public QDialog
{
    Q_OBJECT

public:
    explicit adddiscount_code(QWidget *parent = 0);
    ~adddiscount_code();

private slots:
    void on_newcode_addthis_clicked();

private:
    Ui::adddiscount_code *ui;
    managerpage * managpage;
};

#endif // ADDDISCOUNT_CODE_H
