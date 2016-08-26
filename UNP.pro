TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lib/error.cpp \
    lib/wrapsock.cpp \
    lib/wrapunix.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    lib/unp.h

