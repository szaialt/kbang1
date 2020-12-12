#include "characterprestonpresbyope.h"
#include "playingcard.h"

CharacterPrestonPresbyope::CharacterPrestonPresbyope(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_PRESTON_PRESBYOPE);
}

int CharacterPrestonPresbyope::maxLifePoints() const
{
  return 7;
}

 void CharacterPrestonPresbyope::useAbility(QList<PlayingCard*> cards){
    if (cards.size() < 2){
        throw BadCardException();
    }
    PlayingCard* targetCard = cards.at(0);
    if (targetCard->owner() != mp_player){
        throw BadCardException();
    }
    if ((targetCard->type() != CARD_APPALOSSA) && (targetCard->type() != CARD_MUSTANG)){
        throw BadCardException();
    }
    PlayingCard* targetCard2 = cards.at(1);
    if ((targetCard2->type() != CARD_APPALOSSA) && (targetCard2->type() != CARD_MUSTANG)){
        throw BadCardException();
    }
    Player* targetPlayer = targetCard2->owner();
    gameTable().playerStealCard(mp_player, targetCard2);
    gameTable().playerStealCard(targetPlayer, targetCard);
}
