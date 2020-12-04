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
    cardexplosion.h \
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
    cardpeacepipe.h \
    cardmemento.h \
    cardhiddenweapon.h \
    cardcharm.h \
    cardthief.h \
    carddirtyjob.h \
    cardcowboypocket.h \
    cardbleedinginjury.h \
    cardflamebottle.h \
    cardthunder.h \
    cardstunning.h \
    cardsteroid.h \
    carddrugs.h \
    cardheadache.h \
    cardmorphine.h \
    cardweakness.h \
    cardshock.h \
    cardreward.h \
    cardpackmule.h \
    cardgamble.h \
    cardtakerbang.h \
    cardlelabang.h \
    cardghost.h \
    cardcustoms.h \
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
    charactersoldier.h \
    charactercoronelmortimer.h \
    characterdjango.h \
    characteremma.h \
    characterjohnford.h \
    characterloco.h \
    charactersartana.h \
    charactervienna.h \
    characterwyattearp.h \
    characterernestsaliven.h \
    characterernestsaliven2.h \
    charactercrazybear.h \
    charactertomyleeghost.h \
    characterwhitewolf.h \
    charactercharlesboggen.h \
    characterjonathhexx.h \
    characterantonycarma.h \
    charactermatthewhell.h \
    characterabilitythief.h \
    charactercardkeeper.h \
    characterdanquake.h \
    charactersamueldiehard.h \
    charactergordonchristensen.h \
    characterjoeljanis.h \
    charactercaptwcaroll.h \
    characterauntieangelici.h \
    characteredwardangle.h \
    charactergvblack.h \
    characterbushidobill.h \
    charactercheckingblack.h \
    characterelfantasma.h \
    charactercrazywolf.h \
    characterturdferguson.h \
    characterlilsureshot.h \
    charactercheckingroyal.h \
    characterqueenanne.h \
    characterjosebasset.h \
    characterannerogers.h \
    charactermaggiemae.h \
    characterleladevere.h \
    characterjuliebulette.h \
    charactercaptbarret.h \
    characterdaltongang.h \
    characterdynamitedick.h \
    characterjaremybaile.h \
    characterjuanmiranda.h \
    characterjudgedread.h \
    characterjulyannwislow.h \
    characterbuckshotroberts.h \
    characterchosingthomas.h \
    characterfastfranz.h \
    characterfelipedelgado.h \
    charactergreenkatejanet.h \
    characterhurtingbob.h \
    characterjackbrown.h \
    characterjohnnyclem.h \
    characterlindavivenda.h \
    characteroscarrodriguez.h \
    characterpepitaduelita.h \
    characterridinghorse.h \
    characterstonewalljackson.h \
    charactertonyarmed.h \
    characterwilliamlongley.h \
    characteralfonsoduelo.h \
    characterambidexterbo.h \
    characterbartbarber.h \
    characterbigfatjoe.h \
    characterburtlongcatcher.h \
    charactercolinbarrel.h \
    charactercrazyhorse.h \
    characterdynamitejoe.h \
    characterjamesstoneheart.h \
    characterjenniferbigheart.h

#    characterroostercogburn.h
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
    cardexplosion.cpp \
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
    cardpeacepipe.cpp \
    cardmemento.cpp \
    cardhiddenweapon.cpp \
    cardcharm.cpp \
    cardthief.cpp \
    carddirtyjob.cpp \
    cardcowboypocket.cpp \
    cardbleedinginjury.cpp \
    cardflamebottle.cpp \
    cardthunder.cpp \
    cardstunning.cpp \
    cardsteroid.cpp \
    carddrugs.cpp \
    cardmorphine.cpp \
    cardheadache.cpp \
    cardweakness.cpp \
    cardshock.cpp \
    cardreward.cpp \
    cardpackmule.cpp \
    cardgamble.cpp \
    cardtakerbang.cpp \
    cardlelabang.cpp \
    cardghost.cpp \
    cardcustoms.cpp \
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
    charactersoldier.cpp \
    charactercoronelmortimer.cpp \
    characterdjango.cpp \
    characteremma.cpp \
    characterjohnford.cpp \
    characterloco.cpp \
    charactersartana.cpp \
    charactervienna.cpp \
    characterwyattearp.cpp \
    characterernestsaliven.cpp \
    characterernestsaliven2.cpp \
    charactercrazybear.cpp \
    charactertomyleeghost.cpp \
    characterwhitewolf.cpp \
    charactercharlesboggen.cpp \
    characterjonathhexx.cpp \
    characterantonycarma.cpp \
    charactermatthewhell.cpp \
    characterabilitythief.cpp \
    charactercardkeeper.cpp \
    characterdanquake.cpp \
    charactersamueldiehard.cpp \
    charactergordonchristensen.cpp \
    characterjoeljanis.cpp \
    charactercaptwcaroll.cpp \
    characterauntieangelici.cpp \
    characteredwardangle.cpp \
    charactergvblack.cpp \
    characterbushidobill.cpp \
    charactercheckingblack.cpp \
    characterelfantasma.cpp \
    charactercrazywolf.cpp \
    characterturdferguson.cpp \
    characterlilsureshot.cpp \
    charactercheckingroyal.cpp \
    characterqueenanne.cpp \
    characterjosebasset.cpp \
    characterannerogers.cpp \
    charactermaggiemae.cpp \
    characterleladevere.cpp \
    characterjuliebulette.cpp \
    charactercaptbarret.cpp \
    characterdaltongang.cpp \
    characterdynamitedick.cpp \
    characterjaremybaile.cpp \
    characterjuanmiranda.cpp \
    characterjudgedread.cpp \
    characterjulyannwislow.cpp \
    characterbuckshotroberts.cpp \
    characterchosingthomas.cpp \
    characterfastfranz.cpp \
    characterfelipedelgado.cpp \
    charactergreenkatejanet.cpp \
    characterhurtingbob.cpp \
    characterjackbrown.cpp \
    characterjohnnyclem.cpp \
    characterlindavivenda.cpp \
    characteroscarrodriguez.cpp \
    characterpepitaduelita.cpp \
    characterridinghorse.cpp \
    characterstonewalljackson.cpp \
    charactertonyarmed.cpp \
    characterwilliamlongley.cpp \
    characteralfonsoduelo.cpp \
    characterambidexterbo.cpp \
    characterbartbarber.cpp \
    characterbigfatjoe.cpp \
    characterburtlongcatcher.cpp \
    charactercolinbarrel.cpp \
    charactercrazyhorse.cpp \
    characterdynamitejoe.cpp \
    characterjamesstoneheart.cpp \
    characterjenniferbigheart.cpp

#    characterroostercogburn.cpp
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
