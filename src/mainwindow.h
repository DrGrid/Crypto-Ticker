#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QVector>
#include <QtGui>
#include <QThread>
#include <string>
#include <thread>
#include "data_parser.h"
#include "curl_wrapper_class.h"
#include "curl_worker_class.h"

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
    //reset the alarm triggers
    void clear_alarm();
    //sound the alarm
    void alarm();
    //call the data pushing function for the plot, and the plot ui function
    void plot_memory_stepping();
    void plotter();

    void set_labels(parsed_data &data);
    //Destructor
    ~MainWindow();

signals:
    //singals that the writing of the current market is finished, others may still be under work! This has the potential for race conditions
   void  finished_all();
   //signals that the writing and parsing for the specific markets has been done
   void finished_okcoin(std::string okcoin_string);
   void finished_btcchina(std::string btcchina_string);
   void finished_bitfinex(std::string bitfinex_string);
   void finished_bitstamp(std::string bitstamp_string);

private slots:
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
    //sets the data after it has been emited from the parallel thread
    void set_okcoin_data(QString okcoin_data);
    void set_btcchina_data(QString btcchina_data);
    void set_bitfinex_data(QString bitfinex_data);
    void set_bitstamp_data(QString bitstamp_data);

private:
    Ui::MainWindow *ui;
    curl_worker* worker;
    QTimer * plot_timer;
    QThread* curl_thread;
    QString label_text, up_bound, down_bound, alarm_path, ranges;
    float upper_bound, lower_bound;
    std::string okcoin_string, bitfinex_string, btcchina_string, bitstamp_string; //passed to the curl object and returned, with the conentent of the tickers
    parsed_data okcoin_parsing, btcchina_parsing, bitstamp_parsing, bitfinex_parsing; //shows the current data
    QVector<double> okcoin_history = QVector<double> (1001); //QVector initialized with C++11 copy-only member initialisers. The Vector holds the last price of the past 100 seconds.
    QVector<double> btcchina_history = QVector<double> (1001);
    QVector<double> bitfinex_history = QVector<double> (1001);
    QVector<double> bitstamp_history = QVector<double> (1001);
    QVector<double>time = QVector<double>(1001); //This Vector holds the time, as in 100 seconds.
    int position; //position for the data, that is being appended to the plot
    double plot_time, plot_price, current_last; //hold the range of the plot time and plot  price ; holds the last price of the selecte market in the ui
};

#endif // MAINWINDOW_H
