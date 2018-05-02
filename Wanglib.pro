TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Exception.cpp \
    object.cpp

HEADERS += \
    SmartPointer.h \
    Exception.h \
    object.h \
    list.h \
    seqlist.h \
    staticlist.h \
    dynamiclist.h \
    array.h \
    staticarray.h \
    dynamicarray.h \
    linklist.h \
    staticlinklist.h \
    pointer.h \
    sharedpointer.h
