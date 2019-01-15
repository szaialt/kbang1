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
#include "cardbang.h"
#include "player.h"
#include "gamecycle.h"
#include "gameexceptions.h"
#include "gametable.h"
#include "game.h"
#include "cardbarrel.h"
#include "gameeventmanager.h"

#include <iostream>

CardBang::CardBang(Game* game, int id, BangType type, CardSuit cardSuit, CardRank cardRank):
        ReactionCard(game, id, CARD_BANG, cardSuit, cardRank),
        mp_attackedPlayer(0)
{
    switch(type) {
    case Bang:
        setType(CARD_BANG);
        break;
    case DoubleBang:
        setType(CARD_DOUBLE_BANG);
        break;
    case Heavy:
        setType(CARD_HEAVY_BANG);
        break;
    default:
            NOT_REACHED();
    }
}


CardBang::~CardBang()
{ 
}

void CardBang::play(Player *targetPlayer)
{
    controlCard();
    controlTarget(targetPlayer);
    shot(targetPlayer);
}

    void CardBang::controlCard(){
            gameCycle()->assertTurn();
            assertInHand();

        /* one-bang-per-turn check */
        if ((!owner()->canPlayBang())){
            throw OneBangPerTurnException();
        }
    }
    
    void CardBang::controlTarget(Player *targetPlayer){
        
        /* don't allow shoot yourself */
        if (owner() == targetPlayer){
            throw BadTargetPlayerException();
        }
        if (targetPlayer == 0){
            throw BadTargetPlayerException();
        }
        /* distance check */
        if (game()->getDistance(owner(), targetPlayer) > owner()->weaponRange()){
            throw PlayerOutOfRangeException();
        }
        }
    
void CardBang::shot(Player *targetPlayer){
        if ((type() == CARD_BANG) || (type() == CARD_HEALING_BANG)){
            owner()->onBangPlayed(true);
        }
        mp_attackingPlayer = owner();
        gameTable()->playerPlayCard(this, targetPlayer);
        m_usedBarrels.clear();
        mp_attackedPlayer = targetPlayer;
        m_missedLeft = mp_attackingPlayer->bangPower();
        if (type() == CARD_HEAVY_BANG) m_missedLeft = 2;
        QList<PlayingCard*> table = mp_attackedPlayer->table();
        foreach (PlayingCard* card, table){
            if (card->type() == CARD_JARATE){
                m_missedLeft = 2;
            }
        }
        game()->gameCycle().setResponseMode(this, targetPlayer);
    }

void CardBang::respondPass()
{
    Q_ASSERT(mp_attackedPlayer != 0);
    gameCycle()->unsetResponseMode();
    gameTable()->playerPass(mp_attackedPlayer);
    bool injure = true;
    if (injure){
        if (type() == CARD_BANG){
            QList<PlayingCard*> table2 = mp_attackingPlayer->table();
            foreach (PlayingCard* card, table2){
                if (card->type() == CARD_HALF_ZATOCHI){
                    mp_attackingPlayer->modifyLifePoints(1, 0);
                }
                if (card->type() == CARD_SANDMAN){
                    injure = false;
                    QList<PlayingCard*> hand = mp_attackedPlayer->hand();
                    foreach (PlayingCard* card2, hand){
                        gameTable()->cancelCard(card2);   
                    }
                }
            }
        }
    }
    if (injure){
        if (type() == CARD_DOUBLE_BANG){
             mp_attackedPlayer->modifyLifePoints(-2, mp_attackingPlayer);
        }
        else {
           mp_attackedPlayer->modifyLifePoints(-1, mp_attackingPlayer);
        }
    }
}

void CardBang::respondCard(PlayingCard* targetCard)
{
    Player* player = targetCard->owner();
    //try{
    if (player == 0) {
        qDebug() << "CardBang::respondCard(PlayingCard* targetCard) target card owner is NULL";
        return;
    }
    if (mp_attackingPlayer == 0) {
        qDebug() << "CardBang::respondCard(PlayingCard* targetCard) mp_attackingPlayer is NULL";
        return;
    }
    switch(targetCard->type()) {
    case CARD_MISSED: 
        targetCard->assertInHand();
        game()->gameCycle().unsetResponseMode();
        gameTable()->playerRespondWithCard(targetCard);
        missed();
        return;
    case CARD_BARREL: {
        if (m_usedBarrels.contains(targetCard)){ 
            break;
        }
        targetCard->assertOnTable();
        m_usedBarrels.append(targetCard);
        CardBarrel* barrel = qobject_cast<CardBarrel*>(targetCard);
        barrel->check(this);
        return;
        }
    case CARD_DEAD_RINGER:
        targetCard->assertInHand();
        game()->gameCycle().unsetResponseMode();
        gameTable()->playerRespondWithCard(targetCard);
        missed();
        game()->gameCycle().setNeedsFinishTurn(true);
        return;
    default:
        break;
    }
    throw BadCardException();
//     }
//     catch (BadPlayerException ex){
//         if (type() == CARD_BACKFIRE){
//             qDebug() << "CARD_BACKFIRE: BadPlayerException caught.";
//         }
//         else {
//             qDebug() << "BadPlayerException.";
//             throw ex;
//         }
//     }
}

void CardBang::checkResult(bool result)
{
    if (result) {
        game()->gameCycle().unsetResponseMode();
        missed();
    }
}

void CardBang::missed()
{
    m_missedLeft--;
    if (m_missedLeft > 0) {
        game()->gameCycle().setResponseMode(this, mp_attackedPlayer);
    }

}


