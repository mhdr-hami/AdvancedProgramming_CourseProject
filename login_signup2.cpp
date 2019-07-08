#include "login_signup2.h"
#include "ui_login_signup2.h"

#define cash_file "C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Document\\Users.txt"

login_signup2::login_signup2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_signup2)
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
    ui->logsi_msg2->setStyleSheet("QLabel { color : black; }");
    ui->logsi_msg2->setFont(QFont("Calibri", 11, QFont::Bold));

    //Title

    //


}

login_signup2::~login_signup2()
{
    delete ui;
}

int login_signup2::findMaxIp(user_table ut)
{
    int max=0;
    for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
        if(itr->ip>max)
            max=itr->ip;
    return max;
}

void login_signup2::on_signup2_clicked()
{
    QString name,pass;
    name = ui->line_nam_logsi2->text();
    pass = ui->line_pas_logsi2->text();
    if(name=="" || pass=="")
    {
        QMessageBox::warning(this,"SignUp Error","Fields Can Not Be Empty!");
        return;
    }
    user_table ut;
    for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
    {
        if(itr->name == name)
        {
            QMessageBox::warning(this,"Signup Error","This Name Already Exists!");
            return;
        }
    }
    user_main * newuser = new user_main(name,pass,0,0,0,0);
    ut.push_back(* newuser);
    QMessageBox::information(this,"Signup Done!","You SignedUp Successfully.");
}

void login_signup2::on_login2_clicked()
{
    int flag=0;
    QString name,pass;
    name = ui->line_nam_logsi2->text();
    pass = ui->line_pas_logsi2->text();
    if(name=="" || pass=="")
    {
        QMessageBox::warning(this,"Signup Error","Fields Can Not Be Empty!");
        return;
    }
    //oning and show cashier page
    {
        user_table ut;
        for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
        {
            if(itr->name==name && itr->password==pass)
            {
                //Oning
                itr->ip=findMaxIp(ut)+1;
                flag=1;
            }
        }
    }
    if(flag==1)
    {
        //Show Cashierpage
        user_table ut;
//        cashpage = new cashierpage(findMaxIp(ut));
        cashpage = new cashierpage;
        cashpage->page_ip = findMaxIp(ut);
        cashpage->setCashPageUIbyIP();
        cashpage->show();
        close();
    }
    else if(flag==0)
        QMessageBox::warning(this,"Login Error!","Username or Password is Incorrect!");

}
