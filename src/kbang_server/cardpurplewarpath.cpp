#include "cardpurplewarpath.h"
#include "gametable.h"



CardColor CardPurpleWarpath::color() const {
    return COLOR_VIOLET;
}
void CardPurpleWarpath::play(){
    if (pocket() == POCKET_HAND) {
        qDebug() << "CARD_PURPLE_WARPATH POCKET_HAND";
        throw BadUsageException();
    }
    else if (m_turnPlayed < CardBang::owner()->game()->gameCycle().turnNumber()){
        //Multiple inheritance didn't work.
        qDebug() << "CARD_PURPLE_WARPATH";
        gameCycle()->assertTurn();
        assertOnTable();
        mp_shootingPlayer = owner();
        mp_requestedPlayer = owner();
        m_usedBarrels.clear();
        gameTable()->playerPlayCard(this);
        requestNext();
    }
    else {
        qDebug() << "CARD_PURPLE_WARPATH exception";
        throw BadUsageException();
    }
}

void CardPurpleWarpath::play(Player* targetPlayer){
    qDebug() << "CARD_PURPLE_WARPATH";
    if (pocket() == POCKET_HAND) {
        shot(targetPlayer);
    }
    else
        throw BadUsageException();
}

void CardPurpleWarpath::respondPass(){
    if (m_turnPlayed == owner()->game()->gameCycle().turnNumber())
        CardBang::respondPass();
    else {
        gameCycle()->unsetResponseMode();
        gameTable()->playerPass(mp_requestedPlayer);
        mp_requestedPlayer->modifyLifePoints(-1, mp_shootingPlayer);
        requestNext();
    }
    
}

void CardPurpleWarpath::respondCard(PlayingCard* targetCard){
    switch(targetCard->type()) {
        case CARD_BANG:
             qDebug() << "respondCard(PlayingCard* targetCard) CARD_BANG" << endl;
             targetCard->assertInHand();
             gameTable()->playerRespondWithCard(targetCard);
             game()->gameCycle().unsetResponseMode();
             requestNext();
             return;
        default:/*{
            QList<PlayingCard*> table = targetCard->owner()->table();
            foreach (PlayingCard* card, table){
            if (card->type() == CARD_STEROID){
                qDebug() << "respondCard(PlayingCard* targetCard) CARD_STEROID" << endl;
                targetCard->assertInHand();
                respondWith(targetCard);
                return;
                break;
                if (m_playedNextDirection){
                    requestNext();
                }
                else {
                    requestPrevious();
                }
                return;
            }
        }*/
        {
            qDebug() << "respondCard(PlayingCard* targetCard)" << endl;
             targetCard->assertInHand();
             gameTable()->playerRespondWithCard(targetCard);
             game()->gameCycle().unsetResponseMode();
             requestNext();
             return;
        }
        break;
        
        
        }
    //}
}
    
void CardPurpleWarpath::checkResult(bool result){
    throw BadUsageException();
}

ReactionType CardPurpleWarpath::reactionType() const{
    if (m_turnPlayed == owner()->game()->gameCycle().turnNumber())
        return REACTION_BANG;
    else
        return REACTION_INDIANS;
}

void CardPurpleWarpath::requestNext() {
    mp_requestedPlayer = game()->nextPlayer(mp_requestedPlayer);
    if (mp_requestedPlayer == mp_shootingPlayer) return;
    game()->gameCycle().setResponseMode(this, mp_requestedPlayer);
}

