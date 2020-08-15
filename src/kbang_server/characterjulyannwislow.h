#ifndef CHARACTERJULYANNWINSLOW_H
#define CHARACTERJULYANNWINSLOW_H

#include "characterbase.h"

class CharacterJulyAnnWislow : public CharacterBase
{
Q_OBJECT;
public:
    CharacterJulyAnnWislow(QObject *parent);
    virtual void draw(bool specialDraw);
};

#endif // CHARACTERJULYANNWINSLOW_H
