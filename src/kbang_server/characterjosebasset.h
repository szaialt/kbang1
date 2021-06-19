#ifndef CHARACTERJOSEYBASSET_H
#define CHARACTERJOSEYBASSET_H

#include "characterbase.h"
#include "gametable.h"
#include "player.h"

class CharacterJoseBasset : public CharacterBase
{
Q_OBJECT
public:
    CharacterJoseBasset(QObject* parent);
    virtual void playCard(PlayingCard* card);
    virtual void playCard(PlayingCard* card, Player* targetPlayer);
    virtual void playCard(PlayingCard* card, PlayingCard* targetCard);
    virtual void playCard(PlayingCard* card, PlayingCard* targetCard, Player* targetPlayer);
    virtual void playCard(PlayingCard* card, QList<PlayingCard*> targetCards);

    virtual bool canGetCards();
    virtual void resetAbility();
protected: 
    bool m_canUseAbility;
};

#endif // CHARACTERJOSEYBASSET_H
