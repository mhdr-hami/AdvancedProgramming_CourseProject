 #include "basket.h"
#include "ui_basket.h"

basket::basket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::basket)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Images\\Logo2"));
}

basket::~basket()
{
    delete ui;
}

void basket::setBasketPageUIbyIP()
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

    //LineEdits PlaceHolder
    ui->lineEdit->setPlaceholderText("Code's name");
    //

    //Filling the userName
    {
        user_table ut;
        for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
        {
//            if(itr->ip==findMaxIp(ut))
            if(itr->ip==this->page_ip)
            {
                ui->basket_username->setText(itr->name);
                ui->basket_username->setStyleSheet("QLabel { color : black; }");
                ui->basket_username->setFont(QFont("Calibri", 13));
                QString credit = QString::number(itr->money);
                ui->basket_credit->setText(credit);
                ui->basket_credit->setStyleSheet("QLabel { color : black; }");
                ui->basket_credit->setFont(QFont("Calibri", 13));
                break;
            }
        }
    }
    //

    //Filling the bill
    {
        int i=0;
        double payment =0;
        basketproduct_table bt;

        for ( basketproduct_table::iterator itr = bt.begin() ; itr != bt.end() ; ++ itr )
        {
            if(itr->buyer_ip == this->page_ip)
            {
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                QTableWidgetItem * newitem0 = new QTableWidgetItem;
                newitem0->setText(itr->name);
                ui->tableWidget->setItem(i,0,newitem0);
                QTableWidgetItem * newitem1 = new QTableWidgetItem;
                newitem1->setText(QString::number(itr->quantity));
                ui->tableWidget->setItem(i,1,newitem1);
                QTableWidgetItem * newitem2 = new QTableWidgetItem;
                newitem2->setText(QString::number(itr->price));
                ui->tableWidget->setItem(i,2,newitem2);
                QTableWidgetItem * newitem3 = new QTableWidgetItem;
                newitem3->setText(QString::number(itr->sum));
                ui->tableWidget->setItem(i,3,newitem3);
                payment += itr->sum;

                i++;
            }
        }
        //Filling the paymentAmount
        {
            QString Spayment = QString::number(payment);
            ui->basket_payment->setText(Spayment);
            ui->basket_payment->setStyleSheet("QLabel { color : black; }");
            ui->basket_payment->setFont(QFont("Calibri", 13));
        }
        //Filling the user_basketMoney
        {
            user_table ut;
            for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
//                if(itr->ip==findMaxIp(ut))
                if(itr->ip==this->page_ip)
                    itr->basket_money = payment;
        }
        //
    }
    //
}

void basket::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply =  QMessageBox::question(this,"Payment Manager", "Are You Sure?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        //Erasing the basket
        basketproduct_table bt;
        for ( basketproduct_table::iterator itr = bt.begin() ; itr != bt.end() ; ++ itr )
        {
            //Decreasing the product
            product_table pt;
            for ( product_table::iterator ir = pt.begin() ; ir != pt.end() ; ++ ir )
            {
                if(itr->name == ir->name && itr->price==ir->price && itr->buyer_ip == this->page_ip)
                {
                    ir->quantity -= itr->quantity;
                    bt.erase(itr);
                    break;
                }
            }
            //
        }

        //

        //Decrease the credit
        {
            user_table ut;
            for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
            {
//                if(itr->ip==findMaxIp(ut))
                if(itr->ip==this->page_ip)
                {
                    itr->money -= ui->basket_payment->text().toDouble();
                    itr->basket_money =0;
                    break;
                }
            }
        }
        //
        QMessageBox::information(this,"Done!","Thanks. Hope to See You Agin.");

        {
            //Show Cashierpage
            cashpage = new cashierpage;
            cashpage->page_ip = this->page_ip;
            cashpage->setCashPageUIbyIP();
            cashpage->show();
            close();
        }
    }
}

void basket::on_pushButton_2_clicked()
{
    {
        //Show Cashierpage
        cashpage = new cashierpage;
        cashpage->page_ip = this->page_ip;
        cashpage->setCashPageUIbyIP();
        cashpage->show();
        close();
    }
}

void basket::on_pushButton_3_clicked()
{
    if(ui->label_6->text()=="✓")
    {
        QMessageBox::warning(this,"Error!","You Can Use the Code Once!");
        return;
    }
    double payment = ui->basket_payment->text().toDouble();
    QString code = ui->lineEdit->text();
    code_table ct;
    for ( code_table::iterator itr = ct.begin() ; itr != ct.end() ; ++ itr )
    {
        //Decreasing the payment
        if(itr->code_name == code)
        {
            //Filling the paymentAmount Again
            {
                payment -= itr->percent*payment/100;
                QString Spayment = QString::number(payment);
                ui->basket_payment->setText(Spayment);
                ui->basket_payment->setStyleSheet("QLabel { color : black; }");
                ui->basket_payment->setFont(QFont("Calibri", 13));
                ui->label_6->setText("✓");
                ui->label_6->setStyleSheet("QLabel { color : green; }");
                ui->label_6->setFont(QFont("Calibri", 19));
            }
            return;
        }
        //
    }
    QMessageBox::warning(this,"Error!","No Such Code Found! Try Again.");
}
