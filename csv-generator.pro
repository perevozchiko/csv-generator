TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        cmdparams.cpp \
        csvFile.cpp \
        generator.cpp \
        main.cpp

HEADERS += \
    cmdparams.h \
    constants.h \
    csvFile.h \
    generator.h

DISTFILES +=
