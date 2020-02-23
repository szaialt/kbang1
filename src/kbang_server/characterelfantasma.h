#ifndef CHARACTERELFANTASMA_H
#define CHARACTERELFANTASMA_H

#include "characterbase.h"
#include "cardbeer.h"

class CharacterElFantasma : public CharacterBase
{
Q_OBJECT
public:
    CharacterElFantasma(QObject *parent);
    void playerDied();
private:
    CardBeer* mp_integratedBeer;
};

#endif // CHARACTERELFANTASMA_H
