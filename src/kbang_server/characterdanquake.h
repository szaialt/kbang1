#ifndef CHARACTERDANQUAKE_H
#define CHARACTERDANQUAKE_H

#include "characterbase.h"

class CharacterDanQuake : public CharacterBase
{
Q_OBJECT
public:
    CharacterDanQuake(QObject *parent);
    virtual void draw(bool specialDraw);
private:
    bool check(PlayingCard* card);
};

#endif // CHARACTERDANQUAKE_H
