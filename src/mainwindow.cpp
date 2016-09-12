#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    grid_layout = new QGridLayout;
    //call the ui function first, to allow interaction with the QObject
    nmarkets = config.str_url.size();
    //muting = new std::mutex [nmarkets];
    data = new parsed_data(config.market_labels, config.dimensions);
    worker = new curl_worker[nmarkets];
    view = new QGraphicsView (this);
    for (unsigned short c = 0; c < 4; c++)
    {
        worker[c].settings(config.str_url[c].c_str());
        worker[c].process();
    }
    ui->setupUi(this);
    main_timer = new QTimer(this);
    connect(main_timer, SIGNAL(timeout()), this, SLOT(set_data()));
    main_timer->start(500);
    //set the data used by the plotter
    set_plot_data();
    //set the details of the mainwindow ui
    set_ui_details();
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
    //next spawn the worker thread and class.
    learner_timer = new QTimer(this);
    connect(learner_timer, SIGNAL(timeout()), this,SLOT(data_pusher()));
    learner_timer->start(5000);
    debugger.write_debug("Finished the constructor");
}

void MainWindow::set_data()
{
    for (int c = 0; c < nmarkets; c++)
    {
        data->data_writer(worker[c].curling_data, c);
    }
    debugger.write_debug(worker[1].curling_data.c_str());
    set_labels();
    debugger.write_debug("Set the labels");
    for (int c = 0; c < nmarkets; c++)
    {
        learner.learn_data_names(config.markets[c].c_str());
    }
}

void MainWindow::set_ui_details() //called in the constructor
{
    //add the different fields to the ui, that can't be declared in the form
    for (int c(0); c < nmarkets; c++)
    {
        ui->choose_market->addItem(config.markets[c].c_str());
    }
    ui->choose_market->setCurrentIndex(0);
    //sets the title of the programm
}

void MainWindow::set_plot_data() //called  in the constructor
{
    //set the data of the time vector, every step is called once every second.
    for(unsigned short c = 0; c < 1001; c++)
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
    if ((upper_bound < data->main_field[0].sell) | (lower_bound > data->main_field[0].buy))
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
}

void MainWindow::plotter()
{
    // if not defined by user, set the range
    ui->customPlot->xAxis->setRange(0,plot_time);
    //initialise customPlot graphs
    for (int c = 0; c < nmarkets; c++)
    {
        if (ui->choose_market->currentIndex() == c)
        {
            ui->customPlot->yAxis->setRange(data->main_field[c].last-plot_price, data->main_field[c].last+plot_price);
            ui->customPlot->graph(0)->setData(time, market_history[c]);
            //Remove the current title and set to this
            ui->customPlot->plotLayout()->removeAt(0);
            ui->customPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(ui->customPlot, config.markets[c].c_str()));
        }
    }
   // replot every time the function is called to show the changes
    ui->customPlot->replot();
}

void MainWindow::plot_memory_stepping()
{
    debugger.write_debug("I am stuck here");
    if (position < plot_time) //populates the vector for the first hundred time steps (default case would be price every second)
    {
        for (int c = 0; c < nmarkets; c++)
        {
            market_history[c][position] = data->main_field[c].last;
        }
    }
    else
    {
        for (int c = 0; c < nmarkets; c++)
        {
            market_history[c][plot_time] = data->main_field[c].last;
        }
        for (int c = 0; c < nmarkets; c++)
        {
            for (unsigned short i(0); i < plot_time; i++ ) //step through the past hundred seconds and update them to their nearest cell.
            {
                market_history[c][i] = market_history[c][i+1];
            }
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

void MainWindow::set_labels()
{
    index = ui->choose_market->currentIndex();
    //print the data to the screen with text labels, clear the label text every time to allow reuse.
    ui->label->setText(label_text.setNum(data->main_field[index].last));
    label_text.clear();
    ui->label_2->setText(label_text.setNum(data->main_field[index].daily_high));
    label_text.clear();
    ui->label_3->setText(label_text.setNum(data->main_field[index].daily_low));
    label_text.clear();
    ui->label_4->setText(label_text.setNum(data->main_field[index].sell));
    label_text.clear();
    ui->label_5->setText(label_text.setNum(data->main_field[index].buy));
    label_text.clear();
    ui->label_6->setText(label_text.setNum(data->main_field[index].sell-data->main_field[index].buy));
    label_text.clear();
    ui->label_7->setText(label_text.setNum(data->main_field[index].volume));
    label_text.clear();
    emit finished_all();
}

//triggered on finished_all signal
void MainWindow::set_cross_market()
{
    ui->label_8->setText(label_text.setNum(data->main_field[0].last-data->main_field[1].last));
    label_text.clear();
    ui->label_9->setText(label_text.setNum(data->main_field[2].last-data->main_field[3].last));
    label_text.clear();
    ui->virtual_exchange_rate->setText(label_text.setNum(((data->main_field[0].last+data->main_field[1].last) / 2) / ((data->main_field[2].last+data->main_field[3].last) / 2)));
    label_text.clear();
}

void MainWindow::data_pusher()
{
    china1_current = data->main_field[0].last;
    china2_current = data->main_field[1].last;
    usd1_current = data->main_field[2].last;
    usd2_current = data->main_field[3].last;
    learner.data_feeder(china1_current, china2_current, usd1_current, usd2_current);
    ui->label_11->setText(label_text.setNum(learner.score_china1));
    ui->label_12->setText(label_text.setNum(learner.score_china2));
    ui->label_13->setText(label_text.setNum(learner.score_usd1));
    ui->label_14->setText(label_text.setNum(learner.score_usd2));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete data;
    delete plot_timer;
    delete learner_timer;
    delete main_timer;
    delete worker;
}

