#-------------------------------------------------
#
# Project created by QtCreator 2018-11-30T15:22:19
#
#-------------------------------------------------

QT       += core gui

QT += widgets

TARGET = usb-camera
TEMPLATE = app
CONFIG += static

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
MYLIB_SDL2=-L/usr/local/lib -lSDL2
}

LIBS += $$MYLIB_SDL2



INCLUDEPATH += /usr/local/ffmpeg/include

SOURCES += \
        main.cpp \
    gather_picture.cpp

HEADERS += \
    gather_picture.h
