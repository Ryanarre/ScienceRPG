QT       += core gui widgets sql

TARGET = ScienceRPG
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
        main.cpp \
        MainWindow.cpp \
    DatabaseManager.cpp

HEADERS += \
        MainWindow.h \
    DatabaseManager.h

FORMS += \
        MainWindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
