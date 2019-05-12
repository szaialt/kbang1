#ifndef CARDBEER_H
#define CARDBEER_H

#include "playingcard.h"
#include "reactionhandler.h"

class Player;

class CardBeer : public PlayingCard
{
Q_OBJECT;
public:
    enum BeerType { 
        Beer,
        Saloon,
        Sandvich,
        MadMilk,
        Elixir,
        FirstAidKit,
        Medicines
    }; 
    
    CardBeer(Game* game, int id, BeerType type, CardSuit cardSuit, CardRank cardRank);
    ~CardBeer();

    CardColor color();
    virtual void play();
    void takeGreenCardEffect();
protected:
    BeerType m_type;
};

class BeerRescue: public QObject, public ReactionHandler
{
Q_OBJECT
public:
    BeerRescue(Game* game);
    virtual void respondPass();
    virtual void respondCard(PlayingCard* targetCard);
    virtual void dismiss();

    virtual ReactionType reactionType() const { return REACTION_LASTSAVE; }
    virtual Player* causedBy() const { return 0; }

    void allowSaveWithBeer(Player* attacker, Player* target, int lifePointsToSave, int hitPoints);
    
private:
    Player* mp_attacker;
    Player* mp_target;
    int     m_lifePointsToSave;
    int     m_hitPoints;
    Game*   mp_game;
};

#endif // CARDBEER_H
