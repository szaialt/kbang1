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

#include "cardtakerbang.h"
#include "gametable.h"

CardTakerBang::CardTakerBang(Game* game, int id, CardSuit cardSuit, CardRank cardRank):
        ReactionCard(game, id, CARD_TAKER_BANG, cardSuit, cardRank)
{

}

CardTakerBang::~CardTakerBang()
{ 
}

void CardTakerBang::play(PlayingCard* targetCard){
    if (targetCard == 0) {
        return;
    }
    mp_attackingPlayer = owner();
    mp_attackedCard = targetCard;
    Player* targetPlayer = targetCard->owner();
    if (targetPlayer == 0) {
        return;
    }
    gameTable()->playerPlayCard(this, targetPlayer);
    game()->gameCycle().setResponseMode(this, targetPlayer);
}

void CardTakerBang::respondPass(){
    gameTable()->cancelCard(mp_attackedCard, mp_attackingPlayer);
}

void CardTakerBang::respondCard(PlayingCard* targetCard){
    if (targetCard == 0) {
        return;
    }
    Player* player = targetCard->owner();
    if (player == 0) {
        return;
    }
    if (mp_attackingPlayer == 0) {
        return;
    }
    Player* targetPlayer = targetCard->owner();
    switch(targetCard->type()) {
        case CARD_MISSED: 
            game()->gameCycle().unsetResponseMode();
            gameTable()->playerRespondWithCard(targetCard);
            missed();
            return;
        default:{
            QList<PlayingCard*> table = targetPlayer->table();
            foreach (PlayingCard* card, table){
                if (card->type() == CARD_STEROID){
                    game()->gameCycle().unsetResponseMode();
                    gameTable()->playerRespondWithCard(targetCard);
                    missed();
                    return;
                }
            }
        }
    }
}

void CardTakerBang::missed(){
    gameCycle()->unsetResponseMode();
}
