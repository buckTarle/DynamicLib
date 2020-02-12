TEMPLATE  = subdirs

CONFIG   += ordered


SUBDIRS  += MySignalEmiter
SUBDIRS  += MyDynamicLib
SUBDIRS  += StaticDynamicLoader
SUBDIRS  += demoQML

MySignalEmiter.file      = MySignalEmiter/MySignalEmiter.pro
MyDynamicLib.file        = MyDynamicLib/MyDynamicLib.pro
StaticDynamicLoader.file = StaticDynamicLoader/StaticDynamicLoader.pro
demoQML.file             = demoQML/demoQML.pro

MyDynamicLib.depends        = MySignalEmiter
StaticDynamicLoader.depends = MySignalEmiter
demoQML.depends             = MyDynamicLib StaticDynamicLoader MySignalEmiter
