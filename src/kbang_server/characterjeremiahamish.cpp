#include "characterjeremiahamish.h"
#include "gamecycle.h"
#include "gametable.h"
#include "gameexceptions.h"
#include "player.h"
#include "playingcard.h"
#include "reactionhandler.h"


CharacterJeremiahAmish::CharacterJeremiahAmish(QObject *parent):
        CharacterBase(parent, CHARACTER_JEREMIAH_AMISH)
{
}

void CharacterJeremiahAmish::playCard(PlayingCard* card){
    if (card->type() == CARD_BEER){
        gameTable().playerDrawFromDeck(mp_player, 2);
        gameTable().playerPlayCard(card);
    }
    else {
        card->play();
    }
}

void CharacterJeremiahAmish::useAbility(QList<PlayingCard*> cards)
{
    if (cards.size() != 2)
        throw BadCardException();

    foreach (PlayingCard* card, cards) {
        if (card->type() != CARD_BANG)
            throw BadCardException();
    }
    
    foreach (PlayingCard* card, cards) {
        if (card->owner() != mp_player ||
            card->pocket() != POCKET_HAND)
            throw BadCardException();
    }

    if (gameCycle().gamePlayState() == GAMEPLAYSTATE_TURN &&
        gameCycle().currentPlayer() == mp_player) {
        notifyAbilityUse();
        foreach (PlayingCard* card, cards) {
            gameTable().playerDiscardCard(card);
        }
        mp_player->modifyLifePoints(1, 0);
        return;
    }

    if (gameCycle().gamePlayState() == GAMEPLAYSTATE_RESPONSE &&
        gameCycle().requestedPlayer() == mp_player &&
        gameCycle().reactionHandler()->reactionType() == REACTION_LASTSAVE) {
        notifyAbilityUse();
        foreach (PlayingCard* card, cards) {
            gameTable().playerDiscardCard(card);
        }
        gameCycle().reactionHandler()->dismiss();
        return;
    }
    throw BadGameStateException();
}
