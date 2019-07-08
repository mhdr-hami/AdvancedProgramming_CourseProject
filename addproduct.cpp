#include "addproduct.h"
#include "ui_addproduct.h"

addproduct::addproduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addproduct)
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
    ui->label_3->setStyleSheet("QLabel { color : black; }");
    ui->label_3->setFont(QFont("Calibri", 11));
    ui->label_4->setStyleSheet("QLabel { color : black; }");
    ui->label_4->setFont(QFont("Calibri", 11));
    ui->label_5->setStyleSheet("QLabel { color : black; }");
    ui->label_5->setFont(QFont("Calibri", 11));
    ui->label_6->setStyleSheet("QLabel { color : black; }");
    ui->label_6->setFont(QFont("Calibri", 11, QFont::Bold));
    ui->label_9->setStyleSheet("QLabel { color : black; }");
    ui->label_9->setFont(QFont("Calibri", 11));
    ui->label_10->setStyleSheet("QLabel { color : black; }");
    ui->label_10->setFont(QFont("Times", 11));
    //

    //Line Edits PlaceHolder
    ui->nameline->setPlaceholderText("Product's name");
    ui->factoryline->setPlaceholderText("Product's factory");
    ui->dayline->setPlaceholderText("xx");
    ui->monthline->setPlaceholderText("xx");
    ui->yearline->setPlaceholderText("xxxx");
    ui->priceline->setPlaceholderText("Price");
    ui->quantotyline->setPlaceholderText("Quantity");
    //
}

addproduct::~addproduct()
{
    delete ui;
}

void addproduct::on_newproaddthisbutton_clicked()
{
    product_table pt;
    QString name = ui->nameline->text();
    QString factory = ui->factoryline->text();
    QString category = ui->categorycombo->currentText();
    QString license = ui->dayline->text()+"|"+ui->monthline->text()+"|"+ui->yearline->text();
    QString qu = ui->quantotyline->text();
    QString pri = ui->priceline->text();
    int disc = 0;
    int quantity = qu.toInt();
    double price = pri.toDouble();
    if(name=="" || factory=="" ||category=="-----" || ui->dayline->text()=="" || ui->monthline->text()=="" || ui->yearline->text()=="" || qu=="" || pri=="")
    {
        QMessageBox::warning(this,"Adding Error","Fields Can Not Be Empty!");
        return;
    }
    for ( product_table::iterator itr = pt.begin() ; itr != pt.end() ; ++ itr )
    {
       if(itr->license==license)
       {
           QMessageBox::warning(this,"Adding Error","This License Already Exists!");
           return;
       }
    }
    Productmain * mahsool = new Productmain (name,factory,category,license,quantity,price,disc);
    pt.push_back(*mahsool);
    QMessageBox::StandardButton reply =  QMessageBox::question(this,"Adding Done!", "Do You Want to Add More?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::No)
    {
//        hide();
        close();
        managpage = new managerpage;
        managpage->show();
    }
}
