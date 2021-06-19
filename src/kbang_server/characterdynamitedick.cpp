#include "characterdynamitedick.h"
#include "game.h"
#include "playingcard.h"

CharacterDynamiteDick::CharacterDynamiteDick(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_DYNAMITE_DICK);
}

void CharacterDynamiteDick::playCard(PlayingCard* card, Player* targetPlayer){
    if (card->type() == CARD_DYNAMITE){
        gameCycle().assertTurn();

        //Double dynamite
        if (!(mp_player->game()->gameInfo().stackingDynamiteFlag())){
          if (targetPlayer->hasIdenticalCardOnTable(card)) {
            throw TwoSameOnTableException();
          }
        }
        gameTable().playerPlayCardOnTable(card, targetPlayer);
    }
    else {
        CharacterBase::playCard(card, targetPlayer);
    }
}

int CharacterDynamiteDick::maxLifePoints() const
{
  return 5;
}

void CharacterDynamiteDick::useAbility() 
{
    try {
        mp_player->game()->gameTable().playerDrawDynamiteFromGraveyard(mp_player);
    }
    catch (BadGameStateException ex){
        throw BadUsageException();
    }

}

