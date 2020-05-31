/***************************************************************************
 *   Copyright (C) 2008 by MacJariel                                       *
 *   echo "badmailet@gbalt.dob" | tr "edibmlt" "ecrmjil"                   *
 *                                                                          *
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
#include "cardmissed.h"
#include "gametable.h"

CardMissed::CardMissed(Game* game, int id, MissedType type, CardSuit cardSuit, CardRank cardRank):
        PlayingCard(game, id, CARD_MISSED, cardSuit, cardRank)
{
    switch(type) {
    case Missed:
        setType(CARD_MISSED);
        break;
    case DeadRinger:
        setType(CARD_DEAD_RINGER);
    case Vest:
        setType(CARD_VEST); 
        break; 
    case Dodge:
        setType(CARD_DODGE);
        break; 
    default:
            NOT_REACHED();
    }
}

CardMissed::~CardMissed() 
{
}

CardColor CardMissed::color() const {
    if (type() == CARD_VEST)
    return COLOR_BLUE;
    return COLOR_BROWN;
}

void CardMissed::play()
{
    gameCycle()->assertTurn();
    if ((color() == COLOR_GREEN) && (pocket() == POCKET_HAND)) {
        playAsGreenCard();
    }
    if ((color() == COLOR_BLUE) && (pocket() == POCKET_HAND)) {
        playAsBlueCard();
//         if (pocket() == POCKET_HAND){
//             owner()->removeCardFromHand(this);
//             setPocket(POCKET_TABLE);
//         }
    }
    else {
        throw BadUsageException();
    }
}


