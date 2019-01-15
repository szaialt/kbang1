#ifndef CARDTEAMFORTRESSBANG_H
#define CARDTEAMFORTRESSBANG_H
#include "cardbang.h"

class CardTeamFortressBang : public CardBang {
public:
    CardTeamFortressBang(Game *game, int id, BangType type, CardSuit, CardRank);
    ~CardTeamFortressBang(); 
    virtual ReactionType reactionType() const;
    virtual void respondPass();
protected:
    virtual void controlCard();
    virtual void controlTarget(Player *targetPlayer);
    virtual void shot(Player *targetPlayer);
};

#endif // CARDTEAMFORTRESSBANG_H
