#include "allproducts.h"
#include "ui_allproducts.h"

#define Pro_file "C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Document\\Products"

allproducts::allproducts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::allproducts)
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
    ui->myapplogo3->setStyleSheet("QLabel { color : black; }");
    ui->myapplogo3->setFont(QFont("Calibri", 17));
    //

    //filling the table
    {
        product_table pt;
        for(int i=0; i<pt.size(); i++)        
            ui->allprotable->insertRow(ui->allprotable->rowCount());

        int i=0;
        for ( product_table::iterator itr = pt.begin() ; itr != pt.end() ; ++ itr )
        {
            QTableWidgetItem * newitem0 = new QTableWidgetItem;
            newitem0->setText(itr->name);
            ui->allprotable->setItem(i,0,newitem0);
            QTableWidgetItem * newitem1 = new QTableWidgetItem;
            newitem1->setText(itr->factory);
            ui->allprotable->setItem(i,1,newitem1);
            QTableWidgetItem * newitem2 = new QTableWidgetItem;
            newitem2->setText(itr->category);
            ui->allprotable->setItem(i,2,newitem2);
            QTableWidgetItem * newitem3 = new QTableWidgetItem;
            newitem3->setText(itr->license);
            ui->allprotable->setItem(i,3,newitem3);
            QTableWidgetItem * newitem4 = new QTableWidgetItem;
            QString qun = QString::number(itr->quantity);
            newitem4->setText(qun);
            ui->allprotable->setItem(i,4,newitem4);
            QTableWidgetItem * newitem5 = new QTableWidgetItem;
            QString pri = QString::number(itr->price);
            newitem5->setText(pri);
            ui->allprotable->setItem(i,5,newitem5);
            QTableWidgetItem * newitem6 = new QTableWidgetItem;
            QString disc = QString::number(itr->discount)+" % ";
            newitem6->setText(disc);
            ui->allprotable->setItem(i,6,newitem6);

            i++;
        }
    }



}

allproducts::~allproducts()
{
    delete ui;
}

void allproducts::on_allpro_mainpage_clicked()
{
    //Show manager page
    close();
    managpage = new managerpage;
    managpage->show();

}
