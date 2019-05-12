#include "cardstunning.h"
#include "gamecycle.h"
#include "gameexceptions.h"
#include "gametable.h"
#include "game.h"
#include "player.h"
#include "cardbang.h"

CardStunning::CardStunning(Game *game, int id, CardSuit suit, CardRank rank):
        PlayingCard(game, id, CARD_STUNNING, suit, rank)
{

}

CardColor CardStunning::color() const {
    return COLOR_BLUE;
}

void CardStunning::play()
{
    assertInHand();
    gameCycle()->assertTurn();
    playAsBlueCard();
    
}    

void CardStunning::play(PlayingCard* targetCard, Player* targetPlayer)
{
    assertOnTable();
    gameCycle()->assertTurn();
    if (targetCard == 0) throw BadUsageException();
    if (targetCard->type() != CARD_BANG) throw BadUsageException();
    CardBang* stunning1 = new CardBang(owner()->game(), 0, CardBang::Stunning, targetCard->suit(), targetCard->rank());
    stunning1->setVirtual(targetCard);
    stunning1->play(targetPlayer);
}


