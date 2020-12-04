#ifndef CHARACTERJAMESSTONEHEART_H
#define CHARACTERJAMESSTONEHEART_H

#include "characterbase.h"

class PlayingCard;
class Player;

class CharacterJamesStoneheart: public CharacterBase
{
Q_OBJECT
public:
    CharacterJamesStoneheart(QObject *parent);
    virtual int maxLifePoints() const;
};

#endif // CHARACTERJAMESSTONEHEART_H
