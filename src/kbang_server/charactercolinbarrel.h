#ifndef CHARACTERCOLINBARREL_H
#define CHARACTERCOLINBARREL_H

#include "characterbase.h"

class PlayingCard;
class Player;

class CharacterColinBarrel : public CharacterBase
{
Q_OBJECT
public:
    CharacterColinBarrel(QObject *parent);
};

#endif // CHARACTERCOLINBARREL_H
