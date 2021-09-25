#include "characterdynamitejoe.h"
#include "game.h"
#include "playingcard.h"

CharacterDynamiteJoe::CharacterDynamiteJoe(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_DYNAMITE_JOE);
}

int CharacterDynamiteJoe::maxLifePoints() const
{
  return 5;
}

void CharacterDynamiteJoe::useAbility(Player* targetPlayer) 
{
    try {
            PlayingCard* dynamite = mp_player->game()->gameTable().playerDrawDynamiteFromGraveyard(mp_player);
            if (!(mp_player->game()->gameInfo().stackingDynamiteFlag())){
              if (targetPlayer->hasIdenticalCardOnTable(dynamite)) {
                throw TwoSameOnTableException();
             }
          }
          gameTable().playerPlayCardOnTable(dynamite, targetPlayer);
            //dynamite->play(targetPlayer);
        }
    catch (BadGameStateException ex){
        throw BadUsageException();
    }

}

