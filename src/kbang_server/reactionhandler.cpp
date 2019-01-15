#include "reactionhandler.h"
#include "gameexceptions.h"

void ReactionHandler::respondPass()
{
    throw BadUsageException();
    
}

void ReactionHandler::respondCard(PlayingCard* targetCard)
{
    Q_UNUSED(targetCard);
    throw BadUsageException();
}

void ReactionHandler::respondCard(QList<PlayingCard*> targetCards){
    Q_UNUSED(targetCards);
    throw BadUsageException();
}

void ReactionHandler::dismiss()
{
    throw BadUsageException();
}
