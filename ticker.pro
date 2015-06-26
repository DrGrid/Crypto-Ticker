QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ticker
TEMPLATE = app

OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = src

QMAKE_CFLAGS += -std=c++11 -lcurl -g
QMAKE_CXXFLAGS += -std=c++11 -lcurl -g
QMAKE_LFLAGS += -std=c++11 -lcurl -g

SOURCES += src/main.cpp\
        src/mainwindow.cpp\
        src/curl_wrapper_class.cpp\
        src/config_parser.cpp\
        src/data_parser.cpp\
    	  src/qcustomplot/qcustomplot.cpp\
    	  src/curl_worker_class.cpp \
        src/learner.cpp \
        src/debug_write.cpp

HEADERS  += src/mainwindow.h\
        src/curl_wrapper_class.h\
        src/data_parser.h \
        src/config_parser.h\
        src/qcustomplot/qcustomplot.h \
        src/curl_worker_class.h \
        src/learner.h \
        src/debug_write.h

FORMS    += src/mainwindow.ui

QT       += core gui

