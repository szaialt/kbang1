#ifndef VOIDAI3LEVEL_H
#define VOIDAI3LEVEL_H

#include "gameeventlistener.h"
#include "parser/parserstructs.h"
#include "voidai.h"
#include "voidai2level.h"

#include <QObject>
#include <iostream>

class PlayerCtrl;

class VoidAI3Level : public VoidAI2Level {
  Q_OBJECT;
  public:
    VoidAI3Level(QObject* parent); 
    virtual void requestWithAction();
    virtual void stealCard(PlayingCard* card, PublicPlayerView* targetPlayer);
}; 

#endif // VOIDAI3LEVEL_H
