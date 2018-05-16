TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Exception.cpp \
    object.cpp \
    check_parentheses.cpp

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
    sharedpointer.h \
    circlelist.h \
    dualinklist.h \
    circledualist.h \
    LinuxList.h \
    stack.h \
    staticstack.h \
    linkstack.h
