#-------------------------------------------------
#
# Project created by QtCreator 2018-11-07T19:02:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = xplay2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

linux{
message("linux Lib")
MYLIB=-L/usr/local/ffmpeg/lib -lavcodec -lavformat -lavutil
}

LIBS += $$MYLIB

INCLUDEPATH += /usr/local/ffmpeg/include

SOURCES += \
        main.cpp \
        xplay2.cpp \
        XDecode.cpp \
        XDemux.cpp

HEADERS += \
        xplay2.h \
        XDecode.h \
        XDemux.h

FORMS += \
        xplay2.ui
