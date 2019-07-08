#include "buycredit.h"
#include "ui_buycredit.h"

buyCredit::buyCredit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buyCredit)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Images\\Logo2"));
}

buyCredit::~buyCredit()
{
    delete ui;
}

void buyCredit::setBuyCreditPageUIbyIP()
{
    //background
    QPixmap bkgnd("C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Images\\v");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    //

    //Font
    ui->label->setStyleSheet("QLabel { color : black; }");
    ui->label->setFont(QFont("Calibri", 16));
    ui->label_2->setStyleSheet("QLabel { color : black; }");
    ui->label_2->setFont(QFont("Calibri", 12));
    ui->label_3->setStyleSheet("QLabel { color : black; }");
    ui->label_3->setFont(QFont("Calibri", 12));
    ui->label_4->setStyleSheet("QLabel { color : black; }");
    ui->label_4->setFont(QFont("Calibri", 12));
    ui->label_5->setStyleSheet("QLabel { color : black; }");
    ui->label_5->setFont(QFont("Calibri", 12));
    //

    //filling the currnet credit
    {
        user_table ut;
        for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
        {
//            if(itr->ip==findMaxIp(ut))
            if(itr->ip==this->page_ip)
            {
                ui->cloud_lable->setText(QString::number(itr->coming_money));
                ui->cloud_lable->setStyleSheet("QLabel { color : black; }");
                ui->cloud_lable->setFont(QFont("Calibri", 13));
                QString credit = QString::number(itr->money);
                ui->currnet_lable->setText(credit);
                ui->currnet_lable->setStyleSheet("QLabel { color : black; }");
                ui->currnet_lable->setFont(QFont("Calibri", 13));
                break;
            }
        }
    }
    //
}

void buyCredit::on_pushButton_clicked()
{
    QString pass = ui->passline->text();
    double add_com = ui->buyline->text().toDouble();

    //adding cloud credit
    {
        user_table ut;
        for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
        {
//            if(itr->ip==findMaxIp(ut))
            if(itr->ip==this->page_ip)
            {
                if(itr->password == pass)
                {
                    itr->coming_money += add_com;
                    QMessageBox::information(this,"Done Successfully!","It Will Be Added When Manager Accepted.");
                }
                else
                {
                    QMessageBox::warning(this,"Error!","Password Is Incorrect!");
                    return;
                }
                break;
            }
        }
    }
    //

    {
        //Show Cashierpage
        cashpage = new cashierpage;
        cashpage->page_ip = this->page_ip;
        cashpage->setCashPageUIbyIP();
        cashpage->show();
        close();
    }
}
