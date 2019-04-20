#include "cardexpansionbeer.h"
#include "gamecycle.h"
#include "game.h"
#include "gameexceptions.h"
#include "gametable.h"

#include <iostream>

CardExpansionBeer::CardExpansionBeer(Game* game, int id, BeerType type, CardSuit cardSuit, CardRank cardRank):
        CardBeer(game, id, BeerType::Beer, cardSuit, cardRank){
    switch(type) {
    case Sandvich:
        setType(CARD_SANDVICH);
        break;
    case MadMilk:
        setType(CARD_MAD_MILK);
        break;
    case Elixir:
        setType(CARD_ELIXIR);
        break;
    default:
        NOT_REACHED();
    }
}

CardExpansionBeer::~CardExpansionBeer(){}

void CardExpansionBeer::play(){
    Player* player = owner();
    if (owner()->lifePoints() == 0){
        throw BadUsageException();
    }
    gameTable()->playerPlayCard(this);
    player->modifyLifePoints(1, 0);
    if (type() == CARD_ELIXIR){
        player->setElixirPlayed(true);
    }
}
