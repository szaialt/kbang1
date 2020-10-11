#include "cardvalleyofshadowsbang.h"
#include "player.h"
#include "gamecycle.h"
#include "gameexceptions.h"
#include "gametable.h"
#include "game.h"
#include "cardbarrel.h"
#include <iostream>

CardValleyOfShadowsBang::CardValleyOfShadowsBang(Game* game, int id, BangType type, CardSuit cardSuit, CardRank cardRank):
        CardBang(game, id, BangType::Bang, cardSuit, cardRank)
{
    switch(type) {
    case Aim:
        setType(CARD_AIM);
        break;
    case Fanning: 
        setType(CARD_FANNING);
        break;
    case Tomahawk:
        setType(CARD_TOMAHAWK);
        break;
    case Backfire:
        setType(CARD_BACKFIRE);
        break;
    default:
            NOT_REACHED();
    }
}

void CardValleyOfShadowsBang::play(PlayingCard* targetCard, Player* targetPlayer){
    if (type() == CARD_AIM){
        if (targetCard->owner() != owner())
            throw BadUsageException(); 
        if ((type() == CARD_AIM) && targetCard->type() != CARD_BANG){
            throw BadUsageException(); 
        }
        mp_attackingPlayer = owner();
        gameTable()->playerPlayCard(this, targetPlayer);
        m_usedBarrels.clear();
        mp_attackedPlayer = targetPlayer;
        m_missedLeft = 1;
        game()->gameCycle().setResponseMode(this, targetPlayer);
        if (targetCard->pocket() != POCKET_GRAVEYARD)
            gameTable()->playerDiscardCard(targetCard);
    }
    else {
        throw BadUsageException();
    }
}

void CardValleyOfShadowsBang::play(Player *targetPlayer)
{
    if (type() == CARD_BACKFIRE){
        shot(targetPlayer);
    }
    else {
      controlCard();
      controlTarget(targetPlayer);
      shot(targetPlayer);
    }
}

    void CardValleyOfShadowsBang::controlCard(){
        if (type() == CARD_AIM) throw BadUsageException();
        gameCycle()->assertTurn();

        /* one-bang-per-turn check */
        if ((type() == CARD_FANNING) && (!owner()->canPlayBang())){
            throw OneBangPerTurnException();
        }
    }
    
    void CardValleyOfShadowsBang::controlTarget(Player *targetPlayer){
        /* don't allow shoot yourself */
        if (owner() == targetPlayer){
            throw BadTargetPlayerException();
        }
        if (targetPlayer == 0){
            throw BadTargetPlayerException();
        }
        /* distance check */
        
        if (((type() != CARD_BACKFIRE) && (type() != CARD_TOMAHAWK)) && (game()->getDistance(owner(), targetPlayer) > owner()->weaponRange())){
            throw PlayerOutOfRangeException();
        }
        if (type() == CARD_TOMAHAWK) {
            if (game()->getDistance(owner(), targetPlayer) > 2) 
                throw PlayerOutOfRangeException();
            }
        }
    
    void CardValleyOfShadowsBang::shot(Player *targetPlayer){
        Player* player = owner();
        mp_attackingPlayer = owner();
        if (type() != CARD_FANNING){ 
            if ((this != 0) && (targetPlayer != 0) && (type() != CARD_BACKFIRE)){
                //CARD_BACKFIRE is not only a missed card, it is also a bang,
                //it needs to remain in hand after respond.
                //It will discarded after playing it. 
                gameTable()->playerPlayCard(this, targetPlayer);
            }
        }
        m_usedBarrels.clear();
        mp_attackedPlayer = targetPlayer;
        m_missedLeft = 1;
        if ((this != 0) && (targetPlayer != 0))
        game()->gameCycle().setResponseMode(this, targetPlayer);
    }


void CardValleyOfShadowsBang::play(QList<Player*> targetPlayers){
    //controlCard();
    if (type() != CARD_FANNING) throw BadUsageException();
    if (targetPlayers.size() > 2) throw BadUsageException();
    if (targetPlayers.size() == 2) {
        if (game()->getDistance(targetPlayers.at(0), targetPlayers.at(1)) > 1){
             throw BadUsageException();
        }
    } 
    mp_attackingPlayer = owner();
    controlTarget(targetPlayers.at(0));
    shot(targetPlayers.at(0));
    controlTarget(targetPlayers.at(1));
    shot(targetPlayers.at(1));
    gameTable()->playerPlayCard(this, targetPlayers.at(0));
    mp_attackingPlayer->onBangPlayed();
}

void CardValleyOfShadowsBang::respondPass()
{
    Q_ASSERT(mp_attackedPlayer != 0);
    gameCycle()->unsetResponseMode();
    gameTable()->playerPass(mp_attackedPlayer);
    if (type() == CARD_AIM){
        mp_attackedPlayer->modifyLifePoints(-2, mp_attackingPlayer);
    }
    else {
        mp_attackedPlayer->modifyLifePoints(-1, mp_attackingPlayer);
    }
}

