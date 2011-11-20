#-------------------------------------------------
#
# Project created by QtCreator 2011-07-31T10:54:43
#
#-------------------------------------------------

QT       -= core

QT       -= gui

TARGET = heapspeed
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
DEFINES += VERSION="\"0.0.0.2\""
QMAKE_CXXFLAGS_DEBUG += -std=c++0x -O0 -g -march=native
QMAKE_CXXFLAGS += -std=c++0x -O3 -march=native -fomit-frame-pointer

SOURCES += src/heapspeed.cpp \
    src/heapsort.cpp
SOURCES += randomInit.cpp

HEADERS += src/randomInit.h \
    src/heapsort.h \
    src/timediff.h

INCLUDEPATH += 

LIBS += 




