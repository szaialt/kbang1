#include( ../kbang_common/kbang_common.pri )
TEMPLATE = app
@
INCLUDEPATH += $$PWD/../kbang_common $$PWD/lib
@
#INCLUDEPATH+=$$PWD/lib
#@
UI_DIR = uics/client
MOC_DIR = mocs/client
RCC_DIR = rccs/client
#OBJECTS_DIR = obj/client
CONFIG += qt
CONFIG += release \
    warn_on
QT += network xml multimedia widgets 
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x000000
RESOURCES += resources/client.qrc
DEPENDPATH += $$PWD/../common

# Input
HEADERS += gameloop.h \
    connecttoserverdialog.h \
    mainwindow.h \
    serverconnection.h \
    clientcommon.h \
    joingamedialog.h \
    logwidget.h \
    chatwidget.h \
    card.h \
    opponentwidget.h \
    game.h \
    cardwidget.h \
    creategamedialog.h \
    playerwidget.h \
    characterwidget.h \
    cardpilewidget.h \
    deckwidget.h \
    cardpocket.h \
    localplayerwidget.h \
    cardlistwidget.h \
    gameevent.h \
    cardmovementevent.h \
    gameeventqueue.h \
    gameeventhandler.h \
    gamecontextchangeevent.h \
    gamesyncevent.h \
    lifepointschangeevent.h \
    cardactionswidget.h \
    cardwidgetfactory.h \
    gameactionmanager.h \
    playerdiedevent.h \
    playerevent.h \
    graveyardwidget.h \
    cardzoomwidget.h \
    newserverdialog.h \
    selectplayericonwidget.h \
    gamemessageevent.h \
    cardwidgetsizemanager.h \
    aboutdialog.h
#     common/config.h \
#     common/gameenums.h \ 
#     common/util.h 
FORMS += connecttoserverdialog.ui \
    mainwindow.ui \
    joingamedialog.ui \
    logwidget.ui \
    chatwidget.ui \
    opponentwidget.ui \
    creategamedialog.ui \
    localplayerwidget.ui \
    newserverdialog.ui \
    aboutdialog.ui
SOURCES += gameloop.cpp \
    main.cpp \
    connecttoserverdialog.cpp \
    mainwindow.cpp \
    serverconnection.cpp \
    clientcommon.cpp \
    joingamedialog.cpp \
    logwidget.cpp \
    chatwidget.cpp \
    card.cpp \
    opponentwidget.cpp \
    game.cpp \
    cardwidget.cpp \
    creategamedialog.cpp \
    playerwidget.cpp \
    characterwidget.cpp \
    cardpilewidget.cpp \
    deckwidget.cpp \
    localplayerwidget.cpp \
    cardlistwidget.cpp \
    gameevent.cpp \
    cardmovementevent.cpp \
    gameeventqueue.cpp \
    gameeventhandler.cpp \
    gamecontextchangeevent.cpp \
    gamesyncevent.cpp \
    lifepointschangeevent.cpp \
    cardactionswidget.cpp \
    cardwidgetfactory.cpp \
    gameactionmanager.cpp \
    cardpocket.cpp \
    playerdiedevent.cpp \
    playerevent.cpp \
    graveyardwidget.cpp \
    cardzoomwidget.cpp \
    newserverdialog.cpp \
    selectplayericonwidget.cpp \
    gamemessageevent.cpp \
    cardwidgetsizemanager.cpp \
    aboutdialog.cpp
#     common/config.cpp \
#     common/gameenums.cpp \
#     common/util.cpp 
unix { 
    #LIB += lib
    LIBPATH += lib
    TARGETDEPS += lib/libkbang_common.a
    #PRE_TARGETDEPS += lib/libkbang_common.a
    #POST_TARGETDEPS += lib/libkbang_common.a
}
win32 { 
    RC_FILE = kbang_client.rc
    debug:LIBPATH += debug/lib
    release:LIBPATH += release/lib
}
#LIBS += -lkbang_common
@
LIBS += -L/$$PWD/lib -lkbang_common #That solves the problem "The library couldnot be found."

TARGET = kbang-client
QMAKE_CXXFLAGS_DEBUG += -Wall
#QMAKE_CXXFLAGS += -I/$$PWD/lib/libkbang_common.a -L/$$PWD/lib/libkbang_common.a
