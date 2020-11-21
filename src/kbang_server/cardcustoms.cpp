#include "cardcustoms.h"
#include "gametable.h"
#include "gamecycle.h"
#include "game.h"
#include "player.h"
#include "gameexceptions.h"
#include <iostream>

CardCustoms::CardCustoms(Game* game, int id, CardSuit cardSuit, CardRank cardRank):
        CardMultiShoot(game, id, CardMultiShoot::Gatling, cardSuit, cardRank)
{
    setType(CARD_CUSTOMS);
}

CardCustoms::~CardCustoms()
{
}

CardColor CardCustoms::color(){
    return COLOR_BLUE;
}

void CardCustoms::play()
{
    
    gameCycle()->assertTurn();
    
    if (pocket() == POCKET_HAND){
        playAsBlueCard();
    }
    
    if (pocket() == POCKET_TABLE){
        gameCycle()->assertTurn();
        m_playedNextDirection = true;
        mp_shootingPlayer = owner();
        mp_requestedPlayer = owner();
        m_usedBarrels.clear();
        requestNext();
    }
    
}

void CardCustoms::respondPass()
{
    game()->gameCycle().unsetResponseMode();
    gameTable()->playerPass(mp_requestedPlayer);
    if (mp_requestedPlayer == selectPlayer()){
        PlayingCard* card = mp_requestedPlayer->getRandomCardFromHand();
        gameTable()->playerStealCard(mp_shootingPlayer, card);
    }
    if (mp_requestedPlayer == mp_shootingPlayer) return;
    requestNext();
}

void CardCustoms::respondCard(PlayingCard* targetCard)
{
    targetCard->assertInHand();
    if (mp_requestedPlayer == selectPlayer()){
        gameTable()->playerStealCard(mp_shootingPlayer, targetCard);
    }
    if (mp_requestedPlayer == mp_shootingPlayer) return;
    requestNext();
}

Player* CardCustoms::selectPlayer(){
    Player* player = owner();
    Player* selectedPlayer = owner();
    bool tie = false;
    foreach (player, game()->playerList()){
        if (player->handSize() > selectedPlayer->handSize() ){
            selectedPlayer = player;
            tie = false;
        }
        if (player->handSize() == selectedPlayer->handSize() ){
            tie = true;
        }
    }
    if (tie) return owner();
    return selectedPlayer;
}

