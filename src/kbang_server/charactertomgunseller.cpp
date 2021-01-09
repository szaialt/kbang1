#include "charactertomgunseller.h"
#include "playingcard.h"

CharacterTomGunSeller::CharacterTomGunSeller(QObject* parent):
    CharacterBase(parent, CHARACTER_TOM_GUN_SELLER){

}

void CharacterTomGunSeller::setPlayer(Player* player)
{
    CharacterBase::setPlayer(player);
        player->setWeaponNumber(99);
}

void CharacterTomGunSeller::playCard(PlayingCard* card, Player* targetPlayer){
    if (card->hasBangSymbol()){
        if (calculateWeapons() < 2) card->play(targetPlayer);
        else {
            throw BadCardException();
        }
    }
    else {
        card->play(targetPlayer);
    }
}

 void CharacterTomGunSeller::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
     if (cards.size() < 2) throw BadCardException();
     PlayingCard* card1 = cards.at(0);
     if (card1->owner() != mp_player) throw BadCardException();
     if (card1->pocket() != POCKET_TABLE) throw BadCardException();
     if (!card1->isWeapon()) throw BadCardException();
     PlayingCard* card2 = cards.at(1);
     if (card2->pocket() != POCKET_HAND) throw BadCardException();
     if (!card2->hasBangSymbol()) throw BadCardException();
     card1->registerPlayer(mp_player);
     card2->play(targetPlayer);
}

int CharacterTomGunSeller::calculateWeapons(){
    int weapons = 0;
    QList<PlayingCard*> table = mp_player->table();
       foreach(PlayingCard* c, table){
        if (c->isWeapon()){
            weapons++;
        }
    }
    return weapons;
}
