#include "charactermatthewhell.h"
#include "game.h"
#include "playingcard.h"

CharacterMatthewHell::CharacterMatthewHell(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_MATTHEW_HELL);
}

void CharacterMatthewHell::useAbility(QList<PlayingCard*> cards) 
{
    if (mp_player->lifePoints() > 1){
        if (cards.empty()) throw BadCardException();
        PlayingCard* card = cards.at(0);
        if (card->owner() != mp_player) throw BadCardException();
        if (card->pocket() != POCKET_HAND) throw BadCardException();
        if (card->color() != COLOR_BLUE) throw BadCardException();
        mp_player->modifyLifePoints(-1, 0);
        mp_player->game()->gameTable().playerDiscardCard(card);
        mp_player->game()->gameTable().drawGraveyardIntoSelection(mp_player);
        notifyAbilityUse();
        gameCycle().setResponseMode(this, mp_player);
    }
    else {
        throw BadUsageException();
    }
}

void CharacterMatthewHell::respondCard(PlayingCard* targetCard)
{
    if (targetCard->pocket() != POCKET_SELECTION)
        throw BadCardException();
    gameTable().playerPickFromSelection(mp_player, targetCard);
    gameCycle().unsetResponseMode();
    foreach(PlayingCard* p, gameTable().selection()){
        gameTable().undrawFromSelection(p);
    }
    Q_ASSERT(gameTable().selection().size() == 0);
    gameTable().shuffleDeck();
}
