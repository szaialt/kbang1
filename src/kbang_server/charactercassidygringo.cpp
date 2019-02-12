#include "charactercassidygringo.h"
#include "gametable.h"
#include "player.h"
#include "playingcard.h"
#include "cardbeer.h"

CharacterCassidyGringo::CharacterCassidyGringo(QObject* parent, Type type):
    CharacterBase(parent, CHARACTER_UNKNOWN),
    m_type(type)
{
    if (type == BartCassidy)
        setCharacterType(CHARACTER_BART_CASSIDY);
    else if (type == ElGringo)
        setCharacterType(CHARACTER_EL_GRINGO);
    else if (type == ViejoSikes)
        setCharacterType(CHARACTER_VIEJO_SIKES);
}

void CharacterCassidyGringo::setPlayer(Player* player)
{
    CharacterBase::setPlayer(player);
    connect(player, SIGNAL(onHit(int,Player*)),
            this,   SLOT(onHit(int,Player*)));
}

int CharacterCassidyGringo::maxLifePoints() const
{
    if (m_type == BartCassidy)
        return 4;
    else
        return 3;
}

void CharacterCassidyGringo::onHit(int lifePoints, Player* causedBy)
{
    if (m_type == BartCassidy) {
        notifyAbilityUse();
        gameTable().playerDrawFromDeck(mp_player, lifePoints, 0);
        return;
    }
    if (m_type == ElGringo) {
        if (causedBy == 0 || causedBy == mp_player) return;
        notifyAbilityUse();
        for (int i = 0; i < lifePoints; ++i) {
            PlayingCard* targetCard = causedBy->getRandomCardFromHand();
            if (targetCard == 0) return;
            gameTable().playerStealCard(mp_player, targetCard);
        }
        return;
    }
    if (m_type == ViejoSikes) {
        notifyAbilityUse();
        mp_player->modifyDistanceIn(1);
        return;
    }
}

void CharacterCassidyGringo::onHit(int lifePoints)
{
    if (m_type == ElGringo) return;
    if (m_type == BartCassidy) {
        notifyAbilityUse();
        gameTable().playerDrawFromDeck(mp_player, lifePoints, 0);
        return;
    }
    if (m_type == ViejoSikes) {
        notifyAbilityUse();
        mp_player->modifyDistanceIn(1);
        return;
    }
}

void CharacterCassidyGringo::playCard(PlayingCard* card)
{
    if (m_type == ViejoSikes) {
        CardBeer* beer = qobject_cast<CardBeer*>(card);
         if (beer == 0)
            ;
         else {
             if (mp_player->lifePoints() != mp_player->maxLifePoints())
                 mp_player->modifyDistanceIn(-1);
         }
         card->play();
    }
    else {
        card->play();
    }
}

