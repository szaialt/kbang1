#ifndef CHARACTERJULIEBULETTE_H
#define CHARACTERJULIEBULETTE_H

#include "characterbase.h"

class CharacterJulieBulette : public CharacterBase
{
Q_OBJECT
public:
    CharacterJulieBulette(QObject *parent);
    virtual void useAbility(QList<PlayingCard*> cards);
    void resetAbility();
protected:
    bool m_used;

};

#endif // CHARACTERJULIEBULETTE_H
