QT          -= gui

TEMPLATE     = lib
DEFINES     += MYDYNAMICLIB_LIBRARY

# Prevent creation of double folder for debug and release
CONFIG      -= debug_and_release
CONFIG      += c++11

SOURCES     += MyDynamicLib.cpp

HEADERS     += MyDynamicLib_global.h
HEADERS     += MyDynamicLib.h


# IMPORT MySignalEmiter

INCLUDEPATH += $$PWD/../MySignalEmiter
win32: LIBS += -L$$OUT_PWD/../MySignalEmiter  -lMySignalEmiter

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
