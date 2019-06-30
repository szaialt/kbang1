#include "cardmorphine.h"
#include "gametable.h"

CardMorphine::CardMorphine(Game* game, int id, CardSuit cardSuit, CardRank cardRank):
        PlayingCard(game, id, CARD_MORPHINE, cardSuit, cardRank)
{
}

CardColor CardMorphine::color() const {
    return COLOR_POSITIVE_GREY;
}

void CardMorphine::play()
{
    playAsBlueCard();
}
 
void CardMorphine::registerPlayer(Player* player){
    m_isOwnerLiving = player->isAlive();
    player->setAlive(true);
}
 
void CardMorphine::unregisterPlayer(Player* player){
    player->setAlive(m_isOwnerLiving);
}
