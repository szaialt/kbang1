#ifndef VOIDAI2LEVEL_H
#define VOIDAI2LEVEL_H

#include "gameeventlistener.h"
#include "parser/parserstructs.h"
#include "voidai.h"

#include <QObject>
#include <iostream>

class PlayerCtrl;

class VoidAI2Level : public VoidAI {
  Q_OBJECT;
  public: 
    VoidAI2Level(QObject* parent); 
    virtual void requestWithAction();
  protected:
    int calculateMisseds();
    PublicPlayerView* chooseRandomPLayer();
    PublicPlayerView* chooseTarget();
    bool inEndGame();
    bool isDeputyLiving();
    bool sheriffOnMoreThanTwoLifePoints();
    bool amIWounded();
    bool isTheSheriffWounded();
};

#endif // VOIDAI2LEVEL_H
