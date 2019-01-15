#include "charactersuzylafayette.h"
#include "gametable.h"
#include "player.h"
#include "gamecycle.h"

CharacterSuzyLafayette::CharacterSuzyLafayette(QObject* parent):
        CharacterBase(parent, CHARACTER_SUZY_LAFAYETTE)
{
}

void CharacterSuzyLafayette::setPlayer(Player* player)
{
    CharacterBase::setPlayer(player);
    connect(player, SIGNAL(onEmptyHand()),
            this,   SLOT(onEmptyHand()));
}

void CharacterSuzyLafayette::onEmptyHand()
{
    Q_ASSERT(mp_player->handSize() == 0);
    if (!mp_player->isAlive()) return;
    //if ((gameCycle().gamePlayState() != GAMEPLAYSTATE_DISCARD) || mp_player->lifePoints() > 0){
        notifyAbilityUse();
        gameTable().playerDrawFromDeck(mp_player, 1, 0);
    //}
}
