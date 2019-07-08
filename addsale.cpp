#include "addsale.h"
#include "ui_addsale.h"

addSale::addSale(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addSale)
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
}

addSale::~addSale()
{
    delete ui;
}

void addSale::on_pushButton_clicked()
{    
    if(ui->addsale_li1->text()=="" || ui->addsale_li2->text()=="" || ui->addsale_li3->text()=="" || ui->addsale_time->text()=="")
    {
        QMessageBox::warning(this,"Error!","Fields Can Not Be Empty!");
        return;
    }

    {
        sale_table st;
        if(!st.isEmpty())
        {
            QMessageBox::warning(this,"Adding Error","The Sale Has Not Finished Yet!");
            return;
        }
    }

    int flag=0;
    //adding to sale_table
    {
        sale_table st;
        product_table pt;
        QString license = ui->addsale_li1->text()+"|"+ui->addsale_li2->text()+"|"+ui->addsale_li3->text();
        int time = ui->addsale_time->text().toInt();
        for ( product_table::iterator itr = pt.begin() ; itr != pt.end() ; ++ itr )
        {
           if(itr->license==license)
           {
               saleItem * newsale = new saleItem(itr->name,"NoBody",license,time*60000,0);
               st.push_back(*newsale);
               QMessageBox::information(this,"Adding Done!","This Sale Started!");
               flag=1;
               break;
           }
        }
    }
    if(!flag)
        QMessageBox::warning(this,"Adding Error","No Such License Found!");
    else
    {
        close();
        managpage = new managerpage;
        managpage->show();
    }


}

void addSale::on_pushButton_2_clicked()
{
    //Showing the managerPage
    close();
    managpage = new managerpage;
    managpage->show();
}
