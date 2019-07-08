#ifndef MAN_USERS_H
#define MAN_USERS_H
class managerpage;

#include <managerpage.h>
#include <users.h>
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class man_users;
}

class man_users : public QDialog
{
    Q_OBJECT

public:
    explicit man_users(QWidget *parent = 0);
    ~man_users();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::man_users *ui;
    managerpage * managpage;
};

#endif // MAN_USERS_H
