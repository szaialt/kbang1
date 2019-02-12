#include "characterjohnford.h"
#include "playingcard.h"
#include "cardbang.h"
#include "characterlist.h"

CharacterJohnFord::CharacterJohnFord(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_JOHN_FORD);
}

void CharacterJohnFord::useAbility(QList<PlayingCard*> cards, Player* targetPlayer){
    if (cards.empty()){
        throw BadCardException();
    }
    else {
        PlayingCard* card = cards.at(0);
        if (card->owner() != mp_player) throw BadCardException();
        if (card->pocket() != POCKET_HAND) 
        if (card->type() != CARD_BANG) throw BadCardException();
        
        PlayerRole role = targetPlayer->role();
        CharacterList characters = CharacterList(player()->game(), player()->game()->playerList().size());
        QListIterator<CharacterBase*> cIt(characters);
        targetPlayer->setRoleAndCharacter(cIt.peekNext(), role);
        gameTable().playerDiscardCard(card);
    }
}


