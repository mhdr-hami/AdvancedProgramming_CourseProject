#ifndef LOGIN_SIGNUP2_H
#define LOGIN_SIGNUP2_H
class cashierpage;

#include <users.h>
#include <QDialog>
#include <cashierpage.h>
#include <QIcon>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

namespace Ui {
class login_signup2;
}

class login_signup2 : public QDialog
{
    Q_OBJECT

public:
    explicit login_signup2(QWidget *parent = 0);
    ~login_signup2();
    int findMaxIp(user_table ut);

private slots:
    void on_signup2_clicked();

    void on_login2_clicked();

private:
    Ui::login_signup2 *ui;
    cashierpage * cashpage;
};

#endif // LOGIN_SIGNUP2_H
