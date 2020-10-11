#include "cardteamfortressbang.h"
#include "gametable.h"

CardTeamFortressBang::CardTeamFortressBang(Game* game, int id, BangType type, CardSuit cardSuit, CardRank cardRank):
        CardBang(game, id, CardBang::Bang, cardSuit, cardRank){
    switch(type) {
    case CardBang::DirectHit:
        setType(CARD_DIRECT_HIT);
        break;
    case CardBang::HealingBang:
         setType(CARD_HEALING_BANG);
        break;
    default:
        NOT_REACHED();
    }
}

CardTeamFortressBang::~CardTeamFortressBang(){} 

void CardTeamFortressBang::controlCard(){
    if (type() == CARD_DIRECT_HIT){
        gameCycle()->assertTurn();
    }
    else {
        CardBang::controlCard();
    }
}

void CardTeamFortressBang::controlTarget(Player *targetPlayer){
    /* don't allow shoot yourself */
    if (type() == CARD_DIRECT_HIT){
        if (owner() == targetPlayer){
            throw BadTargetPlayerException();
        }
        if (targetPlayer == 0){
            throw BadTargetPlayerException();
        }
    }
    else {
        CardBang::controlTarget(targetPlayer);
    }
}

void CardTeamFortressBang::shot(Player *targetPlayer){
    if (type() == CARD_DIRECT_HIT){
        CardBang::shot(targetPlayer);
    }
    else {
        owner()->onBangPlayed(true);
        mp_attackingPlayer = owner();
        gameTable()->playerPlayCard(this, targetPlayer);
        targetPlayer->modifyLifePoints(1, 0);
        //CardBang::shot(targetPlayer);
    }
}
ReactionType CardTeamFortressBang::reactionType() const {
    if (type() == CARD_DIRECT_HIT) 
        return REACTION_BANG;
    else
        return REACTION_HEALING_BANG;
}

void CardTeamFortressBang::respondPass(){
    if (type() == CARD_DIRECT_HIT){
        CardBang::respondPass();
    }
}
