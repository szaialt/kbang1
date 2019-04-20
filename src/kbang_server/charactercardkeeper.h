#ifndef CHARACTERCARDKEEPER_H
#define CHARACTERCARDKEEPER_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterCardKeeper : public CharacterBase
{
Q_OBJECT
public:
    enum Type {
        BillyLonglife
    };
    CharacterCardKeeper(QObject* parent, Type);
    virtual int cardKeeping() const; 
private:
    Type m_type;
};

#endif // CHARACTERCARDKEEPER_H
