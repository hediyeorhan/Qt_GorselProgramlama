#-------------------------------------------------
#
# Project created by QtCreator 2021-05-05T14:19:47
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ders_TcpServer
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    server.cpp

HEADERS  += dialog.h \
    server.h

FORMS    += dialog.ui
