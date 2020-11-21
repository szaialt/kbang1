#ifndef CHARACTERBARTBARBER_H
#define CHARACTERBARTBARBER_H

#include "characterbase.h"
#include "cardcustoms.h"

class CharacterBartBarber : public CharacterBase
{
Q_OBJECT 
public:
    CharacterBartBarber(QObject *parent);
    virtual void draw(bool specialDraw);

private:
    CardCustoms* mp_integratedCustoms;
};

#endif // CHARACTERBARTBARBER_H
