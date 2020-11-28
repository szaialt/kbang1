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

void CharacterDynamiteJoe::useAbility() 
{
    try {
        //if (gameTable().graveyardTop()->type() == CARD_DYNAMITE){
            PlayingCard* dynamite = mp_player->game()->gameTable().playerDrawDynamiteFromGraveyard(mp_player);
//             if (!(mp_player->game()->gameInfo().stackingDynamiteFlag())){
//                 if (player->hasIdenticalCardOnTable(dynamite)) {
//                      throw TwoSameOnTableException();
//                 }
//             }
//             gameTable().playerPlayCardOnTable(dynamite, player);
        }
    //}
    catch (BadGameStateException ex){
        throw BadUsageException();
    }

}

