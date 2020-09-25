#include "characterbuckshotroberts.h"
#include "player.h"
#include "gametable.h"
#include "gamecycle.h"
#include "playingcard.h"
#include "cardtaker.h"

CharacterBuckshotRoberts::CharacterBuckshotRoberts(QObject* parent, Type type):
        CharacterBase(parent, CHARACTER_UNKNOWN)
       
{
    switch(type) {
        case BuckshotRoberts:
            setCharacterType(CHARACTER_BUCKSHOT_ROBERTS);
           break;
        case DroseraAlba:
            setCharacterType(CHARACTER_DROSERA_ALBA);
            break;
        }
}

int CharacterBuckshotRoberts::maxLifePoints() const {
    return 5;
}

void CharacterBuckshotRoberts::useAbility(QList<PlayingCard*> cards){
    if (cards.size() < 4)  throw BadCardException();
    PlayingCard* card= cards.at(0);
    if (card->owner() != mp_player) throw BadCardException();
    if (characterType() == CHARACTER_BUCKSHOT_ROBERTS){
        if (card->type() != CARD_CATBALOU) throw BadCardException();
    }
    else {
        if (card->type() != CARD_PANIC) throw BadCardException();
    }
    PlayingCard* card1= cards.at(1);
    if (card1->owner() != mp_player) throw BadCardException();
    if (card1->type() != CARD_MISSED) throw BadCardException();
    gameTable().cancelCard(card1);
    QList<PlayingCard*> targetCards;
    targetCards.append(cards.at(2));
    targetCards.append(cards.at(3));
    PlayingCard* taker;
    if (characterType() == CHARACTER_BUCKSHOT_ROBERTS) {
        taker = new CardTaker(mp_player->game(), -1, CardTaker::DoubleCatBalou, SUIT_INVALID, 5);
    }
    else {
        taker = new CardTaker(mp_player->game(), -1, CardTaker::DoublePanic, SUIT_INVALID, 5);
    }
    taker->setVirtual(card);
    taker->play(targetCards);
    notifyAbilityUse();
}
