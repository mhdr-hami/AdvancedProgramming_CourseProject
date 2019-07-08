#include "managerpage.h"
#include "ui_managerpage.h"

managerpage::managerpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managerpage)
{
    ui->setupUi(this);
    //Logo
    this->setWindowIcon(QIcon("C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Images\\Logo2"));
    //background
    QPixmap bkgnd("C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Images\\v");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    //

    //Font
    ui->myapplogo2->setStyleSheet("QLabel { color : black; }");
    ui->myapplogo2->setFont(QFont("Calibri", 17));
    ui->man_hi_lable->setStyleSheet("QLabel { color : black; }");
    ui->man_hi_lable->setFont(QFont("Calibri", 11));
    ui->date->setText(QDate::currentDate().toString());
    ui->date->setStyleSheet("QLabel { color : black; }");
    ui->date->setFont(QFont("Calibri", 11));
    //

    //Filling the managerName
    manager_table mt;
    for ( manager_table::iterator itr = mt.begin() ; itr != mt.end() ; ++ itr )
    {
        if(itr->onoff=="on")
        {
            ui->man_name_managerpage->setText(itr->name);
            ui->man_name_managerpage->setStyleSheet("QLabel { color : black; }");
            ui->man_name_managerpage->setFont(QFont("Calibri", 11));
        }
    }

    //

    //Setting the digital_timer_refresher
    digitaltimer_refresher = new QTimer(this);
    connect(digitaltimer_refresher,SIGNAL(timeout()),this,SLOT(digitaltimer_func()));
    digitaltimer_refresher->start(1000);
    {
        QTime time = QTime::currentTime();
        QString stime = time.toString("hh : mm : ss");
        ui->digital_time->setText(stime);
    }

    //Setting the Timers
    manager_check = new QTimer(this);
    connect(manager_check,SIGNAL(timeout()),this,SLOT(manager_check_func()));
    manager_check->start(1000);
    sale_general_timer = new QTimer(this);
    time_file_fixer = new QTimer(this);
    connect(time_file_fixer,SIGNAL(timeout()),this,SLOT(time_file_fixer_func()));

}
managerpage::~managerpage()
{
    delete ui;
}

void managerpage::digitaltimer_func()
{
    QTime time = QTime::currentTime();
    QString stime = time.toString("hh : mm : ss");
    ui->digital_time->setText(stime);

    //Filling the pm
    {
        int i=0;
        user_table ut;
        for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
        {
            if(itr->coming_money!=0)
                i++;
        }
        if(i)
        {
            ui->pm_lable->setText(QString::number(i));
            ui->pm_lable->setStyleSheet("QLabel { color : red; }");
            ui->pm_lable->setFont(QFont("Calibri", 14,QFont::Bold));
        }

    }
}

void managerpage::manager_check_func()
{
    sale_table st;
    if(!st.isEmpty())
        for ( sale_table::iterator itr = st.begin() ; itr != st.end() ; ++ itr )
        {
            sale_general_timer->start(itr->time);
            time_file_fixer->start(200);
            manager_check->stop();
        }
}

void managerpage::time_file_fixer_func()
{
    sale_table st;
    for ( sale_table::iterator itr = st.begin() ; itr != st.end() ; ++ itr )
        itr->time = sale_general_timer->remainingTime();

}

void managerpage::on_manager_logout_clicked()
{
    //Show mainwindow
    QMessageBox::StandardButton reply =  QMessageBox::question(this,"Logging out", "Do You Want to Logout?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        //offing the managerName
        {
            manager_table mt;
            for ( manager_table::iterator itr = mt.begin() ; itr != mt.end() ; ++ itr )
            {
                if(itr->onoff =="on")
                {
                    itr->onoff="off";
                }
            }
        }
        close();
//        mainpage = new MainWindow;
//        mainpage->show();
    }
}

void managerpage::on_man_showPro_clicked()
{
    //Show All Products Page
    close();
    allpropage = new allproducts;
    allpropage->show();
}

void managerpage::on_man_addPro_clicked()
{
    //Show Add Product Page
    close();
    addpropage = new addproduct;
    addpropage->show();
}

void managerpage::on_man_adddiscode_clicked()
{
    //Show Add Discount Code
    close();
    adddiscodepage = new adddiscount_code;
    adddiscodepage->show();
}

void managerpage::on_man_adddispro_clicked()
{
    //Show Add Discount Product
    close();
    adddispropage = new addiscount_pro;
    adddispropage->show();
}

void managerpage::on_man_showCATEG_clicked()
{
    //Show ShowCategory Page
    close();
    showcatpage = new showcategory;
    showcatpage->show();
}

void managerpage::on_man_edditPro_clicked()
{
    //Show EditProduct Page
    close();
    editpropage = new editproducts;
    editpropage->show();
}

void managerpage::on_man_users_clicked()
{
    //Accepting the user's cloud credit
    {
        user_table ut;
        for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
        {
            if(itr->coming_money!=0)
            {
                QMessageBox::StandardButton reply =  QMessageBox::question(this,"Accepting Cloud Credit", "User  "+itr->name+"  Wants to buy "+QString::number(itr->coming_money)+"  Credit."+"\n"+"Do You Accept that?",QMessageBox::Yes | QMessageBox::No);
                if(reply == QMessageBox::Yes)
                {
                    itr->money += itr->coming_money;
                    itr->coming_money =0;
                }
                else
                    itr->coming_money=0;
            }
        }
    }
    close();
    man_uspage = new man_users;
    man_uspage->show();
}

void managerpage::on_man_addsalebutton_clicked()
{
    //Show AddSalePage
    close();
    addsalpage = new addSale;
    addsalpage->show();
}
