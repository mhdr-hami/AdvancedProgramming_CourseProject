#include "cashierpage.h"
#include "ui_cashierpage.h"

cashierpage::cashierpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cashierpage)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Images\\Logo2"));
}

void cashierpage::setCashPageUIbyIP()
{
    //background
    QPixmap bkgnd("C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Images\\v");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    //

    //Font
    ui->myapplogo->setStyleSheet("QLabel { color : black; }");
    ui->myapplogo->setFont(QFont("Calibri", 17));
    ui->Cashier_search->setStyleSheet("QLabel { color : black; }");
    ui->Cashier_search->setFont(QFont("Calibri", 12));
    ui->Cashier_in->setStyleSheet("QLabel { color : black; }");
    ui->Cashier_in->setFont(QFont("Calibri", 12));
    ui->label->setStyleSheet("QLabel { color : black; }");
    ui->label->setFont(QFont("Calibri", 12));
    ui->label_2->setStyleSheet("QLabel { color : black; }");
    ui->label_2->setFont(QFont("Calibri", 12));
    ui->label_3->setStyleSheet("QLabel { color : black; }");
    ui->label_3->setFont(QFont("Calibri", 12));
    ui->label_6->setStyleSheet("QLabel { color : black; }");
    ui->label_6->setFont(QFont("Calibri", 12));
    ui->label_7->setStyleSheet("QLabel { color : black; }");
    ui->label_7->setFont(QFont("Calibri", 12));
    ui->date->setText(QDate::currentDate().toString());
    ui->date->setStyleSheet("QLabel { color : black; }");
    ui->date->setFont(QFont("Calibri", 11));

    //Hidding and Making the SaleButton
    ui->salebutton->setFont(QFont("Calibri", 14));
    ui->alarm->setText("!");
    ui->alarm->setStyleSheet("QLabel { color : red; }");
    ui->alarm->setFont(QFont("Calibri", 19,QFont::Bold));
    ui->alarm_2->setText("!");
    ui->alarm_2->setStyleSheet("QLabel { color : red; }");
    ui->alarm_2->setFont(QFont("Calibri",19,QFont::Bold));
    ui->salebutton->hide();
    ui->alarm->hide();
    ui->alarm_2->hide();


    //User_payment_setting
    {
        user_table ut;
        for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
        {
//            if(itr->ip==findMaxIp(ut))
            if(itr->ip==this->page_ip)
            {
                QString userpay = QString::number(itr->basket_money);
                ui->user_payment->setText(userpay);
                ui->user_payment->setStyleSheet("QLabel { color : black; }");
                ui->user_payment->setFont(QFont("Calibri", 12));
                break;
            }
        }
    }

    //

    //Line Edits PlaceHolder
    ui->cashier_input_searchline->setPlaceholderText("Search by name,category,factory");
    ui->cashier_li1->setPlaceholderText("xx");
    ui->cashier_li2->setPlaceholderText("xx");
    ui->cashier_li3->setPlaceholderText("xxxx");
    //

    //Filling the userName
        user_table ut;
        for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
        {
//            if(itr->ip==findMaxIp(ut))
            if(itr->ip==this->page_ip)
            {
                ui->user_name_lable->setText(itr->name);
                ui->user_name_lable->setStyleSheet("QLabel { color : black; }");
                ui->user_name_lable->setFont(QFont("Calibri", 13));
                QString credit = QString::number(itr->money);
                ui->user_credit_lable->setText(credit);
                ui->user_credit_lable->setStyleSheet("QLabel { color : black; }");
                ui->user_credit_lable->setFont(QFont("Calibri", 13));
                break;
            }
        }

    //

    //Making the list unvisible
    ui->listWidget->hide();

    //Creating the timers
    cashcheck_timer = new QTimer(this);
    connect(cashcheck_timer,SIGNAL(timeout()),this,SLOT(cashcheck_func()));
    cashcheck_timer->start(1000);

    //Setting the digital_timer_refresher
    digitaltimer_refresher = new QTimer(this);
    connect(digitaltimer_refresher,SIGNAL(timeout()),this,SLOT(digitaltimer_func()));
    digitaltimer_refresher->start(1000);
    {
        QTime time = QTime::currentTime();
        QString stime = time.toString("hh : mm : ss");
        ui->digital_time->setText(stime);
    }



}

cashierpage::~cashierpage()
{
    delete ui;
}

void cashierpage::digitaltimer_func()
{
    QTime time = QTime::currentTime();
    QString stime = time.toString("hh : mm : ss");
    ui->digital_time->setText(stime);
    //Filling the userName
        user_table ut;
        for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
        {
//            if(itr->ip==findMaxIp(ut))
            if(itr->ip==this->page_ip)
            {
                ui->user_name_lable->setText(itr->name);
                ui->user_name_lable->setStyleSheet("QLabel { color : black; }");
                ui->user_name_lable->setFont(QFont("Calibri", 13));
                QString credit = QString::number(itr->money);
                ui->user_credit_lable->setText(credit);
                ui->user_credit_lable->setStyleSheet("QLabel { color : black; }");
                ui->user_credit_lable->setFont(QFont("Calibri", 13));
                break;
            }
        }

    //
}

void cashierpage::on_cashier_logout_clicked()
{
    //Show mainwindow
    QMessageBox::StandardButton reply =  QMessageBox::question(this,"Logging out", "Do You Want to Logout?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        //offing the managerName
        {
            user_table ut;
            for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
            {
//                if(itr->ip==findMaxIp(ut))
                if(itr->ip==this->page_ip)
                {
                    itr->ip=0;
                    itr->basket_money =0;
                    break;
                }
            }
        }

        //erasing the basket
        {
            basketproduct_table bt;
            bt.erase(bt.begin(),bt.end());
        }
        //

        close();
//        mainpage = new MainWindow;
//        mainpage->show();
    }

}

void cashierpage::on_cashier_input_searchline_textChanged(const QString &arg1)
{
    if(arg1=="")
        ui->listWidget->hide();
    else
        ui->listWidget->show();
    ui->listWidget->clear();
    QString combo = ui->Cashier_combo->currentText();

    product_table pt;
    if(combo=="Names")
    {
        for ( product_table::iterator itr = pt.begin() ; itr != pt.end() ; ++ itr )
            if(itr->name.toLower().startsWith(arg1.toLower()) && arg1!="")
                ui->listWidget->addItem(itr->name);

    }
    else if(combo == "Categories")
    {
        for ( product_table::iterator itr = pt.begin() ; itr != pt.end() ; ++ itr )
            if(itr->category.toLower().startsWith(arg1.toLower()) && arg1!="")
            {
                ui->listWidget->addItem(itr->category);
                break;
            }
    }
    else if(combo == "Factories")
    {
        for ( product_table::iterator itr = pt.begin() ; itr != pt.end() ; ++ itr )
            if(itr->factory.toLower().startsWith(arg1.toLower()) && arg1!="")
                ui->listWidget->addItem(itr->factory);
    }
}


void cashierpage::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->cashier_input_searchline->setText(item->text());
    ui->listWidget->hide();
    cashierpage::on_cashier_searchbutton_clicked();
}

void cashierpage::on_cashier_searchbutton_clicked()
{
    product_table pt;
    ui->listWidget->hide();
    ui->tableWidget->clearContents();
    QString arg1 = ui->cashier_input_searchline->text();
    if(arg1=="")
    {
        QMessageBox::warning(this,"Error!","Fields Can Not be Empty! Try again.");
        return;
    }
    QString combo = ui->Cashier_combo->currentText();
    if(combo=="Names")
    {
        int i=0;

        for ( product_table::iterator itr = pt.begin() ; itr != pt.end() ; ++ itr )
            if(itr->name.toLower().startsWith(arg1.toLower()) && arg1!="")
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
    else if(combo == "Categories")
    {
        int i=0;

        for ( product_table::iterator itr = pt.begin() ; itr != pt.end() ; ++ itr )
            if(itr->category.toLower().startsWith(arg1.toLower()) && arg1!="")
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
    else if(combo == "Factories")
    {
        int i=0;

        for ( product_table::iterator itr = pt.begin() ; itr != pt.end() ; ++ itr )
            if(itr->factory.toLower().startsWith(arg1.toLower()) && arg1!="")
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
    ui->tableWidget->clearSpans();
}

void cashierpage::on_cashier_addBaslket_clicked()
{
    double payment=ui->user_payment->text().toDouble();
    basketproduct_table bt;
    product_table pt;
    QString license = ui->cashier_li1->text()+"|"+ui->cashier_li2->text()+"|"+ui->cashier_li3->text();
    if(ui->cashier_li1->text()=="" ||ui->cashier_li2->text()==""||ui->cashier_li3->text()==""|| ui->cashier_purchline->text()=="")
    {
        QMessageBox::warning(this,"Adding error!","Fields Can Not be Empty! Try again.");
        return;
    }
    for ( product_table::iterator itr = pt.begin() ; itr != pt.end() ; ++ itr )
    {
        if(itr->license==license)
        {
            if((payment+(itr->price)*(ui->cashier_purchline->text().toInt()))>ui->user_credit_lable->text().toDouble())
            {
                QMessageBox::warning(this,"Adding Error!","Not Enough Credit");
                return;
            }
            else if(itr->quantity-ui->cashier_purchline->text().toInt()<0)
            {
                QMessageBox::warning(this,"Adding Error!","There Is Not Enough Amount of This Product.");
                return;
            }
            basketproduct_main * newbaspro = new basketproduct_main(itr->name,ui->cashier_purchline->text().toInt(),itr->price,(itr->price)*ui->cashier_purchline->text().toInt(),this->page_ip);
            bt.push_back(* newbaspro);
            payment += (itr->price)*ui->cashier_purchline->text().toInt();
            //User_payment_setting
            {
                user_table ut;
                for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
                {
//                    if(itr->ip==findMaxIp(ut))
                    if(itr->ip==this->page_ip)
                    {
                        itr->basket_money = payment;
                        break;
                    }
                }
            }
            QString Spayment = QString::number(payment);
            ui->user_payment->setText(Spayment);
            QMessageBox::information(this,"DONE!", "Adding Done Successfully.");
            return;
        }
    }

    QMessageBox::warning(this,"Adding Error!","No Such License Found! Try Again.");
}

void cashierpage::on_cashier_show_basket_clicked()
{
    {
        //Show BaketPage
        baspage = new basket;
        baspage->page_ip = this->page_ip;
        baspage->setBasketPageUIbyIP();
        baspage->show();
        close();
    }

}

void cashierpage::on_cashier_buyCredit_clicked()
{
    {
        //Show BuyCreditPage
        buycrpage = new buyCredit;
        buycrpage->page_ip = this->page_ip;
        buycrpage->setBuyCreditPageUIbyIP();
        buycrpage->show();
        close();
    }
}

void cashierpage::cashcheck_func()
{
    sale_table st;
    if(!st.isEmpty())
    {
        //Showing the SaleButton
        ui->alarm->show();
        ui->alarm_2->show();
        ui->salebutton->show();
        cashcheck_timer->stop();
    }
}

void cashierpage::on_salebutton_clicked()
{
    {
        //Show The SalePage
        cashsalepage = new cash_saleee;
        cashsalepage->page_ip = this->page_ip;
        cashsalepage->setCashSalePageUIbyIP();
        cashsalepage->show();
        close();
    }
}
