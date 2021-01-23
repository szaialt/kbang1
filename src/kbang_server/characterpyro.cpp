#include "characterpyro.h"
#include "playingcard.h"
#include "cardbang.h"
#include "cardarson.h"
#include "gametable.h"
#include "game.h"
#include <iostream>

CharacterPyro::CharacterPyro(QObject* parent):
    CharacterBase(parent, CHARACTER_PYRO)
    {
}

void CharacterPyro::useAbility(QList<PlayingCard*> cards){
        if (cards.empty()){
          throw BadCardException();
        }
        if (cards.size() < 3){
          throw BadCardException();
        }
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->owner() != mp_player) throw BadCardException();
        if (targetCard->pocket() != POCKET_HAND) throw BadCardException();
        if (targetCard->type() != CARD_BANG) throw BadCardException();
        CardArson* arson = new CardArson(mp_player->game(), 0, CardMultiShoot::Arson,  targetCard->suit(), targetCard->rank());
        arson->setVirtual(targetCard);
        QList<Player*> targetPlayers;
        targetPlayers.append(cards.at(1)->owner());
        targetPlayers.append(cards.at(2)->owner());
        arson->play(targetPlayers);
        notifyAbilityUse();
}
