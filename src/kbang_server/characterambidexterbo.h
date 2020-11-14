#ifndef CHARACTERAMBIDEXTERBO_H
#define CHARACTERAMBIDEXTERBO_H

#include "characterbase.h"

class CharacterAmbidexterBo : public CharacterBase
{
Q_OBJECT
public:
    CharacterAmbidexterBo(QObject* parent);
    virtual void setPlayer(Player* player);
    Player* targetedPlayer();
    void setTargetedPlayer(Player* player);
protected:
    Player* mp_targetedPlayer;
};

#endif // CHARACTERAMBIDEXTERBO_H
