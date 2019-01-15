/***************************************************************************
 *   Copyright (C) 2009 by MacJariel                                       *
 *   MacJariel (at) gmail.com                                              *
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

#include "gameenums.h"
#include "util.h"


CardSuit stringToCardSuit(const QString& s)
{
    if (s == "spades")      return SUIT_SPADES;
    if (s == "hearts")      return SUIT_HEARTS;
    if (s == "diamonds")    return SUIT_DIAMONDS;
    if (s == "clubs")       return SUIT_CLUBS;
    return SUIT_INVALID;
}

QString cardSuitToString(const CardSuit& suit)
{
    switch(suit) {
        case SUIT_SPADES:   return "spades";
        case SUIT_HEARTS:   return "hearts";
        case SUIT_DIAMONDS: return "diamonds";
        case SUIT_CLUBS:    return "clubs";
	case SUIT_INVALID:  return "invalid";
    }
    return "invalid";
}

CharacterType stringToCharacterType(const QString& s)
{
    if (s == "slab the killer") return CHARACTER_SLAB_THE_KILLER;
    if (s == "lucky duke")      return CHARACTER_LUCKY_DUKE;
    if (s == "suzy lafayette")  return CHARACTER_SUZY_LAFAYETTE;
    if (s == "vulture sam")     return CHARACTER_VULTURE_SAM;
    if (s == "black jack")      return CHARACTER_BLACK_JACK;
    if (s == "sid ketchum")     return CHARACTER_SID_KETCHUM;
    if (s == "jourdonnais")     return CHARACTER_JOURDONNAIS;
    if (s == "el gringo")       return CHARACTER_EL_GRINGO;
    if (s == "kit carlson")     return CHARACTER_KIT_CARLSON;
    if (s == "jesse jones")     return CHARACTER_JESSE_JONES;
    if (s == "pedro ramirez")   return CHARACTER_PEDRO_RAMIREZ;
    if (s == "calamity janet")  return CHARACTER_CALAMITY_JANET;
    if (s == "rose doolan")     return CHARACTER_ROSE_DOOLAN;
    if (s == "bart cassidy")    return CHARACTER_BART_CASSIDY;
    if (s == "paul regret")     return CHARACTER_PAUL_REGRET;
    if (s == "willy the kid")   return CHARACTER_WILLY_THE_KID;
    if (s == "cowboy")          return CHARACTER_COWBOY;
    if (s == "Five Life Point Back") return CHARACTER_UNKNOWN5;
    //Team Fortress
    if (s == "demoman")        return CHARACTER_DEMOMAN;
    if (s == "engineer")       return CHARACTER_ENGINEER;
    if (s == "heavy")          return CHARACTER_HEAVY;
    if (s == "medic")          return CHARACTER_MEDIC;
    if (s == "pyro")           return CHARACTER_PYRO;
    if (s == "scout")          return CHARACTER_SCOUT;
    if (s == "sniper")         return CHARACTER_SNIPER;
    if (s == "soldier")        return CHARACTER_SOLDIER;
    if (s == "spy")            return CHARACTER_SPY;
    return CHARACTER_UNKNOWN;
}

QString characterTypeToString(const CharacterType& t)
{
    switch(t) {
    case CHARACTER_UNKNOWN:         return "unknown";
    case CHARACTER_SLAB_THE_KILLER: return "slab the killer";
    case CHARACTER_LUCKY_DUKE:      return "lucky duke";
    case CHARACTER_SUZY_LAFAYETTE:  return "suzy lafayette";
    case CHARACTER_VULTURE_SAM:     return "vulture sam";
    case CHARACTER_BLACK_JACK:      return "black jack";
    case CHARACTER_SID_KETCHUM:     return "sid ketchum";
    case CHARACTER_JOURDONNAIS:     return "jourdonnais";
    case CHARACTER_EL_GRINGO:       return "el gringo";
    case CHARACTER_KIT_CARLSON:     return "kit carlson";
    case CHARACTER_JESSE_JONES:     return "jesse jones";
    case CHARACTER_PEDRO_RAMIREZ:   return "pedro ramirez";
    case CHARACTER_CALAMITY_JANET:  return "calamity janet";
    case CHARACTER_ROSE_DOOLAN:     return "rose doolan";
    case CHARACTER_BART_CASSIDY:    return "bart cassidy";
    case CHARACTER_PAUL_REGRET:     return "paul regret";
    case CHARACTER_WILLY_THE_KID:   return "willy the kid";
    case CHARACTER_COWBOY:          return "cowboy";
    case CHARACTER_UNKNOWN5:        return "Five Life Point Back";
    case CHARACTER_DEMOMAN:          return "demoman";
    case CHARACTER_ENGINEER:         return "engineer";
    case CHARACTER_HEAVY:            return "heavy";
    case CHARACTER_MEDIC:            return "medic";
    case CHARACTER_PYRO:             return "pyro";
    case CHARACTER_SCOUT:            return "scout";
    case CHARACTER_SNIPER:           return "sniper";
    case CHARACTER_SOLDIER:          return "soldier";
    case CHARACTER_SPY:              return "spy";
    }
    return "unknown";
}

SuitColor cardSuitToSuitColor(const CardSuit& suit)
{
    switch(suit) {
        case SUIT_SPADES:   return SUIT_BLACK;
        case SUIT_HEARTS:   return SUIT_RED;
        case SUIT_DIAMONDS: return SUIT_RED;
        case SUIT_CLUBS:    return SUIT_BLACK;
	    case SUIT_INVALID:  return SUIT_UNKNOWN;
    }
    return SUIT_UNKNOWN;
}

SuitColor stringToSuitColor(const QString& s)
{
    if (s == "red")        return SUIT_RED;
    if (s == "black")      return SUIT_BLACK;
    return SUIT_UNKNOWN;
}

QString suitColorToString(const SuitColor& suit)
{
    switch(suit) {
        case SUIT_RED:     return "red";
        case SUIT_BLACK:   return "black";
	case SUIT_UNKNOWN:     return "invalid";
    }
    return "invalid";
}

CardColor stringToCardColor(const QString& s){
    if (s == "black")     return COLOR_BLACK;
    if (s == "red")       return COLOR_RED;
    if (s == "brown")     return COLOR_BROWN;
    if (s == "blue")      return COLOR_BLUE;
    if (s == "green")     return COLOR_GREEN;
    if (s == "gold")      return COLOR_GOLD;
    if (s == "silver")    return COLOR_SILVER;
    if (s == "yellow")    return COLOR_YELLOW;
    if (s == "orange")    return COLOR_ORANGE;
    if (s == "violet")    return COLOR_VIOLET;
    if (s == "grey")      return COLOR_GREY;
    if (s == "dynamite")  return COLOR_DYNAMITE;
    return COLOR_UNKNOWN;
    
}

QString cardColorToString(const CardColor& c){
    
    switch(c) {
        case COLOR_BLACK:           return "black";
        case COLOR_RED:             return "red";
        case COLOR_BROWN:           return "brown";
        case COLOR_BLUE:            return "blue";
        case COLOR_GREEN:           return "green";
        case COLOR_GOLD:            return "gold";
        case COLOR_SILVER:          return "silver";
        case COLOR_YELLOW:          return "yellow";
        case COLOR_ORANGE:          return "orange";
        case COLOR_VIOLET:          return "violet";
        case COLOR_GREY:            return "grey";
        case COLOR_DYNAMITE:        return "dynamite";
        case COLOR_UNKNOWN:         return "";
    }
    return "";
}

PlayingCardType stringToPlayingCardType(const QString& s)
{
    if (s == "bang")             return CARD_BANG;
    if (s == "missed")           return CARD_MISSED;
    if (s == "beer")             return CARD_BEER;
    if (s == "saloon")           return CARD_SALOON;
    if (s == "wellsfargo")       return CARD_WELLSFARGO;
    if (s == "diligenza")        return CARD_DILIGENZA;
    if (s == "generalstore")     return CARD_GENERALSTORE;
    if (s == "panic")            return CARD_PANIC;
    if (s == "catbalou")         return CARD_CATBALOU;
    if (s == "indians")          return CARD_INDIANS;
    if (s == "duel")             return CARD_DUEL;
    if (s == "gatling")          return CARD_GATLING;
    if (s == "mustang")          return CARD_MUSTANG;
    if (s == "appalossa")        return CARD_APPALOSSA;
    if (s == "barrel")           return CARD_BARREL;
    if (s == "dynamite")         return CARD_DYNAMITE;
    if (s == "jail")             return CARD_JAIL;
    if (s == "volcanic")         return CARD_VOLCANIC;
    if (s == "schofield")        return CARD_SCHOFIELD;
    if (s == "remington")        return CARD_REMINGTON;
    if (s == "carabine")         return CARD_CARABINE;
    if (s == "winchester")       return CARD_WINCHESTER;
    //Team Fortress
    if (s == "arson")            return CARD_ARSON;
    if (s == "direct_hit")       return CARD_DIRECT_HIT;
    if (s == "direct hit")       return CARD_DIRECT_HIT;
    if (s == "direct-hit")       return CARD_DIRECT_HIT;
    if (s == "suppy_crate")      return CARD_SUPPLY_CRATE;
    if (s == "supply crate")     return CARD_SUPPLY_CRATE;
    if (s == "supply-crate")     return CARD_SUPPLY_CRATE;
    if (s == "dead_ringer")      return CARD_DEAD_RINGER;
    if (s == "dead ringer")      return CARD_DEAD_RINGER;
    if (s == "dead-ringer")      return CARD_DEAD_RINGER;
    if (s == "sandvich")         return CARD_SANDVICH;
    if (s == "mad_milk")         return CARD_MAD_MILK;
    if (s == "mad milk")         return CARD_MAD_MILK;
    if (s == "mad-milk")         return CARD_MAD_MILK;
    if (s == "man_vs_machine")   return CARD_MANN_VS_MACHINE;
    if (s == "man vs machine")   return CARD_MANN_VS_MACHINE;
    if (s == "man-vs-machine")   return CARD_MANN_VS_MACHINE;
    if (s == "healing-bang")     return CARD_HEALING_BANG;
    if (s == "healing_bang")     return CARD_HEALING_BANG;
    if (s == "healing bang")     return CARD_HEALING_BANG;
    if (s == "half_zatochi")     return CARD_HALF_ZATOCHI;
    if (s == "half zatochi")     return CARD_HALF_ZATOCHI;
    if (s == "half-zatochi")     return CARD_HALF_ZATOCHI;
    if (s == "medi_gun")         return CARD_MEDI_GUN;
    if (s == "medi gun")         return CARD_MEDI_GUN;
    if (s == "medi-gun")         return CARD_MEDI_GUN;
    if (s == "sandman")          return CARD_SANDMAN;
    if (s == "guitar")           return CARD_GUITAR;
    if (s == "teleport")         return CARD_TELEPORT;
    if (s == "persuasion")       return CARD_PERSUASION;
    if (s == "jarate")           return CARD_JARATE;
    if (s == "double-bang")      return CARD_DOUBLE_BANG;
    if (s == "double bang")      return CARD_DOUBLE_BANG;
    if (s == "double_bang")      return CARD_DOUBLE_BANG;
    if (s == "heavy-bang")       return CARD_HEAVY_BANG;
    if (s == "heavy bang")       return CARD_HEAVY_BANG;
    if (s == "heavy_bang")       return CARD_HEAVY_BANG;
    return CARD_UNKNOWN;
} 

QString playingCardTypeToString(const PlayingCardType& c)
{
    switch(c) {
        case CARD_BANG:           return "bang";
        case CARD_MISSED:         return "missed";
        case CARD_BEER:           return "beer";
        case CARD_SALOON:         return "saloon";
        case CARD_WELLSFARGO:     return "wellsfargo";
        case CARD_DILIGENZA:      return "diligenza";
        case CARD_GENERALSTORE:   return "generalstore";
        case CARD_PANIC:          return "panic";
        case CARD_CATBALOU:       return "catbalou";
        case CARD_INDIANS:        return "indians";
        case CARD_DUEL:           return "duel";
        case CARD_GATLING:        return "gatling";
        case CARD_MUSTANG:        return "mustang";
        case CARD_APPALOSSA:      return "appalossa";
        case CARD_BARREL:         return "barrel";
        case CARD_DYNAMITE:       return "dynamite";
        case CARD_JAIL:           return "jail";
        case CARD_VOLCANIC:       return "volcanic";
        case CARD_SCHOFIELD:      return "schofield";
        case CARD_REMINGTON:      return "remington";
        case CARD_CARABINE:       return "carabine";
        case CARD_WINCHESTER:     return "winchester";
        //Team Fortress
        case CARD_ARSON:           return "arson";
        case CARD_DIRECT_HIT:      return "direct hit";
        case CARD_SUPPLY_CRATE:    return "supply crate";
        case CARD_DEAD_RINGER:     return "dead ringer";
        case CARD_SANDVICH:        return "sandvich";
        case CARD_MAD_MILK:        return "mad milk";
        case CARD_MANN_VS_MACHINE: return "man vs machine";
        case CARD_HEALING_BANG:    return "healing bang";
        case CARD_HALF_ZATOCHI:    return "half zatochi";
        case CARD_MEDI_GUN:        return "medi gun";
        case CARD_SANDMAN:         return "sandman";
        case CARD_GUITAR:          return "guitar";
        case CARD_TELEPORT:        return "teleport";
        case CARD_PERSUASION:      return "persuasion";
        case CARD_JARATE:          return "jarate";
        case CARD_DOUBLE_BANG:     return "double bang";
        case CARD_HEAVY_BANG:      return "heavy bang";
        //Unknown
        case CARD_UNKNOWN:        return "";
    }
    return "";
}

PlayerRole stringToPlayerRole(const QString& s)
{
    if (s == "unknown")  return ROLE_UNKNOWN;
    if (s == "outlaw")   return ROLE_OUTLAW;
    if (s == "deputy")   return ROLE_DEPUTY;
    if (s == "sheriff")  return ROLE_SHERIFF;
    if (s == "renegade") return ROLE_RENEGADE;
    return ROLE_INVALID;
}

QString playerRoleToString(const PlayerRole& r)
{
    if (r == ROLE_UNKNOWN)  return "unknown";
    if (r == ROLE_OUTLAW)   return "outlaw";
    if (r == ROLE_DEPUTY)   return "deputy";
    if (r == ROLE_SHERIFF)  return "sheriff";
    if (r == ROLE_RENEGADE) return "renegade";
    if (r == ROLE_INVALID)  return "invalid";
    NOT_REACHED();
    return "invalid";
}


GamePlayState stringToGamePlayState(const QString& s)
{
    if (s == "draw")     return GAMEPLAYSTATE_DRAW;
    if (s == "turn")     return GAMEPLAYSTATE_TURN;
    if (s == "response") return GAMEPLAYSTATE_RESPONSE;
    if (s == "discard")  return GAMEPLAYSTATE_DISCARD;
    return GAMEPLAYSTATE_INVALID;
}

QString gamePlayStateToString(const GamePlayState& s)
{
    if (s == GAMEPLAYSTATE_DRAW)     return "draw";
    if (s == GAMEPLAYSTATE_TURN)     return "turn";
    if (s == GAMEPLAYSTATE_RESPONSE) return "response";
    if (s == GAMEPLAYSTATE_DISCARD)  return "discard";
    if (s == GAMEPLAYSTATE_INVALID)  return "invalid";
    NOT_REACHED();
    return "invalid";
}

ReactionType stringToReactionType(const QString& s)
{
    if (s == "bang")            return REACTION_BANG;
    if (s == "gatling")         return REACTION_GATLING;
    if (s == "indians")         return REACTION_INDIANS;
    if (s == "duel")            return REACTION_DUEL;
    if (s == "general-store")   return REACTION_GENERALSTORE;
    if (s == "last-save")       return REACTION_LASTSAVE;
    if (s == "lucky-duke")      return REACTION_LUCKYDUKE;
    if (s == "kit-carlson")     return REACTION_KITCARLSON;
    if (s == "healing-bang")    return REACTION_HEALING_BANG;
    return REACTION_NONE;
}

QString reactionTypeToString(const ReactionType& r)
{
    switch(r) {
    case REACTION_BANG:         return "bang";
    case REACTION_GATLING:      return "gatling";
    case REACTION_INDIANS:      return "indians";
    case REACTION_DUEL:         return "duel";
    case REACTION_GENERALSTORE: return "general-store";
    case REACTION_LASTSAVE:     return "last-save";
    case REACTION_LUCKYDUKE:    return "lucky-duke";
    case REACTION_KITCARLSON:   return "kit-carlson";
    case REACTION_HEALING_BANG: return "healing-bang";
    case REACTION_NONE:         return "";
    }
    return "";
}

PocketType stringToPocketType(const QString& s)
{
    if (s == "deck")      return POCKET_DECK;
    if (s == "graveyard") return POCKET_GRAVEYARD;
    if (s == "hand")      return POCKET_HAND;
    if (s == "table")     return POCKET_TABLE;
    if (s == "selection") return POCKET_SELECTION;
    return POCKET_INVALID;
}

QString pocketTypeToString(const PocketType& p)
{
    if (p == POCKET_DECK)       return "deck";
    if (p == POCKET_GRAVEYARD)  return "graveyard";
    if (p == POCKET_HAND)       return "hand";
    if (p == POCKET_TABLE)      return "table";
    if (p == POCKET_SELECTION)  return "selection";
    return "";
}


GameState stringToGameState(const QString& s)
{
    if (s == "WaitingForPlayers")   return GAMESTATE_WAITINGFORPLAYERS;
    if (s == "Playing")             return GAMESTATE_PLAYING;
    if (s == "Finished")            return GAMESTATE_FINISHED;
    return GAMESTATE_INVALID;
}

QString gameStateToString(const GameState& s)
{
    switch(s) {
    case GAMESTATE_WAITINGFORPLAYERS:   return "WaitingForPlayers";
    case GAMESTATE_PLAYING:             return "Playing";
    case GAMESTATE_FINISHED:            return "Finished";
    default:                            break;
    }
    return "Invalid";
}

ClientType stringToClientType(const QString& s) {
    if (s == "player") return CLIENT_PLAYER;
    else return CLIENT_SPECTATOR;
}

QString clientTypeToString(const ClientType& t) {
    switch(t) {
    case CLIENT_PLAYER:     return "player";
    case CLIENT_SPECTATOR:  return "spectator";
    }
    return "";
}

GameMessageType stringToGameMessageType(const QString& s) {
    if (s == "game-started")                return GAMEMESSAGE_GAMESTARTED;
    if (s == "game-finished")               return GAMEMESSAGE_GAMEFINISHED;
    if (s == "player-draw-from-deck")       return GAMEMESSAGE_PLAYERDRAWFROMDECK;
    if (s == "player-draw-from-graveyard")  return GAMEMESSAGE_PLAYERDRAWFROMGRAVEYARD;
    if (s == "player-discard-card")         return GAMEMESSAGE_PLAYERDISCARDCARD;
    if (s == "player-play-card")            return GAMEMESSAGE_PLAYERPLAYCARD;
    if (s == "player-respond-with-card")    return GAMEMESSAGE_PLAYERRESPONDWITHCARD;
    if (s == "player-pass")                 return GAMEMESSAGE_PLAYERPASS;
    if (s == "player-pick-from-selection")  return GAMEMESSAGE_PLAYERPICKFROMSELECTION;
    if (s == "player-check-deck")           return GAMEMESSAGE_PLAYERCHECKDECK;
    if (s == "player-steal-card")           return GAMEMESSAGE_PLAYERSTEALCARD;
    if (s == "player-cancel-card")          return GAMEMESSAGE_PLAYERCANCELCARD;
    if (s == "deck-regenerate")             return GAMEMESSAGE_DECKREGENERATE;
    if (s == "player-died")                 return GAMEMESSAGE_PLAYERDIED;
    return GAMEMESSAGE_INVALID;
}

QString gameMessageTypeToString(const GameMessageType& g) {
    switch(g) {
    case GAMEMESSAGE_GAMESTARTED:               return "game-started";
    case GAMEMESSAGE_GAMEFINISHED:              return "game-finished";
    case GAMEMESSAGE_PLAYERDRAWFROMDECK:        return "player-draw-from-deck";
    case GAMEMESSAGE_PLAYERDRAWFROMGRAVEYARD:   return "player-draw-from-graveyard";
    case GAMEMESSAGE_PLAYERDISCARDCARD:         return "player-discard-card";
    case GAMEMESSAGE_PLAYERPLAYCARD:            return "player-play-card";
    case GAMEMESSAGE_PLAYERRESPONDWITHCARD:     return "player-respond-with-card";
    case GAMEMESSAGE_PLAYERPASS:                return "player-pass";
    case GAMEMESSAGE_PLAYERPICKFROMSELECTION:   return "player-pick-from-selection";
    case GAMEMESSAGE_PLAYERCHECKDECK:           return "player-check-deck";
    case GAMEMESSAGE_PLAYERSTEALCARD:           return "player-steal-card";
    case GAMEMESSAGE_PLAYERCANCELCARD:          return "player-cancel-card";
    case GAMEMESSAGE_DECKREGENERATE:            return "deck-regenerate";
    case GAMEMESSAGE_PLAYERDIED:                return "player-died";
    case GAMEMESSAGE_INVALID:                   return "";
    }
    return "";
}
