#ifndef CHARACTERJOURDONNAIS_H
#define CHARACTERJOURDONNAIS_H

#include "characterbase.h"

class CharacterJourdonnais : public CharacterBase
{
Q_OBJECT
public:
    CharacterJourdonnais(QObject *parent);
    virtual void respondCard(ReactionHandler*, PlayingCard* targetCard);
    void resetAbility();
    void inactivate();
private:
    bool check(PlayingCard* card);
    bool canCheck;
};


#endif // CHARACTERJOURDONNAIS_H
