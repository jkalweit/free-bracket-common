#-------------------------------------------------
#
# Project created by QtCreator 2014-09-11T17:37:15
#
#-------------------------------------------------

CONFIG += c++11

QT       += qml

QT       -= gui

TARGET = free-bracket-common
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    FreeBracketCommands.cpp \
    Team.cpp \
    Bracket.cpp \
    BracketRound.cpp \
    BracketMatch.cpp

HEADERS += \
    FreeBracketCommands.h \
    Team.h \
    Bracket.h \
    BracketRound.h \
    BracketMatch.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
