#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QtGui>
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
    void curl_request();
    ~MainWindow();

private slots:
    void timerout();
    void set_up_input();
    void set_down_input();
    void set_path();

private:
    Ui::MainWindow *ui;
    QString label_text, up_bound, down_bound, alarm_path;
    float upper_bound, lower_bound;
    QTimer * timer;
    CppCurl okcoin_curler, btcchina_curler, bitstamp_curler, bitfinex_curler; //initializes the different curl object; more efficient than constant cleanup and re-setting of data
    std::string data; //passed to the curl object and returned, with the conentent of the tickers
    parsed_data current; //shows the current data
    save time_data;
};

#endif // MAINWINDOW_H
