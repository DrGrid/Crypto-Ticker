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
    setWindowTitle("Crypto-Ticker");
    upper_bound = 10000;
    lower_bound = 0;
    curler.settings("https://www.okcoin.cn/api/ticker.do");
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timerout()));
    timer -> start(1000);
}

void MainWindow::timerout()
{
    data = curler.Fetch();
    curler.data_cleanup();
    current.data_writer(data);
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
    data.clear();
    connect(ui->setup,SIGNAL(clicked()), this, SLOT(set_up_input()));
    connect(ui->setdown,SIGNAL(clicked()), this, SLOT(set_down_input()));
    if ((upper_bound<=current.sell) | (lower_bound>=current.buy))
    {
      std::thread(&MainWindow::clear_alarm, this).detach();
      std::thread(&MainWindow::alarm,this).detach();
    }
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

void MainWindow::alarm()
{
    system("play ~/Music/waving_files/gun.wav");}

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
