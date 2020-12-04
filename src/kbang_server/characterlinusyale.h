#ifndef CHARACTERLINUSYALE_H
#define CHARACTERLINUSYALE_H

#include "characterbase.h"

class PlayingCard;
class Player;

class CharacterLinusYale: public CharacterBase
{
Q_OBJECT
public:
    CharacterLinusYale(QObject *parent);
    virtual int maxLifePoints() const;
};

#endif // CHARACTERLINUSYALE_H
