/***************************************************************************
 *   Copyright (C) 2008 by MacJariel                                       *
 *   echo "badmailet@gbalt.dob" | tr "edibmlt" "ecrmjil"                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <QtDebug>
#include "card.h"
#include "config.h"

#include <QPainter>
#include <QFont>

using namespace client;

QMap<PlayingCardType, Card*> Card::sm_playingCards;
QMap<PlayerRole,      Card*> Card::sm_roleCards;
QMap<CharacterType,   Card*> Card::sm_characterCards;

Card::Card(const QString& name, PlayingCardType playingCardType, const QString& imageFileName):
        m_name(name),
        m_type(Card::Playing),
        m_imageFileName(imageFileName)

{
    if (sm_playingCards.contains(playingCardType)) {
        qCritical("Unable to create a playing card. Given type already created.");
        return;
    }
    loadPixmap();
    sm_playingCards[playingCardType] = this;
}

Card::Card(const QString& name, PlayerRole role, const QString& imageFileName):
        m_name(name),
        m_type(Card::Role),
        m_imageFileName(imageFileName)

{
    if (sm_roleCards.contains(role)) {
        qCritical("Unable to create a role card. Given role card already created.");
        return;
    }
    loadPixmap();
    sm_roleCards[role] = this;
}

Card::Card(const QString& name, CharacterType character, const QString& imageFileName):
        m_name(name),
        m_type(Card::Character),
        m_imageFileName(imageFileName)
{
    if (sm_characterCards.contains(character)) {
        qCritical("Unable to create a character card. Given character card already created.");
        return;
    }
    loadPixmap();
    sm_characterCards[character] = this;
}

QPixmap Card::image(const CardSuit& suit, const CardRank& rank) const
{

        QPoint posRank(35, 590);

        QFont font;
        font.setPixelSize(60);
        QPixmap  result = image();
        QPainter painter(&result);

        QString textRank = rankToString(rank);
        QChar   textSuit = suitToChar(suit);
        QColor  suitColor = suitToColor(suit);

        QPainterPath path1;
        QPainterPath path2;
        //timesFont.setStyleStrategy(QFont::ForceOutline);
        path1.addText(posRank, font, textRank);
        QPoint posSuit = posRank + QPoint((int)(font.pixelSize() * 2 * textRank.size() / 3), 0);
        path2.addText(posSuit, font, textSuit);

        painter.setRenderHint(QPainter::Antialiasing);
/*
        painter.setPen(QPen(Qt::white, 2, Qt::SolidLine, Qt::RoundCap,
                         Qt::RoundJoin));

        painter.setBrush(Qt::black);
        painter.drawPath(path1);
        painter.drawPath(path2);
*/
        painter.setPen(QPen(Qt::white, 1, Qt::SolidLine, Qt::RoundCap,
                         Qt::RoundJoin));

        painter.setBrush(Qt::black);
    painter.drawPath(path1);

        painter.setPen(QPen(Qt::white, 1, Qt::SolidLine, Qt::RoundCap,
                         Qt::RoundJoin));
        painter.setBrush(suitColor);
        painter.drawPath(path2);
        return result;
}


void Card::loadDefaultRuleset()
{
    //Playing cards
    new Card("Bang!",       CARD_BANG,       "gfx/cards/bang.png");
    new Card("Mancato",     CARD_MISSED,     "gfx/cards/missed.png");
    new Card("Birra",       CARD_BEER,       "gfx/cards/beer.png");
    new Card("Saloon",      CARD_SALOON,     "gfx/cards/saloon.png");
    new Card("Wells Fargo", CARD_WELLSFARGO,  "gfx/cards/wellsfargo.png");
    new Card("Diligenza",   CARD_DILIGENZA,   "gfx/cards/diligenza.png");
    new Card("Emporio",     CARD_GENERALSTORE,"gfx/cards/emporio.png");
    new Card("Panico!",     CARD_PANIC,       "gfx/cards/panico.png");
    new Card("Cat Balou",   CARD_CATBALOU,    "gfx/cards/catbalou.png");
    new Card("Indiani!",    CARD_INDIANS,     "gfx/cards/indians.png");
    new Card("Duello",      CARD_DUEL,        "gfx/cards/duel.png");
    new Card("Gatling",     CARD_GATLING,     "gfx/cards/gatling.png");
    new Card("Mustang",     CARD_MUSTANG,    "gfx/cards/mustang.png");
    new Card("Appaloosa",   CARD_APPALOSSA,  "gfx/cards/appaloosa.png");
    new Card("Barile",      CARD_BARREL,     "gfx/cards/barrel.png");
    new Card("Dinamite",    CARD_DYNAMITE,   "gfx/cards/dynamite.png");
    new Card("Prigione",    CARD_JAIL,       "gfx/cards/jail.png");
    new Card("Volcanic",    CARD_VOLCANIC,   "gfx/cards/volcanic.png");
    new Card("Schofield",   CARD_SCHOFIELD,  "gfx/cards/schofield.png");
    new Card("Winchester",  CARD_WINCHESTER, "gfx/cards/winchester.png");
    new Card("Remington",   CARD_REMINGTON,  "gfx/cards/remington.png");
    new Card("Carabine",    CARD_CARABINE,   "gfx/cards/carabine.png");
    //Cards from Team Fortress
    new Card("Arson",       CARD_ARSON,        "gfx/cards/teamfortress/arson.png" );
    new Card("Direct hit",  CARD_DIRECT_HIT,    "gfx/cards/teamfortress/direct_hit.png" );
    new Card("Supply crate", CARD_SUPPLY_CRATE, "gfx/cards/teamfortress/supply_crate.png" );
    new Card("Dead ringer", CARD_DEAD_RINGER,  "gfx/cards/teamfortress/dead_ringer.png" );
    new Card("Sandvich",    CARD_SANDVICH,        "gfx/cards/teamfortress/sandvich.png" );
    new Card("Mad milk",    CARD_MAD_MILK,        "gfx/cards/teamfortress/mad_milk.png" );
    new Card("Mann vs machine", CARD_MANN_VS_MACHINE, "gfx/cards/teamfortress/mann_vs_machine.png" );
    new Card("Half zatochi", CARD_HALF_ZATOCHI,"gfx/cards/teamfortress/half_zatoichi.png" );
    new Card("Medi gun",   CARD_MEDI_GUN,       "gfx/cards/teamfortress/medi_gun.png" );
    new Card("Sandman",    CARD_SANDMAN,        "gfx/cards/teamfortress/sandman.png" );
    new Card("Guitar",     CARD_GUITAR,         "gfx/cards/teamfortress/guitar.png" );
    new Card("Teleport",   CARD_TELEPORT,       "gfx/cards/teamfortress/teleport.png" );
    new Card("Persuasion", CARD_PERSUASION,    "gfx/cards/teamfortress/persuasion.png" );
    new Card("Jarate",     CARD_JARATE,        "gfx/cards/teamfortress/jarate.png" );
    new Card("Healing bang", CARD_HEALING_BANG,"gfx/cards/teamfortress/healing-bang.png" );
    //Cards from Director's Cuts
    new Card("Ace up your sleeve", CARD_ACE_UP_YOUR_SLEEVE,        "gfx/cards/directorscuts/ace-up-your-sleeve.jpg" );
    new Card("Deflection",    CARD_DEFLECTION,    "gfx/cards/directorscuts/deflection.jpg" );
    new Card("Union pacific", CARD_UNION_PACIFIC, "gfx/cards/directorscuts/union-pacific.jpg" );
    new Card("Hidden weapon", CARD_HIDDEN_WEAPON, "gfx/cards/directorscuts/hidden-weapon.jpg" );
    new Card("Memento",       CARD_MEMENTO,         "gfx/cards/directorscuts/memento.jpg" );
    new Card("Packing mule", CARD_PACKING_MULE,   "gfx/cards/directorscuts/packing-mule.jpg" );
    new Card("Peace pipe",   CARD_PEACE_PIPE,     "gfx/cards/directorscuts/peace-pipe.jpg" );
    new Card("Shotgun",      CARD_SHOTGUN,         "gfx/cards/directorscuts/shotgun.jpg" );
    new Card("Sun glare",    CARD_SUN_GLARE,       "gfx/cards/directorscuts/sun-glare.jpg" );
    //Cards from Martin City
    new Card("Elixir",       CARD_ELIXIR,         "gfx/cards/martincity/elixir.png" );
    new Card("Explosion",    CARD_EXPLOSION,      "gfx/cards/martincity/explosion.png" );
    new Card("First aid kit", CARD_FIRST_AID_KIT, "gfx/cards/martincity/first-aid-kit.png" );
    new Card("Kombo",        CARD_KOMBO,          "gfx/cards/martincity/kombo.png" );
    new Card("Dirty job",   CARD_DIRTY_JOB,       "gfx/cards/martincity/dirty-job.png" );
    new Card("Killer",       CARD_KILLER,         "gfx/cards/martincity/killer.png" );
    new Card("Golden brown", CARD_GOLDEN_BROWN,   "gfx/cards/martincity/golden-brown.png" );
    new Card("Thunder",      CARD_THUNDER,        "gfx/cards/martincity/thunder.png" );
    new Card("Vest",         CARD_VEST,           "gfx/cards/martincity/vest.png" );
    new Card("Stunning",     CARD_STUNNING,       "gfx/cards/martincity/stunning.png" );
    new Card("Cowboy pocket", CARD_COWBOY_POCKET, "gfx/cards/martincity/cowboy-pocket.png" );
    new Card("Gold watch",   CARD_GOLD_WATCH,     "gfx/cards/martincity/goldwatch.png" );
    new Card("Inflammatory bottle", CARD_INFLAMMATORY_BOTTLE, "gfx/cards/martincity/inflammatory-bottle.png" );
    new Card("Prayer",      CARD_PRAYER,          "gfx/cards/martincity/prayer.png" );
    new Card("Bleeding injury", CARD_BLEEDING_INJURY, "gfx/cards/martincity/bleeding-injury.png" );
    new Card("Adrenaline",  CARD_ADRENALINE,       "gfx/cards/martincity/adrenaline.png" );
    new Card("Medicines",   CARD_MEDICINES,        "gfx/cards/martincity/medicines.png" );
    new Card("Steroid",     CARD_STEROID,          "gfx/cards/martincity/steroid.png" );
    new Card("Drugs",       CARD_DRUGS,            "gfx/cards/martincity/drugs.png" );
    new Card("Headache",    CARD_HEADACHE,         "gfx/cards/martincity/headache.png" );
    new Card("Morphine",    CARD_MORPHINE,         "gfx/cards/martincity/morphine.png" );
    new Card("Shock",       CARD_SHOCK,            "gfx/cards/martincity/shock.png" );
    new Card("Weakness",    CARD_WEAKNESS,         "gfx/cards/martincity/weakness.png" );
    new Card("Indian bang", CARD_INDIAN_BANG,       "gfx/cards/martincity/hitman.png" );
    new Card("Undefensible bang", CARD_UNDEFENSABLE, "gfx/cards/martincity/finishing-hit.png" );
    new Card("Thief",       CARD_THIEF,            "gfx/cards/martincity/thief.png" );
    //Cusp of Carabelli
    new Card("Green fur  trade", CARD_GREEN_FUR_TRADE, "gfx/cards/cuspofcarabelli/green-fur-trade.jpg");
    new Card("War party",   CARD_WAR_PARTY,     "gfx/cards/cuspofcarabelli/war-party.jpg");
    new Card("Plunder",     CARD_PLUNDER,       "gfx/cards/cuspofcarabelli/plunder.jpg");
    new Card("Bar fight",   CARD_BAR_FIGHT,     "gfx/cards/cuspofcarabelli/bar-fight.jpg");
    new Card("Pilfer",      CARD_PILFER,        "gfx/cards/cuspofcarabelli/pilfer.jpg");
    new Card("Roulette",    CARD_ROULETTE,      "gfx/cards/cuspofcarabelli/roulette.jpg");
    new Card("Green on the house", CARD_GREEN_ON_THE_HOUSE,"gfx/cards/cuspofcarabelli/green-on-the-house.jpg");
    new Card("Brown molotov cocktail", CARD_BROWN_MOLOTOV_COCKTAIL,       "gfx/cards/cuspofcarabelli/brown-molotov-cocktail.jpg");
    new Card("Brown investment", CARD_BROWN_INVESTMENT, "gfx/cards/cuspofcarabelli/brown-investment.jpg");
    new Card("Brown loan",  CARD_BROWN_LOAN,    "gfx/cards/cuspofcarabelli/brown-loan.jpg");
    new Card("Rob grave",   CARD_ROB_GRAVE,     "gfx/cards/cuspofcarabelli/rob-grave.jpg");
    new Card("Blood pact",  CARD_BLOOD_PACT,    "gfx/cards/cuspofcarabelli/blood-pact.jpg");
    new Card("Brown show time", CARD_BROWN_SHOW_TIME, "gfx/cards/cuspofcarabelli/brown-show-time.jpg");
    new Card("Brown moonshine", CARD_BROWN_MOONSHINE, "gfx/cards/cuspofcarabelli/brown-moonshine.jpg");
    new Card("Showndown",   CARD_SHOWNDOWN,     "gfx/cards/cuspofcarabelli/showdown.jpg");
    new Card("Hatchet",     CARD_HATCHET,       "gfx/cards/cuspofcarabelli/hatchet.jpg");
    new Card("Reward",      CARD_REWARD,        "gfx/cards/cuspofcarabelli/reward.jpg");
    new Card("Gamble",      CARD_GAMBLE,        "gfx/cards/cuspofcarabelli/gamble.jpg"); 
    new Card("Walker",      CARD_WALKER,        "gfx/cards/cuspofcarabelli/walker.jpg");
    new Card("Pack mule",   CARD_PACK_MULE,     "gfx/cards/cuspofcarabelli/pack-mule.jpg");
    new Card("Bulldog 1",   CARD_BULLDOG_1,     "gfx/cards/cuspofcarabelli/bulldog-1.jpg");
    new Card("Ricochet",    CARD_RICOCHET,      "gfx/cards/cuspofcarabelli/ricochet.jpg");
    new Card("Hill top",    CARD_HILL_TOP,      "gfx/cards/cuspofcarabelli/hill-top.jpg");
    new Card("Taker bang",  CARD_TAKER_BANG,      "gfx/cards/cuspofcarabelli/taker-bang.png");
    //Robber's Roost
    new Card("Cannon",      CARD_CANNON,        "gfx/cards/robbersroost/cannon.jpg");
    new Card("Artillery",   CARD_ARTILLERY,     "gfx/cards/robbersroost/artillery.jpg");
    new Card("Bulldog 2",   CARD_BULLDOG_2,     "gfx/cards/robbersroost/bulldog.jpg");
    new Card("James dougall", CARD_JAMES_DOUGALL,   "gfx/cards/robbersroost/james-dougall.jpg");
    new Card("Purple warpath", CARD_PURPLE_WARPATH, "gfx/cards/robbersroost/warpatch.jpg");
    
    //Unknown card 
    new Card("",            CARD_UNKNOWN,          "gfx/cards/back-playing.png");

    //Characters
    new Card("Bart Cassidy",    CHARACTER_BART_CASSIDY,     "gfx/characters/bart-cassidy.png");
    new Card("Black Jack",      CHARACTER_BLACK_JACK,       "gfx/characters/black-jack.png");
    new Card("Calamity Janet",  CHARACTER_CALAMITY_JANET,   "gfx/characters/calamity-janet.png");
    new Card("El Gringo",       CHARACTER_EL_GRINGO,        "gfx/characters/el-gringo.png");
    new Card("Jesse Jones",     CHARACTER_JESSE_JONES,      "gfx/characters/jesse-jones.png");
    new Card("Jourdonnais",     CHARACTER_JOURDONNAIS,      "gfx/characters/jourdonnais.png");
    new Card("Kit Carlson",     CHARACTER_KIT_CARLSON,      "gfx/characters/kit-carlson.png");
    new Card("Lucky Duke",      CHARACTER_LUCKY_DUKE,       "gfx/characters/lucky-duke.png");
    new Card("Paul Regret",     CHARACTER_PAUL_REGRET,      "gfx/characters/paul-regret.png");
    new Card("Pedro Ramirez",   CHARACTER_PEDRO_RAMIREZ,    "gfx/characters/pedro-ramirez.png");
    new Card("Rose Doolan",     CHARACTER_ROSE_DOOLAN,      "gfx/characters/rose-doolan.png");
    new Card("Sid Ketchum",     CHARACTER_SID_KETCHUM,      "gfx/characters/sid-ketchum.png");
    new Card("Slab the Killer", CHARACTER_SLAB_THE_KILLER,  "gfx/characters/slab-the-killer.png");
    new Card("Suzy Lafayette",  CHARACTER_SUZY_LAFAYETTE,   "gfx/characters/suzy-lafayette.png");
    new Card("Vulture Sam",     CHARACTER_VULTURE_SAM,      "gfx/characters/vulture-sam.png");
    new Card("Willy the Kid",   CHARACTER_WILLY_THE_KID,    "gfx/characters/willy-the-kid.png");
    //Team Fortress
    new Card("Demoman",         CHARACTER_DEMOMAN,         "gfx/characters/teamfortress/demo.png");
    new Card("Engineer",        CHARACTER_ENGINEER,        "gfx/characters/teamfortress/engineer.png");
    new Card("Heavy",           CHARACTER_HEAVY,           "gfx/characters/teamfortress/heavy.png");
    new Card("Medic",           CHARACTER_MEDIC,          "gfx/characters/teamfortress/medic.png");
    new Card("Pyro",            CHARACTER_PYRO,           "gfx/characters/teamfortress/pyro.png");
    new Card("Scout",           CHARACTER_SCOUT,         "gfx/characters/teamfortress/scout.png");
    new Card("Sniper",          CHARACTER_SNIPER,        "gfx/characters/teamfortress/sniper.png");
    new Card("Soldier",         CHARACTER_SOLDIER,       "gfx/characters/teamfortress/soldier.png");
    new Card("Spy",             CHARACTER_SPY,           "gfx/characters/teamfortress/spy.png");
    
    //Directory Cuts
    new Card("Coronel Mortimer", CHARACTER_CORONEL_MORTIMER, "gfx/characters/directorscuts/coronel-mortimer.jpg");
    new Card("Django",           CHARACTER_DJANGO,           "gfx/characters/directorscuts/django.jpg");
    new Card("Emma",             CHARACTER_EMMA,             "gfx/characters/directorscuts/emma.jpg");
    new Card("Howard Hawks",     CHARACTER_HOWARD_HAWKS,     "gfx/characters/directorscuts/howard-hawks.jpg");
    new Card("John Ford",        CHARACTER_JOHN_FORD,        "gfx/characters/directorscuts/john-ford.jpg");
    new Card("Llanero Solitario", CHARACTER_LLANERO_SOLITARIO, "gfx/characters/directorscuts/llanero-solitario.jpg");
    new Card("Loco",            CHARACTER_LOCO,             "gfx/characters/directorscuts/loco.jpg");
    new Card("Pat Garrett",     CHARACTER_PAT_GARRETT,      "gfx/characters/directorscuts/pat-garrett.jpg");
    new Card("Rev Jonathan Rudd", CHARACTER_REV_JONATHAN_RUDD, "gfx/characters/directorscuts/rev-jonathan-rudd.jpg");
    new Card("Rooster Cogburn", CHARACTER_ROOSTER_COGBURN,  "gfx/characters/directorscuts/rooster-cogburn.jpg");
    new Card("Sartana",        CHARACTER_SARTANA,           "gfx/characters/directorscuts/sartana.jpg");
    new Card("Tuco El Feo",    CHARACTER_TUCO_EL_FEO,       "gfx/characters/directorscuts/tuco-el-feo.jpg");
    new Card("Viejo Sikes",    CHARACTER_VIEJO_SIKES,       "gfx/characters/directorscuts/viejo-sikes.jpg");
    new Card("Vienna",         CHARACTER_VIENNA,            "gfx/characters/directorscuts/vienna.jpg");
    new Card("Wyatt Earp",     CHARACTER_WYATT_EARP,        "gfx/characters/directorscuts/wyatt-earp.jpg");
    
    //Martin City
    new Card("Ernest Saliven", CHARACTER_ERNEST_SALIVEN,    "gfx/characters/martincity/ernest-saliven.png");
    new Card("Ernest Saliven2", CHARACTER_ERNEST_SALIVEN2,   "gfx/characters/martincity/ernest-saliven2.png");
    new Card("Crazy Bear",     CHARACTER_CRAZY_BEAR,        "gfx/characters/martincity/crazy-bear.png");
    new Card("Tomy Lee Ghost", CHARACTER_TOMY_LEE_GHOST,    "gfx/characters/martincity/tomy-lee-ghost.png");
    new Card("White Wolf",     CHARACTER_WHITE_WOLF,        "gfx/characters/martincity/white-wolf.png");
    new Card("Jonath Hexx",  CHARACTER_JONATH_HEXX,     "gfx/characters/martincity/jonath-hexx.png");
    new Card("Matthew Hell",   CHARACTER_MATTHEW_HELL,      "gfx/characters/martincity/matthew-hell.png");
    new Card("Sergeant O Reilly", CHARACTER_SERGEANT_O_REILLY, "gfx/characters/martincity/sergeant-o-reilly.png");
    new Card("Billy Longlife", CHARACTER_BILLY_LONGLIFE,    "gfx/characters/martincity/billy-longlife.png");
    new Card("Antony Carma",   CHARACTER_ANTONY_CARMA,      "gfx/characters/martincity/antony-carma.png");
    new Card("Dan Quake",      CHARACTER_DAN_QUAKE,         "gfx/characters/martincity/dan-quake.png");
    new Card("Ron Robber",     CHARACTER_RON_ROBBER,        "gfx/characters/martincity/ron-robber.png");
    new Card("Samuel Diehard", CHARACTER_SAMUEL_DIEHARD,    "gfx/characters/martincity/samuel-diehard.png");
   //Cusp of Carabelli 
    new Card("Gordon Christensen",      CHARACTER_GORDON_CHRISTENSEN,       "gfx/characters/cuspofcarabelli/gordon-christensen.png");
    new Card("Joel Janis",  CHARACTER_JOEL_JANIS,   "gfx/characters/cuspofcarabelli/joel-janis.png");
    new Card("capt W Caroll",       CHARACTER_CAPT_W_CAROLL,        "gfx/characters/cuspofcarabelli/capt-w-caroll.png");
    new Card("Edward Angle",     CHARACTER_EDWARD_ANGLE,      "gfx/characters/cuspofcarabelli/edward-angle.png");
    new Card("Auntie Angelici",     CHARACTER_AUNTIE_ANGELICI,      "gfx/characters/cuspofcarabelli/auntie-angelici.png");
    new Card("G V Black",     CHARACTER_G_V_BLACK,      "gfx/characters/cuspofcarabelli/g-v-black.png");
    new Card("Bushido Bill",      CHARACTER_BUSHIDO_BILL,       "gfx/characters/cuspofcarabelli/bushido-bill.png");
    new Card("William Harman",   CHARACTER_WILLIAM_HARMAN,    "gfx/characters/cuspofcarabelli/william-harman.png");
    new Card("Clockwork",     CHARACTER_CLOCKWORK,      "gfx/characters/cuspofcarabelli/clockwork.png");
    new Card("El Fantasma",     CHARACTER_EL_FANTASMA,      "gfx/characters/cuspofcarabelli/el-fantasma.png");
    //Robbers Roost 
    new Card("Crazy Wolf",  CHARACTER_CRAZY_WOLF,   "gfx/characters/robbersroost/crazy-wolf.png");
    new Card("Turd Ferguson",     CHARACTER_TURD_FERGUSON,      "gfx/characters/robbersroost/turd-ferguson.png");
    new Card("Lil Sure Shot",   CHARACTER_LIL_SURE_SHOT,    "gfx/characters/robbersroost/lil-sure-shot.png");
    new Card("Flint Dixon",    CHARACTER_FLINT_DIXON,     "gfx/characters/robbersroost/flint-dixon.png");
    new Card("Job Mushgrove",      CHARACTER_JOB_MUSHGROVE,       "gfx/characters/robbersroost/job-mushgrove.png");
    new Card("Porter Rockwall",  CHARACTER_PORTER_ROCKWALL,   "gfx/characters/robbersroost/porter-rockwall.png");
    new Card("Queen Anne",     CHARACTER_QUEEN_ANNE,      "gfx/characters/robbersroost/queen-anne.png");
    new Card("Josey Basset",     CHARACTER_JOSEY_BASSET,      "gfx/characters/robbersroost/josey-basset.png");
    new Card("Maggie Mae",   CHARACTER_MAGGIE_MAE,    "gfx/characters/robbersroost/maggie-mae.png");
    new Card("Lela Devere",     CHARACTER_LELA_DEVERE,      "gfx/characters/robbersroost/lela-devere.png");
    new Card("Julie Bulette", CHARACTER_JULIE_BULETTE,  "gfx/characters/robbersroost/julie-bulette.png");
    
     //Boot Hill
    new Card("Capt Barrett",         CHARACTER_CAPT_BARRETT,         "gfx/characters/boothill/capt-barrett.png");
    new Card("Dalton Gang",        CHARACTER_DALTON_GANG,        "gfx/characters/boothill/dalton-gang.png");
    new Card("Dynamite Dick",           CHARACTER_DYNAMITE_DICK,           "gfx/characters/boothill/dynamite-dick.png");
    new Card("Jaremy Baile",           CHARACTER_JAREMY_BAILE,          "gfx/characters/boothill/jaremy-baile.png");
    new Card("Juan Miranda",            CHARACTER_JUAN_MIRANDA,           "gfx/characters/boothill/juan-miranda.png");
    new Card("Jugde Dread",           CHARACTER_JUGDE_DREAD,         "gfx/characters/boothill/jugde-dread.png");
    new Card("July Ann Winslow",          CHARACTER_JULY_ANN_WINSLOW,        "gfx/characters/boothill/july-ann-winslow.png");
    // 20
    new Card("Buckshot Roberts",         CHARACTER_BUCKSHOT_ROBERTS,         "gfx/characters/20/buckshot-roberts.jpg");
    new Card("Chosing Thomas",        CHARACTER_CHOSING_THOMAS,        "gfx/characters/20/chosing-thomas.jpg");
    new Card("Drosera Alba",           CHARACTER_DROSERA_ALBA,          "gfx/characters/20/drosera-alba.jpg");
    new Card("Fast Franz",            CHARACTER_FAST_FRANZ,           "gfx/characters/20/fast-franz.jpg");
    new Card("Felipe Delgado",           CHARACTER_FELIPE_DELGADO,         "gfx/characters/20/felipe-delgado.jpg");
    new Card("Green Kate Janet",         CHARACTER_GREEN_KATE_JANET,       "gfx/characters/20/green-kate-janet.jpg");
    new Card("Hurting Bob",             CHARACTER_HURTING_BOB,           "gfx/characters/20/hurting-bob.jpg");
    new Card("Jack Brown",             CHARACTER_JACK_BROWN,           "gfx/characters/20/jack-brown.jpg");
    new Card("Johnny Clem",         CHARACTER_JOHNNY_CLEM,         "gfx/characters/20/johnny-clem.jpg");
    new Card("Linda Vivenda",        CHARACTER_LINDA_VIVENDA,        "gfx/characters/20/linda-vivenda.jpg");
    new Card("Oscar Rodriguez",           CHARACTER_OSCAR_RODRIGUEZ,           "gfx/characters/20/oscar-rodriguez.jpg");
    new Card("Pepita Duelita",           CHARACTER_PEPITA_DUELITA,          "gfx/characters/20/pepita-duelita.jpg");
    new Card("Riding Horse",            CHARACTER_RIDING_HORSE,           "gfx/characters/20/riding-horse.jpg");
    new Card("Slobodan The Killer",          CHARACTER_SLOBODAN_THE_KILLER,         "gfx/characters/20/slobodan-the-killer");
    new Card("Stonewall Jackson",         CHARACTER_STONEWALL_JACKSON,       "gfx/characters/20/stonewall-jackson.jpg");
    new Card("Tony Armed",             CHARACTER_TONY_ARMED,           "gfx/characters/20/tony-armed.jpg");
    new Card("William Longley",             CHARACTER_WILLIAM_LONGLEY,           "gfx/characters/20/william-longley.jpg");

     // 33
    new Card("Alfonso Duelo",         CHARACTER_ALFONSO_DUELO,         "gfx/characters/33/alfonso-duelo.jpg");
    new Card("Ambidexter Bo",        CHARACTER_AMBIDEXTER_BO,        "gfx/characters/33/bo-ambidextre.jpg");
    new Card("Bart Barber",           CHARACTER_BART_BARBER,           "gfx/characters/33/bart-barber.jpg");
    new Card("Big Fat Joe",           CHARACTER_BIG_FAT_JOE,          "gfx/characters/33/big-fat-joe.jpg");
    new Card("Burt Longcatcher",           CHARACTER_BURT_LONGCATCHER,         "gfx/characters/33/burt-longcatcher.jpg");
    new Card("Colin Barrel",          CHARACTER_COLIN_BARREL,        "gfx/characters/33/colin-barrel.jpg");
    new Card("Crazy Horse",         CHARACTER_CRAZY_HORSE,       "gfx/characters/33/crazy-horse.jpg");
    new Card("Hank the Bank",           CHARACTER_HANK_THE_BANK,           "gfx/characters/33/hank-bank.jpg");
    new Card("James Stoneheart",           CHARACTER_JAMES_STONEHEART,          "gfx/characters/33/james-stoneheart.jpg");
    new Card("Jennifer Big-Heart",            CHARACTER_JENNIFER_BIG_HEART,           "gfx/characters/33/jennifer-big-heart.jpg");
    new Card("Jeremiah Amish",          CHARACTER_JEREMIAH_AMISH,         "gfx/characters/33/jeremiah-amish.jpg");
    new Card("Jimmy Squint",          CHARACTER_JIMMY_SQUINT,        "gfx/characters/33/jimmy-squint.jpg");
    new Card("Linus Yale",         CHARACTER_LINUS_YALE,       "gfx/characters/33/linus-yale.jpg");
    new Card("Max Painless",             CHARACTER_MAX_PAINLESS,           "gfx/characters/33/max-painless.jpg");
    new Card("Myke Myope",         CHARACTER_MYKE_MYOPE,         "gfx/characters/33/myke-myope.jpg");
    new Card("Nelly Chose-Chair",        CHARACTER_NELLY_CHOSE_CHAIR,        "gfx/characters/33/nelly-chose-chair.jpg");
    new Card("Nina Nine lives",           CHARACTER_NINA_NINE_LIVES,           "gfx/characters/33/nina-9-lives.jpg");
    new Card("One-Eyed Jack",           CHARACTER_ONE_EYED_JACK,          "gfx/characters/33/one-eyed-jack.jpg");
    new Card("Phil Thinwire",            CHARACTER_PHIL_THINWIRE,           "gfx/characters/33/phil-thinwire.jpg");
    new Card("Preston Presbyope",           CHARACTER_PRESTON_PRESBYOPE,         "gfx/characters/33/preston-presbyope.jpg");
    new Card("Richard Gatling",          CHARACTER_RICHARD_GATLING,        "gfx/characters/33/richard-gatling.jpg");
    new Card("Scalping Bull",             CHARACTER_SCALPING_BULL,           "gfx/characters/33/scalping-bull.jpg");
    new Card("Ted Revenge",             CHARACTER_TED_REVENGE,           "gfx/characters/33/ted-revenge.jpg");
    new Card("Tim Croupier",         CHARACTER_TIM_CROUPIER,         "gfx/characters/33/tim-croupier.jpg");
    new Card("Tobias The Mole",        CHARACTER_TOBIAS_THE_MOLE,        "gfx/characters/33/tobias-mole.jpg");
    new Card("Tom Gun-Seller",           CHARACTER_TOM_GUN_SELLER,           "gfx/characters/33/tom-gun-seller.jpg");
   
    new Card("",                CHARACTER_UNKNOWN,          "gfx/cards/back-character2.png");
    new Card("Five Life Point Back", CHARACTER_UNKNOWN5,          "gfx/cards/back-character.png");
    new Card("Cowboy",          CHARACTER_COWBOY,           "gfx/characters/cowboy.png");


    //Roles 
    new Card("Sheriff",  ROLE_SHERIFF,    "gfx/cards/sheriff-moral.png");
    new Card("Renegade", ROLE_RENEGADE,   "gfx/cards/renegade-moral.png");
    new Card("Outlaw",   ROLE_OUTLAW,     "gfx/cards/outlaw-moral.png");
    new Card("Deputy",   ROLE_DEPUTY,     "gfx/cards/deputy-moral.png");
    new Card("",         ROLE_UNKNOWN,    "gfx/cards/back-role.png");
}


const Card* Card::findPlayingCard(PlayingCardType id)
{
    return (sm_playingCards.contains(id) ? sm_playingCards[id] : 0);
}

const Card* Card::findRoleCard(PlayerRole id)
{
    return (sm_roleCards.contains(id) ? sm_roleCards[id] : 0);
}

const Card* Card::findCharacterCard(CharacterType id)
{
    return (sm_characterCards.contains(id) ? sm_characterCards[id] : 0);
}

QString Card::rankToString(CardRank rank)
{
    if (rank <= 9) {
        return QString::number(rank);
    } else if (rank == 10) {
        return "10";
    } else if (rank == 11) {
        return "J";
    } else if (rank == 12) {
        return "Q";
    } else if (rank == 13) {
        return "K";
    } else if (rank == 14) {
        return "A";
    }
    return "";
}

QChar Card::suitToChar(CardSuit suit)
{
    switch (suit) {
    case SUIT_CLUBS:    return 0x2663;
    case SUIT_DIAMONDS: return 0x2666;
    case SUIT_HEARTS:   return 0x2665;
    case SUIT_SPADES:   return 0x2660;
    case SUIT_INVALID:  return 0x0020;
    }
    NOT_REACHED();
    return QChar();
}

QColor Card::suitToColor(CardSuit suit)
{
    switch (suit) {
    case SUIT_CLUBS:    return Qt::black;
    case SUIT_DIAMONDS: return Qt::red;
    case SUIT_HEARTS:   return Qt::red;
    case SUIT_SPADES:   return Qt::black;
    case SUIT_INVALID:  return Qt::white;

    }
    NOT_REACHED();
    return QColor();
}

QString Card::suitToColorString(CardSuit suit)
{

    QString color;
    switch (suit) {
    case SUIT_CLUBS:
        color = "black";
        break;
    case SUIT_DIAMONDS:
        color = "red";
        break;
    case SUIT_HEARTS:
        color = "red";
        break;
    case SUIT_SPADES:
        color = "black";
        break;
    case SUIT_INVALID:
        color = "white";
        break;
    }
    return QString("<font color=\"%1\">%2</font>").arg(color).arg(suitToChar(suit));
}


void Card::loadPixmap()
{
    if (!m_image.load(Config::dataPathString() + m_imageFileName)) {
        qWarning(qPrintable(QString("Cannot load pixmap: %1").arg(Config::dataPathString() + m_imageFileName)));
    }
}
