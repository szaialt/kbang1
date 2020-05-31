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
    qDebug() << "CharacterQueenAnne::useAbility 1";
     if (cards.empty()){
        throw BadCardException();
    }
    if (cards.size() < 3){
        throw BadCardException();
    }
    else {
        qDebug() << "CharacterQueenAnne::useAbility 2";
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->owner() != mp_player) throw BadCardException();
        if (targetCard->type() != CARD_BANG) throw BadCardException();
        PlayingCard* targetCard1 = cards.at(1);
        if (targetCard1->owner() != mp_player) throw BadCardException();
        PlayingCard* targetCard2 = cards.at(2);
        qDebug() << "CharacterQueenAnne::useAbility 3";
       PlayingCard* taker = new CardTaker(mp_player->game(), -1, CardTaker::CatBalou, SUIT_INVALID, 5);
       taker->setVirtual(mp_player, POCKET_HAND);
       qDebug() << "CharacterQueenAnne::useAbility 4";
        taker->play(targetCard2);
        qDebug() << "CharacterQueenAnne::useAbility 5";
    }
}
