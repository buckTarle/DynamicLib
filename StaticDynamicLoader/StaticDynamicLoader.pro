QT -= gui

TEMPLATE = lib
DEFINES += STATICDYNAMICLOADER_LIBRARY

# Prevent creation of double folder for debug and release
CONFIG    -= debug_and_release
CONFIG    += c++11

SOURCES   += StaticDynamicLoader.cpp

HEADERS   += StaticDynamicLoader_global.h
HEADERS   += StaticDynamicLoader.h

# IMPORT MySignalEmiter

INCLUDEPATH += $$PWD/../MySignalEmiter
win32: LIBS += -L$$OUT_PWD/../MySignalEmiter  -lMySignalEmiter

# INCLUDE MyDynamicLib headers

INCLUDEPATH += $$PWD/../MyDynamicLib

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
