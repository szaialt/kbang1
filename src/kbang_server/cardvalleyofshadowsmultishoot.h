#ifndef CARD_VALLEY_OF_SHADOWS_MULTISHOOT_H
#define CARD_VALLEY_OF_SHADOWS_MULTISHOOT_H

#include "cardmultishoot.h" 

class CardValleyOfShadowMultiShoot : public CardMultiShoot {
public:
    CardValleyOfShadowMultiShoot(Game* game, int id, CardMultiShoot::Type type, CardSuit cardSuit, CardRank cardRank);
    virtual void play(); 
    virtual void play(PlayingCard* targetCard);
    virtual void respondPass();
    virtual void respondCard(PlayingCard* targetCard);
    virtual ReactionType reactionType() const;
    virtual void dismiss();
protected: 
    int m_missedLeft;
}; 

#endif
