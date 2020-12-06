#include "characterjimmysquint.h"
#include "playingcard.h"

CharacterJimmySquint::CharacterJimmySquint(QObject* parent):
        CharacterBase(parent, CHARACTER_UNKNOWN)
{
        setCharacterType(CHARACTER_JIMMY_SQUINT); 
}


int CharacterJimmySquint::maxLifePoints() const
{
  return 5;
}

void CharacterJimmySquint::playCard(PlayingCard* card, Player* targetPlayer){
    if (card->type() == CARD_BANG){
        QList<Player*> seenPlayer;
        Player* player;
        foreach (player, mp_player->game()->playerList()){
            if  (mp_player->game()->getDistance(mp_player, player) <= mp_player->weaponRange()){
              seenPlayer.append(player);
            }
        }
        
        int size = seenPlayer.size();
        if (size == 0) return;
        card->play(seenPlayer[qrand() % size]);
        
     }
    else {
        card->play(targetPlayer);
    }
}
