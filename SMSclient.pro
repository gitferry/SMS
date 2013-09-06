#-------------------------------------------------
#
# Project created by Gaifangyu 2013-08-30T10:59:59
#
#-------------------------------------------------

QT       += core gui
QT       += network

TARGET = SMSclient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    edicttext.cpp \
    inbox.cpp \
    sentbox.cpp \
    drafts.cpp \
    contactor.cpp \
    trsh.cpp \
    clientserver.cpp \
    clientthread.cpp

HEADERS  += mainwindow.h \
    edicttext.h \
    inbox.h \
    sentbox.h \
    drafts.h \
    contactor.h \
    trsh.h \
    clientserver.h \
    clientthread.h

FORMS    += mainwindow.ui \
    edicttext.ui \
    inbox.ui \
    sentbox.ui \
    drafts.ui \
    contactor.ui \
    trsh.ui
