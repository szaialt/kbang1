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
    new Card("Medi gun",  CARD_MEDI_GUN,       "gfx/cards/teamfortress/medi_gun.png" );
    new Card("Sandman",   CARD_SANDMAN,        "gfx/cards/teamfortress/sandman.png" );
    new Card("Guitar",    CARD_GUITAR,         "gfx/cards/teamfortress/guitar.png" );
    new Card("Teleport",  CARD_TELEPORT,       "gfx/cards/teamfortress/teleport.png" );
    new Card("Persuasion", CARD_PERSUASION,    "gfx/cards/teamfortress/persuasion.png" );
    new Card("Jarate",    CARD_JARATE,        "gfx/cards/teamfortress/jarate.png" );
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
    //Unknown card 
    new Card("",            CARD_UNKNOWN,    "gfx/cards/back-playing.png");

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
    new Card("Hermanos Elder",   CHARACTER_HERMANOS_ELDER,   "gfx/characters/directorscuts/hermanos-elder.jpg");
    new Card("Howard Hawks",     CHARACTER_HOWARD_HAWKS,     "gfx/characters/directorscuts/howard-hawks.jpg");
    new Card("Joe",              CHARACTER_JOE,              "gfx/characters/directorscuts/joe.jpg");
    new Card("John Ford",        CHARACTER_JOHN_FORD,        "gfx/characters/directorscuts/john-ford.jpg");
    new Card("Llanero Solitario", CHARACTER_LLANERO_SOLITARIO, "gfx/characters/directorscuts/llanero-solitario.jpg");
    new Card("Loco",            CHARACTER_LOCO,             "gfx/characters/directorscuts/loco.jpg");
    new Card("Max Sand",        CHARACTER_MAX_SAND,         "gfx/characters/directorscuts/max-sand.jpg");
    new Card("Pat Garrett",     CHARACTER_PAT_GARRETT,      "gfx/characters/directorscuts/pat-garrett.jpg");
    new Card("Rev Jonathan Rudd", CHARACTER_REV_JONATHAN_RUDD, "gfx/characters/directorscuts/rev-jonathan-rudd.jpg");
    new Card("Rooster Cogburn", CHARACTER_ROOSTER_COGBURN,  "gfx/characters/directorscuts/rooster-cogburn.jpg");
    new Card("Sartana",        CHARACTER_SARTANA,           "gfx/characters/directorscuts/sartana.jpg");
    new Card("Sergio Leone",   CHARACTER_SERGIO_LEONE,      "gfx/characters/directorscuts/sergio-leone.jpg");
    new Card("Tuco El Feo",    CHARACTER_TUCO_EL_FEO,       "gfx/characters/directorscuts/tuco-el-feo.jpg");
    new Card("Viejo Sikes",    CHARACTER_VIEJO_SIKES,       "gfx/characters/directorscuts/viejo-sikes.jpg");
    new Card("Vienna",         CHARACTER_VIENNA,            "gfx/characters/directorscuts/vienna.jpg");
    new Card("Wyatt Earp",     CHARACTER_WYATT_EARP,        "gfx/characters/directorscuts/wyatt-earp.jpg");
    
    
    
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
