#ifndef CHARACTERMYKEMYOPE_H
#define CHARACTERMYKEMYOPE_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterMykeMyope : public CharacterBase
{
Q_OBJECT
public:
    CharacterMykeMyope(QObject* parent);
    virtual int maxLifePoints() const;
    virtual void playCard(PlayingCard* card);
};

#endif // CHARACTERMYKEMYOPE_H
