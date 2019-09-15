/***************************************************************************
 *   Copyright (C) 2009 by MacJariel                                       *
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
#ifndef PARSERSTRUCTS_H
#define PARSERSTRUCTS_H

#include "gameenums.h"

#include <QList>
#include <QImage>
#include <QXmlStreamWriter>

class XmlNode;

struct ServerInfoData
{
    QString name, description;
    void read(XmlNode*);
    void write(QXmlStreamWriter*) const;
    static QString elementName;
};

struct PlayerInfoData
{
    int     id;
    QString name;
    bool    hasPassword;
    bool    hasController;
    bool    isAI;
    bool    isAlive;
    void read(XmlNode*);
    void write(QXmlStreamWriter*) const;
    static QString elementName;
};

struct GameInfoData
{
    int id;
    QString name, description;
    int minPlayers, maxPlayers, maxSpectators;
    int alivePlayersCnt, totalPlayersCnt, spectatorsCnt, AIPlayersCnt;
//     int characterNumber;
//     bool characterChoice;
    bool hasPlayerPassword, hasSpectatorPassword;
    GameState state;
    QList<PlayerInfoData> players;
    void read(XmlNode*);
    void write(QXmlStreamWriter*) const;
    static QString elementName;
     bool lifePointsMaxFlag; 
     bool dodgeCityFlag;
     bool teamFortressFlag;
     bool ourFlag;
     bool stackingDynamiteFlag;
     bool teamFortressCharactersFlag;
     bool directorsCutsFlag;
     bool directorsCutsCharactersFlag;
     bool martinCityFlag;
     bool martinCityCharactersFlag;
     bool cuspOfCarabelliFlag;
     bool cuspOfCarabelliCharactersFlag;
     bool robberRoostFlag;
     bool robberRoostCharactersFlag;
     int aiLevel;

};

struct GameInfoListData: public QList<GameInfoData>
{
    void read(XmlNode*);
    void write(QXmlStreamWriter*) const;
    static QString elementName;
};

struct CreatePlayerData
{
    QString name, password;
    QImage avatar;
    void read(XmlNode*);
    void write(QXmlStreamWriter*) const;
    static QString elementName;
};

struct CreateGameData
{
    QString name, description; 
    int minPlayers, maxPlayers, maxSpectators, AIPlayers;
//     int characterNumber;
//     bool characterChoice;
    QString playerPassword, spectatorPassword;
    bool flagShufflePlayers;
      bool lifePointsMaxFlag;
      bool ourFlag;
      bool dodgeCityFlag; 
      bool teamFortressFlag;
      bool stackingDynamiteFlag;
      bool teamFortressCharactersFlag;
      bool directorsCutsFlag;
      bool directorsCutsCharactersFlag;
      bool martinCityFlag;
      bool martinCityCharactersFlag;
      bool cuspOfCarabelliFlag;
      bool cuspOfCarabelliCharactersFlag;
      bool robberRoostFlag;
      bool robberRoostCharactersFlag;
    void read(XmlNode*);
    void write(QXmlStreamWriter*) const;
    static QString elementName; 
    int aiLevel;
    
};

struct CardData {
    CardData(): id(0), type(CARD_UNKNOWN) {}
    int             id;
    PlayingCardType type;
    CardSuit        suit;
    CardRank        rank;
    bool            isAct;
    PocketType      pocket;
    void read(XmlNode*);
    void write(QXmlStreamWriter*) const;
    static QString elementName;
};

struct PublicPlayerData {
    int     id;
    QString name;

    bool    hasPassword;
    bool    hasController;
    bool    isAI;
    bool    isAlive;
    bool    isWinner;

    QImage avatar;
    CharacterType character;
    QList<CharacterType> characters;
    int lifePoints;
    bool isSheriff;
    int handSize;
    QList<CardData> table;
    PlayerRole role; // for dead players
    int countOfLivingPlayers;
    void read(XmlNode*);
    void write(QXmlStreamWriter*) const;
    static QString elementName;
};

struct PrivatePlayerData {
    int             id;
    PlayerRole      role;
    QList<CardData> hand;
    void read(XmlNode*);
    void write(QXmlStreamWriter*) const;
    static QString elementName;
};

struct GameContextData {
    int             currentPlayerId;
    int             requestedPlayerId;
    int             turnNumber;
    GamePlayState   gamePlayState;
    ReactionType    reactionType;
    int             causedBy;
    void read(XmlNode*);
    void write(QXmlStreamWriter*) const;
    static QString elementName;
};

struct GameSyncData {
    int                     id;
    QString                 name;
    bool                    isCreator;
    QList<PublicPlayerData> players;
    PrivatePlayerData       localPlayer;
    GameContextData         gameContext;
    GameState               state;
    CardData                graveyard;
    QList<CardData>         selection;
    void read(XmlNode*);
    void write(QXmlStreamWriter*) const;
    static QString elementName;
};

struct GameMessage {
    GameMessage(): type(GAMEMESSAGE_INVALID), player(0), targetPlayer(0), causedBy(0) {}
    GameMessageType type;
    int player;
    int targetPlayer;
    int causedBy;
    CardData card;
    CardData targetCard;
    QList<CardData> cards;
    bool checkResult;
    void read(XmlNode*);
    void write(QXmlStreamWriter*) const;
    static QString elementName;
};

struct CardMovementData {
    PocketType        pocketTypeFrom;
    PocketType        pocketTypeTo;
    int               playerFrom;
    int               playerTo;
    CardData          card;
    CardData          secondCard;
    void read(XmlNode*);
    void write(QXmlStreamWriter*) const;
    static QString elementName;
};

/**
 * @todo remove PLAYCARD_HAND, use PLAYCARD_PLAYER instead
 */
struct ActionPlayCardData {
    int playedCardId;
    enum {
        PLAYCARD_SIMPLE,    // card is played solo
        PLAYCARD_PLAYER,    // card is played with target player
        PLAYCARD_CARD,      // card is played with target (revealed) card
        PLAYCARD_HAND,       // card is played with target (unrevealed) card in opponent hands
        PLAYCARD_CARD_AND_PLAYER,
        PLAYCARD_CARDS,
        PLAYCARD_PLAYERS
    } type;
    int targetPlayerId;
    int targetCardId;
    int targetHandId;
    QList<int> targetCardsId;
    QList<int> targetPlayersId;
    void read(XmlNode*);
    void write(QXmlStreamWriter*) const;
    static QString elementName;
};

struct ActionUseAbilityData {
    enum {
        TypeSimple,
        TypePlayer,
        TypeCards,
        TypeCardsAndPLayer
    } type;
    int targetPlayerId;
    int targetCardId;
    QList<int> targetCardsId;
    QList<int> targetPlayerIds;
    void read(XmlNode*);
    void write(QXmlStreamWriter*) const;
    static QString elementName;
};

#endif
