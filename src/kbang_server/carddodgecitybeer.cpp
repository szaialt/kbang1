#include "carddodgecitybeer.h"
#include "cardbeer.h"
#include "player.h"
#include "gametable.h"
#include "gamecycle.h"
#include "game.h"
#include "gameexceptions.h"
 
CardDodgeCityBeer::CardDodgeCityBeer(Game* game, int id, BeerType type, CardSuit cardSuit, CardRank cardRank):
        CardBeer(game, id, CardBeer::Beer, cardSuit, cardRank)
{
    switch(type) {
    case Canteen:
         setType(CARD_CANTEEN);
         break;
    case Whiskey:
        setType(CARD_WHISKEY);
        break;
    case Tequila:
        setType(CARD_TEQUILA);
        break;
    default:
        NOT_REACHED();
    }
}

CardColor CardDodgeCityBeer::color() const {
    if (type() == CARD_CANTEEN) return COLOR_GREEN;
    return COLOR_BROWN;
}

void CardDodgeCityBeer::play()
{
      qDebug() << "CardBeer: pocket " << pocketTypeToString(pocket());
      qDebug() << "CardBeer: type " << playingCardTypeToString(type());
      gameCycle()->assertTurn();
      if (owner()->lifePoints() == 0){
          throw BadUsageException();
      }
      Player* player = owner();
      if (type() == CARD_WHISKEY) {
        throw BadUsageException();
      }
      else if (type() == CARD_CANTEEN){  
        playAsGreenCard();
      }
}

void CardDodgeCityBeer::takeGreenCardEffect(){
    if (owner()->lifePoints() == 0){
          throw BadUsageException();
    }
    if (type() == CARD_CANTEEN){
        owner()->modifyLifePoints(1, 0);
    }
}

void CardDodgeCityBeer::play(PlayingCard* targetCard){
    if (owner()->lifePoints() == 0){
        throw BadUsageException();
    }
    if (type() == CARD_WHISKEY) {
        if (targetCard->owner() != owner())
            throw BadUsageException(); 
        if (targetCard->pocket() != POCKET_HAND)
            throw BadUsageException();
        owner()->modifyLifePoints(2, 0);
        gameTable()->playerDiscardCard(this);
        if (targetCard->pocket() != POCKET_GRAVEYARD)
            gameTable()->playerDiscardCard(targetCard);
        }
    else {
        throw BadUsageException(); 
    }
    
}

void CardDodgeCityBeer::play(PlayingCard* targetCard, Player* targetPlayer){
    if (targetPlayer->lifePoints() == 0){
          throw BadUsageException();
    }
    if (type() == CARD_TEQUILA) {
      if (targetCard->owner() != owner()){
        throw BadUsageException();
      }
      if (targetCard->pocket() != POCKET_HAND){
        throw BadUsageException();
      }
      targetPlayer->modifyLifePoints(1, 0);
      if (pocket() != POCKET_GRAVEYARD){
        gameTable()->playerDiscardCard(this);
      }
      if (targetCard->pocket() != POCKET_GRAVEYARD){
        gameTable()->playerDiscardCard(targetCard);
      }
    }
    else {
       throw BadUsageException(); 
    }
}

