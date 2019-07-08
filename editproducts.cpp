#include "editproducts.h"
#include "ui_editproducts.h"

editproducts::editproducts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editproducts)
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
    ui->label_4->setStyleSheet("QLabel { color : black; }");
    ui->label_4->setFont(QFont("Calibri", 11));
    ui->label_5->setStyleSheet("QLabel { color : black; }");
    ui->label_5->setFont(QFont("Calibri", 11));
    ui->label_6->setStyleSheet("QLabel { color : black; }");
    ui->label_6->setFont(QFont("Calibri", 11));
    ui->label_7->setStyleSheet("QLabel { color : black; }");
    ui->label_7->setFont(QFont("Calibri", 11));
    ui->label_8->setStyleSheet("QLabel { color : black; }");
    ui->label_8->setFont(QFont("Calibri", 11));
    ui->label_9->setStyleSheet("QLabel { color : black; }");
    ui->label_9->setFont(QFont("Calibri", 11));
    ui->label_10->setStyleSheet("QLabel { color : black; }");
    ui->label_10->setFont(QFont("Calibri", 11));
    ui->label_11->setStyleSheet("QLabel { color : black; }");
    ui->label_11->setFont(QFont("Calibri", 11));
    ui->label_12->setStyleSheet("QLabel { color : black; }");
    ui->label_12->setFont(QFont("Calibri", 11));
    ui->label_13->setStyleSheet("QLabel { color : black; }");
    ui->label_13->setFont(QFont("Times", 11));
    ui->label_14->setStyleSheet("QLabel { color : black; }");
    ui->label_14->setFont(QFont("Times", 11));
    ui->label_15->setStyleSheet("QLabel { color : black; }");
    ui->label_15->setFont(QFont("Calibri", 11));
    //

    //Line Edits PlaceHolder    
    ui->editpro_edit_name->setPlaceholderText("Product's name");
    ui->editpro_edit_fac->setPlaceholderText("Product's factory");
    ui->editpro_search1->setPlaceholderText("xx");
    ui->editpro_search2->setPlaceholderText("xx");
    ui->editpro_search3->setPlaceholderText("xxxx");
    //
}

editproducts::~editproducts()
{
    delete ui;
}

void editproducts::on_editpro_searchbutton_clicked()
{
    product_table pt;
    int flag=0;
    if(ui->editpro_search1->text()=="" || ui->editpro_search2->text()=="" || ui->editpro_search3->text()=="")
    {
        QMessageBox::warning(this,"Error!","Fields Can Not Be Empty!");
        return;
    }
    QString searchlic = ui->editpro_search1->text()+"|"+ui->editpro_search2->text()+"|"+ui->editpro_search3->text();
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    for ( product_table::iterator itr = pt.begin() ; itr != pt.end() ; ++ itr )
    {
        if(itr->license == searchlic)
        {
            QTableWidgetItem * newitem0 = new QTableWidgetItem;
            newitem0->setText(itr->name);
            ui->tableWidget->setItem(0,0,newitem0);
            QTableWidgetItem * newitem1 = new QTableWidgetItem;
            newitem1->setText(itr->factory);
            ui->tableWidget->setItem(0,1,newitem1);
            QTableWidgetItem * newitem2 = new QTableWidgetItem;
            newitem2->setText(itr->category);
            ui->tableWidget->setItem(0,2,newitem2);
            QTableWidgetItem * newitem3 = new QTableWidgetItem;
            newitem3->setText(itr->license);
            ui->tableWidget->setItem(0,3,newitem3);
            QTableWidgetItem * newitem4 = new QTableWidgetItem;
            QString qun = QString::number(itr->quantity);
            newitem4->setText(qun);
            ui->tableWidget->setItem(0,4,newitem4);
            QTableWidgetItem * newitem5 = new QTableWidgetItem;
            QString pri = QString::number(itr->price);
            newitem5->setText(pri);
            ui->tableWidget->setItem(0,5,newitem5);
            QTableWidgetItem * newitem6 = new QTableWidgetItem;
            QString disc = QString::number(itr->discount)+" % ";
            newitem6->setText(disc);
            ui->tableWidget->setItem(0,6,newitem6);
            flag =1;
        }
    }

    //filling the license
    ui->licenstext->setText(searchlic);
    ui->licenstext->setStyleSheet("QLabel { color : black; }");
    ui->licenstext->setFont(QFont("Times", 11));
    ui->licenstext_2->setText(searchlic);
    ui->licenstext_2->setStyleSheet("QLabel { color : black; }");
    ui->licenstext_2->setFont(QFont("Times", 11));
    //

    if(flag==0)
    {
        QMessageBox::warning(this,"Error!","No Such License Found! Try Again.");
        return;
    }
}

void editproducts::on_editpro_editbutton_clicked()
{
    if(ui->editpro_edit_name->text()=="" || ui->editpro_edit_fac->text()=="" ||ui->editpro_edit_categ->currentText()=="-----" ||
          ui->editpro_search1->text()=="" || ui->editpro_search2->text()=="" || ui->editpro_search3->text()=="" || ui->editpro_edit_quan->text()==""
          || ui->editpro_edit_pric->text()==""||ui->editpro_edit_disc->text()=="")
    {
        QMessageBox::warning(this,"Error!","Fields Can Not Be Empty!");
        return;
    }
    product_table pt;
    QString searchlic = ui->editpro_search1->text()+"|"+ui->editpro_search2->text()+"|"+ui->editpro_search3->text();
    for ( product_table::iterator itr = pt.begin() ; itr != pt.end() ; ++ itr )
    {
        if(itr->license == searchlic)
        {
            itr->name = ui->editpro_edit_name->text();
            itr->factory = ui->editpro_edit_fac->text();
            itr->category = ui->editpro_edit_categ->currentText();
            itr->quantity = ui->editpro_edit_quan->text().toInt();
            itr->price = ui->editpro_edit_pric->text().toDouble();
            itr->discount = ui->editpro_edit_disc->text().toInt();
            QMessageBox::information(this,"Done!","The Product Edited Successfully.");
            //going back to managerPage
            close();
            managpage = new managerpage;
            managpage->show();
            return;
        }
    }
    QMessageBox::warning(this,"Error!","No Such License Found! Try Again.");

}

void editproducts::on_editpro_mainpagebutton_clicked()
{
    //going back to managerPage
    close();
    managpage = new managerpage;
    managpage->show();
}

void editproducts::on_editpro_deletebutton_clicked()
{
    product_table pt;
    QString searchlic = ui->editpro_search1->text()+"|"+ui->editpro_search2->text()+"|"+ui->editpro_search3->text();
    for ( product_table::iterator itr = pt.begin() ; itr != pt.end() ; ++ itr )
    {
        if(itr->license == searchlic)
        {
            pt.erase(itr);
            QMessageBox::information(this,"Done!","The Product Deleted Successfully.");
            //going back to managerPage
            close();
            managpage = new managerpage;
            managpage->show();
            return;
        }
    }
    QMessageBox::warning(this,"Error!","No Such License Found! Try Again.");
}
