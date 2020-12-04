#ifndef CHARACTERJEREMIAHAMISH_H
#define CHARACTERJEREMIAHAMISH_H

#include "characterbase.h"

class CharacterJeremiahAmish : public CharacterBase
{
Q_OBJECT
public:
    CharacterJeremiahAmish(QObject *parent);
    virtual void playCard(PlayingCard* card);
    virtual void useAbility(QList<PlayingCard*> cards);
};

#endif // CHARACTERJEREMIAHAMISH_H
