#ifndef CHARACTERANNEROGERS_H
#define CHARACTERANNEROGERS_H

#include "characterbase.h"

class PlayingCard;
class Player;

class CharacterAnneRogers : public CharacterBase
{
Q_OBJECT
public:
    CharacterAnneRogers(QObject *parent);
    virtual void useAbility(QList<PlayingCard*> cards);
    virtual void resetAbility();
private:
    PlayingCard* mp_integratedCard;
    Player* mp_ownerOfCard;
};

#endif // CHARACTERANNEROGERS_H
