#include "characterhenryblock.h"
#include "cardvalleyofshadowsbang.h"


CharacterHenryBlock::CharacterHenryBlock(QObject* parent):
    CharacterBase(parent, CHARACTER_UNKNOWN){
  setCharacterType(CHARACTER_HENRY_BLOCK);
  
}

void CharacterHenryBlock::setPlayer(Player* player)
{
    CharacterBase::setPlayer(player);
    //GameCycle gameCycle1 = player->game()->gameCycle();
    connect(&(player->game()->gameCycle()), SIGNAL(cardPlayed(Player*, PlayingCard*, Player*)),
            this,   SLOT(useAbility(Player*, PlayingCard*, Player*)));
    connect(&(player->game()->gameCycle()), SIGNAL(cardPlayed(Player*, PlayingCard*, PlayingCard*, Player*)),
            this,   SLOT(useAbility(Player*, PlayingCard*, PlayingCard*, Player*)));
    connect(&(player->game()->gameCycle()), SIGNAL(cardPlayed(Player*, PlayingCard*, PlayingCard*)),
            this,   SLOT(useAbility(Player*, PlayingCard*, PlayingCard*)));
    connect(&(player->game()->gameCycle()), SIGNAL(cardPlayed(Player*, PlayingCard*, QList<PlayingCard*>)),
            this,   SLOT(useAbility(Player*, PlayingCard*, QList<PlayingCard*>)));
    connect(&(player->game()->gameCycle()), SIGNAL(cardPlayed(Player*, PlayingCard*, QList<PublicPlayerView*>)),
            this,   SLOT(useAbility(Player*, PlayingCard*, QList<PublicPlayerView*>)));
}

 void CharacterHenryBlock::useAbility(Player* player, PlayingCard* card, Player* targetPlayer){
    if ((isCardTaker(card)) && (card->owner() != mp_player) && (targetPlayer == mp_player)){
        qDebug() << "card->owner is " << card->owner()->name();
        qDebug() << "The player is " << mp_player->name();
        qDebug() << "hit(player)";
    }
}

 void CharacterHenryBlock::useAbility(Player* player, PlayingCard* card, PlayingCard* targetCard, Player* targetPlayer){
    if ((isCardTaker(card)) && (card->owner() != mp_player) && (targetPlayer == mp_player)){
        qDebug() << "card->owner is " << card->owner()->name();
        qDebug() << "The player is " << mp_player->name();
        qDebug() << "hit(player)";
    }
}
    
 void CharacterHenryBlock::useAbility(Player* player, PlayingCard* card, PlayingCard* targetCard){
    if ((isCardTaker(card)) && (card->owner() != mp_player) && (targetCard->owner() == mp_player)){
        qDebug() << "card->owner is " << card->owner()->name();
        qDebug() << "The player is " << mp_player->name();
        qDebug() << "hit(player)";
    }
}
    
 void CharacterHenryBlock::useAbility(Player* player, PlayingCard* card, QList<PlayingCard*> targetCards){
     foreach(PlayingCard* c, targetCards) {
         if ((card->owner() != mp_player) && (c->owner() == mp_player)){
             qDebug() << "card->owner is " << card->owner()->name();
             qDebug() << "The player is " << mp_player->name();
             qDebug() << "hit(player)";
        }
    }
}
    
 void CharacterHenryBlock::useAbility(Player* player, PlayingCard* card, QList<PublicPlayerView*> targetPlayers){
//      foreach(PublicPlayerView p, targetPlayers) {
//          if (p == mp_player->publicView()){
//              qDebug() << "hit(player)";
//         }
//     }
}

void CharacterHenryBlock::hit(Player* targetPlayer){
    PlayingCard* hit = new CardValleyOfShadowsBang(mp_player->game(), -3, CardBang::Hit, SUIT_INVALID, 3);
    hit->setVirtual(targetPlayer, POCKET_HAND);
    hit->play();
}

bool CharacterHenryBlock::isCardTaker(PlayingCard* card){
    switch (card->type()){
        case CARD_PANIC:
        case CARD_CATBALOU:
        case CARD_CAN_CAN:
        case CARD_CONESTOGA:
        case CARD_RAG_TIME:
            return true;
        default:
            return false;
    }
}
