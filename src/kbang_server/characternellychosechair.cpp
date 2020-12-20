#include "characternellychosechair.h"
#include "playingcard.h"
#include "cardbang.h"
#include "game.h"
#include <iostream>

CharacterNellyChoseChair::CharacterNellyChoseChair(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_NELLY_CHOSE_CHAIR);
}

void CharacterNellyChoseChair::useAbility(Player* targetPlayer){
    int myNumber = 0;
    Game* game = mp_player->game();
    foreach (Player* player, game->playerList()){
        if (player == mp_player)
            break;
        myNumber++;
    }
    myNumber++;
    if (myNumber >= game->playerList().size()) myNumber = 0;
    int targetNumber = 0;
    foreach (Player* player, game->playerList()){
        if (player == targetPlayer)
            break;
        targetNumber++;
    }
    targetNumber++;
    if (targetNumber >= game->playerList().size()) targetNumber = 0;
    game->swapPlayers(myNumber, targetNumber);
}

