#include "cardjail.h"

#include "gameexceptions.h"
#include "player.h"
#include "gametable.h"
#include "gamecycle.h"
#include "charactertomyleeghost.h"

CardJail::CardJail(Game *game, int id, JailType type, CardSuit suit, CardRank rank, int PredrawCheck):
        PlayingCard(game, id, CARD_JAIL, suit, rank)
{
    m_PredrawCheck = PredrawCheck;
    m_jailType = type;
    m_distanceModified = false;
    switch(m_jailType) {
    case Jail:
        setType(CARD_JAIL);
        break;
    case Sunglare:
        setType(CARD_SUN_GLARE);
        break;
    }
}

CardJail::~CardJail()
{
}

CardColor CardJail::color() const{
    return COLOR_BLUE;
}

void CardJail::play()
{
    
    gameCycle()->assertDraw();
    assertOnTable();
    owner()->predrawCheck(m_PredrawCheck);
    gameCycle()->checkDeck(owner(), this, *CardJail::checkJail, this);
}


void CardJail::play(Player* targetPlayer)
{
    gameCycle()->assertTurn();
    assertInHand();
    if (targetPlayer->role() == ROLE_SHERIFF){
        throw BadTargetPlayerException();
    }
    if (targetPlayer->characterType() == CHARACTER_TOMY_LEE_GHOST){
            CharacterTomyLeeGhost* ghost =  qobject_cast<CharacterTomyLeeGhost*>(targetPlayer->character());
            if (ghost->isAlive() && ghost->isAtFirstDead()){
                throw BadTargetPlayerException();
            }
        }
    if (targetPlayer->hasIdenticalCardOnTable(this)) {
        throw TwoSameOnTableException();
    }
    gameTable()->playerPlayCardOnTable(this, targetPlayer);
}

void CardJail::checkResult(bool result)
{       
    gameTable()->playerDiscardCard(this);
    if (!result) {
        if (type() == CARD_JAIL){
            gameCycle()->skipPlayersTurn();
        }
        else {
            gameCycle()->currentPlayer()->modifyDistanceOut(-1);
            m_distanceModified = true;
        }
    }
}


void CardJail::registerPlayer(Player* player)
{
    player->registerPredrawCheck(m_PredrawCheck);
}

void CardJail::unregisterPlayer(Player* player)
{
    player->unregisterPredrawCheck(m_PredrawCheck);
    if (m_distanceModified){
        player->modifyDistanceOut(1);
        m_distanceModified = false;
    }
}

bool CardJail::checkJail(PlayingCard* card)
{
    return (card->suit() == SUIT_HEARTS);

}
