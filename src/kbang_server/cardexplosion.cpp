#include "cardexplosion.h"
#include "gametable.h"
#include "game.h"

CardExplosion::CardExplosion(Game* game, int id, CardSuit cardSuit, CardRank cardRank):
        PlayingCard(game, id, CARD_EXPLOSION, cardSuit, cardRank)
{
  
}

void CardExplosion::play(){
    gameCycle()->assertTurn();
    mp_shootingPlayer = owner();
    mp_requestedPlayer = owner();
    gameTable()->playerPlayCard(this);
    playInNextDirection(mp_requestedPlayer);
}

//Starts at targetPlayers.at(0)
void CardExplosion::playInNextDirection(Player* player){
    mp_requestedPlayer = player;
    player->modifyLifePoints(-1, mp_requestedPlayer);
    mp_requestedPlayer = game()->nextPlayer(mp_requestedPlayer);
    if (mp_requestedPlayer == mp_shootingPlayer) return;
    playInNextDirection(mp_requestedPlayer);
}
   
