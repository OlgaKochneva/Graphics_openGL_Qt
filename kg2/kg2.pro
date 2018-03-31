#-------------------------------------------------
#
# Project created by QtCreator 2018-03-01T10:24:47
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gr_lab1
TEMPLATE = app

LIBS += -lglu32 -lopengl32


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    glwidget.h

FORMS    += mainwindow.ui
