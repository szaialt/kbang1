#include "cardvalleyofshadowsmultishoot.h"
#include "gametable.h"
#include "gamecycle.h"
#include "game.h"
#include "player.h"
#include "gameexceptions.h"
#include "cardbarrel.h"

CardValleyOfShadowMultiShoot::CardValleyOfShadowMultiShoot(Game* game, int id, CardMultiShoot::Type type, CardSuit cardSuit, CardRank cardRank):
        CardMultiShoot(game, id, CardMultiShoot::Gatling, cardSuit, cardRank)
{
    switch(type) { 
    case Bandidos:  //Could not be implemented correctly. AI players
        setType(CARD_BANDIDOS); //simply throw out two cards. If they 
        break; //don't have that, they don't get hurted. Human players
    case Tornado: //need not throw out two cards, they can simply pass,
        setType(CARD_TORNADO); //and not get hurted.
        break;
    case Poker:
        setType(CARD_POKER);
        break;
    default:
        NOT_REACHED();
    }
    m_missedLeft = 1;
    if (type == Bandidos){
        m_missedLeft = 2;
    }
}

void CardValleyOfShadowMultiShoot::play()
{
    if (type() == CARD_TORNADO){
        throw BadUsageException();
    }
    gameCycle()->assertTurn();
    mp_shootingPlayer = owner();
    mp_requestedPlayer = owner();
    m_usedBarrels.clear();
    gameTable()->playerPlayCard(this);
    if (type() == CARD_POKER){
        gameTable()->playerDrawFromDeck(mp_shootingPlayer, 2); 
    }
    requestNext();
    
}

void CardValleyOfShadowMultiShoot::play(PlayingCard* targetCard)
{
    if (type() == CARD_TORNADO){
        if (targetCard->owner() != owner()){
            throw BadUsageException();
        }
        if (targetCard == 0){
            throw BadUsageException();
        }
        gameCycle()->assertTurn();
        mp_shootingPlayer = owner();
        mp_requestedPlayer = owner();
        m_usedBarrels.clear();
        gameTable()->playerPlayCard(this);
        gameTable()->cancelCard(targetCard, mp_shootingPlayer);
        gameTable()->playerDrawFromDeck(mp_shootingPlayer, 2);
        requestNext();
    }
    else {
        throw BadUsageException();
    }
    
}

void CardValleyOfShadowMultiShoot::respondPass()
{
    gameCycle()->unsetResponseMode();
    gameTable()->playerPass(mp_requestedPlayer);
    if (type() == CARD_TORNADO){
        if (mp_requestedPlayer->hand().empty())
            gameTable()->playerDrawFromDeck(mp_requestedPlayer, 2);
        else {
            PlayingCard* card = mp_requestedPlayer->getRandomCardFromHand();
            gameTable()->cancelCard(card, mp_requestedPlayer);
            gameTable()->playerDrawFromDeck(mp_requestedPlayer, 2);
        }
        requestNext();
            
    }
    else if (type() == CARD_POKER){
        if (!(mp_requestedPlayer->hand().empty())){
            PlayingCard* card = mp_requestedPlayer->getRandomCardFromHand();
            //m_pokercards.push_back(card);
            gameTable()->cancelCard(card);
        }
        requestNext();
    }
    else if (type() == CARD_BANDIDOS){
        //Why can I set payedBandidos only for the first player? 
        qDebug() << "CardValleyOfShadowMultiShoot:: payedBandidos: " << mp_requestedPlayer->payedBandidos();
        //If you outcomment it, only a player can defend 
        //it/him/herself; others get hurt in spite of throwing out cards
        /* if (!(mp_requestedPlayer->payedBandidos())){
            mp_requestedPlayer->modifyLifePoints(-1, mp_shootingPlayer);
        }
        mp_requestedPlayer->setPayedBandidos(false);*/
        requestNext();
        
    }
}

void CardValleyOfShadowMultiShoot::respondCard(PlayingCard* targetCard)
{
    Player* player = targetCard->owner();
    if (type() == CARD_BANDIDOS){
        //Response with two cards is correct.
        qDebug() << "CardValleyOfShadowMultiShoot: reactionHandler is REACTION_BANDIDOS";
        gameTable()->playerRespondWithCard(targetCard);
        dismiss();
        return;
    }
    else if (type() == CARD_TORNADO){
        gameTable()->playerRespondWithCard(targetCard);
        game()->gameCycle().unsetResponseMode();
        gameTable()->playerDrawFromDeck(player, 2);
        requestNext();
    }
    else if (type() == CARD_POKER){
        //m_pokercards.push_back(targetCard); 
        //game()->gameCycle().unsetResponseMode();
        //requestNext();
        gameTable()->playerRespondWithCard(targetCard);
        game()->gameCycle().unsetResponseMode();
        requestNext();
        /*
        //This would be after playing the card
        bool cancel = false;
        foreach (PlayingCard* card, m_pokercards){
            if (card->rank() == 14){
                cancel = true;
            }
        }
        if (cancel) {
            foreach (PlayingCard* card, m_pokercards){
                gameTable()->cancelCard(card, player);
            }  
        }
        else {
        //get two cards from this selection
            for (int i = 0; i < 2; i++){
                int index = rand() % m_pokercards.size();
                PlayingCard* card = m_pokercards.at(index);
                gameTable()->playerStealCard(owner(), card);
                m_pokercards.removeAll(card);        
            }
            foreach (PlayingCard* card, m_pokercards){
                gameTable()->cancelCard(card, player);
            } 
        }*/
        return; 
    }
}

ReactionType CardValleyOfShadowMultiShoot::reactionType() const
{
    if (type() == CARD_BANDIDOS)
        return REACTION_BANDIDOS;
    else if (type() == CARD_TORNADO)
        return REACTION_TORNADO;
    else if (type() == CARD_POKER)
        return REACTION_POKER;
}

void CardValleyOfShadowMultiShoot::dismiss()
{
    //Used by CARD_BANDIDOS.
    //Response with two cards is correct.
    m_missedLeft--;
    if (m_missedLeft == 0) {
        mp_requestedPlayer->setPayedBandidos(true);
        game()->gameCycle().unsetResponseMode();
        //mp_requestedPlayer = mp_requestedPlayer->nextPlayer();
        requestNext();
    }
}

