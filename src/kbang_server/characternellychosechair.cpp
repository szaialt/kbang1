#include "characternellychosechair.h"
#include "playingcard.h"
#include "cardbang.h"
#include "gametable.h"
#include "game.h"
#include <iostream>

CharacterNellyChoseChair::CharacterNellyChoseChair(QObject* parent, Type type):
    CharacterBase(parent, CHARACTER_UNKNOWN),
    m_type(type){
        setCharacterType(CHARACTER_NELLY_CHOSE_CHAIR);
        if (type == NellyChoseChair)
          setCharacterType(CHARACTER_NELLY_CHOSE_CHAIR);
        else if (type == Spy)
          setCharacterType(CHARACTER_SPY);
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

void CharacterNellyChoseChair::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
    if (m_type == NellyChoseChair) {
        throw BadUsageException();
    }
    else {
        if (cards.empty()){
          throw BadCardException();
        }
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->owner() != mp_player) throw BadCardException();
        if (targetCard->pocket() != POCKET_HAND) throw BadCardException();
        if (targetCard->color() != COLOR_BLUE) throw BadCardException();
        gameTable().playerDiscardCard(targetCard);
        useAbility(targetPlayer);
    }
}
