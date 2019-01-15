#include( $$PWD/../kbang_common/kbang_common.pri )
TEMPLATE = app
@
INCLUDEPATH += $$PWD/../kbang_common $$PWD/lib
@
UI_DIR = uics/server
MOC_DIR = mocs/server
OBJECTS_DIR = obj/server
QT += network xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x000000
CONFIG += qt
CONFIG += release \
    warn_on

INCLUDEPATH += $$PWD $$PWD/../common
DEPENDPATH += $$PWD/../common

HEADERS += \ 
    player.h \
    gameserver.h \
    game.h \
    console.h \
    consolecommand.h \
    client.h \
    tcpserver.h \
    common.h \
    publicgameview.h \
    publicplayerview.h \
    privateplayerview.h \
    playingcard.h \
    reactioncard.h \
    weaponcard.h \
    cardbang.h \
    cardteamfortressbang.h \
    cardmissed.h \
    cards.h \
    gamecycle.h \
    gameexceptions.h \
    gameinfo.h \
    gametable.h \
    playerctrl.h \
    gameeventlistener.h \
    voidai.h \
    voidai2level.h \
    voidai3level.h \
    cardbeer.h \
    cardexpansionbeer.h \
    cardhorse.h \
    cardpersuasion.h \
    cardfactory.h \
    carddrawcards.h \
    cardmultishoot.h \
    cardarson.h \
    cardduel.h \
    cardgeneralstore.h \
    cardjail.h \
    cardteleport.h \
    cardjarate.h \
    reactionhandler.h \
    carddynamite.h \
    cardtaker.h \
    cardbarrel.h \
    gameeventmanager.h \
    gamelogger.h \
    characterbase.h \
    charactercalamityjanet.h \
    characterblackjack.h \
    characterlist.h \
    charactercassidygringo.h \
    charactersuzylafayette.h \
    characterpropertychange.h \
    characterjourdonnais.h \
    characterpedroramirez.h \
    characterjessejones.h \
    charactersidketchum.h \
    characterkitcarlson.h \
    playerreaper.h \
    charactervulturesam.h \
    checkdeckresulthandler.h \
    characterluckyduke.h \
    charactercowboy.h \
    characterdemoman.h \
    characterengineer.h \
    characterheavy.h \
    charactermedic.h \
    characterscout.h \
    charactersniper.h \
    charactersoldier.h
#     common/config.h \
#     common/gameenums.h \
#     common/util.h 
    
SOURCES += \
    main.cpp \
    player.cpp \
    gameserver.cpp \
    game.cpp \
    console.cpp \
    consolecommand.cpp \
    client.cpp \
    tcpserver.cpp \
    common.cpp \
    publicgameview.cpp \
    publicplayerview.cpp \
    privateplayerview.cpp \
    playingcard.cpp \
    reactioncard.cpp \
    weaponcard.cpp \
    cardbang.cpp \
    cardteamfortressbang.cpp \
    cardmissed.cpp \
    gamecycle.cpp \
    gameinfo.cpp \
    gametable.cpp \
    playerctrl.cpp \
    voidai.cpp \
    voidai2level.cpp \
    voidai3level.cpp \
    gameeventlistener.cpp \
    cardbeer.cpp \
    cardexpansionbeer.cpp \
    cardhorse.cpp \
    cardpersuasion.cpp \
    cardfactory.cpp \
    carddrawcards.cpp \
    cardmultishoot.cpp \
    cardarson.cpp \
    cardduel.cpp \
    cardgeneralstore.cpp \
    cardjail.cpp \
    cardteleport.cpp \
    cardjarate.cpp \
    reactionhandler.cpp \
    carddynamite.cpp \
    cardtaker.cpp \
    cardbarrel.cpp \
    gameeventmanager.cpp \
    gamelogger.cpp \
    characterbase.cpp \
    charactercalamityjanet.cpp \
    characterblackjack.cpp \
    characterlist.cpp \
    charactercassidygringo.cpp \
    charactersuzylafayette.cpp \
    characterpropertychange.cpp \
    characterjourdonnais.cpp \
    characterpedroramirez.cpp \
    characterjessejones.cpp \
    charactersidketchum.cpp \
    characterkitcarlson.cpp \
    playerreaper.cpp \
    charactervulturesam.cpp \
    characterluckyduke.cpp \
    charactercowboy.cpp \
    characterdemoman.cpp \
    characterengineer.cpp \
    characterheavy.cpp \
    charactermedic.cpp \
    characterscout.cpp \
    charactersniper.cpp \
    charactersoldier.cpp
#     common/config.cpp \
#     common/gameenums.cpp \
#     common/util.cpp 
unix {
    LIBPATH += lib
    TARGETDEPS += lib/libkbang_common.a
}

win32 {
    debug:LIBPATH += debug/lib
    release:LIBPATH += release/lib
}

@
LIBS += -L/$$PWD/lib -lkbang_common #That solves the problem "The library couldnot be found."

TARGET = kbang-server
QMAKE_CXXFLAGS_DEBUG += -Wall