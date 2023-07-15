#-------------------------------------------------
#
# Project created by QtCreator 2023-04-18T18:15:38
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = V0_1_62
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp \
    setnet.cpp \
    nmuserin.cpp \
    signup.cpp \
    aduserin.cpp \
    aduserf.cpp \
    savethread.cpp \
    showthread.cpp \
    nmusersel.cpp \
    aulook.cpp \
    ausearch.cpp

HEADERS += \
        widget.h \
    setnet.h \
    nmuserin.h \
    signup.h \
    aduserin.h \
    aduserf.h \
    savethread.h \
    showthread.h \
    nmusersel.h \
    aulook.h \
    ausearch.h

FORMS += \
        widget.ui \
    setnet.ui \
    nmuserin.ui \
    signup.ui \
    aduserin.ui \
    aduserf.ui \
    nmusersel.ui \
    aulook.ui \
    ausearch.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += "C:\Users\JUEMING SHI\Documents\vm_share\opencv_3.4.2_Qt\x86\bin\libopencv_*.dll"

INCLUDEPATH  += "C:\Users\JUEMING SHI\Documents\vm_share\opencv_3.4.2_Qt\include"
