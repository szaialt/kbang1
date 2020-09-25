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

#ifndef GAMEENUMS_H
#define GAMEENUMS_H

#include <QString>

/**
 * @deprecated
 */
enum ActionRequestType {
    REQUEST_DRAW,
    REQUEST_PLAY,
    REQUEST_RESPOND,
    REQUEST_DISCARD/*,
    REQUEST_CHOOSE_CHARACTERS,
    REQUEST_ORDER_CHARACTERS*/
};

enum PlayerRole {
    ROLE_INVALID = 0,
    ROLE_UNKNOWN,
    ROLE_SHERIFF,
    ROLE_DEPUTY,
    ROLE_OUTLAW,
    ROLE_RENEGADE
};

enum PocketType {
    POCKET_INVALID = 0,
    POCKET_DECK,
    POCKET_GRAVEYARD,
    POCKET_HAND,
    POCKET_TABLE,
    POCKET_SELECTION
};

enum SuitColor {
    SUIT_BLACK,
    SUIT_RED,
    SUIT_UNKNOWN
};

enum CardColor {
    COLOR_BLACK,
    COLOR_RED,
    COLOR_BROWN,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_GOLD,
    COLOR_SILVER,
    COLOR_YELLOW,
    COLOR_ORANGE,
    COLOR_VIOLET,
    COLOR_NEGATIVE_GREY, //Martin City negative grey
    COLOR_POSITIVE_GREY, //Martin City positive grey
    COLOR_DYNAMITE,
    COLOR_UNKNOWN
};

enum PlayingCardType {
    CARD_UNKNOWN = 0,
    CARD_BANG,
    CARD_MISSED,
    CARD_BEER,
    CARD_SALOON,
    CARD_WELLSFARGO,
    CARD_DILIGENZA,
    CARD_GENERALSTORE,
    CARD_PANIC,
    CARD_CATBALOU,
    CARD_INDIANS,
    CARD_DUEL,
    CARD_GATLING,
    CARD_MUSTANG,
    CARD_APPALOSSA,
    CARD_BARREL,
    CARD_DYNAMITE,
    CARD_JAIL,
    CARD_VOLCANIC,
    CARD_SCHOFIELD,
    CARD_REMINGTON,
    CARD_CARABINE,
    CARD_WINCHESTER,
    //Team Fortress
    CARD_ARSON,
    CARD_DIRECT_HIT,
    CARD_SUPPLY_CRATE,
    CARD_DEAD_RINGER,
    CARD_SANDVICH,
    CARD_MAD_MILK,
    CARD_MANN_VS_MACHINE,
    CARD_HEALING_BANG,
    CARD_HALF_ZATOCHI,
    CARD_MEDI_GUN,
    CARD_SANDMAN,
    CARD_GUITAR,
    CARD_TELEPORT,
    CARD_PERSUASION,
    CARD_JARATE,
    CARD_DOUBLE_BANG,
    CARD_HEAVY_BANG,
    //Director's Cuts
    CARD_ACE_UP_YOUR_SLEEVE,
    CARD_DEFLECTION,
    CARD_UNION_PACIFIC,
    CARD_HIDDEN_WEAPON,
    CARD_MEMENTO,
    CARD_PACKING_MULE,
    CARD_PEACE_PIPE,
    CARD_SHOTGUN,
    CARD_SUN_GLARE,
    //Martin City
    CARD_ELIXIR,
    CARD_EXPLOSION,
    CARD_FIRST_AID_KIT,
    CARD_KOMBO,
    CARD_DIRTY_JOB,
    CARD_KILLER,
    CARD_GOLDEN_BROWN,
    CARD_THUNDER,
    CARD_VEST,
    CARD_STUNNING,
    CARD_COWBOY_POCKET,
    CARD_GOLD_WATCH,
    CARD_INFLAMMATORY_BOTTLE,
    CARD_PRAYER,
    CARD_BLEEDING_INJURY,
    CARD_ADRENALINE,
    CARD_MEDICINES,
    CARD_STEROID,
    CARD_DRUGS,
    CARD_HEADACHE,
    CARD_MORPHINE,
    CARD_SHOCK,
    CARD_WEAKNESS,
    CARD_TRIPLE_BANG,
    CARD_QUAD_BANG,
    CARD_INDIAN_BANG,
    CARD_CHARM,
    CARD_UNDEFENSABLE,
    CARD_THIEF,
    CARD_STUNNING_BANG,
    CARD_GHOST,
    //Cusp of carabelli
    CARD_GREEN_FUR_TRADE,
    CARD_WAR_PARTY,
    CARD_PLUNDER,
    CARD_BAR_FIGHT,
    CARD_PILFER,
    CARD_ROULETTE,
    CARD_GREEN_ON_THE_HOUSE,
    CARD_BROWN_MOLOTOV_COCKTAIL,
    CARD_BROWN_INVESTMENT,
    CARD_BROWN_LOAN,
    CARD_ROB_GRAVE,
    CARD_BLOOD_PACT,
    CARD_BROWN_SHOW_TIME,
    CARD_BROWN_MOONSHINE,
    CARD_SHOWNDOWN,
    CARD_HATCHET,
    CARD_REWARD,
    CARD_GAMBLE,
    CARD_WALKER,
    CARD_PACK_MULE,
    CARD_BULLDOG_1,
    CARD_RICOCHET,
    CARD_HILL_TOP,
    CARD_TAKER_BANG,
    //Robber's Roost
    CARD_BULLDOG_2,
    CARD_JAMES_DOUGALL,
    CARD_CANNON,
    CARD_ARTILLERY,
    CARD_PURPLE_WARPATH,
    CARD_BACKFIRE,
    CARD_DODGE,
    CARD_EXTRA_BANG,
    CARD_DOUBLE_EXTRA_BANG,
    CARD_LELA_BANG,
    CARD_LELA_GATLING,
    // 20
    CARD_DOUBLE_PANIC,
    CARD_DOUBLE_CATBALOU

};

enum CharacterType {
    CHARACTER_UNKNOWN = 0,
    CHARACTER_BART_CASSIDY,
    CHARACTER_BLACK_JACK,
    CHARACTER_CALAMITY_JANET,
    CHARACTER_EL_GRINGO,
    CHARACTER_JESSE_JONES,
    CHARACTER_JOURDONNAIS,
    CHARACTER_KIT_CARLSON,
    CHARACTER_LUCKY_DUKE,
    CHARACTER_PAUL_REGRET,
    CHARACTER_PEDRO_RAMIREZ,
    CHARACTER_ROSE_DOOLAN,
    CHARACTER_SID_KETCHUM,
    CHARACTER_SLAB_THE_KILLER, 
    CHARACTER_SUZY_LAFAYETTE,
    CHARACTER_VULTURE_SAM,
    CHARACTER_WILLY_THE_KID,
    CHARACTER_UNKNOWN5,
    CHARACTER_COWBOY,
    //Team Fortress
    CHARACTER_DEMOMAN,
    CHARACTER_ENGINEER,
    CHARACTER_HEAVY,
    CHARACTER_MEDIC,
    CHARACTER_PYRO,
    CHARACTER_SCOUT,
    CHARACTER_SNIPER,
    CHARACTER_SOLDIER,
    CHARACTER_SPY,
    //Director's Cuts
    CHARACTER_CORONEL_MORTIMER,
    CHARACTER_DJANGO,
    CHARACTER_EMMA,
    CHARACTER_HERMANOS_ELDER,
    CHARACTER_HOWARD_HAWKS,
    CHARACTER_JOE,
    CHARACTER_JOHN_FORD,
    CHARACTER_LLANERO_SOLITARIO,
    CHARACTER_LOCO,
    CHARACTER_MAX_SAND,
    CHARACTER_PAT_GARRETT,
    CHARACTER_REV_JONATHAN_RUDD,
    CHARACTER_ROOSTER_COGBURN,
    CHARACTER_SARTANA,
    CHARACTER_SERGIO_LEONE,
    CHARACTER_TUCO_EL_FEO,
    CHARACTER_VIEJO_SIKES,
    CHARACTER_VIENNA,
    CHARACTER_WYATT_EARP,
    //Martin City
    CHARACTER_ERNEST_SALIVEN,
    CHARACTER_ERNEST_SALIVEN2,
    CHARACTER_EMIL_DOCAINE,
    CHARACTER_LADY_BURBOUN,
    CHARACTER_SAM_SCALPHUNTER,
    CHARACTER_CRAZY_BEAR,
    CHARACTER_TOMY_LEE_GHOST,
    CHARACTER_WHITE_WOLF,
    CHARACTER_CHARLES_BOGGEN,
    CHARACTER_JONATH_HEXX,
    CHARACTER_SAMUEL_MCGREGGOR,
    CHARACTER_MATTHEW_HELL,
    CHARACTER_SERGEANT_O_REILLY,
    CHARACTER_JIM_SCARECROW,
    CHARACTER_BILLY_LONGLIFE,
    CHARACTER_ANTONY_CARMA,
    CHARACTER_DAN_QUAKE,
    CHARACTER_RON_ROBBER,
    CHARACTER_SAMUEL_DIEHARD,
    //Cusp of Carabelli 
    CHARACTER_JAMES_DONAHOO,
    CHARACTER_GORDON_CHRISTENSEN,
    CHARACTER_JOEL_JANIS,
    CHARACTER_CAPT_W_CAROLL,
    CHARACTER_EDWARD_ANGLE,
    CHARACTER_AUNTIE_ANGELICI,
    CHARACTER_G_V_BLACK,
    CHARACTER_BUSHIDO_BILL,
    CHARACTER_CRAZY_SKULL,
    CHARACTER_WILLIAM_HARMAN,
    CHARACTER_CLOCKWORK,
    CHARACTER_EL_FANTASMA,
    CHARACTER_ADAM_MC_CORMICK,
    //Robbers Roost
    CHARACTER_CRAZY_WOLF,
    CHARACTER_TURD_FERGUSON,
    CHARACTER_LIL_SURE_SHOT,
    CHARACTER_FLINT_DIXON,
    CHARACTER_JOB_MUSHGROVE,
    CHARACTER_PORTER_ROCKWALL,
    CHARACTER_PAT_BARRETT,
    CHARACTER_JOHNNY_POPE,
    CHARACTER_QUEEN_ANNE,
    CHARACTER_JOSEY_BASSET,
    CHARACTER_EVA_PLACE,
    CHARACTER_LAURA_BILLION,
    CHARACTER_MAGGIE_MAE,
    CHARACTER_ANNE_ROGERS,
    CHARACTER_LELA_DEVERE,
    CHARACTER_JULIE_BULETTE,
    //Boot Hill
    CHARACTER_CAPT_BARRETT,
    CHARACTER_DALTON_GANG,
    CHARACTER_DYNAMITE_DICK,
    CHARACTER_JAREMY_BAILE,
    CHARACTER_JUAN_MIRANDA,
    CHARACTER_JUGDE_DREAD,
    CHARACTER_JULY_ANN_WINSLOW,
    CHARACTER_MATTHEW_HAZARD,
    CHARACTER_THARLEY_CALLUM,
    CHARACTER_WILL_PENNY,
    // 20
    CHARACTER_BUCKSHOT_ROBERTS,
    CHARACTER_CHOSING_THOMAS,
    CHARACTER_DAFNE_STAR,
    CHARACTER_DROSERA_ALBA,
    CHARACTER_FAST_FRANZ,
    CHARACTER_FELIPE_DELGADO,
    CHARACTER_GINGER_STAR,
    CHARACTER_GREEN_KATE_JANET,
    CHARACTER_HURTING_BOB,
    CHARACTER_JACK_BROWN,
    CHARACTER_JOHNNY_CLEM,
    CHARACTER_LINDA_VIVENDA,
    CHARACTER_OSCAR_RODRIGUEZ,
    CHARACTER_PEPITA_DUELITA,
    CHARACTER_RIDING_HORSE,
    CHARACTER_SLOBODAN_THE_KILLER,
    CHARACTER_STEVE_HYPNOTIC,
    CHARACTER_STONEWALL_JACKSON,
    CHARACTER_TONY_ARMED,
    CHARACTER_WILLIAM_LONGLEY
};

enum ReactionType {
    REACTION_NONE,
    REACTION_BANG,
    REACTION_GATLING,
    REACTION_INDIANS,
    REACTION_DUEL,
    REACTION_GENERALSTORE,
    REACTION_LASTSAVE,
    REACTION_LUCKYDUKE,
    REACTION_KITCARLSON,
    REACTION_HEALING_BANG,
    REACTION_TAKER_BANG
};

enum ClientType {
    CLIENT_PLAYER,
    CLIENT_SPECTATOR
};

enum CardSuit {
    SUIT_SPADES,
    SUIT_HEARTS,
    SUIT_DIAMONDS,
    SUIT_CLUBS,
    SUIT_INVALID
};

/**
 * Represents the rank of a card. Numeral ranks are represented with the
 * corresponding number, others are represented by following values:
 *  * jack  = 11,
 *  * queen = 12,
 *  * king  = 13,
 *  * ace   = 14
 * This represention allows convenient comparing.
 */
typedef int CardRank;

enum GamePlayState {
    GAMEPLAYSTATE_INVALID = 0,
    GAMEPLAYSTATE_DRAW,
    GAMEPLAYSTATE_TURN,
    GAMEPLAYSTATE_RESPONSE,
    GAMEPLAYSTATE_DISCARD,
//     GAMEPLAYSTATE_CHOOSE_CHARACTERS,
//     GAMEPLAYSTATE_ORDER_CHARACTERS
};

enum GameState {
    GAMESTATE_INVALID = 0,
    GAMESTATE_WAITINGFORPLAYERS,
    GAMESTATE_PLAYING,
    GAMESTATE_FINISHED
};


enum GameMessageType {
    GAMEMESSAGE_INVALID = 0,
    GAMEMESSAGE_GAMESTARTED,
    GAMEMESSAGE_GAMEFINISHED,
    GAMEMESSAGE_PLAYERDRAWFROMDECK,
    GAMEMESSAGE_PLAYERDRAWFROMGRAVEYARD,
    GAMEMESSAGE_PLAYERDISCARDCARD,
    GAMEMESSAGE_PLAYERPLAYCARD,
    GAMEMESSAGE_PLAYERRESPONDWITHCARD,
    GAMEMESSAGE_PLAYERPASS,
    GAMEMESSAGE_PLAYERPICKFROMSELECTION,
    GAMEMESSAGE_PLAYERCHECKDECK,
    GAMEMESSAGE_PLAYERSTEALCARD,
    GAMEMESSAGE_PLAYERCANCELCARD,
    GAMEMESSAGE_DECKREGENERATE,
    GAMEMESSAGE_PLAYERDIED,
};


CardSuit        stringToCardSuit(const QString& s);
QString         cardSuitToString(const CardSuit& suit);
CharacterType   stringToCharacterType(const QString& s);
QString         characterTypeToString(const CharacterType& t);
PlayingCardType stringToPlayingCardType(const QString& s);
QString         playingCardTypeToString(const PlayingCardType& c);
PlayerRole      stringToPlayerRole(const QString& s);
QString         playerRoleToString(const PlayerRole& r);
GamePlayState   stringToGamePlayState(const QString& s);
QString         gamePlayStateToString(const GamePlayState& s);
ReactionType    stringToReactionType(const QString& s);
QString         reactionTypeToString(const ReactionType& r);
PocketType      stringToPocketType(const QString& s);
QString         pocketTypeToString(const PocketType& p);
GameState       stringToGameState(const QString& s);
QString         gameStateToString(const GameState& s);
ClientType      stringToClientType(const QString& s);
QString         clientTypeToString(const ClientType& t);
GameMessageType stringToGameMessageType(const QString& s);
QString         gameMessageTypeToString(const GameMessageType& g);

#endif // GAMEENUMS_H
