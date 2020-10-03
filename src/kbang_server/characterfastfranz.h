#ifndef CHARACTERFASTFRANZ_H
#define CHARACTERFASTFRANZ_H

#include "characterbase.h"

class CharacterFastFranz : public CharacterBase
{
Q_OBJECT
public:
    CharacterFastFranz(QObject *parent);
    virtual int maxLifePoints() const;
    bool check(PlayingCard* card);
};

#endif // CHARACTERFASTFRANZ_H
