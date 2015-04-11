#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QtGui>
#include <thread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->choose_market->addItem("OkCoin");
    ui->choose_market->addItem("BTCChina");
    ui->choose_market->addItem("Bitfinex");
    ui->choose_market->addItem("Bitstamp");
   ui->choose_market->setCurrentIndex(0);
    setWindowTitle("Crypto-Ticker");
    upper_bound = 10000;
    lower_bound = 0;
    alarm_path= "play ";
    okcoin_curler.settings("https://www.okcoin.cn/api/ticker.do");
    btcchina_curler.settings("https://data.btcchina.com/data/ticker");
    bitfinex_curler.settings("https://api.bitfinex.com/v1/pubticker/BTCUSD");
    bitstamp_curler.settings("https://www.bitstamp.net/api/ticker/");
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timerout()));
    timer -> start(1000);
}

void MainWindow::timerout()
{
    std::thread curl_thread  (&MainWindow::curl_request,this);
    curl_thread.join();
    time_data.memory_stepping(current.last);
    ui->label->setText(label_text.setNum(current.last));
    label_text.clear();
    ui->label_2->setText(label_text.setNum(current.daily_high));
    label_text.clear();
    ui->label_3->setText(label_text.setNum(current.daily_low));
    label_text.clear();
    ui->label_4->setText(label_text.setNum(current.sell));
    label_text.clear();
    ui->label_5->setText(label_text.setNum(current.buy));
    label_text.clear();
    ui->label_6->setText(label_text.setNum(current.sell-current.buy));
    label_text.clear();
        ui->label_7->setText(label_text.setNum(current.volume));
    label_text.clear();
    data.clear();
    connect(ui->setup,SIGNAL(clicked()), this, SLOT(set_up_input()));
    connect(ui->setdown,SIGNAL(clicked()), this, SLOT(set_down_input()));
    connect(ui->setpath,SIGNAL(clicked()), this, SLOT(set_path()));
    if ((upper_bound<=current.sell) | (lower_bound>=current.buy))
    {
      std::thread(&MainWindow::clear_alarm, this).detach();
      std::thread(&MainWindow::alarm, this).detach();
    }
}

void MainWindow::curl_request()
{
            if (ui->choose_market->currentIndex() == 0)
            {
                data = okcoin_curler.fetch();
                okcoin_curler.data_cleanup();
                current.okcoin_data_writer(data);
            }
            else if (ui->choose_market->currentIndex() == 1)
            {
                data = btcchina_curler.fetch();
                btcchina_curler.data_cleanup();
                current.btcchina_data_writer(data);
            }
            else if (ui->choose_market->currentIndex() == 2)
            {
                data = bitfinex_curler.fetch();
                bitfinex_curler.data_cleanup();
                current.bitfinex_data_writer(data);
            }
            else if (ui->choose_market->currentIndex() == 3)
            {
                data = bitstamp_curler.fetch();
                bitstamp_curler.data_cleanup();
                current.bitstamp_data_writer(data);
            }
           data.clear();
}

void MainWindow::set_up_input()
{
    up_bound = ui->lineup->text();
    ui->label_up->setText(up_bound);
    upper_bound = up_bound.toFloat();
}

void MainWindow::set_down_input()
{
    down_bound = ui->linedown->text();
    ui->label_down->setText(down_bound);
    lower_bound = down_bound.toFloat();
}

void MainWindow::set_path()
{
    alarm_path+= ui->linepath->text();
    ui->linepath->clear();
}

void MainWindow::alarm()
{
    system(alarm_path.toStdString().c_str());
}

void MainWindow::clear_alarm()
{
    ui->lineup->clear();
    upper_bound = 10000;
    ui->label_up->setText("");
    ui->linedown->clear();
    ui->label_down->setText("");
    lower_bound = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}
