#include "addiscount_pro.h"
#include "ui_addiscount_pro.h"


addiscount_pro::addiscount_pro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addiscount_pro)
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
    ui->label->setFont(QFont("Calibri", 11));
    ui->label_2->setStyleSheet("QLabel { color : black; }");
    ui->label_2->setFont(QFont("Calibri", 11));
    ui->label_4->setStyleSheet("QLabel { color : black; }");
    ui->label_4->setFont(QFont("Calibri", 11));
    ui->label_3->setStyleSheet("QLabel { color : black; }");
    ui->label_3->setFont(QFont("Calibri", 11, QFont::Bold));
    ui->label_5->setStyleSheet("QLabel { color : black; }");
    ui->label_5->setFont(QFont("Calibri", 11, QFont::Bold));
    //

    //LineEdits PlaceHolder
    ui->name_discountpto->setPlaceholderText("factory or category");    
}

addiscount_pro::~addiscount_pro()
{
    delete ui;
}

void addiscount_pro::on_addbutton_discountpro_clicked()
{
    product_table pt;
    int dispro=0;
    QString name = ui->name_discountpto->text();
    QString perc = ui->int_discountpro->text();
    QString field = ui->combo_discountpro->currentText();
    if(field=="Factory")
    {
        for ( product_table::iterator itr = pt.begin() ; itr != pt.end() ; ++ itr )
        {
           if(itr->factory==name)
           {               
               double percent = perc.toDouble();
               double off = (percent)/100;
               itr->discount = 100 - (100-itr->discount)*(100- percent)/100;
               off*=itr->price;
               itr->price -= off;
               dispro++;
           }
        }

    }
    else if(field=="Drink" || field == "Snack" || field=="Dairy" || field=="Food" || field=="Others")
    {
        for ( product_table::iterator itr = pt.begin() ; itr != pt.end() ; ++ itr )
        {
           if(itr->name==name)
           {               
               double percent = perc.toDouble();
               double off = (percent)/100;
               itr->discount =100 - (100-itr->discount)*(100- percent)/100;
               off*=itr->price;
               itr->price -= off;
               dispro++;
           }
        }
    }
    if(dispro==0)
    {
        QMessageBox::warning(this,"Adding Error!","No Such Field Found! Try Again.");
        return;
    }
    if(dispro>0)
    {
        QMessageBox::StandardButton reply =  QMessageBox::question(this,"Adding Done!", "Do You Want to Add More?",QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::No)
        {
            close();
            managpage = new managerpage;
            managpage->show();
        }
    }
}
