#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QVector>
#include <QtGui>
#include <thread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //call the ui function first, to allow interaction with the QObject
    ui->setupUi(this);
    //set the data used by the plotter
    set_plot_data();
    //set the details of the mainwindow ui
    set_ui_details();
    //span a worker thread and listen to its signals
    worker = new curl_worker();
    curl_thread = new QThread;
    connect(curl_thread,SIGNAL(started()), worker,SLOT(process()));
    connect(worker, SIGNAL(finished_okcoin(QString)),this,SLOT(set_okcoin_data(QString)));
    connect(worker, SIGNAL(finished_btcchina(QString)),this,SLOT(set_btcchina_data(QString)));
    connect(worker, SIGNAL(finished_bitfinex(QString)),this,SLOT(set_bitfinex_data(QString)));
    connect(worker, SIGNAL(finished_bitstamp(QString)),this,SLOT(set_bitstamp_data(QString)));
    worker->moveToThread(curl_thread);
    curl_thread->start();
    //when the data is finished writing, check it against the alarm
    connect(this,SIGNAL (finished_all()), this, SLOT(check_alarm()));
    connect(this,SIGNAL (finished_all()), this, SLOT(set_cross_market()));
    //sets two arbitrary low and high bounds for the alarm
    upper_bound = 10000;
    lower_bound = 0;
     //accept input for the threashholds to trigger the alarm
    connect(ui->setup,SIGNAL(clicked()), this, SLOT(set_up_input()));
    connect(ui->setdown,SIGNAL(clicked()), this, SLOT(set_down_input()));
    connect(ui->setpath,SIGNAL(clicked()), this, SLOT(set_path()));
    //accept input to change the range of the graph
    connect(ui->push_price_range,SIGNAL(clicked()), this,SLOT(set_price_range()));
    connect(ui->push_time_scale,SIGNAL(clicked()), this, SLOT(set_time_scale()));
    //timer to get the seconds in the plotter right
   plot_timer = new QTimer(this);
    connect(plot_timer, SIGNAL(timeout()), this, SLOT(update_plot()));
    plot_timer->start(1000);
}

void MainWindow::set_ui_details() //called in the constructor
{
    //add the different fields to the ui, that can't be declared in the form
   ui->choose_market->addItem("OkCoin");
   ui->choose_market->addItem("BTCChina");
   ui->choose_market->addItem("Bitfinex");
   ui->choose_market->addItem("Bitstamp");
  ui->choose_market->setCurrentIndex(0);
  //sets the title of the programm
   setWindowTitle("Crypto-Ticker");
}

void MainWindow::set_plot_data() //called  in the constructor
{
    //set the data of the time vector, every step is called once every second.
    for(unsigned short c(0); c < 1001; c++)
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
    //set the position of the data feeder to 0.
    position = 0;
    //something for the title here
    ui->customPlot->plotLayout()->insertRow(0);
    ui->customPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(ui->customPlot, "Market Data"));
}

//triggers on the finished all_signal, as soon as the current curl request is done processing
void MainWindow::check_alarm()
{
    //set the logic to call the alarm function, detach the called thread, to allow the program to run further in the background
    if ((upper_bound<okcoin_parsing.sell) | (lower_bound>okcoin_parsing.buy))
    {
      clear_alarm();
      std::thread(&MainWindow::alarm, this).detach();
    }
}

// triggers on click; sets the upper trigger for the alarm. Once this price has been reached, the alarm will sound
void MainWindow::set_up_input()
{
    up_bound = ui->lineup->text();
    ui->lineup->clear();
    ui->label_up->setText(up_bound);
    upper_bound = up_bound.toFloat();
}

// triggers on click; sets the lower trigger for the alarm. Once this price has been reached, the alarm will sound.
void MainWindow::set_down_input()
{
    down_bound = ui->linedown->text();
    ui->lineup->clear();
    ui->label_down->setText(down_bound);
    lower_bound = down_bound.toFloat();
}

//triggers on click; set the path to the location of the of the .wav file. The "path" already contains the "play"  command, which will initialise the built in default playback device"
void MainWindow::set_path()
{
    alarm_path.clear();
    //adds the play command to the alarm path, this will be prepended to the actual path.
    alarm_path= "play ";
    alarm_path+= ui->linepath->text();
    ui->linepath->clear();
}

//function of check_alarm(), sounds the alarm as a system call to a playable music file (preferably .wav)
void MainWindow::alarm()
{
    system(alarm_path.toStdString().c_str());
}

//function of check_alarm(), resets the alarm input to be able to accept a new boundary as the alarm
void MainWindow::clear_alarm()
{
    ui->lineup->clear();
    upper_bound = 10000;
    ui->label_up->setText("");
    ui->linedown->clear();
    ui->label_down->setText("");
    lower_bound = 0;
}

//triggers on timer timeout, which is once every second. Allows to accurately plot the time function
void MainWindow::update_plot()
{
    plot_memory_stepping(); //add the current data state into the last data element in the vector (which is static)
    plotter(); //plots the selected market
    analyzer(); //analyzes the vector
}

void MainWindow::plotter()
{
    // if not defined by user, set the range
    ui->customPlot->xAxis->setRange(0,plot_time);
    ui->customPlot->yAxis->setRange(current_last-plot_price, current_last+plot_price);
    //initialise customPlot graphs
    if (ui->choose_market->currentIndex() == 0)
        ui->customPlot->graph(0)->setData(time, okcoin_history);
    if (ui->choose_market->currentIndex() == 1)
        ui->customPlot->graph(0)->setData(time, btcchina_history);
    if (ui->choose_market->currentIndex() == 2)
        ui->customPlot->graph(0)->setData(time, bitfinex_history);
    if (ui->choose_market->currentIndex() == 3)
        ui->customPlot->graph(0)->setData(time, bitstamp_history);
    // replot every time the function is called to show the changes
    ui->customPlot->replot();
}

void MainWindow::plot_memory_stepping()
{
    if (position < plot_time) //populates the vector for the first hundred time steps (default case would be price every second)
    {
        okcoin_history[position] = okcoin_parsing.last;
    }
    else
    {
        okcoin_history[plot_time] = okcoin_parsing.last;
        for (unsigned short c(0); c < plot_time; c++ ) //step through the past hundred seconds and update them to their nearest cell.
        {
            okcoin_history[c] = okcoin_history[c+1];
        }
    }
    if (position < plot_time) //populates the vector for the first hundred time steps (default case would be price every second)
    {
        btcchina_history[position] = btcchina_parsing.last;
    }
    else
    {
        btcchina_history[plot_time] = btcchina_parsing.last;
        for (unsigned short c(0); c < plot_time; c++ ) //step through the past hundred seconds and update them to their nearest cell.
        {
            btcchina_history[c] = btcchina_history[c+1];
        }
    }
    if (position < plot_time) //populates the vector for the first hundred time steps (default case would be price every second)
    {
        bitfinex_history[position] = bitfinex_parsing.last;
    }
    else
    {
        bitfinex_history[plot_time] = bitfinex_parsing.last;
        for (unsigned short c(0); c < plot_time; c++ ) //step through the past hundred seconds and update them to their nearest cell.
        {
            bitfinex_history[c] = bitfinex_history[c+1];
        }
    }
    if (position < plot_time) //populates the vector for the first hundred time steps (default case would be price every second)
    {
        bitstamp_history[position] = bitstamp_parsing.last;
    }
    else
    {
        bitstamp_history[plot_time] = bitstamp_parsing.last;
        for (unsigned short c(0); c < plot_time; c++ ) //step through the past hundred seconds and update them to their nearest cell.
        {
            bitstamp_history[c] = bitstamp_history[c+1];
        }
    }
    position++;
}

//triggered on push button clicked
void MainWindow::set_time_scale() //take the time of the q_text_edit, convert to double and resize the graph
{
    ranges = ui->edit_time_scale->text();
    plot_time = ranges.toDouble();
    ranges.clear();
}

//triggered on push button clicked
void MainWindow::set_price_range()
{
    ranges = ui->edit_price_range->text();
    plot_price = ranges.toDouble();
    ranges.clear();
}

void MainWindow::analyzer()
{

}

//triggered on finished_all signal
void MainWindow::set_cross_market()
{
    ui->label_8->setText(label_text.setNum(okcoin_parsing.last-btcchina_parsing.last));
    label_text.clear();
    ui->label_9->setText(label_text.setNum(bitfinex_parsing.last-bitstamp_parsing.last));
    label_text.clear();
}

void MainWindow::set_okcoin_data(QString okcoin_data)
{
    okcoin_string = okcoin_data.toStdString();
    okcoin_parsing.okcoin_data_writer(okcoin_string);
    if (ui->choose_market->currentIndex() == 0)
    {
        set_labels(okcoin_parsing);
    }
}

void MainWindow::set_btcchina_data(QString btcchina_data)
{
    btcchina_string = btcchina_data.toStdString();
    btcchina_parsing.btcchina_data_writer(btcchina_string);
    if (ui->choose_market->currentIndex() == 1)
    {
        set_labels(btcchina_parsing);
    }
}

void MainWindow::set_bitfinex_data(QString bitfinex_data)
{
    bitfinex_string = bitfinex_data.toStdString();
    bitfinex_parsing.bitfinex_data_writer(bitfinex_string);
    if (ui->choose_market->currentIndex() == 2)
    {
        set_labels(bitfinex_parsing);
    }
}

void MainWindow::set_bitstamp_data(QString bitstamp_data)
{
    bitstamp_string = bitstamp_data.toStdString();
    bitstamp_parsing.bitstamp_data_writer(bitstamp_string);
    if (ui->choose_market->currentIndex() == 3)
    {
        set_labels(bitstamp_parsing);
    }
}

void MainWindow::set_labels(parsed_data &data)
{
    //print the data to the screen with text labels, clear the label text every time to allow reuse.
    ui->label->setText(label_text.setNum(data.last));
    label_text.clear();
    ui->label_2->setText(label_text.setNum(data.daily_high));
    label_text.clear();
    ui->label_3->setText(label_text.setNum(data.daily_low));
    label_text.clear();
    ui->label_4->setText(label_text.setNum(data.sell));
    label_text.clear();
    ui->label_5->setText(label_text.setNum(data.buy));
    label_text.clear();
    ui->label_6->setText(label_text.setNum(data.sell-data.buy));
    label_text.clear();
    ui->label_7->setText(label_text.setNum(data.volume));
    label_text.clear();
    emit finished_all();
    current_last = data.last;
}

MainWindow::~MainWindow()
{
    delete ui;
}

