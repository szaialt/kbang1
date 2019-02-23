#include "characterwyattearp.h"
#include "playingcard.h"
#include "cardtaker.h"

CharacterWyattEarp::CharacterWyattEarp(QObject* parent, Type type):
    CharacterBase(parent, CHARACTER_UNKNOWN), m_type(type){
        
        switch(type) {
        case WyattEarp:
            setCharacterType(CHARACTER_WYATT_EARP);
            break;
        case RonRobber:
            setCharacterType(CHARACTER_RON_ROBBER);
            break;
        }
        
  setCharacterType(CHARACTER_WYATT_EARP);
}

void CharacterWyattEarp::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* card = cards.at(0);
        if (card->owner() != mp_player) throw BadCardException();
        if (card->pocket() != POCKET_HAND) throw BadCardException();
        if (card->type() == CARD_PANIC) {
            PlayingCard* catbalou = new CardTaker(mp_player->game(), 0, CardTaker::CatBalou, SUIT_INVALID,    10);
            catbalou->setVirtual(card);
            catbalou->play(targetPlayer);
        }
        else if (card->type() == CARD_CATBALOU) {
            PlayingCard* panic = new CardTaker(mp_player->game(), 0, CardTaker::Panic, SUIT_INVALID,    10);
            panic->setVirtual(card);
            panic->play(targetPlayer);
        }
        else {
            card->play(targetPlayer);
        }
    }
}


