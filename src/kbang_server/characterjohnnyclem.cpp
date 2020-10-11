#include "characterjohnnyclem.h"
#include "player.h"
#include "playingcard.h"
#include "gametable.h"

CharacterJohnnyClem::CharacterJohnnyClem(QObject* parent):
        CharacterBase(parent, CHARACTER_JOHNNY_CLEM)
     
{
}

int CharacterJohnnyClem::maxLifePoints() const
{
    return 5;
}

void CharacterJohnnyClem::useAbility(QList<PlayingCard*> cards){
    if (cards.size() < 4){
        throw BadCardException();
    }
    else {
        PlayingCard* targetCard = cards.at(0);
        if (targetCard->owner() != mp_player) throw BadCardException();
        PlayingCard* targetCard2 = cards.at(1);
        if (targetCard2->owner() != mp_player) throw BadCardException();
        PlayingCard* targetCard3 = cards.at(2);
        if (targetCard3->owner() != mp_player) throw BadCardException();
        PlayingCard* targetCard4 = cards.at(3);
        if (targetCard4->owner() != mp_player) throw BadCardException();
        gameTable().playerDiscardCard(targetCard);
        gameTable().playerDiscardCard(targetCard2);
        gameTable().playerDiscardCard(targetCard3);
        gameTable().playerDiscardCard(targetCard4);
        Player* p1 = player();
        
        if (p1->lifePoints() > 0){
            p1->modifyLifePoints(1, 0);
        }
        for (Player* p = player()->game()->nextPlayer(p1);
             p != p1;
             p = player()->game()->nextPlayer(p)) {
            if (p->lifePoints() > 0){
                p->modifyLifePoints(1, 0);
            }
        }
        
        notifyAbilityUse();
    }
} 


