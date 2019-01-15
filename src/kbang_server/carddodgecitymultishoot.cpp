#include "carddodgecitymultishoot.h"
#include "gametable.h"
#include "gamecycle.h"
#include "game.h"
#include "player.h"
#include "gameexceptions.h"
#include "cardbarrel.h"

CardDodgeCityMultiShoot::CardDodgeCityMultiShoot(Game* game, int id, CardMultiShoot::Type type, CardSuit cardSuit, CardRank cardRank):
        CardMultiShoot(game, id, Type::Gatling, cardSuit, cardRank)
{
        setType(CARD_HOWITZER);

}

CardColor CardDodgeCityMultiShoot::color() const{
    return COLOR_GREEN;
}
 

void CardDodgeCityMultiShoot::play()
{
    gameCycle()->assertTurn();
    playAsGreenCard();
}

void CardDodgeCityMultiShoot::takeGreenCardEffect(){
    mp_shootingPlayer = owner();
    mp_requestedPlayer = owner();
    m_usedBarrels.clear();
    requestNext();
}

void CardDodgeCityMultiShoot::checkResult(bool result)
{
    Q_ASSERT(type() == CARD_HOWITZER);
    if (result) {
        game()->gameCycle().unsetResponseMode();
        requestNext();
    }
}


ReactionType CardDodgeCityMultiShoot::reactionType() const
{
      return REACTION_HOWITZER;
}

