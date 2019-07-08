#ifndef MAINWINDOW_H
#define MAINWINDOW_H
class login_signup;
class login_signup2;

#include <QMainWindow>
#include <login_signup.h>
#include <login_signup2.h>
#include<QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_manager_clicked();

    void on_cashier_clicked();

private:
    Ui::MainWindow *ui;
    login_signup * loginsignuppage;
    login_signup2 * loginsignuppage2;
};

#endif // MAINWINDOW_H
