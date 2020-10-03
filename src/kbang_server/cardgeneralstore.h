#ifndef CARDGENERALSTORE_H
#define CARDGENERALSTORE_H

#include "reactioncard.h"

class CardGeneralStore : public ReactionCard
{
public:
    enum Type {
        GeneralStore,
        RobGrave
    };
    CardGeneralStore(Game* game, int id, Type type, CardSuit, CardRank);
    ~CardGeneralStore();
    virtual void play();
    virtual void respondPass();
    virtual void respondCard(PlayingCard* targetCard);
    virtual ReactionType reactionType() const { return REACTION_GENERALSTORE; }
    virtual Player* causedBy() const { return mp_firstPlayer; }
    void requestNext();

private:
    
    Player* mp_firstPlayer;
    Player* mp_currentPlayer;
    Type m_type;
    int m_remained;
};

#endif // CARDGENERALSTORE_H
