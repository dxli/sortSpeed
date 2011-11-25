#-------------------------------------------------
#
# Project created by QtCreator 2011-07-31T10:54:43
#
#-------------------------------------------------
#/****************************************************************************
#*
# * Speed of classical sort algorithms
# *  quicksort
# *  merge sort
# * in-place merge sort
# * heapsort
#
# speed, total number of comparison and movement are normalized by n*log2(n)
#
#Copyright (C) 2011 Dongxu Li (dongxuli2011@gmail.com)
#
#This program is free software; you can redistribute it and/or
#modify it under the terms of the GNU General Public License
#as published by the Free Software Foundation; either version 2
#of the License, or (at your option) any later version.
#
#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.
#
#You should have received a copy of the GNU General Public License
#along with this program; if not, write to the Free Software
#Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#**********************************************************************/


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
    src/heapsort.cpp \
    src/actionFactory.cpp \
    src/linkedlist.cpp
SOURCES += randomInit.cpp

HEADERS += src/randomInit.h \
    src/heapsort.h \
    src/timediff.h \
    src/actionFactory.h \
    src/linkedlist.h

INCLUDEPATH +=

LIBS +=








