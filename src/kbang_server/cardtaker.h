#ifndef CARDTAKER_H
#define CARDTAKER_H

#include "playingcard.h"

class CardTaker : public PlayingCard
{
public:
    enum Type {
        Panic,
        CatBalou,
        Pilfer,
        GreenFurTrade,
        Plunder,
        BarFight,
        DoublePanic,
        DoubleCatBalou,
    };

    CardTaker(Game *game, int id, Type, CardSuit, CardRank);
    ~CardTaker();
    
    virtual CardColor color() const;
    virtual void play();
    virtual void play(Player* targetPlayer);
    virtual void play(PlayingCard* targetCard);
    virtual void play(PlayingCard* targetCard, Player* targetPlayer);
    virtual void play(QList<PlayingCard*> targetCards);

private:
    Type m_type;
};

#endif // CARDTAKER_H
