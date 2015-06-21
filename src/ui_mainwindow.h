/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "qcustomplot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Ticker;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QComboBox *choose_market;
    QLabel *label_down;
    QLabel *label_up;
    QPushButton *setup;
    QPushButton *setpath;
    QLineEdit *lineup;
    QLineEdit *linedown;
    QPushButton *setdown;
    QLineEdit *linepath;
    QLabel *sellnow;
    QLabel *buynow;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout;
    QLabel *price;
    QLabel *label;
    QLabel *high;
    QLabel *label_2;
    QLabel *low;
    QLabel *label_3;
    QLabel *sell;
    QLabel *label_4;
    QLabel *bid;
    QLabel *label_5;
    QLabel *spread;
    QLabel *label_6;
    QLabel *volume;
    QLabel *label_7;
    QCustomPlot *customPlot;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLineEdit *edit_time_scale;
    QPushButton *push_time_scale;
    QLineEdit *edit_price_range;
    QPushButton *push_price_range;
    QGridLayout *gridLayout_5;
    QLabel *USD_Spread;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *CNY_Spread;
    QLabel *label_10;
    QLabel *virtual_exchange_rate;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout_2;
    QLabel *OkCoin_Arbi_Score;
    QLabel *label_11;
    QLabel *BTCChina_Arbi_Score;
    QLabel *label_12;
    QFormLayout *formLayout_3;
    QLabel *Bitfinex_Arbi_Score;
    QLabel *label_13;
    QLabel *Bitstamp_Arbi_Score;
    QLabel *label_14;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(462, 712);
        actionNew_Ticker = new QAction(MainWindow);
        actionNew_Ticker->setObjectName(QString::fromUtf8("actionNew_Ticker"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 442, 159));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        choose_market = new QComboBox(layoutWidget);
        choose_market->setObjectName(QString::fromUtf8("choose_market"));

        gridLayout->addWidget(choose_market, 0, 0, 1, 2);

        label_down = new QLabel(layoutWidget);
        label_down->setObjectName(QString::fromUtf8("label_down"));

        gridLayout->addWidget(label_down, 2, 2, 1, 1);

        label_up = new QLabel(layoutWidget);
        label_up->setObjectName(QString::fromUtf8("label_up"));

        gridLayout->addWidget(label_up, 1, 2, 1, 1);

        setup = new QPushButton(layoutWidget);
        setup->setObjectName(QString::fromUtf8("setup"));

        gridLayout->addWidget(setup, 1, 1, 1, 1);

        setpath = new QPushButton(layoutWidget);
        setpath->setObjectName(QString::fromUtf8("setpath"));

        gridLayout->addWidget(setpath, 3, 1, 1, 1);

        lineup = new QLineEdit(layoutWidget);
        lineup->setObjectName(QString::fromUtf8("lineup"));

        gridLayout->addWidget(lineup, 1, 0, 1, 1);

        linedown = new QLineEdit(layoutWidget);
        linedown->setObjectName(QString::fromUtf8("linedown"));

        gridLayout->addWidget(linedown, 2, 0, 1, 1);

        setdown = new QPushButton(layoutWidget);
        setdown->setObjectName(QString::fromUtf8("setdown"));

        gridLayout->addWidget(setdown, 2, 1, 1, 1);

        linepath = new QLineEdit(layoutWidget);
        linepath->setObjectName(QString::fromUtf8("linepath"));

        gridLayout->addWidget(linepath, 3, 0, 1, 1);

        sellnow = new QLabel(layoutWidget);
        sellnow->setObjectName(QString::fromUtf8("sellnow"));

        gridLayout->addWidget(sellnow, 3, 2, 1, 1);

        buynow = new QLabel(layoutWidget);
        buynow->setObjectName(QString::fromUtf8("buynow"));

        gridLayout->addWidget(buynow, 0, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        price = new QLabel(layoutWidget);
        price->setObjectName(QString::fromUtf8("price"));

        formLayout->setWidget(0, QFormLayout::LabelRole, price);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label);

        high = new QLabel(layoutWidget);
        high->setObjectName(QString::fromUtf8("high"));

        formLayout->setWidget(1, QFormLayout::LabelRole, high);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_2);

        low = new QLabel(layoutWidget);
        low->setObjectName(QString::fromUtf8("low"));

        formLayout->setWidget(2, QFormLayout::LabelRole, low);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_3);

        sell = new QLabel(layoutWidget);
        sell->setObjectName(QString::fromUtf8("sell"));

        formLayout->setWidget(3, QFormLayout::LabelRole, sell);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::FieldRole, label_4);

        bid = new QLabel(layoutWidget);
        bid->setObjectName(QString::fromUtf8("bid"));

        formLayout->setWidget(4, QFormLayout::LabelRole, bid);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::FieldRole, label_5);

        spread = new QLabel(layoutWidget);
        spread->setObjectName(QString::fromUtf8("spread"));

        formLayout->setWidget(5, QFormLayout::LabelRole, spread);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::FieldRole, label_6);

        volume = new QLabel(layoutWidget);
        volume->setObjectName(QString::fromUtf8("volume"));

        formLayout->setWidget(6, QFormLayout::LabelRole, volume);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(6, QFormLayout::FieldRole, label_7);


        horizontalLayout->addLayout(formLayout);

        customPlot = new QCustomPlot(centralWidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(10, 170, 441, 311));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 490, 441, 76));
        gridLayout_4 = new QGridLayout(layoutWidget1);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        edit_time_scale = new QLineEdit(layoutWidget1);
        edit_time_scale->setObjectName(QString::fromUtf8("edit_time_scale"));

        gridLayout_3->addWidget(edit_time_scale, 0, 0, 1, 1);

        push_time_scale = new QPushButton(layoutWidget1);
        push_time_scale->setObjectName(QString::fromUtf8("push_time_scale"));

        gridLayout_3->addWidget(push_time_scale, 0, 1, 1, 1);

        edit_price_range = new QLineEdit(layoutWidget1);
        edit_price_range->setObjectName(QString::fromUtf8("edit_price_range"));

        gridLayout_3->addWidget(edit_price_range, 1, 0, 1, 1);

        push_price_range = new QPushButton(layoutWidget1);
        push_price_range->setObjectName(QString::fromUtf8("push_price_range"));

        gridLayout_3->addWidget(push_price_range, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        USD_Spread = new QLabel(layoutWidget1);
        USD_Spread->setObjectName(QString::fromUtf8("USD_Spread"));

        gridLayout_5->addWidget(USD_Spread, 0, 0, 1, 1);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_5->addWidget(label_8, 0, 1, 1, 1);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_5->addWidget(label_9, 1, 1, 1, 1);

        CNY_Spread = new QLabel(layoutWidget1);
        CNY_Spread->setObjectName(QString::fromUtf8("CNY_Spread"));

        gridLayout_5->addWidget(CNY_Spread, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_5, 0, 1, 1, 1);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 570, 251, 21));
        virtual_exchange_rate = new QLabel(centralWidget);
        virtual_exchange_rate->setObjectName(QString::fromUtf8("virtual_exchange_rate"));
        virtual_exchange_rate->setGeometry(QRect(290, 570, 101, 16));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 590, 441, 44));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        OkCoin_Arbi_Score = new QLabel(widget);
        OkCoin_Arbi_Score->setObjectName(QString::fromUtf8("OkCoin_Arbi_Score"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, OkCoin_Arbi_Score);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label_11);

        BTCChina_Arbi_Score = new QLabel(widget);
        BTCChina_Arbi_Score->setObjectName(QString::fromUtf8("BTCChina_Arbi_Score"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, BTCChina_Arbi_Score);

        label_12 = new QLabel(widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, label_12);


        gridLayout_2->addLayout(formLayout_2, 0, 0, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        Bitfinex_Arbi_Score = new QLabel(widget);
        Bitfinex_Arbi_Score->setObjectName(QString::fromUtf8("Bitfinex_Arbi_Score"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, Bitfinex_Arbi_Score);

        label_13 = new QLabel(widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, label_13);

        Bitstamp_Arbi_Score = new QLabel(widget);
        Bitstamp_Arbi_Score->setObjectName(QString::fromUtf8("Bitstamp_Arbi_Score"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, Bitstamp_Arbi_Score);

        label_14 = new QLabel(widget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, label_14);


        gridLayout_2->addLayout(formLayout_3, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 462, 29));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(choose_market, lineup);
        QWidget::setTabOrder(lineup, setup);
        QWidget::setTabOrder(setup, linedown);
        QWidget::setTabOrder(linedown, setdown);
        QWidget::setTabOrder(setdown, linepath);
        QWidget::setTabOrder(linepath, setpath);
        QWidget::setTabOrder(setpath, edit_time_scale);
        QWidget::setTabOrder(edit_time_scale, push_time_scale);
        QWidget::setTabOrder(push_time_scale, edit_price_range);
        QWidget::setTabOrder(edit_price_range, push_price_range);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew_Ticker);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNew_Ticker->setText(QApplication::translate("MainWindow", "&New Ticker", 0, QApplication::UnicodeUTF8));
        label_down->setText(QString());
        label_up->setText(QString());
        setup->setText(QApplication::translate("MainWindow", "Set Up", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        setpath->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        setpath->setText(QApplication::translate("MainWindow", "Set Path", 0, QApplication::UnicodeUTF8));
        lineup->setText(QString());
        linedown->setText(QString());
        setdown->setText(QApplication::translate("MainWindow", "Set down", 0, QApplication::UnicodeUTF8));
        linepath->setText(QString());
        sellnow->setText(QString());
        buynow->setText(QString());
        price->setText(QApplication::translate("MainWindow", "Price:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Fetching Data...", 0, QApplication::UnicodeUTF8));
        high->setText(QApplication::translate("MainWindow", "Daily High:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Fetching Data..", 0, QApplication::UnicodeUTF8));
        low->setText(QApplication::translate("MainWindow", "Daily Low:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Fetching Data...", 0, QApplication::UnicodeUTF8));
        sell->setText(QApplication::translate("MainWindow", "Lowest Sell:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Fetching Data...", 0, QApplication::UnicodeUTF8));
        bid->setText(QApplication::translate("MainWindow", "Highest Bid:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Fetching Data...", 0, QApplication::UnicodeUTF8));
        spread->setText(QApplication::translate("MainWindow", "Spread:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Fetching Data...", 0, QApplication::UnicodeUTF8));
        volume->setText(QApplication::translate("MainWindow", "24h Volume:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Fetching Data..", 0, QApplication::UnicodeUTF8));
        edit_time_scale->setText(QString());
        push_time_scale->setText(QApplication::translate("MainWindow", "Time Scale", 0, QApplication::UnicodeUTF8));
        edit_price_range->setText(QString());
        push_price_range->setText(QApplication::translate("MainWindow", "Price Range", 0, QApplication::UnicodeUTF8));
        USD_Spread->setText(QApplication::translate("MainWindow", "CNY Spread:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Fetching Data...", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Fetching Data...", 0, QApplication::UnicodeUTF8));
        CNY_Spread->setText(QApplication::translate("MainWindow", "USD Spread:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Virtual Exchange Rate Dollar to Yuan:", 0, QApplication::UnicodeUTF8));
        virtual_exchange_rate->setText(QApplication::translate("MainWindow", "Fetching Data...", 0, QApplication::UnicodeUTF8));
        OkCoin_Arbi_Score->setText(QApplication::translate("MainWindow", "OkCoin Arbi Score:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        BTCChina_Arbi_Score->setText(QApplication::translate("MainWindow", "BTCChina Arbi Score:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        Bitfinex_Arbi_Score->setText(QApplication::translate("MainWindow", "Bitfinex Arbi Score:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        Bitstamp_Arbi_Score->setText(QApplication::translate("MainWindow", "Bitstamp Arbi Score:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "Fi&le", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
