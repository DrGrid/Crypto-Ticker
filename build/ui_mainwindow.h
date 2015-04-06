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
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Ticker;
    QWidget *centralWidget;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *price;
    QLabel *high;
    QLabel *low;
    QLabel *sell;
    QLabel *bid;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineup;
    QPushButton *setup;
    QLineEdit *linedown;
    QPushButton *setdown;
    QLabel *label_up;
    QLabel *label_down;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(533, 200);
        actionNew_Ticker = new QAction(MainWindow);
        actionNew_Ticker->setObjectName(QString::fromUtf8("actionNew_Ticker"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 11, 449, 92));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        price = new QLabel(widget);
        price->setObjectName(QString::fromUtf8("price"));

        formLayout->setWidget(0, QFormLayout::LabelRole, price);

        high = new QLabel(widget);
        high->setObjectName(QString::fromUtf8("high"));

        formLayout->setWidget(1, QFormLayout::LabelRole, high);

        low = new QLabel(widget);
        low->setObjectName(QString::fromUtf8("low"));

        formLayout->setWidget(2, QFormLayout::LabelRole, low);

        sell = new QLabel(widget);
        sell->setObjectName(QString::fromUtf8("sell"));

        formLayout->setWidget(3, QFormLayout::LabelRole, sell);

        bid = new QLabel(widget);
        bid->setObjectName(QString::fromUtf8("bid"));

        formLayout->setWidget(4, QFormLayout::LabelRole, bid);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::FieldRole, label_5);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::FieldRole, label_4);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_3);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_2);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label);


        gridLayout->addLayout(formLayout, 0, 0, 2, 1);

        lineup = new QLineEdit(widget);
        lineup->setObjectName(QString::fromUtf8("lineup"));

        gridLayout->addWidget(lineup, 0, 1, 1, 1);

        setup = new QPushButton(widget);
        setup->setObjectName(QString::fromUtf8("setup"));

        gridLayout->addWidget(setup, 0, 2, 1, 1);

        linedown = new QLineEdit(widget);
        linedown->setObjectName(QString::fromUtf8("linedown"));

        gridLayout->addWidget(linedown, 1, 1, 1, 1);

        setdown = new QPushButton(widget);
        setdown->setObjectName(QString::fromUtf8("setdown"));

        gridLayout->addWidget(setdown, 1, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 2, 1);

        label_up = new QLabel(widget);
        label_up->setObjectName(QString::fromUtf8("label_up"));

        gridLayout_2->addWidget(label_up, 0, 1, 1, 1);

        label_down = new QLabel(widget);
        label_down->setObjectName(QString::fromUtf8("label_down"));

        gridLayout_2->addWidget(label_down, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 533, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew_Ticker);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNew_Ticker->setText(QApplication::translate("MainWindow", "New Ticker", 0, QApplication::UnicodeUTF8));
        price->setText(QApplication::translate("MainWindow", "Price:", 0, QApplication::UnicodeUTF8));
        high->setText(QApplication::translate("MainWindow", "Daily High:", 0, QApplication::UnicodeUTF8));
        low->setText(QApplication::translate("MainWindow", "Daily Low:", 0, QApplication::UnicodeUTF8));
        sell->setText(QApplication::translate("MainWindow", "Lowest Sell:", 0, QApplication::UnicodeUTF8));
        bid->setText(QApplication::translate("MainWindow", "Highest Bid:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Fetching Data...", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Fetching Data...", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Fetching Data...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Fetching Data..", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Fetching Data...", 0, QApplication::UnicodeUTF8));
        setup->setText(QApplication::translate("MainWindow", "Set Up", 0, QApplication::UnicodeUTF8));
        setdown->setText(QApplication::translate("MainWindow", "Set down", 0, QApplication::UnicodeUTF8));
        label_up->setText(QString());
        label_down->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
