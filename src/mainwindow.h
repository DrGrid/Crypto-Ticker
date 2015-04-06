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
    CppCurl curler;
    std::string data;
    parsed_data current;
    five_step time_data;
};

#endif // MAINWINDOW_H
