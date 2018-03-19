QT += core
QT -= gui
QT += network

CONFIG += c++11

TARGET = Chat_server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    chatserver.cpp \
    mysocket.cpp

HEADERS += \
    chatserver.h \
    mysocket.h
