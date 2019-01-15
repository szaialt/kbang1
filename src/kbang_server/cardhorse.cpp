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
    }
}

CardHorse::~CardHorse()
{
}

void CardHorse::play()
{
    playAsBlueCard();
}

CardColor CardHorse::color() const {
    return COLOR_BLUE;
}

void CardHorse::registerPlayer(Player* player)
{
    switch(m_horseType) {
    case Mustang:
        player->modifyDistanceIn(1);
        break;
    case Appaloosa:
        player->modifyDistanceOut(1);
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
    }
}

