#-------------------------------------------------
#
# Project created by QtCreator 2015-09-29T23:47:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tutorial1
TEMPLATE = app


SOURCES += main.cpp \
    myrect.cpp \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    score.cpp \
    health.cpp

HEADERS  += \
    myrect.h \
    enemy.h \
    game.h \
    score.h \
    health.h \
    bullet.h

FORMS    +=

RESOURCES += \
    res.qrc

DISTFILES +=
