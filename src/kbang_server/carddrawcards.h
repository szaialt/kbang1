#ifndef CARDDRAWCARDS_H
#define CARDDRAWCARDS_H

#include "playingcard.h"

class Player;

class CardDrawCards : public PlayingCard
{
Q_OBJECT;
public: 
    enum Type {
        Diligenza,
        WellsFargo, 
        SupplyCrate,
        AceUpYourSleeve,
        UnionPacific,
        Adrenaline
    };
    CardDrawCards(Game* game, int id, Type, CardSuit, CardRank);
    ~CardDrawCards();
    virtual CardColor color() const;
    virtual void play();
    virtual void play(PlayingCard* targetCard);
    virtual void takeGreenCardEffect();
private:
    Type m_type;
    int  m_cardCount;
};

#endif // CARDDRAWCARDS_H
