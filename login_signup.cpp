#include "login_signup.h"
#include "ui_login_signup.h"

login_signup::login_signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_signup)
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
    ui->logsi_msg->setStyleSheet("QLabel { color : black; }");
    ui->logsi_msg->setFont(QFont("Calibri", 11, QFont::Bold));

    //Title

    //


}

login_signup::~login_signup()
{
    delete ui;
}

void login_signup::on_signup_clicked()
{
    QString name,pass;
    name = ui->line_nam_logsi->text();
    pass = ui->line_pas_logsi->text();
    if(name=="" || pass=="")
    {
        QMessageBox::warning(this,"Signup Error","Fields Can Not Be Empty!");
        return;
    }
    manager_table mt;
    for ( manager_table::iterator itr = mt.begin() ; itr != mt.end() ; ++ itr )
    {
        if(itr->name == name)
        {
            QMessageBox::information(this,"Signup Error","This Name Already Exists!");
            return;
        }
    }
    manager_main * newmanager = new manager_main(name,pass,"off");
    mt.push_back(* newmanager);
    QMessageBox::information(this,"Signup Done!","You SignedUp Successfully.");
}

void login_signup::on_login_clicked()
{
    int flag=0;
    QString name,pass;
    name = ui->line_nam_logsi->text();
    pass = ui->line_pas_logsi->text();
    if(name=="" || pass=="")
    {
        QMessageBox::warning(this,"Signup Error","Fields Can Not Be Empty!");
        return;
    }
    //oning and show manager page
    {
        manager_table mt;
        for ( manager_table::iterator itr = mt.begin() ; itr != mt.end() ; ++ itr )
        {
            if(itr->name==name && itr->password==pass)
            {
                //Oning
                itr->onoff="on";
                flag=1;
            }
        }
    }
    if(flag==1)
    {
        //Show Managerpag
        manpage = new managerpage;
        manpage->show();
        close();
    }
    else if(flag==0)
        QMessageBox::warning(this,"Login Error!","Username or Password is Incorrect!");

}
