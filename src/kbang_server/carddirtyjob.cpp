#include "carddirtyjob.h"
#include "gametable.h"
#include "characterlist.h"

CardDirtyJob::CardDirtyJob(Game* game, int id, CardSuit cardSuit, CardRank cardRank):
        PlayingCard(game, id, CARD_DIRTY_JOB, cardSuit, cardRank)
{
}

void CardDirtyJob::play(Player* targetPlayer)
{
    gameCycle()->assertTurn();
    assertInHand();
    if (targetPlayer->isAlive()) throw BadUsageException();
    if (targetPlayer->hasIdenticalCardOnTable(this)) {
        throw TwoSameOnTableException();
    }
    Player* owner1 = owner();
    gameTable()->playerPlayCard(this, targetPlayer);
    targetPlayer->setAlive(true);
    targetPlayer->modifyLifePoints(1, owner1);
    PlayerRole role = ROLE_RENEGADE;
    CharacterList characters = CharacterList(owner1->game(), owner1->game()->playerList().size());
    QListIterator<CharacterBase*> cIt(characters);
    targetPlayer->setRoleAndCharacter(cIt.peekNext(), role);
    gameTable()->playerDrawFromDeck(targetPlayer, 3, 0);
    owner1->game()->installNewRenegade();
}
 
