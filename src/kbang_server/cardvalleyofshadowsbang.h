#ifndef CARD_VALLEY_OF_SHADOWS_BANG_H
#define CARD_VALLEY_OF_SHADOWS_BANG_H

#include "cardbang.h"

class CardValleyOfShadowsBang : public CardBang {
public:
    CardValleyOfShadowsBang(Game* game, int id, BangType type, CardSuit cardSuit, CardRank cardRank);
    virtual void play(PlayingCard* targetCard, Player* targetPlayer);
    virtual void play(Player *targetPlayer);
    virtual void play(QList<Player*> targetPlayers);
    virtual void respondPass();
protected:
    virtual void controlCard();
    virtual void controlTarget(Player *targetPlayer);
    virtual void shot(Player *targetPlayer);
};

#endif
