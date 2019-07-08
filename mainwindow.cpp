#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Logo
    this->setWindowIcon(QIcon("C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Images\\Logo2"));
    ui->setupUi(this);
    //



    //background
    QPixmap bkgnd("C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Images\\v");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    //

    //Font
    ui->wlcm_msg->setStyleSheet("QLabel { color : black; }");
    ui->wlcm_msg->setFont(QFont("Calibri", 15, QFont::Bold));
    ui->who_msg->setStyleSheet("QLabel { color : black; }");
    ui->who_msg->setFont(QFont("Calibri", 10, QFont::Bold));
    //

    //Title

    //





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_manager_clicked()
{
    //Show LoginSignup
//    close();
    loginsignuppage = new login_signup;
    loginsignuppage->show();
}

void MainWindow::on_cashier_clicked()
{
    //Show LoginSignup2
//    close();
    loginsignuppage2 = new login_signup2;
    loginsignuppage2->show();
}
