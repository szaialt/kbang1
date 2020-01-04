#ifndef CARDPURPLEWARPATH_H
#define CARDPURPLEWARPATH_H

#include "cardbang.h"
#include "cardmultishoot.h"

class CardPurpleWarpath : public CardBang
{
Q_OBJECT;
public:
    CardPurpleWarpath(Game* game, int id, CardSuit cardSuit, CardRank cardRank):
    CardBang(game, id,  BangType::PurpleWarpath, cardSuit, cardRank) {}
    
    virtual ~CardPurpleWarpath(){}

    virtual CardColor color() const;
    virtual void play();
    virtual void play(Player* targetPlayer);
    virtual void respondPass();
    virtual void respondCard(PlayingCard* targetCard);
    
    virtual void checkResult(bool result);

    virtual ReactionType reactionType() const;
    virtual Player* causedBy() const { return mp_attackingPlayer; }
    virtual int missedLeft() { return m_missedLeft; }
private:
    virtual void requestNext();
protected:
    Player* mp_shootingPlayer;
    Player* mp_requestedPlayer;
};

#endif // CARDPURPLEWARPATH_H
