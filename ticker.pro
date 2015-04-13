#-------------------------------------------------
#
# Project created by QtCreator 2015-04-05T17:42:57
#
#-------------------------------------------------

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
    	src/qcustomplot.cpp

HEADERS  += src/mainwindow.h\
            src/curl_wrapper_class.h\
            src/data_parser.h \
    		src/qcustomplot.h

FORMS    += src/mainwindow.ui

QT       += core gui

