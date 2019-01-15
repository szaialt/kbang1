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
    bool inEndGame();
    bool isDeputyLiving();
    bool sheriffOnMoreThanTwoLifePoints();
    bool amIWounded();
    bool isTheSheriffWounded();
    int calculateMisseds();
    void playCardForDefense(QList<PlayingCard*> list, bool defense);
};

#endif // VOIDAI2LEVEL_H
