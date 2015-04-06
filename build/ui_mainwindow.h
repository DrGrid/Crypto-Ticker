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
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *setdown;
    QPushButton *setpath;
    QLineEdit *linepath;
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
    QPushButton *setup;
    QLineEdit *linedown;
    QLineEdit *lineup;
    QLabel *label_down;
    QLabel *label_up;
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
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 451, 108));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        setdown = new QPushButton(layoutWidget);
        setdown->setObjectName(QString::fromUtf8("setdown"));

        gridLayout->addWidget(setdown, 1, 2, 1, 1);

        setpath = new QPushButton(layoutWidget);
        setpath->setObjectName(QString::fromUtf8("setpath"));

        gridLayout->addWidget(setpath, 2, 2, 1, 1);

        linepath = new QLineEdit(layoutWidget);
        linepath->setObjectName(QString::fromUtf8("linepath"));

        gridLayout->addWidget(linepath, 2, 1, 1, 1);

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


        gridLayout->addLayout(formLayout, 0, 0, 3, 1);

        setup = new QPushButton(layoutWidget);
        setup->setObjectName(QString::fromUtf8("setup"));

        gridLayout->addWidget(setup, 0, 2, 1, 1);

        linedown = new QLineEdit(layoutWidget);
        linedown->setObjectName(QString::fromUtf8("linedown"));

        gridLayout->addWidget(linedown, 1, 1, 1, 1);

        lineup = new QLineEdit(layoutWidget);
        lineup->setObjectName(QString::fromUtf8("lineup"));

        gridLayout->addWidget(lineup, 0, 1, 1, 1);

        label_down = new QLabel(layoutWidget);
        label_down->setObjectName(QString::fromUtf8("label_down"));

        gridLayout->addWidget(label_down, 1, 3, 1, 1);

        label_up = new QLabel(layoutWidget);
        label_up->setObjectName(QString::fromUtf8("label_up"));

        gridLayout->addWidget(label_up, 0, 3, 1, 1);

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
        setdown->setText(QApplication::translate("MainWindow", "Set down", 0, QApplication::UnicodeUTF8));
        setpath->setText(QApplication::translate("MainWindow", "Set Path", 0, QApplication::UnicodeUTF8));
        linepath->setText(QString());
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
        spread->setText(QApplication::translate("MainWindow", "Spread", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Fetching Data...", 0, QApplication::UnicodeUTF8));
        setup->setText(QApplication::translate("MainWindow", "Set Up", 0, QApplication::UnicodeUTF8));
        linedown->setText(QString());
        lineup->setText(QString());
        label_down->setText(QString());
        label_up->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
