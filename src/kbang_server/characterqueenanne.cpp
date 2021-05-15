#include "characterqueenanne.h"
#include "player.h"
#include "playingcard.h"
#include "cardbang.h"
#include "cardtaker.h"
#include "gametable.h"

CharacterQueenAnne::CharacterQueenAnne(QObject* parent):
        CharacterBase(parent, CHARACTER_UNKNOWN)
{
        setCharacterType(CHARACTER_QUEEN_ANNE);
 
}

void CharacterQueenAnne::useAbility(QList<PlayingCard*> cards){
     if (cards.empty()){
        throw BadCardException();
    }
    if (cards.size() < 3){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->owner() != mp_player) throw BadCardException();
        if (targetCard->type() != CARD_BANG) throw BadCardException();
        PlayingCard* targetCard1 = cards.at(1);
        if (targetCard1->owner() != mp_player) throw BadCardException();
        PlayingCard* targetCard2 = cards.at(2);
       PlayingCard* taker = new CardTaker(mp_player->game(), -1, CardTaker::CatBalou, targetCard->suit(), targetCard->rank());
       taker->setVirtual(mp_player, POCKET_HAND);
        taker->play(targetCard2);
        gameTable().playerDiscardCard(targetCard);
        gameTable().playerDiscardCard(targetCard1);
    }
}
