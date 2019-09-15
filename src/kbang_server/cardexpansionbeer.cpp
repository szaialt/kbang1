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
    case FirstAidKit:
        setType(CARD_FIRST_AID_KIT);
        break;
    case BrownMolotovCocktail:
        setType(CARD_BROWN_MOLOTOV_COCKTAIL);
        break;
    case BloodPackt:
        setType(CARD_BLOOD_PACT);
        break;
    case BrownMoonshine:
        setType(CARD_BROWN_MOONSHINE);
        break;
    case CardGreenOntheHouse:
        setType(CARD_GREEN_ON_THE_HOUSE);
        break;
    default:
        NOT_REACHED();
    }
}

CardExpansionBeer::~CardExpansionBeer(){}

CardColor CardExpansionBeer::color(){
    if (type() == CARD_GREEN_ON_THE_HOUSE) return COLOR_GREEN;
    return COLOR_BROWN;
}

void CardExpansionBeer::play(Player* targetPlayer){
    if (type() == CARD_ELIXIR){
        Player* player = owner();
        gameTable()->playerPlayCard(this);
        player->setElixirPlayed(true);
        player->modifyLifePoints(1, 0);
        targetPlayer->modifyLifePoints(1, 0);
    }
    else if (type() == CARD_BROWN_MOLOTOV_COCKTAIL){
        Player* player = owner();
        gameTable()->playerPlayCard(this);
        player->modifyLifePoints(1, 0);
        targetPlayer->modifyLifePoints(-1, player);
    }
    else if (type() == CARD_BLOOD_PACT){
        Player* player = owner();
        gameTable()->playerPlayCard(this);
        player->modifyLifePoints(-1, 0);
        targetPlayer->modifyLifePoints(1, 0);
    }
    else {
        throw BadUsageException();
    }
}

void CardExpansionBeer::play(PlayingCard* targetCard){
    if ( ((type() == CARD_BROWN_MOONSHINE) && (pocket() == POCKET_HAND))
          || ((type() == CARD_GREEN_ON_THE_HOUSE) && (pocket() == POCKET_TABLE)) ){
        Player* player = owner();
        if (targetCard->owner() != player) throw BadUsageException();
        gameTable()->playerPlayCard(this);
        gameTable()->playerDiscardCard(targetCard);
        if (type() == CARD_BROWN_MOONSHINE) {
            player->modifyLifePoints(1, 0);
            gameTable()->playerDrawFromDeck(player, 1);
        }
        else {
            player->modifyLifePoints(2, 0);
        }
        return;
    }
    else {
        throw BadUsageException();
    }
}

void CardExpansionBeer::play(){
    if (type() == CARD_BLOOD_PACT) throw BadUsageException();
    if (type() == CARD_BROWN_MOONSHINE) throw BadUsageException();
    if (type() == CARD_GREEN_ON_THE_HOUSE){
        if (pocket() == POCKET_HAND){
            playAsBlueCard();
            return;
        }
        else {
            throw BadUsageException();
        }
    }
    Player* player = owner();
    if (type() == CARD_ELIXIR){
        player->setElixirPlayed(true);
    }
    if (owner()->lifePoints() == 0){
        throw BadUsageException();
    }
    gameTable()->playerPlayCard(this);
    player->modifyLifePoints(1, 0);
    
    if (type() == CARD_FIRST_AID_KIT){
        gameTable()->playerDrawFromDeck(player, 1, 0);
    }
    
}
