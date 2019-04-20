#ifndef CHARACTERTOMYLEEGHOST_H
#define CHARACTERTOMYLEEGHOST_H

#include "characterbase.h"

class CharacterTomyLeeGhost : public CharacterBase
{
Q_OBJECT
public:
    CharacterTomyLeeGhost(QObject* parent);
    void decrementRounds();
    void setDead();
    bool isAlive();
    bool isAtFirstDead();
    void setAtFirstDead();
private: 
    int m_rounds;
    bool m_isAlive;
    bool m_isAtFirstDead;

};

#endif // CHARACTERTOMYLEEGHOST_H
