#include "showcategory.h"
#include "ui_showcategory.h"

showcategory::showcategory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showcategory)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Images\\Logo2"));
    //background
    QPixmap bkgnd("C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Images\\v");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    //

    //Font
    ui->label->setStyleSheet("QLabel { color : black; }");
    ui->label->setFont(QFont("Calibri", 17));
    ui->label_2->setStyleSheet("QLabel { color : black; }");
    ui->label_2->setFont(QFont("Calibri", 11));
    ui->label_3->setStyleSheet("QLabel { color : black; }");
    ui->label_3->setFont(QFont("Calibri", 11));
}

showcategory::~showcategory()
{
    delete ui;
}

void showcategory::on_showcat_mainbutton_clicked()
{
    //Show manager page
    close();
    managpage = new managerpage;
    managpage->show();
}

void showcategory::on_showcat_show_clicked()
{
    product_table pt;
    QString category = ui->showcat_combo->currentText();
    int i=0;
    for ( product_table::iterator itr = pt.begin() ; itr != pt.end() ; ++ itr )
    {
        if(itr->category==category)
        {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            QTableWidgetItem * newitem0 = new QTableWidgetItem;
            newitem0->setText(itr->name);
            ui->tableWidget->setItem(i,0,newitem0);
            QTableWidgetItem * newitem1 = new QTableWidgetItem;
            newitem1->setText(itr->factory);
            ui->tableWidget->setItem(i,1,newitem1);
            QTableWidgetItem * newitem2 = new QTableWidgetItem;
            newitem2->setText(itr->category);
            ui->tableWidget->setItem(i,2,newitem2);
            QTableWidgetItem * newitem3 = new QTableWidgetItem;
            newitem3->setText(itr->license);
            ui->tableWidget->setItem(i,3,newitem3);
            QTableWidgetItem * newitem4 = new QTableWidgetItem;
            QString qun = QString::number(itr->quantity);
            newitem4->setText(qun);
            ui->tableWidget->setItem(i,4,newitem4);
            QTableWidgetItem * newitem5 = new QTableWidgetItem;
            QString pri = QString::number(itr->price);
            newitem5->setText(pri);
            ui->tableWidget->setItem(i,5,newitem5);
            QTableWidgetItem * newitem6 = new QTableWidgetItem;
            QString disc = QString::number(itr->discount)+" % ";
            newitem6->setText(disc);
            ui->tableWidget->setItem(i,6,newitem6);

            i++;
        }
    }
}
