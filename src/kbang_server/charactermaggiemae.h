#ifndef CHARACTERMAGGIEMAE_H
#define CHARACTERMAGGIEMAE_H

#include "characterbase.h"

class PlayingCard;
class Player;

class CharacterMaggieMae : public CharacterBase
{
Q_OBJECT
public:
    CharacterMaggieMae(QObject *parent);
    virtual void draw(bool specialDraw);
    virtual void useAbility(QList<PlayingCard*> cards);
private:
    bool m_canUseAbility;
};

#endif // CHARACTERANNEROGERS_H
