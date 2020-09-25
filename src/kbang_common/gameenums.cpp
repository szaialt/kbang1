/***************************************************************************
 *   Copyright (C) 2009 by MacJariel                                       *
 *   MacJariel (at) gmail.com                                              *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
//  *   (at your option) any later version.                                  *
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
    
    //Director's Cuts
    if (s == "coronel mortimer") return CHARACTER_CORONEL_MORTIMER;
    if (s == "django")         return CHARACTER_DJANGO;
    if (s == "emma")           return CHARACTER_EMMA;
    if (s == "hermanos elder") return CHARACTER_HERMANOS_ELDER;
    if (s == "howard hawks")   return CHARACTER_HOWARD_HAWKS;
    if (s == "joe")            return CHARACTER_JOE;
    if (s == "john ford")      return CHARACTER_JOHN_FORD;
    if (s == "llanero solitario") return CHARACTER_LLANERO_SOLITARIO;
    if (s == "loco")           return CHARACTER_LOCO;
    if (s == "max sand")       return CHARACTER_MAX_SAND;
    if (s == "pat garrett")    return CHARACTER_PAT_GARRETT;
    if (s == "rev jonathan rudd") return CHARACTER_REV_JONATHAN_RUDD;
    if (s == "rooster cogburn") return CHARACTER_ROOSTER_COGBURN;
    if (s == "sartana")        return CHARACTER_SARTANA;
    if (s == "sergio leone")   return CHARACTER_SERGIO_LEONE;
    if (s == "tuco el feo")    return CHARACTER_TUCO_EL_FEO;
    if (s == "viejo sikes")    return CHARACTER_VIEJO_SIKES;
    if (s == "vienna")         return CHARACTER_VIENNA;
    if (s == "wyatt earp")     return CHARACTER_WYATT_EARP;
    
    //Martin City
    if (s == "ernest saliven") return CHARACTER_ERNEST_SALIVEN;
    if (s == "ernest saliven2") return CHARACTER_ERNEST_SALIVEN2;
    if (s == "emil docaine")   return CHARACTER_EMIL_DOCAINE;
    if (s == "lady burboun")   return CHARACTER_LADY_BURBOUN;
    if (s == "sam scalphunter") return CHARACTER_SAM_SCALPHUNTER;
    if (s == "crazy bear")     return CHARACTER_CRAZY_BEAR;
    if (s == "tomy lee ghost") return CHARACTER_TOMY_LEE_GHOST;
    if (s == "white wolf")     return CHARACTER_WHITE_WOLF;
    if (s ==  "charles boggen") return CHARACTER_CHARLES_BOGGEN;
    if (s == "jonath hexx")     return CHARACTER_JONATH_HEXX;
    if (s == "samuel mcgreggor") return CHARACTER_SAMUEL_MCGREGGOR;
    if (s == "matthew hell")   return CHARACTER_MATTHEW_HELL;
    if (s == "sergeant o reilly") return CHARACTER_SERGEANT_O_REILLY;
    if (s == "jim scarecrow")  return CHARACTER_JIM_SCARECROW;
    if (s == "billy longlife") return CHARACTER_BILLY_LONGLIFE;
    if (s == "antony carma")   return CHARACTER_ANTONY_CARMA;
    if (s == "dan quake")      return CHARACTER_DAN_QUAKE;
    if (s == "ron robber")     return CHARACTER_RON_ROBBER;
    if (s == "samuel diehard") return CHARACTER_SAMUEL_DIEHARD;
    //Cusp of Carabelli 
    if (s == "james donahoo")  return CHARACTER_JAMES_DONAHOO;
    if (s == "gordon christensen") return CHARACTER_GORDON_CHRISTENSEN;
    if (s == "joel janis")     return CHARACTER_JOEL_JANIS;
    if (s == "capt w caroll")  return CHARACTER_CAPT_W_CAROLL;
    if (s == "edward angle")   return CHARACTER_EDWARD_ANGLE;
    if (s == "auntie angelici") return CHARACTER_AUNTIE_ANGELICI;
    if (s == "g v black")      return CHARACTER_G_V_BLACK;
    if (s == "bushido bill")   return CHARACTER_BUSHIDO_BILL;
    if (s == "crazy skull")    return CHARACTER_CRAZY_SKULL;
    if (s == "william harman") return CHARACTER_WILLIAM_HARMAN;
    if (s == "clockwork")      return CHARACTER_CLOCKWORK;
    if (s == "el fantasma")    return CHARACTER_EL_FANTASMA;
    if (s == "adam mc cormick") return CHARACTER_ADAM_MC_CORMICK;
    //Robbers Roost
    if (s == "crazy wolf")     return CHARACTER_CRAZY_WOLF;
    if (s == "turd ferguson")  return CHARACTER_TURD_FERGUSON;
    if (s == "lil sure shot")  return CHARACTER_LIL_SURE_SHOT;
    if (s == "flint dixon")    return CHARACTER_FLINT_DIXON;
    if (s == "job mushgrove")  return CHARACTER_JOB_MUSHGROVE;
    if (s == "porter rockwall") return CHARACTER_PORTER_ROCKWALL;
    if (s == "pat barrett")    return CHARACTER_PAT_BARRETT;
    if (s == "johnny pope")    return CHARACTER_JOHNNY_POPE;
    if (s == "queen anne")     return CHARACTER_QUEEN_ANNE;
    if (s == "josey basset")   return CHARACTER_JOSEY_BASSET;
    if (s == "eva place")      return CHARACTER_EVA_PLACE;
    if (s == "laura billion")  return CHARACTER_LAURA_BILLION;
    if (s == "maggie mae")     return CHARACTER_MAGGIE_MAE;
    if (s == "anne rogers")    return CHARACTER_ANNE_ROGERS;
    if (s == "lela devere")    return CHARACTER_LELA_DEVERE;
    if (s == "julie bulette")  return CHARACTER_JULIE_BULETTE;
    //Boot Hill
    if (s == "capt barrett")   return CHARACTER_CAPT_BARRETT;
    if (s == "dalton gang")    return CHARACTER_DALTON_GANG;
    if (s == "dynamite dick")  return CHARACTER_DYNAMITE_DICK;
    if (s == "jaremy baile")   return CHARACTER_JAREMY_BAILE;
    if (s == "juan miranda")   return CHARACTER_JUAN_MIRANDA;
    if (s == "jugde dread")    return CHARACTER_JUGDE_DREAD;
    if (s == "july ann winslow") return CHARACTER_JULY_ANN_WINSLOW;
    if (s == "matthew hazard") return CHARACTER_MATTHEW_HAZARD;
    if (s == "tharley callum") return CHARACTER_THARLEY_CALLUM;
    if (s == "will penny")     return CHARACTER_WILL_PENNY;
    // 20 
    if (s == "buckshot roberts") return CHARACTER_BUCKSHOT_ROBERTS;
    if (s == "chosing thomas") return CHARACTER_CHOSING_THOMAS;
    if (s == "dafne star")     return CHARACTER_DAFNE_STAR;
    if (s == "drosera alba")   return CHARACTER_DROSERA_ALBA;
    if (s == "fast franz")     return CHARACTER_FAST_FRANZ;
    if (s == "felipe delgado") return CHARACTER_FELIPE_DELGADO;
    if (s == "ginger star")    return CHARACTER_GINGER_STAR;
    if (s == "green kate janet") return CHARACTER_GREEN_KATE_JANET;
    if (s == "hurting bob")    return CHARACTER_HURTING_BOB;
    if (s == "jack brown")     return CHARACTER_JACK_BROWN;
    if (s == "johnny clem")    return CHARACTER_JOHNNY_CLEM;
    if (s == "linda vivenda")  return CHARACTER_LINDA_VIVENDA;
    if (s == "oscar rodriguez") return CHARACTER_OSCAR_RODRIGUEZ;
    if (s == "pepita duelita") return CHARACTER_PEPITA_DUELITA;
    if (s == "riding horse")   return CHARACTER_RIDING_HORSE;
    if (s == "slobodan the killer") return CHARACTER_SLOBODAN_THE_KILLER;
    if (s == "steve hypnotic") return CHARACTER_STEVE_HYPNOTIC;
    if (s == "stonewall jackson") return CHARACTER_STONEWALL_JACKSON;
    if (s == "tony armed")     return CHARACTER_TONY_ARMED;
    if (s == "william longley") return CHARACTER_WILLIAM_LONGLEY;
    
    
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
    //Director's Cuts
    case CHARACTER_CORONEL_MORTIMER: return "coronel mortimer";
    case CHARACTER_DJANGO:          return "django";
    case CHARACTER_EMMA:            return "emma";
    case CHARACTER_HERMANOS_ELDER:  return "hermanos elder";
    case CHARACTER_HOWARD_HAWKS:    return "howard hawks";
    case CHARACTER_JOE:             return "joe";
    case CHARACTER_JOHN_FORD:       return "john ford";
    case CHARACTER_LLANERO_SOLITARIO:  return "llanero solitario";
    case CHARACTER_LOCO:            return "loco";
    case CHARACTER_MAX_SAND:        return "max sand";
    case CHARACTER_PAT_GARRETT:     return "pat garrett";
    case CHARACTER_REV_JONATHAN_RUDD:  return "rev jonathan rudd";
    case CHARACTER_ROOSTER_COGBURN:  return "rooster cogburn";
    case CHARACTER_SARTANA:         return "sartana";
    case CHARACTER_SERGIO_LEONE:    return "sergio leone";
    case CHARACTER_TUCO_EL_FEO:     return "tuco el feo";
    case CHARACTER_VIEJO_SIKES:     return "viejo sikes";
    case CHARACTER_VIENNA:          return "vienna";
    case CHARACTER_WYATT_EARP:      return "wyatt earp";
    //Martin City
    case CHARACTER_ERNEST_SALIVEN:  return "ernest saliven";
    case CHARACTER_ERNEST_SALIVEN2: return "ernest saliven2";
    case CHARACTER_EMIL_DOCAINE:    return "emil docaine";
    case CHARACTER_LADY_BURBOUN:    return "lady burboun";
    case CHARACTER_SAM_SCALPHUNTER: return "sam scalphunter";
    case CHARACTER_CRAZY_BEAR:      return "crazy bear";
    case CHARACTER_TOMY_LEE_GHOST:  return "tomy lee ghost";
    case CHARACTER_WHITE_WOLF:      return "white wolf";
    case CHARACTER_CHARLES_BOGGEN:  return "charles boggen";
    case CHARACTER_JONATH_HEXX:     return "jonath hexx";
    case CHARACTER_SAMUEL_MCGREGGOR: return "samuel mcgreggor";
    case CHARACTER_MATTHEW_HELL:    return "matthew hell";
    case CHARACTER_SERGEANT_O_REILLY: return "sergeant o reilly";
    case CHARACTER_JIM_SCARECROW:   return "jim scarecrow";
    case CHARACTER_BILLY_LONGLIFE:  return "billy longlife";
    case CHARACTER_ANTONY_CARMA:    return "antony carma";
    case CHARACTER_DAN_QUAKE:       return "dan quake";
    case CHARACTER_RON_ROBBER:      return "ron robber";
    case CHARACTER_SAMUEL_DIEHARD:  return "samuel diehard";
    //Cusp of Carabelli
    case CHARACTER_JAMES_DONAHOO:   return "james donahoo";
    case CHARACTER_GORDON_CHRISTENSEN: return "gordon christensen";
    case CHARACTER_JOEL_JANIS:      return "joel janis";
    case CHARACTER_CAPT_W_CAROLL:   return "capt w caroll";
    case CHARACTER_EDWARD_ANGLE:    return "edward angle";
    case CHARACTER_AUNTIE_ANGELICI: return "auntie angelici";
    case CHARACTER_G_V_BLACK:       return "g v black";
    case CHARACTER_BUSHIDO_BILL:    return "bushido bill";
    case CHARACTER_CRAZY_SKULL:     return "crazy skull";
    case CHARACTER_WILLIAM_HARMAN:  return  "william harman";
    case CHARACTER_CLOCKWORK:       return "clockwork";
    case CHARACTER_EL_FANTASMA:     return "el fantasma";
    case CHARACTER_ADAM_MC_CORMICK: return "adam mc cormick";
    //Robbers Roost
    case CHARACTER_CRAZY_WOLF:      return "crazy wolf";
    case CHARACTER_TURD_FERGUSON:   return "turd ferguson";
    case CHARACTER_LIL_SURE_SHOT:   return "lil sure shot";
    case CHARACTER_FLINT_DIXON:     return "flint dixon";
    case CHARACTER_JOB_MUSHGROVE:   return "job mushgrove";
    case CHARACTER_PORTER_ROCKWALL: return "porter rockwall";
    case CHARACTER_PAT_BARRETT:     return "pat barrett";
    case CHARACTER_JOHNNY_POPE:     return "johnny pope";
    case CHARACTER_QUEEN_ANNE:      return "queen anne";
    case CHARACTER_JOSEY_BASSET:    return "josey basset";
    case CHARACTER_EVA_PLACE:       return "eva place";
    case CHARACTER_LAURA_BILLION:   return "laura billion";
    case CHARACTER_MAGGIE_MAE:      return "maggie mae";
    case CHARACTER_ANNE_ROGERS:     return "anne rogers";
    case CHARACTER_LELA_DEVERE:     return "lela devere";
    case CHARACTER_JULIE_BULETTE:   return "julie bulette";
    
    //Boot Hill
    case CHARACTER_CAPT_BARRETT:    return "capt barrett";
    case CHARACTER_DALTON_GANG:     return "dalton gang";
    case CHARACTER_DYNAMITE_DICK:   return "dynamite dick";
    case CHARACTER_JAREMY_BAILE:    return "jaremy baile";
    case CHARACTER_JUAN_MIRANDA:    return "juan miranda";
    case CHARACTER_JUGDE_DREAD:     return "jugde dread";
    case CHARACTER_JULY_ANN_WINSLOW: return "july ann winslow";
    case CHARACTER_MATTHEW_HAZARD:  return "matthew hazard";
    case CHARACTER_THARLEY_CALLUM:  return "tharley callum";
    case CHARACTER_WILL_PENNY:      return "will penny";
    
    // 20 
    case CHARACTER_BUCKSHOT_ROBERTS: return "buckshot roberts";
    case CHARACTER_CHOSING_THOMAS:  return "chosing thomas";
    case CHARACTER_DAFNE_STAR:      return "dafne star";
    case CHARACTER_DROSERA_ALBA:    return "drosera alba";
    case CHARACTER_FAST_FRANZ:      return "fast franz";
    case CHARACTER_FELIPE_DELGADO:  return "felipe delgado";
    case CHARACTER_GINGER_STAR:     return "ginger star";
    case CHARACTER_GREEN_KATE_JANET: return "green kate janet";
    case CHARACTER_HURTING_BOB:     return "hurting bob";
    case CHARACTER_JACK_BROWN:      return "jack brown";
    case CHARACTER_JOHNNY_CLEM:     return "johnny clem";
    case CHARACTER_LINDA_VIVENDA:   return "linda vivenda";
    case CHARACTER_OSCAR_RODRIGUEZ: return "oscar rodriguez";
    case CHARACTER_PEPITA_DUELITA:  return "pepita duelita";
    case CHARACTER_RIDING_HORSE:    return "riding horse";
    case CHARACTER_SLOBODAN_THE_KILLER: return "slobodan the killer";
    case CHARACTER_STEVE_HYPNOTIC:  return "steve hypnotic";
    case CHARACTER_STONEWALL_JACKSON: return "stonewall jackson";
    case CHARACTER_TONY_ARMED:      return "tony armed";
    case CHARACTER_WILLIAM_LONGLEY: return "william longley";
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
    if (s == "negative grey") return COLOR_NEGATIVE_GREY;
    if (s == "positive grey") return COLOR_POSITIVE_GREY;
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
        case COLOR_NEGATIVE_GREY:   return "negative grey";
        case COLOR_POSITIVE_GREY:   return "positive grey";
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
    
    //Director's Cuts
     if (s == "ace_up_your_sleeve") return CARD_ACE_UP_YOUR_SLEEVE;
     if (s == "ace up your sleeve") return CARD_ACE_UP_YOUR_SLEEVE;
     if (s == "ace-up-your-sleeve") return CARD_ACE_UP_YOUR_SLEEVE;
     if (s == "deflection")         return CARD_DEFLECTION;
     if (s == "union_pacific")      return CARD_UNION_PACIFIC;
     if (s == "union pacific")      return CARD_UNION_PACIFIC;
     if (s == "union-pacific")      return CARD_UNION_PACIFIC;
     if (s == "hidden_weapon")      return CARD_HIDDEN_WEAPON;
     if (s == "hidden weapon")      return CARD_HIDDEN_WEAPON;
     if (s == "hidden-weapon")      return CARD_HIDDEN_WEAPON;
     if (s == "memento")            return CARD_MEMENTO;
     if (s == "packing_mule")       return CARD_PACKING_MULE;
     if (s == "packing mule")       return CARD_PACKING_MULE;
     if (s == "packing-mule")       return CARD_PACKING_MULE;
     if (s == "peace_pipe")         return CARD_PEACE_PIPE;
     if (s == "peace pipe")         return CARD_PEACE_PIPE;
     if (s == "peace-pipe")         return CARD_PEACE_PIPE;
     if (s == "shotgun")            return CARD_SHOTGUN;
     if (s == "sun_glare")          return CARD_SUN_GLARE;
     if (s == "sun glare")          return CARD_SUN_GLARE;
     if (s == "sun-glare")          return CARD_SUN_GLARE;
     
     //Martin City
    if (s == "elixir")              return CARD_ELIXIR;
    if (s == "explosion")           return CARD_EXPLOSION;
    if (s == "first_aid_kit")       return CARD_FIRST_AID_KIT;
    if (s == "first aid kit")       return CARD_FIRST_AID_KIT;
    if (s == "first-aid-kit")       return CARD_FIRST_AID_KIT;
    if (s == "kombo")               return CARD_KOMBO;
    if (s == "dirty_job")           return CARD_DIRTY_JOB;
    if (s == "dirty job")           return CARD_DIRTY_JOB;
    if (s == "dirty-job")           return CARD_DIRTY_JOB;
    if (s == "killer")              return CARD_KILLER;
    if (s == "golden_brown")        return CARD_GOLDEN_BROWN;
    if (s == "golden brown")        return CARD_GOLDEN_BROWN;
    if (s == "golden-brown")        return CARD_GOLDEN_BROWN;
    if (s == "thunder")             return CARD_THUNDER;
    if (s == "vest")                return CARD_VEST;
    if (s == "stunning")            return CARD_STUNNING;
    if (s == "cowboy_pocket")       return CARD_COWBOY_POCKET;
    if (s == "cowboy pocket")       return CARD_COWBOY_POCKET;
    if (s == "cowboy-pocket")       return CARD_COWBOY_POCKET;
    if (s == "gold_watch")          return CARD_GOLD_WATCH;
    if (s == "gold watch")          return CARD_GOLD_WATCH;
    if (s == "gold-watch")          return CARD_GOLD_WATCH;
    if (s == "inflammatory_bottle") return CARD_INFLAMMATORY_BOTTLE;
    if (s == "inflammatory bottle") return CARD_INFLAMMATORY_BOTTLE;
    if (s == "inflammatory-bottle") return CARD_INFLAMMATORY_BOTTLE;
    if (s == "prayer")              return CARD_PRAYER;
    if (s == "bleeding_injury")     return CARD_BLEEDING_INJURY;
    if (s == "bleeding injury")     return CARD_BLEEDING_INJURY;
    if (s == "bleeding-injury")     return CARD_BLEEDING_INJURY;
    if (s == "adrenaline")          return CARD_ADRENALINE;
    if (s == "medicines")           return CARD_MEDICINES;
    if (s == "steroid")             return CARD_STEROID;
    if (s == "drugs")               return CARD_DRUGS;
    if (s == "headache")            return CARD_HEADACHE;
    if (s == "morphine")            return CARD_MORPHINE;
    if (s == "shock")               return CARD_SHOCK;
    if (s == "weakness")            return CARD_WEAKNESS;
    if (s == "triple-bang")         return CARD_TRIPLE_BANG;
    if (s == "triple bang")         return CARD_TRIPLE_BANG;
    if (s == "triple_bang")         return CARD_TRIPLE_BANG;
    if (s == "quad-bang")           return CARD_QUAD_BANG;
    if (s == "quad bang")           return CARD_QUAD_BANG;
    if (s == "quad_bang")           return CARD_QUAD_BANG;
    if (s == "indian-bang")         return CARD_INDIAN_BANG;
    if (s == "indian bang")         return CARD_INDIAN_BANG;
    if (s == "indian_bang")         return CARD_INDIAN_BANG;
    if (s == "charm")               return CARD_CHARM;
    if (s == "undefensible-bang")   return CARD_UNDEFENSABLE;
    if (s == "undefensible bang")   return CARD_UNDEFENSABLE;
    if (s == "undefensible_bang")   return CARD_UNDEFENSABLE;
    if (s == "thief")               return CARD_THIEF;
    if (s == "stunning-bang")       return CARD_STUNNING_BANG;
    if (s == "stunning bang")       return CARD_STUNNING_BANG;
    if (s == "stunning_bang")       return CARD_STUNNING_BANG;
    //Cusp of carabelli
    if (s == "green_fur_trade")     return CARD_GREEN_FUR_TRADE;
    if (s == "green fur trade")     return CARD_GREEN_FUR_TRADE;
    if (s == "green-fur-trade")     return CARD_GREEN_FUR_TRADE;
    if (s == "war_party")           return CARD_WAR_PARTY;
    if (s == "war party")           return CARD_WAR_PARTY;
    if (s == "war-party")           return CARD_WAR_PARTY;
    if (s == "plunder")             return CARD_PLUNDER;
    if (s == "bar-fight")           return CARD_BAR_FIGHT;
    if (s == "bar fight")           return CARD_BAR_FIGHT;
    if (s == "bar_fight")           return CARD_BAR_FIGHT;
    if (s == "pilfer")              return CARD_PILFER;
    if (s == "roulette")            return CARD_ROULETTE;
    if (s == "green_on_the_house")  return CARD_GREEN_ON_THE_HOUSE;
    if (s == "green on the house")  return CARD_GREEN_ON_THE_HOUSE;
    if (s == "green-on-the-house")  return CARD_GREEN_ON_THE_HOUSE;
    if (s == "brown-molotov-cocktail") return CARD_BROWN_MOLOTOV_COCKTAIL;
    if (s == "brown molotov cocktail") return CARD_BROWN_MOLOTOV_COCKTAIL;
    if (s == "brown_molotov_cocktail") return CARD_BROWN_MOLOTOV_COCKTAIL;
    if (s == "brown_investment")    return CARD_BROWN_INVESTMENT;
    if (s == "brown investment")    return CARD_BROWN_INVESTMENT;
    if (s == "brown-investment")    return CARD_BROWN_INVESTMENT;
    if (s == "brown-loan")          return CARD_BROWN_LOAN;
    if (s == "brown loan")          return CARD_BROWN_LOAN;
    if (s == "brown_loan")          return CARD_BROWN_LOAN;
    if (s == "rob-grave")           return CARD_ROB_GRAVE;
    if (s == "rob grave")           return CARD_ROB_GRAVE;
    if (s == "rob_grave")           return CARD_ROB_GRAVE;
    if (s == "blood-pact")          return CARD_BLOOD_PACT;
    if (s == "blood pact")          return CARD_BLOOD_PACT;
    if (s == "blood_pact")          return CARD_BLOOD_PACT;
    if (s == "brown-show-time")     return CARD_BROWN_SHOW_TIME;
    if (s == "brown show time")     return CARD_BROWN_SHOW_TIME;
    if (s == "brown_show_time")     return CARD_BROWN_SHOW_TIME;
    if (s == "brown-moonshine")     return CARD_BROWN_MOONSHINE;
    if (s == "brown moonshine")     return CARD_BROWN_MOONSHINE;
    if (s == "brown_moonshine")     return CARD_BROWN_MOONSHINE;
    if (s == "showdown")            return CARD_SHOWNDOWN;
    if (s == "hatchet")             return CARD_HATCHET;
    if (s == "reward")              return CARD_REWARD;
    if (s == "gamble")              return CARD_GAMBLE;
    if (s == "walker")              return CARD_WALKER;
    if (s == "pack-mule")           return CARD_PACK_MULE;
    if (s == "pack_mule")           return CARD_PACK_MULE;
    if (s == "pack mule")           return CARD_PACK_MULE;
    if (s == "bulldog-1")           return CARD_BULLDOG_1;
    if (s == "bulldog 1")           return CARD_BULLDOG_1;
    if (s == "bulldog_1")           return CARD_BULLDOG_1;
    if (s == "ricochet")            return CARD_RICOCHET;
    if (s == "hill-top")            return CARD_HILL_TOP;
    if (s == "hill top")            return CARD_HILL_TOP;
    if (s == "hill_top")            return CARD_HILL_TOP;
    if (s == "card-taker-bang")     return CARD_TAKER_BANG;
    if (s == "card taker bang")     return CARD_TAKER_BANG;
    if (s == "card_taker_bang")     return CARD_TAKER_BANG;
    if (s == "ghost")               return CARD_GHOST;
    //Roober's roost
    if (s == "bulldog-2")           return CARD_BULLDOG_2;
    if (s == "bulldog 2")           return CARD_BULLDOG_2;
    if (s == "bulldog_2")           return CARD_BULLDOG_2;
    if (s == "james-dougall")       return CARD_JAMES_DOUGALL;
    if (s == "james dougall")       return CARD_JAMES_DOUGALL;
    if (s == "james_dougall")       return CARD_JAMES_DOUGALL;
    if (s == "cannon")              return CARD_CANNON;
    if (s == "artillery")           return CARD_ARTILLERY;
    if (s == "purple-warpath")      return CARD_PURPLE_WARPATH;
    if (s == "purple_warpath")      return CARD_PURPLE_WARPATH;
    if (s == "purple warpath")      return CARD_PURPLE_WARPATH;
    if (s == "dodge")               return CARD_DODGE;
    if (s == "backfire")            return CARD_BACKFIRE;
    if (s == "extra-bang")          return CARD_EXTRA_BANG;
    if (s == "extra bang")          return CARD_EXTRA_BANG;
    if (s == "extra_bang")          return CARD_EXTRA_BANG;
    if (s == "double-extra-bang")   return CARD_DOUBLE_EXTRA_BANG;
    if (s == "double extra bang")   return CARD_DOUBLE_EXTRA_BANG;
    if (s == "double_extra_bang")   return CARD_DOUBLE_EXTRA_BANG;
    if (s == "lela-bang")           return CARD_LELA_BANG;
    if (s == "lela bang")           return CARD_LELA_BANG;
    if (s == "lela_bang")           return CARD_LELA_BANG;
    if (s == "lela-gatling")        return CARD_LELA_GATLING;
    if (s == "lela gatling")        return CARD_LELA_GATLING;
    if (s == "lela_gatling")        return CARD_LELA_GATLING;
    if (s == "double-panic")        return CARD_DOUBLE_PANIC;
    if (s == "double panic")        return CARD_DOUBLE_PANIC;
    if (s == "double_panic")        return CARD_DOUBLE_PANIC;
    if (s == "double-catbalou")     return CARD_DOUBLE_CATBALOU;
    if (s == "double catbalou")     return CARD_DOUBLE_CATBALOU;
    if (s == "double_catbalou")     return CARD_DOUBLE_CATBALOU;
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
        //Director's Cuts
        case CARD_ACE_UP_YOUR_SLEEVE: return "ace up your sleeve";
        case CARD_DEFLECTION:      return "deflection";
        case CARD_UNION_PACIFIC:   return "union pacific";
        case CARD_HIDDEN_WEAPON:   return "hidden weapon";
        case CARD_MEMENTO:         return "memento";
        case CARD_PACKING_MULE:    return "packing mule";
        case CARD_PEACE_PIPE:      return "peace pipe";
        case CARD_SHOTGUN:         return "shotgun";
        case CARD_SUN_GLARE:       return "sun glare";
    
        //Martin City
        case CARD_ELIXIR:          return "elixir";
        case CARD_EXPLOSION:       return "explosion";
        case CARD_FIRST_AID_KIT:   return "first aid kit";
        case CARD_KOMBO:           return "kombo";
        case CARD_DIRTY_JOB:       return "dirty job";
        case CARD_KILLER:          return "killer";
        case CARD_GOLDEN_BROWN:    return "golden brown";
        case CARD_THUNDER:         return "thunder";
        case CARD_VEST:            return "vest";
        case CARD_STUNNING:        return "stunning";
        case CARD_COWBOY_POCKET:   return "cowboy pocket";
        case CARD_GOLD_WATCH:      return "gold watch";
        case CARD_INFLAMMATORY_BOTTLE: return "inflammatory bottle";
        case CARD_PRAYER:          return "prayer";
        case CARD_BLEEDING_INJURY: return "bleeding injury";
        case CARD_ADRENALINE:      return "adrenaline";
        case CARD_MEDICINES:       return "medicines";
        case CARD_STEROID:         return "steroid";
        case CARD_DRUGS:           return "drugs";
        case CARD_HEADACHE:        return "headache";
        case CARD_MORPHINE:        return "morphine";
        case CARD_SHOCK:           return "shock";
        case CARD_WEAKNESS:        return "weakness";
        case CARD_TRIPLE_BANG:     return "triple bang";
        case CARD_QUAD_BANG:       return "quad bang";
        case CARD_INDIAN_BANG:     return "indian bang";
        case CARD_CHARM:           return "charm";
        case CARD_UNDEFENSABLE:    return "undefensible bang";
        case CARD_THIEF:           return "thief";
        case CARD_STUNNING_BANG:   return "stunning bang";
        case CARD_GHOST:           return "ghost";
        //Cusp of carabelli
        case CARD_GREEN_FUR_TRADE: return "green fur trade";
        case CARD_WAR_PARTY:       return "war party";
        case CARD_PLUNDER:         return "plunder";
        case CARD_BAR_FIGHT:       return "bar fight";
        case CARD_PILFER:          return "pilfer";
        case CARD_ROULETTE:        return "roulette";
        case CARD_GREEN_ON_THE_HOUSE: return "green on the house";
        case CARD_BROWN_MOLOTOV_COCKTAIL: return "brown molotov cocktail";
        case CARD_BROWN_INVESTMENT:return "brown investment";
        case CARD_BROWN_LOAN:      return "brown loan";
        case CARD_ROB_GRAVE:       return "rob grave";
        case CARD_BLOOD_PACT:      return "blood pact";
        case CARD_BROWN_SHOW_TIME: return "brown show time";
        case CARD_BROWN_MOONSHINE: return "brown moonshine";
        case CARD_SHOWNDOWN:       return "showdown";
        case CARD_HATCHET:         return "hatchet";
        case CARD_REWARD:          return "reward";
        case CARD_GAMBLE:          return "gamble";
        case CARD_WALKER:          return "walker";
        case CARD_PACK_MULE:       return "pack mule";
        case CARD_BULLDOG_1:       return "bulldog 1";
        case CARD_RICOCHET:        return "ricochet";
        case CARD_HILL_TOP:        return "hill top";
        case CARD_TAKER_BANG:      return "card taker bang";
        //Robber's Roost
        case CARD_BULLDOG_2:       return "bulldog 2";
        case CARD_JAMES_DOUGALL:   return "james dougall";
        case CARD_CANNON:          return "cannon";
        case CARD_ARTILLERY:       return "artillery";
        case CARD_PURPLE_WARPATH:  return "purple warpath";
        case CARD_DODGE:           return "dodge";
        case CARD_BACKFIRE:        return "backfire";
        case CARD_EXTRA_BANG:      return "extra bang";
        case CARD_DOUBLE_EXTRA_BANG: return "double extra bang";
        case CARD_LELA_BANG:       return "lela bang";
        case CARD_LELA_GATLING:    return "lela gatling";
        // 20
        case CARD_DOUBLE_PANIC:    return "double panic";
        case CARD_DOUBLE_CATBALOU: return "double catbalou";
      
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
    if (s == "taker-bang")      return REACTION_TAKER_BANG;
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
    case REACTION_TAKER_BANG:   return "taker-bang";
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

