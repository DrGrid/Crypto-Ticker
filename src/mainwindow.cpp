#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QVector>
#include <QtGui>
#include <QThread>
#include <thread>
#include "cross_market_dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //call the ui function first, to allow interaction with the QObject
    ui->setupUi(this);
    thread = new QThread;
    //set the data of the time vector, every step is called once every second.
    for(unsigned short c(0); c < 101; c++)
    {
        time[c] = c;
    }
   //add and construct the graph layout
    ui->customPlot->addGraph();
    // give the axes some labels and set the initial range values:
    ui->customPlot->xAxis->setLabel("Time");
    ui->customPlot->yAxis->setLabel("Price");
    plot_price = 10;
    plot_time = 100;
     //add the different fields to the ui, that can't be declared in the form
    ui->choose_market->addItem("OkCoin");
    ui->choose_market->addItem("BTCChina");
    ui->choose_market->addItem("Bitfinex");
    ui->choose_market->addItem("Bitstamp");
   ui->choose_market->setCurrentIndex(0);
   //sets the title of the programm
    setWindowTitle("Crypto-Ticker");
    //sets two arbitrary low and high bounds
    upper_bound = 10000;
    lower_bound = 0;
    //adds the play command to the alarm path, this will be prepended to the actual path.
    alarm_path= "play ";
    //initialise the settings for the respective curl requests
    okcoin_curler.settings("https://www.okcoin.cn/api/ticker.do");
    btcchina_curler.settings("https://data.btcchina.com/data/ticker");
    bitfinex_curler.settings("https://api.bitfinex.com/v1/pubticker/BTCUSD");
    bitstamp_curler.settings("https://www.bitstamp.net/api/ticker/");
    //set the position of the data feeder to 0.
    position = 0;
     //accept input for the threashholds to trigger the alarm
    connect(ui->setup,SIGNAL(clicked()), this, SLOT(set_up_input()));
    connect(ui->setdown,SIGNAL(clicked()), this, SLOT(set_down_input()));
    connect(ui->setpath,SIGNAL(clicked()), this, SLOT(set_path()));
    //accept input to change the range of the graph
    connect(ui->push_price_range,SIGNAL(clicked()), this,SLOT(set_price_range()));
    connect(ui->push_time_scale,SIGNAL(clicked()), this, SLOT(set_time_scale()));
    //accept input to spawn the cross market analyzer

    //Spawn a timer, that timeouts every second and calls the functions, that will trigger action.
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timerout()));
    timer -> start(1000);
}

void MainWindow::timerout() //triggers on timeout every second.
{
    //Initialize a thread and wait for the curl request to finish, before resuming the programm
    std::thread curl_thread  (&MainWindow::curl_request,this);
    curl_thread.join();
    connect(ui->push_power,SIGNAL(clicked()),this,SLOT(trig_power()));
    //read the data string into a presentable Qt format
    memory_stepping();
    //print the data to the screen with text labels, clear the label text every time to allow reuse.
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
    //clear the data string
    data.clear();
    //set the logic to call the alarm function, detach the called thread, to allow the program to run further in the background
    if ((upper_bound<current.sell) | (lower_bound>current.buy))
    {
      std::thread(&MainWindow::clear_alarm, this).detach();
      std::thread(&MainWindow::alarm, this).detach();
    }
    //call the plotting function last in the method, to avoid data collisions
    plotter();
}

void MainWindow::curl_request() //depending on the index of the comoboBox, the data string is filled with the JSON of the respective ticker API.
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

void MainWindow::set_up_input() //sets the upper trigger for the alarm. Once this price has been reached, the alarm will sound
{
    up_bound = ui->lineup->text();
    ui->label_up->setText(up_bound);
    upper_bound = up_bound.toFloat();
}

void MainWindow::set_down_input() //sets the lower trigger for the alarm. Once this price has been reached, the alarm will sound.
{
    down_bound = ui->linedown->text();
    ui->label_down->setText(down_bound);
    lower_bound = down_bound.toFloat();
}

void MainWindow::set_path() //set the path to the location of the of the .wav file. The "path" already contains the "play"  command, which will initialise the built in default playback device"
{
    alarm_path+= ui->linepath->text();
    ui->linepath->clear();
}

void MainWindow::alarm() //sounds the alarm as a system call to a playable music file (preferably .wav)
{
    system(alarm_path.toStdString().c_str());
}

void MainWindow::clear_alarm() //resets the alarm input to be able to accept a new boundary as the alarm
{
    ui->lineup->clear();
    upper_bound = 10000;
    ui->label_up->setText("");
    ui->linedown->clear();
    ui->label_down->setText("");
    lower_bound = 0;
}

void MainWindow::plotter()
{
    // if not defined by user, set the range
    ui->customPlot->xAxis->setRange(0,plot_time);
    ui->customPlot->yAxis->setRange(current.last-plot_price, current.last+plot_price);
    //initialise customPlot graphs
    ui->customPlot->graph(0)->setData(time, history);
    // replot every time the function is called to show the changes
    ui->customPlot->replot();
}

void MainWindow::memory_stepping()
{
    if (position < plot_time) //populates the vector for the first hundred time steps (default case would be price every second)
    {
        history[position] = current.last;
        position++;
    }
    else
    {
        history[plot_time] = current.last;
        for (unsigned short c(0); c < plot_time; c++ ) //step through the past hundred seconds and update them to their nearest cell.
        {
            history[c] = history[c+1];
        }
    }
}

void MainWindow::set_time_scale() //take the time of the q_text_edit, convert to double and resize the graph
{
    ranges = ui->edit_time_scale->text();
    plot_time = ranges.toDouble();
    ranges.clear();
}

void MainWindow::set_price_range()
{
    ranges = ui->edit_price_range->text();
    plot_price = ranges.toDouble();
    ranges.clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::trig_power()
{
    mDialog = new cross_market_dialog(this);
    mDialog->moveToThread(thread);
    mDialog->show();
}

