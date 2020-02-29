#include "characteredwardangle.h"
#include "playingcard.h"
#include "cardbang.h"
#include "game.h"
#include <iostream>

CharacterEdwardAngle::CharacterEdwardAngle(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_EDWARD_ANGLE);
}

void CharacterEdwardAngle::useAbility(){
    int i = 0;
    Game* game = mp_player->game();
    foreach (Player* player, game->playerList()){
        if (player == mp_player)
            break;
        i++;
    }
    int j = i + 1;
    if (j >= game->playerList().size()) j = 0;
    game->swapPlayers(i, j);
}

