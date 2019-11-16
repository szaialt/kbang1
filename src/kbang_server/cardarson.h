#ifndef CARDARSON_H
#define CARDARSON_H

#include "cardmultishoot.h" 

class CardArson : public CardMultiShoot {
    
public:
    CardArson(Game* game, int id, CardMultiShoot::Type type, CardSuit cardSuit, CardRank cardRank);

    virtual ~CardArson(){}

    virtual CardColor color() const;
    
    virtual void play();
    
    virtual void play(QList<Player*> targetPlayers);
    
    virtual ReactionType reactionType() const;

protected:
    int numberOfPlayersInNextDirection(Player* player0, Player* player1);
    void playInNextDirection(Player* player);
    void playInPreviousDirection(Player* player);
};

#endif //CARDARSON_H
