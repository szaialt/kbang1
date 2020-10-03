#ifndef CHARACTERCHOSINGTHOMAS_H
#define CHARACTERCHOSINGTHOMAS_H

#include "characterbase.h"

class PlayingCard;
class Player;

class CharacterChosingThomas : public CharacterBase
{
Q_OBJECT
public:
    CharacterChosingThomas(QObject *parent);
    bool canUseAbility();
    void resetAbility();
    void abilityUsed();
private:
    bool m_canUseAbility;
};

#endif // CHARACTERCHOSINGTHOMAS_H
