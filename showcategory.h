#ifndef SHOWCATEGORY_H
#define SHOWCATEGORY_H
class managerpage;

#include <managerpage.h>
#include <productmain.h>
#include <QDialog>

namespace Ui {
class showcategory;
}

class showcategory : public QDialog
{
    Q_OBJECT

public:
    explicit showcategory(QWidget *parent = 0);
    ~showcategory();

private slots:
    void on_showcat_mainbutton_clicked();

    void on_showcat_show_clicked();

private:
    Ui::showcategory *ui;
    managerpage * managpage;
};

#endif // SHOWCATEGORY_H
