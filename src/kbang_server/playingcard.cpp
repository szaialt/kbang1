/***************************************************************************
 *   Copyright (C) 2008 by MacJariel                                       *
 *   echo "badmailet@gbalt.dob" | tr "edibmlt" "ecrmjil"                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "playingcard.h"
#include "gametable.h"
#include "game.h"
#include "gameexceptions.h"

PlayingCard::PlayingCard(Game *game, int id, PlayingCardType type, CardSuit suit, CardRank rank):
        QObject(game),
        m_id(id),
        m_type(type),
        m_suit(suit),
        m_rank(rank),
        mp_owner(0),
        m_pocket(POCKET_DECK),
        mp_game(game),
        m_isVirtual(0),
        m_act(false)
{
}

PlayingCard::~PlayingCard()
{
}

bool PlayingCard::isWeapon(){
    if (m_type == CARD_VOLCANIC) return true;
    if (m_type == CARD_SCHOFIELD) return true;
    if (m_type == CARD_REMINGTON) return true;
    if (m_type == CARD_CARABINE) return true;
    if (m_type == CARD_WINCHESTER) return true;
    if (m_type == CARD_HALF_ZATOCHI) return true;
    if (m_type == CARD_MEDI_GUN) return true;
    if (m_type == CARD_SANDMAN) return true;
    if (m_type == CARD_SHOTGUN) return true;
    if (m_type == CARD_WALKER) return true;
    if (m_type == CARD_BULLDOG_1) return true;
    if (m_type == CARD_BULLDOG_2) return true;
    if (m_type == CARD_JAMES_DOUGALL) return true;
    return false;
}

bool PlayingCard::hasBangSymbol(){
    switch(m_type) {
        case CARD_BANG:
        case CARD_DOUBLE_BANG:
        case CARD_DIRECT_HIT:
        case CARD_HEAVY_BANG:
        case CARD_TRIPLE_BANG:
        case CARD_QUAD_BANG:
        case CARD_INDIAN_BANG:
        case CARD_UNDEFENSABLE:
        case CARD_STUNNING_BANG:
        case CARD_EXTRA_BANG:
        case CARD_DOUBLE_EXTRA_BANG:
            return true;
        default:
            return false;
            
    }
    return false;
}


/**
* This method is called (by GameTable) when the card is
* put on the player's table.
*/
void PlayingCard::registerPlayer(Player*) {} 

/**
* This method is called (by GameTable) when the card is
* removed from the player's table.
*/
void PlayingCard::unregisterPlayer(Player*) {}

CardData PlayingCard::cardData() const
{
    CardData result;
    result.id = id();
    result.type = type();
    result.suit = suit();
    result.rank = rank();
    result.isAct = isAct();
    result.pocket = pocket();
    
    return result;
}

void PlayingCard::play()
{
   throw BadUsageException();
}

void PlayingCard::play(Player* targetPlayer)
{
    Q_UNUSED(targetPlayer);
    throw BadUsageException();
}

void PlayingCard::play(PlayingCard* targetCard)
{
    Q_UNUSED(targetCard);
    throw BadUsageException();
}

void PlayingCard::play(PlayingCard* targetCard, Player* targetPlayer){
    Q_UNUSED(targetCard);
    Q_UNUSED(targetPlayer); 
    throw BadUsageException();
}

void PlayingCard::play(QList<PlayingCard*> targetCards)
{
    Q_UNUSED(targetCards);
    throw BadUsageException();
}

void PlayingCard::play(QList<Player*> targetPlayers){
    Q_UNUSED(targetPlayers); 
    throw BadUsageException();
}

CardColor PlayingCard::color() const{
    return COLOR_BROWN;
}

void PlayingCard::playAsBlueCard()
{
    if ((color() == COLOR_BLUE)  && ((owner()->character()->characterType() == CHARACTER_JACK_BROWN) || (owner()->character()->characterType() == CHARACTER_SLOBODAN_THE_KILLER))){
        bool canBePlayed = false;
        if (isWeapon()) canBePlayed = true;
        if (m_type == CARD_DYNAMITE) canBePlayed = true;
        if (m_type == CARD_JAIL) canBePlayed = true;
        if (!canBePlayed) throw BadUsageException();
    }
    gameCycle()->assertTurn();
    assertInHand();
    foreach(PlayingCard* card, owner()->table()) {
        if (card->type() == CARD_SHOCK) throw BadUsageException();
    }
    //We allow replaceing for everyone except of Suzy Lafayette
    //to stop her
    if (!(game()->gameInfo().ourFlag()) || (!(owner()->isCharmed()) && (owner()->character()->characterType() == CHARACTER_SUZY_LAFAYETTE))){
       if (owner()->hasIdenticalCardOnTable(this)){
         throw TwoSameOnTableException();
       }
       else {
         gameTable()->playerPlayCardOnTable(this);
         qDebug() << "playAsBlueCard() pocket: " << pocketTypeToString(pocket());
      }
    } 
    
    else {
        if (owner()->hasIdenticalCardOnTable(this)){
          foreach(PlayingCard* card2, owner()->table()) {
            if (card2 == 0)
              continue;
            if (card2->type() == this->type()){
              if (card2->pocket() == POCKET_GRAVEYARD) {
                card2->setPocket(POCKET_TABLE);
                card2->setOwner(owner());
              }
              gameTable()->playerDiscardCard(card2);
            }
          }
        }
      gameTable()->playerPlayCardOnTable(this);
    }
    if (color() == COLOR_BROWN){
        setAct(true);
    }
}

void PlayingCard::takeGreenCardEffect(){
    //throw BadUsageException();
}

void PlayingCard::playAsGreenCard(){
    Player* owner = mp_owner;
    if (pocket() == POCKET_HAND) {
           playAsBlueCard();
        }
        else if ((pocket() == POCKET_TABLE) && (isAct())) {
          takeGreenCardEffect();
          setAct(false);
          if (m_pocket == POCKET_GRAVEYARD) {
              qDebug() << "POCKET_GRAVEYARD";
              setPocket(POCKET_TABLE);
              setOwner(owner);
          }
        //gameTable()->playerPlayCard(this);
        gameTable()->playerDiscardCard(this);  
     
      } 
}

GameTable* PlayingCard::gameTable() const
{
    return &mp_game->gameTable();
}

GameCycle* PlayingCard::gameCycle() const
{
    return &mp_game->gameCycle();
}

void PlayingCard::assertInHand() const
{
    if (pocket() != POCKET_HAND)
        throw BadCardException();
}

void PlayingCard::assertOnTable() const
{
    if (pocket() != POCKET_TABLE)
        throw BadCardException();
}

void PlayingCard::setVirtual(PlayingCard* master)
{
    mp_master   = master;
    m_isVirtual = 1;
    m_id        = 0;
    m_suit      = master->suit();
    m_rank      = master->rank();
    mp_owner    = master->owner();
    m_pocket    = master->pocket();
    mp_game     = master->game();
}

void PlayingCard::setVirtual(Player* owner, PocketType pocket)
{
    mp_master = 0;
    m_isVirtual = 1;
    m_id = 0;
    mp_owner = owner;
    m_pocket = pocket;
}


void PlayingCard::setType(PlayingCardType type)
{
    m_type = type;
}
