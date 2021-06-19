// POCKET_BANK

#ifndef VOIDAI_H
#define VOIDAI_H

#include "gameeventlistener.h"
#include "parser/parserstructs.h"
#include <QObject>
#include <iostream>

class PlayerCtrl;

class VoidAI : public QObject, public GameEventListener
{
Q_OBJECT;
public: 
    VoidAI(QObject* parent); 
    virtual ~VoidAI() {}

    CreatePlayerData createPlayerData() const;

    virtual bool isAI() { return 1; }

    virtual void onHandlerRegistered(const PublicGameView* publicGameView, PlayerCtrl* playerCtrl);
    virtual void onHandlerUnregistered() {}

    virtual void onGameStartabilityChanged(bool) {}

    virtual void onChatMessage(PublicPlayerView&, const QString&) {}
    virtual void onGameSync() {}
    virtual void onPlayerJoinedGame(PublicPlayerView&) {}
    virtual void onPlayerLeavedGame(PublicPlayerView&) {}
    virtual void onPlayerUpdated(PublicPlayerView&) {}
    virtual void onPlayerDied(PublicPlayerView&, PublicPlayerView*);
    virtual void onPlayerDied(PublicPlayerView&);
    virtual void onGameStarted() {}
    virtual void onGameFinished() {}
    virtual void onPlayerDrawFromDeck(PublicPlayerView&, QList< PlayingCard*>, bool) {}
    virtual void onPlayerDrawFromGraveyard(PublicPlayerView&, const PlayingCard*, const PlayingCard*) {}
    virtual void onPlayerDiscardCard(PublicPlayerView&, const PlayingCard*, PocketType) {}
    virtual void onPlayerPlayCard(PublicPlayerView&, const PlayingCard*, PocketType pocket) {}
    virtual void onPlayerPlayCard(PublicPlayerView&, PlayingCard*,  PlayingCard*, PocketType pocket) {}
    virtual void onPlayerPlayCard(PublicPlayerView&, const PlayingCard*, PublicPlayerView&, PocketType pocket) {}
    virtual void onPlayerPlayCard(PublicPlayerView&, const PlayingCard* card, const PlayingCard* target, PublicPlayerView* targetPlayer,  PocketType pocket1, PocketType pocket2) {}
    virtual void onPlayerPlayCard(PublicPlayerView&, PlayingCard* card1, PlayingCard* card2, PocketType pocket1, PocketType pocket2){}
    virtual void onPlayerPlayCardOnTable(PublicPlayerView&, const PlayingCard*, PublicPlayerView&) {}
    virtual void onPassTableCard(PublicPlayerView&, const PlayingCard*, PublicPlayerView&) {}
    virtual void onPlayerRespondWithCard(PublicPlayerView&, const PlayingCard*) {}
    virtual void onPlayerPass(PublicPlayerView&) {}
    virtual void onDrawIntoSelection(QList<const PlayingCard*>) {}
    virtual void onPlayerPickFromSelection(PublicPlayerView&, const PlayingCard*) {}
    virtual void onUndrawFromSelection(const PlayingCard*) {}
    virtual void onPlayerCheckDeck(PublicPlayerView&, const PlayingCard*, const PlayingCard*, bool) {}
    virtual void onPlayerStealCard(PublicPlayerView&, PublicPlayerView&, PocketType, const PlayingCard*) {}
    virtual void onCancelCard(PocketType, const PlayingCard*, PublicPlayerView*, PublicPlayerView*) {    
    }
    virtual void onCancelCard(PocketType, const PlayingCard*) {    
    }
    virtual void onPlayerDrawFromBank(PublicPlayerView&, PlayingCard* card, bool revealCards){}
    virtual void onPlayerPlayCardOnBank(PublicPlayerView&, const PlayingCard* card) {}
    virtual void onGameContextChange(const GameContextData&) {}
    virtual void onLifePointsChange(PublicPlayerView&, int, PublicPlayerView*) {}
    virtual void onDeckRegenerate() {}
    virtual void onPlayerUseAbility(PublicPlayerView&) {}

    virtual void onActionRequest(ActionRequestType);

public slots:
    virtual void requestWithAction();

protected:
    static int sm_playerCounter;
    int         m_id;
    PlayerCtrl* mp_playerCtrl;
    ActionRequestType m_requestType;
};

#endif // VOIDAI_H
