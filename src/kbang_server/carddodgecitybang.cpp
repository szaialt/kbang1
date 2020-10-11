#include "carddodgecitybang.h"
#include "player.h"
#include "gamecycle.h"
#include "gameexceptions.h"
#include "gametable.h"
#include "game.h"
#include "cardbarrel.h"

CardDodgeCityBang::CardDodgeCityBang(Game* game, int id, BangType type, CardSuit cardSuit, CardRank cardRank):
        CardBang(game, id, CardBang::Bang, cardSuit, cardRank)
{
    switch(type) {
    case CardBang::Pepperbox:
        setType(CARD_PEPPERBOX);
        break;
     case CardBang::Knife:
         setType(CARD_KNIFE);
         break;
    case CardBang::Derringer:
        setType(CARD_DERRINGER);
        break;
    case CardBang::BuffaloRiffle:
        setType(CARD_BUFFALO_RIFFLE);
        break;
    case CardBang::Punch: 
        setType(CARD_PUNCH);
        break;
    case CardBang::Springfield:
        setType(CARD_SPRINGFIELD);
        break;
    default:
            NOT_REACHED();
    }
}

CardColor CardDodgeCityBang::color() const{
    if (type() == CARD_SPRINGFIELD) return COLOR_BROWN;
    if (type() == CARD_PUNCH) return COLOR_BROWN;
    return COLOR_GREEN;
}

void CardDodgeCityBang::play(){
    if ((color() == COLOR_GREEN) && (pocket() == POCKET_HAND)){
        playAsBlueCard();
    }
    else {
        throw BadUsageException();
    } 

}

void CardDodgeCityBang::play(Player *targetPlayer)
{
    controlCard();
    if ((color() == COLOR_BROWN) || ((pocket() == POCKET_TABLE) && isAct())){
        controlTarget(targetPlayer);
        shot(targetPlayer);
    }
}

    void CardDodgeCityBang::controlCard(){
        gameCycle()->assertTurn();
    }
    
    void CardDodgeCityBang::controlTarget(Player *targetPlayer){
        
        /* don't allow shoot yourself */
        if (owner() == targetPlayer){
            throw BadTargetPlayerException();
        }
        if (targetPlayer == 0){
            throw BadTargetPlayerException();
        }
        /* distance check */
        if (game()->getDistance(owner(), targetPlayer) > owner()->weaponRange()){
            throw PlayerOutOfRangeException();
        }
        if ((type() == CARD_DERRINGER) || (type() == CARD_KNIFE) || (type() == CARD_PEPPERBOX) || (type() == CARD_PUNCH)) {
            if (game()->getDistance(owner(), targetPlayer) > 1) 
                 throw PlayerOutOfRangeException();
        }
    }
    
    void CardDodgeCityBang::shot(Player *targetPlayer){
        Player* player = owner();
        if (type() == CARD_DERRINGER){
            gameTable()->playerDrawFromDeck(player, 1);
        }
        mp_attackingPlayer = owner();
        gameTable()->playerPlayCard(this, targetPlayer);
        m_usedBarrels.clear();
        mp_attackedPlayer = targetPlayer;
        m_missedLeft = 1;
        
        game()->gameCycle().setResponseMode(this, targetPlayer);
    }

