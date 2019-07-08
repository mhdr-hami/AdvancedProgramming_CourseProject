#include "man_users.h"
#include "ui_man_users.h"

man_users::man_users(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::man_users)
{
    ui->setupUi(this);

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
    ui->label_2->setFont(QFont("Calibri", 11));
    ui->label_3->setStyleSheet("QLabel { color : black; }");
    ui->label_3->setFont(QFont("Calibri", 11));
    ui->label_4->setStyleSheet("QLabel { color : black; }");
    ui->label_4->setFont(QFont("Calibri", 11));
    ui->label_5->setStyleSheet("QLabel { color : black; }");
    ui->label_5->setFont(QFont("Calibri", 11));
    //

    //filling the table
    {
        user_table ut;
        for(int i=0; i<ut.size(); i++)
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        int i=0;
        for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
        {
            QTableWidgetItem * newitem0 = new QTableWidgetItem;
            newitem0->setText(itr->name);
            ui->tableWidget->setItem(i,0,newitem0);
            QTableWidgetItem * newitem1 = new QTableWidgetItem;
            newitem1->setText(itr->password);
            ui->tableWidget->setItem(i,1,newitem1);
            QTableWidgetItem * newitem2 = new QTableWidgetItem;
            newitem2->setText(QString::number(itr->money));
            ui->tableWidget->setItem(i,2,newitem2);
            i++;
        }
    }
    //
}


man_users::~man_users()
{
    delete ui;
}

void man_users::on_pushButton_clicked()
{
    int flag=0;
    QMessageBox::StandardButton reply =  QMessageBox::question(this,"Deleting User", "Are You Sure?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        //deleting the user
        {
            user_table ut;
            QString name = ui->lineEdit->text();
            QString pass = ui->lineEdit_2->text();
            for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
            {
                if(itr->name == name && itr->password == pass)
                {
                    ut.erase(itr);
                    QMessageBox::information(this,"Done!","User Deleted Successfully.");
                    flag=1;
                }
            }

        }
        //
        if(!flag)
            QMessageBox::warning(this,"Error!","No Such User Found!");
        else
        {
            //Show ManagerPage
            close();
            managpage = new managerpage;
            managpage->show();
        }
    }

}

void man_users::on_pushButton_2_clicked()
{
    //Show ManagerPage
    close();
    managpage = new managerpage;
    managpage->show();
}
