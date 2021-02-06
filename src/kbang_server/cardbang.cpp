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
#include "util.h"
#include "charactercrazybear.h"
#include "characterambidexterbo.h"
#include "charactercolinbarrel.h"

#include <iostream>

class CharacterTedRevenge;

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
    case Deflection:
        setType(CARD_DEFLECTION);
        break;
    case TripleBang:
        setType(CARD_TRIPLE_BANG);
        break;
    case QuadBang:
        setType(CARD_QUAD_BANG);
        break;
    case Hawks:
        setType(CARD_HAWKS);
        break;
    case IndianBang:
        setType(CARD_INDIAN_BANG);
        break;
    case Undefensable:
        setType(CARD_UNDEFENSABLE);
        break;
    case Stunning:
        setType(CARD_STUNNING_BANG);
        break;
    case Hatchet:
        setType(CARD_HATCHET);
        break;
    case Ricochet:
        setType(CARD_RICOCHET);
        break;
    case Backfire:
        setType(CARD_BACKFIRE);
        break;
    case Extra:
        setType(CARD_EXTRA_BANG);
        break;
    case DoubleExtra:
       setType(CARD_DOUBLE_EXTRA_BANG);
       break;
     case NoHurtingBang:
        setType(CARD_NO_HURTING_BANG);
        break;
    case Revenge:
        setType(CARD_REVENGE);
        break;
    default:
            NOT_REACHED();
    }
}


CardBang::~CardBang()
{ 
}

CardColor CardBang::color() const{
    if (type() == CARD_HATCHET) return COLOR_GREEN;
    if (type() == CARD_RICOCHET) return COLOR_GREEN;
    return COLOR_BROWN;
}

void CardBang::play(QList<Player*> targetPlayers){
    if (type() == CARD_DOUBLE_EXTRA_BANG){
        if (targetPlayers.size() < 2) throw BadUsageException();
        PlayingCard* bang1 = new CardBang(owner()->game(), -1, CardBang::Bang, SUIT_INVALID, 5);
                                     bang1->setVirtual(owner(), POCKET_HAND);
        PlayingCard* bang2 = new CardBang(owner()->game(), -1, CardBang::Extra, SUIT_INVALID, 5);
                                     bang2->setVirtual(owner(), POCKET_HAND);
        bang1->play(targetPlayers.at(0));
        bang2->play(targetPlayers.at(1));
    }
    else {
        throw BadUsageException();
    } 
}

void CardBang::play(){
    if ((color() == COLOR_GREEN) && (pocket() == POCKET_HAND)){
        playAsBlueCard();
    }
    else {
        throw BadUsageException();
    } 

}

void CardBang::play(Player *targetPlayer)
{
    if (type() == CARD_NO_HURTING_BANG){
        gameTable()->playerPlayCard(this, targetPlayer);
        return;
    }
    if ((type() == CARD_DEFLECTION) || (type() == CARD_RICOCHET)){
        controlTarget(targetPlayer);
        shot(targetPlayer);
        return;
    }
    else if ((type() == CARD_BACKFIRE) || (type() == CARD_REVENGE)) {
        shot(targetPlayer);
        return;
    }
    controlCard();
    if ((color() == COLOR_BROWN) || ((pocket() == POCKET_TABLE) && isAct())){
        if (!((owner()->characterType() == CHARACTER_CORONEL_MORTIMER) && (suit() == SUIT_DIAMONDS) && (type() == CARD_BANG))){
            controlTarget(targetPlayer);
        }
        if ((owner()->isCharmed())){
            controlTarget(targetPlayer);
        }
    shot(targetPlayer);
    }
}

    void CardBang::controlCard(){
        gameCycle()->assertTurn();
        if (color() != COLOR_BROWN){
            assertOnTable();
        }
        /* one-bang-per-turn check */
        if ((type() != CARD_HAWKS) && (!owner()->canPlayBang())){
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
        if (type() == CARD_DEFLECTION){
            int deflectionDistance = 1;
            if (game()->getDistance(owner(), targetPlayer) > deflectionDistance)
                throw PlayerOutOfRangeException();
        }
        if (type() == CARD_HAWKS){
            int hawksDistance = 1;
            if (game()->getDistance(owner(), targetPlayer) > hawksDistance)
                throw PlayerOutOfRangeException();
        }
        else if (type() == CARD_HATCHET){
            int hatchetDistance = 2;
            if (game()->getDistance(owner(), targetPlayer) > hatchetDistance)
                throw PlayerOutOfRangeException();
        }
        else if (game()->getDistance(owner(), targetPlayer) > owner()->weaponRange()){
            throw PlayerOutOfRangeException();
        }
        
    }
    
void CardBang::shot(Player *targetPlayer){
        if (type() == CARD_BANG) {
            if (owner()->characterType() == CHARACTER_AMBIDEXTER_BO){
                CharacterAmbidexterBo* bo =  qobject_cast<CharacterAmbidexterBo*>(owner()->character());
                if (bo->targetedPlayer() == targetPlayer) throw BadTargetPlayerException();
                bo->setTargetedPlayer(targetPlayer);
          }
      }
        if (oneTimeBang()){
            owner()->onBangPlayed(true);
        }
        mp_attackingPlayer = owner();
        gameTable()->playerPlayCard(this, targetPlayer);
        m_usedBarrels.clear();
        mp_attackedPlayer = targetPlayer;
        m_missedLeft = mp_attackingPlayer->bangPower();
        if (mp_attackingPlayer->characterType() == CHARACTER_CRAZY_BEAR){
            CharacterCrazyBear* bear = qobject_cast<CharacterCrazyBear*>(mp_attackingPlayer);
            if (bear != 0) {
                 int injury = bear->injury();
                 if (injury > 1) m_missedLeft = injury;
            }
        }
        if (type() == CARD_HEAVY_BANG) m_missedLeft = 2;
        QList<PlayingCard*> table = mp_attackedPlayer->table();
        foreach (PlayingCard* card, table){
            if (card->type() == CARD_JARATE){
                m_missedLeft = 2;
            }
        }
        QList<PlayingCard*> table2 = mp_attackingPlayer->table();
        foreach (PlayingCard* card, table2){
            if ((card->type() == CARD_SHOTGUN) || (card->type() == CARD_WALKER)){
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
    if (type() == CARD_STUNNING_BANG){
        injure = false;
        mp_attackedPlayer->charm();
    }
    if (injure){
        if ((type() == CARD_BANG) || (type() == CARD_EXTRA_BANG)){
            QList<PlayingCard*> table2 = mp_attackingPlayer->table();
            foreach (PlayingCard* card, table2){
                if (card->type() == CARD_HALF_ZATOCHI){
                    mp_attackingPlayer->modifyLifePoints(1, 0);
                }
                 if (mp_attackingPlayer->characterType() == CHARACTER_EMMA){
                     gameTable()->playerDrawFromDeck(mp_attackingPlayer, 1, 0);
                }
                if (mp_attackingPlayer->characterType() == CHARACTER_HURTING_BOB){
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
        else if (type() == CARD_TRIPLE_BANG){
             mp_attackedPlayer->modifyLifePoints(-3, mp_attackingPlayer);
        }
        else if (type() == CARD_QUAD_BANG){
             mp_attackedPlayer->modifyLifePoints(-4, mp_attackingPlayer);
        }
        else if ((type() == CARD_BANG) && (mp_attackingPlayer->characterType() == CHARACTER_COLIN_BARREL)){
           gameTable()->playerDrawFromGraveyard(mp_attackingPlayer);
           mp_attackedPlayer->modifyLifePoints(-1, mp_attackingPlayer);
        }
        else if ((type() == CARD_BANG) && (mp_attackedPlayer->characterType() == CHARACTER_BURT_LONGCATCHER)){
            gameTable()->playerDrawFromGraveyard(mp_attackedPlayer);
            mp_attackedPlayer->modifyLifePoints(-1, mp_attackingPlayer);
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
        return;
    }
    if (mp_attackingPlayer == 0) {
        return;
    }
    if (mp_attackingPlayer->characterType() == CHARACTER_SARTANA) {
        if ((type() == CARD_BANG) && (targetCard->type() == CARD_MISSED)
            && (rank() >= targetCard->rank()))
                throw BadCardException();
    }
    if (type() == CARD_UNDEFENSABLE){
        throw BadCardException();
    }
    switch(targetCard->type()) {
        case CARD_BANG:
            if (type() == CARD_INDIAN_BANG){
                game()->gameCycle().unsetResponseMode();
                gameTable()->playerRespondWithCard(targetCard);
                missed();
                return;  
            }
            else {
                throw BadCardException();
            }
    case CARD_MISSED: 
        if (type() == CARD_INDIAN_BANG){
            throw BadCardException();
        }
        game()->gameCycle().unsetResponseMode();
        gameTable()->playerRespondWithCard(targetCard);
        missed();
        return;
    case CARD_DODGE: 
        game()->gameCycle().unsetResponseMode();
        gameTable()->playerRespondWithCard(targetCard);
        missed();
        gameTable()->playerDrawFromDeck(player, 1);
        return;
    case CARD_BARREL: {
        if (type() == CARD_INDIAN_BANG){
            throw BadCardException();
        }
        if (m_usedBarrels.contains(targetCard)){ 
            break;
        }
        targetCard->assertOnTable();
        m_usedBarrels.append(targetCard);
        CardBarrel* barrel = qobject_cast<CardBarrel*>(targetCard);
        barrel->check(this);
        return;
        }
    case CARD_BACKFIRE: 
        game()->gameCycle().unsetResponseMode(); 
        missed();
        targetCard->play(mp_attackingPlayer);
        gameTable()->playerRespondWithCard(targetCard);
        if (targetCard->pocket() != POCKET_GRAVEYARD){ 
            gameTable()->moveCardToGraveyard(targetCard);
        }
        player->checkEmptyHand();
        game()->gameEventManager().onPlayerUpdated(player);
        return;
    case CARD_REVENGE: 
        targetCard->play(mp_attackingPlayer);
        gameTable()->playerRespondWithCard(targetCard);
        if (targetCard->pocket() != POCKET_GRAVEYARD){ 
            gameTable()->moveCardToGraveyard(targetCard);
        }
        player->checkEmptyHand();
        game()->gameEventManager().onPlayerUpdated(player);
        return;
    case CARD_DEAD_RINGER:
        if (type() == CARD_INDIAN_BANG){
            throw BadCardException();
        }
        game()->gameCycle().unsetResponseMode();
        gameTable()->playerRespondWithCard(targetCard);
        missed();
        game()->gameCycle().setNeedsFinishTurn(true);
        return;
    case CARD_RICOCHET:
    case CARD_DEFLECTION: {
        if (type() == CARD_INDIAN_BANG){
            throw BadCardException();
        }
        if (targetCard->color() != COLOR_BROWN){
            targetCard->assertOnTable();
        }
        game()->gameCycle().unsetResponseMode(); 
        game()->gameCycle().deflectionPlayed(); 
        missed();
        QList<Player*> players = game()->playerList();
        shuffleList(players);
        foreach(Player* p, players) {
            if (p == player) {
                continue;
            }
            if (type() == CARD_DEFLECTION){
                if (game()->getDistance(player, p) == 1){
                    targetCard->play(p);
                }
                break;
            }
            else {
                if (game()->getDistance(player, p) <= player->weaponRange()){
                    targetCard->play(p);
                }
                break;
            }
        }
        if (targetCard->pocket() == POCKET_GRAVEYARD){
            targetCard->setPocket(POCKET_HAND);
            targetCard->setOwner(player);
        }
        gameTable()->playerRespondWithCard(targetCard);
        if (targetCard->pocket() != POCKET_GRAVEYARD){ 
            gameTable()->moveCardToGraveyard(targetCard);
        }
        player->checkEmptyHand();
        game()->gameEventManager().onPlayerUpdated(player);
        return;
        break;
    }
    case CARD_VEST: {
        if (type() == CARD_INDIAN_BANG){
            throw BadCardException();
        }
        targetCard->assertOnTable();
        game()->gameCycle().unsetResponseMode();
        gameTable()->playerRespondWithCard(targetCard);
        missed();
        return;
        }
    default:{
        if (type() == CARD_INDIAN_BANG){
            throw BadCardException();
        }
        QList<PlayingCard*> table = mp_attackedPlayer->table();
        foreach (PlayingCard* card, table){
            if (card->type() == CARD_STEROID){
                game()->gameCycle().unsetResponseMode();
                gameTable()->playerRespondWithCard(targetCard);
                missed();
                return;
            }
        }
       
        throw BadCardException();
    }
    
    break;
    

}
}

bool CardBang::oneTimeBang(){
    switch(type()){
        case CARD_BANG:
        case CARD_HEALING_BANG:
        case CARD_DOUBLE_BANG:
        case CARD_TRIPLE_BANG:
        case CARD_QUAD_BANG:
        case CARD_INDIAN_BANG:
        case CARD_UNDEFENSABLE:
            return true;
        default:
            return false;
    }
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
