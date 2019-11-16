#ifndef CARDMULTISHOOT_H
#define CARDMULTISHOOT_H

#include "reactioncard.h"
#include "checkdeckresulthandler.h"

class Player;

class CardMultiShoot : public ReactionCard, public CheckDeckResultHandler
{
Q_OBJECT;
public: 
    enum Type {
        Indians,
        Gatling,
        //Dodge City
        Howitzer,
        //Valley of Shadows
        Bandidos, //the card that could not be implemented correctly
        Tornado,
        Poker,
        //Team Fortress
        ManVsMachine,
        Arson,
        BrownShowTime,
        WarParty,
        Roulette,
        Artillery
    };
    CardMultiShoot(Game* game, int id, Type type, CardSuit, CardRank);
    virtual ~CardMultiShoot(){}

    virtual CardColor color() const;
    virtual void play();

    virtual void respondPass();
    virtual void respondCard(PlayingCard* targetCard);
    
    virtual void checkResult(bool result);

    virtual ReactionType reactionType() const;
    virtual Player* causedBy() const { return mp_shootingPlayer; }
    
protected:
    virtual void respondWith(PlayingCard* targetCard);
    void requestNext();
    void requestPrevious();
    Type    m_type;
    Player* mp_shootingPlayer;
    Player* mp_requestedPlayer;
    QList<PlayingCard*> m_usedBarrels;
    QList<PlayingCard*> m_pokercards;
    bool m_playedNextDirection;
};


#endif // CARDMULTISHOOT_H
