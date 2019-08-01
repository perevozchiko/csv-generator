include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        ../../cmdparams.h \
        ../../constants.h \
        tst_testcase.h

SOURCES += \
        ../../cmdparams.cpp \
        main.cpp
