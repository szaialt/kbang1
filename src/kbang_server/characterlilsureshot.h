#ifndef CHARACTERLILSURESHOT_H
#define CHARACTERLILSURESHOT_H

#include "characterbase.h"

class CharacterLilSureshot : public CharacterBase
{
Q_OBJECT
public:
    CharacterLilSureshot(QObject* parent);
    virtual void setPlayer(Player* player);
    virtual void useAbility(QList<PlayingCard*> cards);
};

#endif // CHARACTERLILSURESHOT_H
