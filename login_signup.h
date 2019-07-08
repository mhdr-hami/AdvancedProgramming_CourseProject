#ifndef LOGIN_SIGNUP_H
#define LOGIN_SIGNUP_H
class managerpage;

#include <QDialog>
#include <managerpage.h>
#include <managers.h>
#include <QIcon>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


namespace Ui {
class login_signup;
}

class login_signup : public QDialog
{
    Q_OBJECT

public:
    explicit login_signup(QWidget *parent = 0);
    ~login_signup();

private slots:
    void on_signup_clicked();

    void on_login_clicked();

private:
    Ui::login_signup *ui;
    managerpage * manpage;

};

#endif // LOGIN_SIGNUP_H
