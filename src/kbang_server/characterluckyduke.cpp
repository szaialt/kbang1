#include "characterluckyduke.h"
#include "gametable.h"
#include "gamecycle.h"
#include "playingcard.h"
#include "cardbang.h"
#include "gameexceptions.h"
#include "player.h"
#include "game.h"
#include "gameeventmanager.h"
#include "checkdeckresulthandler.h"

CharacterLuckyDuke::CharacterLuckyDuke(QObject *parent):
        CharacterBase(parent, CHARACTER_LUCKY_DUKE)
{
}


void CharacterLuckyDuke::checkDeck(PlayingCard* causedBy,
                                   bool (*checkFunc)(PlayingCard*),
                                   CheckDeckResultHandler* resultHandler)
{

    mp_causedBy = causedBy;
    notifyAbilityUse();
    gameTable().drawIntoSelection(2);
    mp_resultHandler = resultHandler;
    mp_checkFunc = checkFunc;
    gameCycle().setResponseMode(this, mp_player, 1);
}

void CharacterLuckyDuke::respondCard(PlayingCard* checkedCard)
{
    if (checkedCard->pocket() != POCKET_SELECTION){
        throw BadCardException();
    }
    gameCycle().unsetResponseMode();
    
    PlayingCard* checkedCard1 = checkedCard;
    
    QList<PlayingCard*> table = mp_player->table();
        foreach (PlayingCard* card, table){
            if (card->type() == CARD_MEMENTO){
                if (checkedCard1->suit() == SUIT_CLUBS){
                    checkedCard1 = new CardBang(mp_player->game(), -1, CardBang::Bang, SUIT_HEARTS, 5);
                    checkedCard1->setVirtual(checkedCard);
                }
            }
        }
    bool checkResult = (*mp_checkFunc)(checkedCard1);
    mp_player->game()->gameEventManager().onPlayerCheckDeck(mp_player, checkedCard1, mp_causedBy, checkResult);
    gameTable().cancelSelection();
    mp_resultHandler->checkResult(checkResult);
}


