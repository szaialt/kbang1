#include "cardhorse.h"
#include "gameexceptions.h"
#include "player.h"
#include "gametable.h"
#include "gamecycle.h"
#include "characterbase.h"

CardHorse::CardHorse(Game *game, int id, CardHorse::HorseType horseType, CardSuit suit, CardRank rank):
        PlayingCard(game, id, CARD_UNKNOWN, suit, rank),
        m_horseType(horseType)
{
    switch(m_horseType) {
    case Mustang:
        setType(CARD_MUSTANG);
        break;
    case Appaloosa:
        setType(CARD_APPALOSSA);
        break;
    case PackingMule:
        setType(CARD_PACKING_MULE);
        break;
    case HillTop:
        setType(CARD_HILL_TOP);
        break;
    }
}

CardHorse::~CardHorse()
{
}

void CardHorse::play()
{
    if (type() == CARD_PACKING_MULE){
        foreach(PlayingCard* card, owner()->table()) {
            CardHorse* equine = qobject_cast<CardHorse*>(card);
            if (equine == 0)
               continue;
            else {
                if ((!(game()->gameInfo().ourFlag())) || (!(owner()->isCharmed()) && (owner()->character()->characterType() == CHARACTER_SUZY_LAFAYETTE))){
                    throw TwoSameOnTableException();
                }
                else {
                    gameTable()->playerDiscardCard(card);
                }
            }
        }
    }
    else {
       foreach(PlayingCard* card, owner()->table()) {
           if (card->type() == CARD_PACKING_MULE){
               if ((!(game()->gameInfo().ourFlag())) || (!(owner()->isCharmed()) && (owner()->character()->characterType() == CHARACTER_SUZY_LAFAYETTE) )){
                    throw TwoSameOnTableException();
                }
                else {
                    gameTable()->playerDiscardCard(card);
                }
           }
       }
       
    }
    playAsBlueCard();
}

CardColor CardHorse::color() const {
    return COLOR_BLUE;
}

void CardHorse::registerPlayer(Player* player)
{
    switch(m_horseType) {
    case Mustang:
        if (player->characterType() == CHARACTER_RIDING_HORSE){
            player->modifyDistanceIn(2);
        }
        else{
            player->modifyDistanceIn(1);
        }
        break;
    case Appaloosa:
        if (player->characterType() == CHARACTER_RIDING_HORSE){
            player->modifyDistanceOut(2);
        }
        else {
            player->modifyDistanceOut(1);
        }
        break;
    case HillTop:
        player->modifyDistanceIn(2);
        break;
    default:
        break;
    }
}

void CardHorse::unregisterPlayer(Player* player)
{
    switch(m_horseType) {
    case Mustang:
        player->modifyDistanceIn(-1);
        break;
    case Appaloosa:
        player->modifyDistanceOut(-1);
        break;
    case HillTop:
        player->modifyDistanceIn(-2);
        break;
    default:
        break;
    }
}

