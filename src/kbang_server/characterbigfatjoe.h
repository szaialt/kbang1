#ifndef CHARACTERBIGFATJOE_H
#define CHARACTERBIGFATJOE_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterBigFatJoe : public CharacterBase
{
Q_OBJECT
public:
    CharacterBigFatJoe(QObject* parent);
    virtual int maxLifePoints() const;
    virtual void playCard(PlayingCard* card);
protected:
    bool m_halfLife;
};

#endif // CHARACTERBIGFATJOE_H
