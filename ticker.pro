QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ticker
TEMPLATE = app

OBJECTS_DIR = src
MOC_DIR = src
UI_DIR = src

QMAKE_CFLAGS += -std=c++11 -lcurl
QMAKE_CXXFLAGS += -std=c++11 -lcurl
QMAKE_LFLAGS += -std=c++11 -lcurl

SOURCES += src/main.cpp\
        src/mainwindow.cpp\
        src/curl_wrapper_class.cpp\
        src/data_parser.cpp\
    	src/qcustomplot/qcustomplot.cpp\
    	src/curl_worker_class.cpp \
        src/learner.cpp

HEADERS  += src/mainwindow.h\
            src/curl_wrapper_class.h\
            src/data_parser.h \
            src/qcustomplot/qcustomplot.h \
            src/curl_worker_class.h \
            src/learner.h

FORMS    += src/mainwindow.ui

QT       += core gui

