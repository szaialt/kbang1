#include "cardarson.h"
#include "gametable.h"
#include "game.h"

CardArson::CardArson(Game* game, int id, CardMultiShoot::Type type, CardSuit cardSuit, CardRank cardRank):
        CardMultiShoot(game, id, CardMultiShoot::Gatling, cardSuit, cardRank)
{
    switch(type) { 
    case Arson:   
        setType(CARD_ARSON);  
        break; 
    default:
        NOT_REACHED();
    }
}

void CardArson::play(){
    throw BadUsageException();
}
    
void CardArson::play(QList<Player*> targetPlayers){
    gameCycle()->assertTurn();
    assertInHand();
    if ((!owner()->canPlayBang())){
        throw OneBangPerTurnException();
    }
    if (targetPlayers.size() != 2) throw BadUsageException();
    if (!targetPlayers.at(0)->isAlive()) throw BadUsageException();
    if (!targetPlayers.at(1)->isAlive()) throw BadUsageException();
    m_usedBarrels.clear();
    int inNextDirection = numberOfPlayersInNextDirection(targetPlayers.at(0), targetPlayers.at(1));
    int inPreviousDirection = numberOfPlayersInNextDirection(targetPlayers.at(1), targetPlayers.at(0));
    if (inNextDirection == inPreviousDirection) throw BadUsageException();
    mp_shootingPlayer = owner();
    mp_requestedPlayer = owner();
    owner()->onBangPlayed(true);
    gameTable()->playerPlayCard(this);
    if (inNextDirection < inPreviousDirection){
        //Starts at targetPlayers.at(0)
        m_playedNextDirection = true;
        playInNextDirection(targetPlayers.at(0));
    }
    else if (inNextDirection > inPreviousDirection){
        //Starts at owner()
        m_playedNextDirection = false;
        playInPreviousDirection(targetPlayers.at(0));
        if (mp_requestedPlayer == mp_shootingPlayer) return;
        if (mp_requestedPlayer == targetPlayers.at(0)) return;
    }
}
    
ReactionType CardArson::reactionType() const {
    return REACTION_GATLING;
}

int CardArson::numberOfPlayersInNextDirection(Player* player0, Player* player1){
    if (!player0->isAlive()) throw BadUsageException();
    if (!player1->isAlive()) throw BadUsageException();
    QList<Player*> players = game()->playerList();
    Player* currentPlayer = player0;
    QListIterator<Player*> it(players);
    if (!it.findNext(currentPlayer))
        return 0;
    int numberOfPlayers = 1;
    while (currentPlayer != player1){
        currentPlayer = game()->nextPlayer(currentPlayer);
        if (currentPlayer == players.last()){
            currentPlayer = players.first();
        }
        numberOfPlayers++;
    }
    return numberOfPlayers;
}

//Starts at targetPlayers.at(0)
void CardArson::playInNextDirection(Player* player){
    mp_requestedPlayer = player;
    requestNext();
}

//Starts at owner()
void CardArson::playInPreviousDirection(Player* player){
    mp_requestedPlayer = player;
    requestPrevious();
}
    
