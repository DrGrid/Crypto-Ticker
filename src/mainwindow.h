#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QVector>
#include <QtGui>
#include <QThread>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>

#include "config_parser.h"
#include "data_parser.h"
#include "curl_wrapper_class.h"
#include "curl_worker_class.h"
#include "learner.h"
#include "debug_write.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //constructor
    explicit MainWindow(QWidget *parent = 0);
    //functions called in the constructor
    void set_plot_data();
    void set_ui_details();
    //set the labels with the curerntly selected market
    void set_labels();
    //reset the alarm triggers
    void clear_alarm();
    //sound the alarm
    void alarm();
    //call the data pushing function for the plot, and the plot ui function
    void plot_memory_stepping();
    void plotter();
    //Destructor
    ~MainWindow();

signals:
    //singals that the writing of the current market is finished, others may still be under work! This has the potential for race conditions
   void  finished_all();


private slots:
    void set_data();
    //listens for user signals regarding plot parameters
    void set_price_range();
    void set_time_scale();
    //updates the plot after timeout every second and calls the public functions responsible for it
    void update_plot();
    //sets the path when the user send the signal
    void set_path();
    //checks the alarm after the finished_all signal
    void check_alarm();
    //sets the alarm bariers on the user input signal
    void set_up_input();
    void set_down_input();
    //sets the cross market labels after finished_all, subject to said race condition!
    void set_cross_market();
    //pushes a copy of the data over to the learner
    void data_pusher();


private:
    Ui::MainWindow *ui;
    QGraphicsView *view;
    QGridLayout *grid_layout;
    debug debugger;
    curl_worker *worker;
    QTimer *plot_timer, *learner_timer, *main_timer;
    QString label_text, up_bound, down_bound, alarm_path, ranges;
    std::vector<curl_worker*> curl_container;
    Learner learner;
    float upper_bound, lower_bound;
    config_data config;
    parsed_data *data;//takes care of config parsing and reading the incoming JSON string.
    QVector<QVector<double>> market_history{10, QVector<double>(100)}; //QVector QVector initialized with C++11 copy-only member initialisers. The Vector holds the last price of the past 100 seconds.
    QVector<double>time = QVector <double> (1001); //This Vector holds the time, as in 100 seconds.
    int nmarkets; //tracks the total number of markets
    int index; //keeps track of where index of the drop down list is.
    int position; //position for the data, that is being appended to the plot
    double plot_time, plot_price; //hold the range of the plot time and plot  price ; holds the last price of the selecte market in the ui
    double diff; //calculates the difference between the two markets
    double china1_current, china2_current, usd1_current, usd2_current;
};

#endif // MAINWINDOW_H
