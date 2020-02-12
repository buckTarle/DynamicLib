QT        += quick

# Prevent creation of double folder for debug and release
CONFIG    -= debug_and_release
CONFIG    += c++11

SOURCES   += main.cpp

RESOURCES += qml.qrc

#######################################
# CONFIG FILE COPY

CONFIG  += file_copies
COPIES  += ImportDll

ImportDll.path = $$OUT_PWD/

#######################################
# IMPORT MySignalEmiter

INCLUDEPATH     +=   $$PWD/../MySignalEmiter

win32: LIBS     += -L$$OUT_PWD/../MySignalEmiter  -lMySignalEmiter

ImportDll.files +=   $$OUT_PWD/../MySignalEmiter/MySignalEmiter.dll

#######################################
# INCLUDE HEADER of MyDynamicLib

INCLUDEPATH     += $$PWD/../MyDynamicLib

ImportDll.files += $$OUT_PWD/../MyDynamicLib/MyDynamicLib.dll

#######################################
# IMPORT StaticDynamicLoader

INCLUDEPATH     +=   $$PWD/../StaticDynamicLoader

win32: LIBS     += -L$$OUT_PWD/../StaticDynamicLoader  -lStaticDynamicLoader

ImportDll.files +=   $$OUT_PWD/../StaticDynamicLoader/StaticDynamicLoader.dll

