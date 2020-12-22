#ifndef CHARACTERTIMCROUPIER_H
#define CHARACTERTIMCROUPIER_H

#include "characterbase.h"

class CharacterTimCroupier : public CharacterBase
{
Q_OBJECT;
public:
    CharacterTimCroupier(QObject *parent);
    virtual void draw(bool specialDraw);
    virtual void useAbility();
protected:
    QList<PlayingCard*> m_cards;
};

#endif // CHARACTERTIMCROUPIER_H
