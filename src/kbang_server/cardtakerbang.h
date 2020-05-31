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
#ifndef CARDTAKERBANG_H
#define CARDTAKERBANG_H

#include "reactioncard.h"
#include "checkdeckresulthandler.h"

class Player;

class CardTakerBang: public ReactionCard {

public:
    enum Type { 
        Ranic,
        Lela
    };
    CardTakerBang(Game *game, int id, Type type, CardSuit, CardRank);
    ~CardTakerBang(); 

    virtual void play(PlayingCard* targetCard);
    virtual ReactionType reactionType() const { return REACTION_TAKER_BANG; }
    virtual Player* causedBy() const { return mp_attackingPlayer; }
    virtual void respondPass();
    virtual void respondCard(PlayingCard* targetCard);
protected:
    virtual void missed();

    Player* mp_attackingPlayer;
    PlayingCard* mp_attackedCard;

};

#endif
