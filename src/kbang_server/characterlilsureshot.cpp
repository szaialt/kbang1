#include "characterlilsureshot.h"
#include "player.h"
#include "playingcard.h"
#include "cardbang.h"

CharacterLilSureshot::CharacterLilSureshot(QObject* parent):
        CharacterBase(parent, CHARACTER_UNKNOWN)
{
        setCharacterType(CHARACTER_LIL_SURE_SHOT);
 
}

void CharacterLilSureshot::setPlayer(Player* player)
{
    CharacterBase::setPlayer(player);
        player->setWeaponNumber(2);
}

void CharacterLilSureshot::useAbility(QList<PlayingCard*> cards){
     if (cards.empty()){
        throw BadCardException();
    }
    if (cards.size() < 3){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->owner() != mp_player) throw BadCardException();
        Player* targetPlayer1 = cards.at(1)->owner();
        Player* targetPlayer2 = cards.at(2)->owner();
        QList<Player*> targetPlayers;
        targetPlayers.append(targetPlayer1);
        targetPlayers.append(targetPlayer2);
        PlayingCard* hit = new CardBang(mp_player->game(), -1, CardBang::DoubleExtra, SUIT_INVALID, 5);
        hit->setVirtual(targetCard);
        hit->play(targetPlayers);
        
    }
}
