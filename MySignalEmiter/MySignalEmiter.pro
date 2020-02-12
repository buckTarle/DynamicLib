QT        -= gui

TEMPLATE   = lib
DEFINES   += MYSIGNALEMITER_LIBRARY

# Prevent creation of double folder for debug and release
CONFIG    -= debug_and_release
CONFIG    += c++11

HEADERS   += MySignalEmiter_global.h
HEADERS   += MySignalEmiter.h

#SOURCES   += MySignalEmiter.cpp


# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
