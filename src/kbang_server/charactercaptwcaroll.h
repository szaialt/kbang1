#ifndef CHARACTERCAPTWCAROLL_H
#define CHARACTERCAPTWCAROLL_H

#include "characterbase.h"

class CharacterCaptWCaroll : public CharacterBase
{
Q_OBJECT
public:
    CharacterCaptWCaroll(QObject *parent);
    virtual void useAbility(QList<PlayingCard*> cards);
    void resetAbility();
protected:
    int m_times;

};

#endif // CHARACTERCAPTWCAROLL_H
