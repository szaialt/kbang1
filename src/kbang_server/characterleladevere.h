#ifndef CHARACTERLELADEVERE_H
#define CHARACTERLELADEVERE_H

#include "characterbase.h"

class CharacterLelaDevere : public CharacterBase
{
Q_OBJECT
public:
    CharacterLelaDevere(QObject* parent);
    virtual void useAbility(QList<PlayingCard*> cards);
};

#endif // CHARACTERLELADEVERE_H
