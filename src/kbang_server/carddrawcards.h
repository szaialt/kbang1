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
        Adrenaline,
        GoldWatch,
        BrownInvestment,
        BrownLoan,
        GarbageTruck
    };
    CardDrawCards(Game* game, int id, Type, CardSuit, CardRank);
    ~CardDrawCards();
    virtual CardColor color() const;
    virtual void play();
    virtual void play(PlayingCard* targetCard);
    virtual void takeGreenCardEffect();
    void reset();
private:
    Type m_type;
    int  m_cardCount;
    bool m_used;
};

#endif // CARDDRAWCARDS_H
