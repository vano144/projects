#-------------------------------------------------
#
# Project created by QtCreator 2014-12-24T20:25:52
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = filePhilosopher
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    fork.cpp \
    philosopher.cpp \
    waiter.cpp

HEADERS += \
    fork.h \
    philosopher.h \
    waiter.h
