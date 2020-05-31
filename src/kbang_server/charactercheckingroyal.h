#ifndef CHARACTERCHECKINGROYAL_H
#define CHARACTERCHECKINGROYAL_H

#include "characterbase.h"

class CharacterCheckingRoyal : public CharacterBase
{
Q_OBJECT
public:
    CharacterCheckingRoyal(QObject *parent);
    virtual void setPlayer(Player* player);
public slots:
    void onHit(int lifePoints, Player* causedBy);
private:
    bool check(PlayingCard* card);
};

#endif // CHARACTERCHECKINGROYAL_H
