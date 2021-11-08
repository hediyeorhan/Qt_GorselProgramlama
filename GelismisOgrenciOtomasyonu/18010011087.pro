#-------------------------------------------------
#
# Project created by QtCreator 2021-06-06T20:01:13
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 18010011087
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ogrenci.cpp \
    dersler.cpp \
    notlar.cpp

HEADERS  += mainwindow.h \
    ogrenci.h \
    dersler.h \
    notlar.h

FORMS    += mainwindow.ui \
    ogrenci.ui \
    dersler.ui \
    notlar.ui

RESOURCES += \
    images/resources.qrc
