#include "cash_saleee.h"
#include "ui_cash_saleee.h"

cash_saleee::cash_saleee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cash_saleee)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("C:\\Users\\SaBa User\\Desktop\\AP_Project2\\Images\\Logo2"));
    cashSale_refresher_timer = new QTimer(this);
    connect(cashSale_refresher_timer,SIGNAL(timeout()),this,SLOT(cashSale_refresher_func()));
    cashSale_refresher_timer->start(200);

}

cash_saleee::~cash_saleee()
{
    delete ui;
}

void cash_saleee::setCashSalePageUIbyIP()
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
    ui->label->setFont(QFont("Calibri", 17));
    ui->label_2->setStyleSheet("QLabel { color : black; }");
    ui->label_2->setFont(QFont("Calibri", 12));
    ui->label_3->setStyleSheet("QLabel { color : black; }");
    ui->label_3->setFont(QFont("Calibri", 12));
    ui->label_4->setStyleSheet("QLabel { color : black; }");
    ui->label_4->setFont(QFont("Calibri", 12));
    ui->label_5->setStyleSheet("QLabel { color : black; }");
    ui->label_5->setFont(QFont("Calibri", 12));
    ui->label_6->setStyleSheet("QLabel { color : black; }");
    ui->label_6->setFont(QFont("Calibri", 12));
    ui->label_7->setStyleSheet("QLabel { color : black; }");
    ui->label_7->setFont(QFont("Calibri", 12));
    ui->label_8->setStyleSheet("QLabel { color : black; }");
    ui->label_8->setFont(QFont("Calibri", 12));

    //Setting YourCredit
    {
        user_table ut;
        for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
        {
//                    if(itr->ip==findMaxIp(ut))
            if(itr->ip==this->page_ip)
            {
                ui->yourcredit->setText(QString::number(itr->money) + " $");
                ui->yourcredit->setStyleSheet("QLabel { color : black; }");
                ui->yourcredit->setFont(QFont("Calibri", 12));
                break;
            }
        }
    }

    //Setting the Sale Details
    {
        sale_table st;
        ui->onsaleItem->setText(st.begin()->item_name);
        ui->onsaleItem->setStyleSheet("QLabel { color : black; }");
        ui->onsaleItem->setFont(QFont("Calibri", 12));
        ui->remaningtime->setText(QString::number(st.begin()->time));
        ui->remaningtime->setStyleSheet("QLabel { color : black; }");
        ui->remaningtime->setFont(QFont("Calibri", 12));
        ui->bestbid->setText(QString::number(st.begin()->bestbid) + " $");
        ui->bestbid->setStyleSheet("QLabel { color : black; }");
        ui->bestbid->setFont(QFont("Calibri", 12));
        ui->bidder->setText(st.begin()->bestbidder);
        ui->bidder->setStyleSheet("QLabel { color : black; }");
        ui->bidder->setFont(QFont("Calibri", 12));
    }

    //Setting the GeneralTimer
    {
        sale_table st;
        saleGeneral_salePage_timer = new QTimer(this);
        connect(saleGeneral_salePage_timer,SIGNAL(timeout()),this,SLOT(saleGeneral_salePage_func()));
        saleGeneral_salePage_timer->start(st.begin()->time);
    }

}

void cash_saleee::on_pushButton_clicked()
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

void cash_saleee::on_bid_Button_clicked()
{
    int bidding_money = ui->lineEdit->text().toInt();
    int currnet_money ;
    QString bidder;
    user_table ut;
    for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
    {
        if(itr->ip==this->page_ip)
        {
            bidder = itr->name;
            currnet_money = itr->money;
            break;
        }
    }
    sale_table st;
    if(ui->lineEdit->text()=="")
    {
        QMessageBox::warning(this,"Bidding Error","Fields Can Not Be Empty!");
        return;
    }
    else if(bidding_money > currnet_money)
    {
        QMessageBox::warning(this,"Bdding Error","Not Enough Credit to Bid That!");
        return;
    }
    else if(bidding_money>st.begin()->bestbid)
    {
        st.begin()->bestbid = bidding_money;
        st.begin()->bestbidder = bidder;
        ui->bestbid->setText(QString::number(st.begin()->bestbid) + " $");
        ui->bestbid->setStyleSheet("QLabel { color : black; }");
        ui->bestbid->setFont(QFont("Calibri", 12));
        ui->bidder->setText(st.begin()->bestbidder);
        ui->bidder->setStyleSheet("QLabel { color : black; }");
        ui->bidder->setFont(QFont("Calibri", 12));
    }

}

void cash_saleee::saleGeneral_salePage_func()
{
    saleGeneral_salePage_timer->stop();
    cashSale_refresher_timer->stop();
    ui->remaningtime->setText("Finished!!");
    ui->remaningtime->setStyleSheet("QLabel { color : black; }");
    ui->remaningtime->setFont(QFont("Calibri", 12));
    sale_table st;
    QString license = st.begin()->license;
    QString bidder;
    {
        user_table ut;
        for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
        {
            if(itr->ip==this->page_ip)
            {
                bidder = itr->name;
                break;
            }
        }
    }
    if(ui->bidder->text() == bidder)
    {
        ui->winlose->setText("WON!!");
        ui->winlose->setStyleSheet("QLabel { color : green; }");
        ui->winlose->setFont(QFont("Calibri", 24, QFont::Bold));

        //Decreasing the Money and Product Quantity
        {
            user_table ut;
            for ( user_table::iterator itr = ut.begin() ; itr != ut.end() ; ++ itr )
                if(itr->ip==this->page_ip)
                {
                    itr->money -= st.begin()->bestbid;
                    break;
                }
            product_table pt;
            for ( product_table::iterator itr = pt.begin() ; itr != pt.end() ; ++ itr )
                if(itr->license==license)
                {
                    itr->quantity-=1;
                    break;
                }
        }
        QMessageBox::information(this,"Congratulatios!","You Won The Sale !");
        {
            //Show Cashierpage
            cashpage = new cashierpage;
            cashpage->page_ip = this->page_ip;
            cashpage->setCashPageUIbyIP();
            cashpage->show();
        }
        st.clear();
        close();
        return;
    }
    else if(ui->bidder->text() != bidder && ui->bidder->text() == "NoBody")
    {
        QMessageBox::information(this,"Sale Finished!","NO ONE WON!");
        {
            //Show Cashierpage
            cashpage = new cashierpage;
            cashpage->page_ip = this->page_ip;
            cashpage->setCashPageUIbyIP();
            cashpage->show();
        }
        st.clear();
        close();
        return;
    }
    else if(ui->bidder->text() != bidder && ui->bidder->text() != "NoBody")
    {
        ui->winlose->setText("LOST!!");
        ui->winlose->setStyleSheet("QLabel { color : red; }");
        ui->winlose->setFont(QFont("Calibri", 24, QFont::Bold));
        QMessageBox::information(this,"Sale Finished!",st.begin()->bestbidder+" WON!");
        {
            //Show Cashierpage
            cashpage = new cashierpage;
            cashpage->page_ip = this->page_ip;
            cashpage->setCashPageUIbyIP();
            cashpage->show();
        }
        st.clear();
        close();
        return;
    }

}

void cash_saleee::cashSale_refresher_func()
{
    //Setting the Sale Details
    {
        sale_table st;
        ui->onsaleItem->setText(st.begin()->item_name);
        ui->onsaleItem->setStyleSheet("QLabel { color : black; }");
        ui->onsaleItem->setFont(QFont("Calibri", 12));
        ui->remaningtime->setText(QString::number((st.begin()->time/1000))+" : " +QString::number((st.begin()->time%1000)));
        ui->remaningtime->setStyleSheet("QLabel { color : black; }");
        ui->remaningtime->setFont(QFont("Calibri", 14));
        ui->bestbid->setText(QString::number(st.begin()->bestbid) + " $");
        ui->bestbid->setStyleSheet("QLabel { color : black; }");
        ui->bestbid->setFont(QFont("Calibri", 12));
        ui->bidder->setText(st.begin()->bestbidder);
        ui->bidder->setStyleSheet("QLabel { color : black; }");
        ui->bidder->setFont(QFont("Calibri", 13));
    }
}
