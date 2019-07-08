#include "adddiscount_code.h"
#include "ui_adddiscount_code.h"
#include <codes.h>
#include <QMessageBox>

adddiscount_code::adddiscount_code(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adddiscount_code)
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
    ui->label_2->setFont(QFont("Calibri", 11, QFont::Bold));
    ui->label_3->setStyleSheet("QLabel { color : black; }");
    ui->label_3->setFont(QFont("Calibri", 11, QFont::Bold));
    ui->label_4->setStyleSheet("QLabel { color : black; }");
    ui->label_4->setFont(QFont("Calibri", 11));
    //

    //LineEdits PlaceHolder
    ui->newcode_code->setPlaceholderText("The discount code's name");
}


adddiscount_code::~adddiscount_code()
{
    delete ui;
}

void adddiscount_code::on_newcode_addthis_clicked()
{
    //filling code_table
    code_table ct;
    QString code = ui->newcode_code->text();
    double percentage = ui->newcode_percentage->text().toDouble();
    codemain * newcode = new codemain(code,percentage);
    ct.push_back(*newcode);
    QMessageBox::StandardButton reply =  QMessageBox::question(this,"Adding Done!", "Do You Want to Add More?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::No)
    {
//        hide();
        close();
        managpage = new managerpage;
        managpage->show();
    }

}
