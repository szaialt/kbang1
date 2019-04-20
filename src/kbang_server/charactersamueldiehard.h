#ifndef CHARACTERSAMUELDIEHARD_H
#define CHARACTERSAMUELDIEHARD_H

#include "characterbase.h"

class CharacterSamuelDiehard : public CharacterBase
{
Q_OBJECT
public:
    CharacterSamuelDiehard(QObject *parent);
    virtual void draw(bool specialDraw);
};

#endif // CHARACTERSAMUELDIEHARD_H
