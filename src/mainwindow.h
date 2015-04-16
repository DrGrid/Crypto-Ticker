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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void clear_alarm();
    void alarm();
    void curl_request(int Index);
    void plot_memory_stepping();
    void okcoin_curl_request();
    void btcchina_curl_request();
    void bitstamp_curl_request();
    void bitfinex_curl_request();
    QVector<double>  give_data();
    ~MainWindow();

signals:
   void  finished();

private slots:
    void plotter();
    void curl_timeout();
    void set_plot_data();
    void set_ui_details();
    void set_up_input();
    void set_down_input();
    void set_path();
    void set_price_range();
    void set_time_scale();
    void set_basic_information();

private:
    Ui::MainWindow *ui;
    QString label_text, up_bound, down_bound, alarm_path, ranges;
    float upper_bound, lower_bound;
    QTimer * curl_timer;
    QThread* thread;
    CppCurl okcoin_curler, btcchina_curler, bitstamp_curler, bitfinex_curler; //initializes the different curl object; more efficient than constant cleanup and re-setting of data
    std::string okcoin_data, bitfinex_data, btcchina_data, bitstamp_data; //passed to the curl object and returned, with the conentent of the tickers
    parsed_data current; //shows the current data
   QVector<double> history = QVector<double> (1001); //QVector initialized with C++11 copy-only member initialisers. The Vector holds the last price of the past 100 seconds.
   QVector<double>time = QVector<double>(1001); //This Vector holds the time, as in 100 seconds.
   bool switcher = false;
    int position; //position for the data, that is being appended to the plot
    double plot_time, plot_price; //hold the range of the plot time and plot  price
};

#endif // MAINWINDOW_H
