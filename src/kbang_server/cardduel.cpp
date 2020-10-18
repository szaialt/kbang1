#include "cardduel.h"
#include "gametable.h"
#include "gamecycle.h"
#include "game.h"
#include "player.h"
#include "gameexceptions.h"
#include <iostream>

CardDuel::CardDuel(Game* game, int id, Type type, CardSuit cardSuit, CardRank cardRank):
        ReactionCard(game, id, CARD_DUEL, cardSuit, cardRank)
{
    switch(type) {
    case Duel:
        setType(CARD_DUEL);
        break;
    case Showdown:
        setType(CARD_SHOWNDOWN);
        break;
    }
}

CardDuel::~CardDuel()
{
}

void CardDuel::play(Player* targetPlayer)
{
    
    gameCycle()->assertTurn();

    /* don't allow shoot yourself */
    if (owner() == targetPlayer){
        throw BadTargetPlayerException();
    }
    mp_initialPlayer = owner();
    // the positions will swap in requestNext(), therefore
    // are swapped here
    mp_requestedPlayer = owner();
    mp_shootingPlayer  = targetPlayer;

    gameCycle()->setCardEffect(1);
    gameTable()->playerPlayCard(this, targetPlayer);
    requestNext();
}

void CardDuel::respondPass()
{
    game()->gameCycle().unsetResponseMode();
    gameTable()->playerPass(mp_requestedPlayer);
    if (type() == CARD_DUEL){
        mp_requestedPlayer->modifyLifePoints(-1, mp_initialPlayer);
    }
    else {
        mp_requestedPlayer->modifyLifePoints(-2, mp_initialPlayer);
    }
    gameCycle()->setCardEffect(0);
}

void CardDuel::respondCard(PlayingCard* targetCard)
{
    switch(targetCard->type()) {
    case CARD_BANG: 
        gameTable()->playerRespondWithCard(targetCard);
        game()->gameCycle().unsetResponseMode();
        requestNext();
        return;
    default:
        if (targetCard->owner()->characterType() == CHARACTER_PEPITA_DUELITA){
            gameTable()->playerRespondWithCard(targetCard);
            game()->gameCycle().unsetResponseMode();
            requestNext();
        return;
        }
        else {
            break;
        }
    }
    throw BadCardException();
}

void CardDuel::requestNext()
{
    Player* tmp = mp_requestedPlayer;
    mp_requestedPlayer = mp_shootingPlayer;
    mp_shootingPlayer = tmp;
    game()->gameCycle().setResponseMode(this, mp_requestedPlayer);
}


