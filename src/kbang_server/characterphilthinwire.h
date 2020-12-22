#ifndef CHARACTERPHILTHINWIRE_H
#define CHARACTERPHILTHINWIRE_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterPhilThinwire : public CharacterBase
{
Q_OBJECT
public:
    CharacterPhilThinwire(QObject* parent);
    virtual int maxLifePoints() const;
    void setDefense();
    void unsetDefense();
    bool isDefended();
protected:
    int m_defense;
};

#endif // CHARACTERPHILTHINWIRE_H
