######################################################################
# Automatically generated by qmake (3.0) H szept. 4 16:09:55 2017
######################################################################

TEMPLATE = lib
UI_DIR = uics/common
MOC_DIR = mocs/common
OBJECTS_DIR = obj/common

CONFIG += staticlib release
INCLUDEPATH += . parser
QT += xml
greaterThan(QT_MAJOR_VERSION, 4): DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x000000
# Input
HEADERS += common.h \
           config.h \
           gameenums.h \
           util.h \
           parser/ioproxy.h \
           parser/parser.h \
           parser/parserstructs.h \
           parser/queryget.h \
           parser/queryresult.h \
           parser/xmlnode.h
SOURCES += config.cpp \
           gameenums.cpp \
           util.cpp \
           parser/ioproxy.cpp \
           parser/parser.cpp \
           parser/parserstructs.cpp \
           parser/queryget.cpp \
           parser/queryresult.cpp \
           parser/xmlnode.cpp
TARGET = lib/kbang_common
QMAKE_CXXFLAGS_DEBUG += -Wall