#-------------------------------------------------
#
# Project created by QtCreator 2011-11-19T14:32:44
#
#-------------------------------------------------

QT       += core gui sql

TARGET = grant
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp \
	ui/MainWindow.cpp \
	ui/TableWindow.cpp \
	ui/CardWiew.cpp \
	core/db_struct.cpp \
    ui/FilterWidget.cpp

HEADERS  += ui/MainWindow.h \
	ui/TableWindow.h \
	ui/CardWiew.h \
 	core/db_struct.h \
    ui/FilterWidget.h

FORMS    += ui/MainWindow.ui \
	ui/TableWindow.ui \
	ui/CardWiew.ui \
    ui/FilterWidget.ui











