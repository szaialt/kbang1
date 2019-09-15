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
#include "weaponcard.h"
#include "gameexceptions.h"
#include "player.h"
#include "gametable.h"
#include "gamecycle.h"
#include "characterbase.h"
#include "cardbang.h"
#include "cardteamfortressbang.h"
#include "cardmultishoot.h"

WeaponCard::WeaponCard(Game *game, int id, WeaponType type, CardSuit suit, CardRank rank):
        PlayingCard(game, id, CARD_UNKNOWN, suit, rank)
{
    switch(type) {
    case Volcanic:
        setType(CARD_VOLCANIC);
        m_range = 1;
        break;
    case Schofield:
        setType(CARD_SCHOFIELD);
        m_range = 2;
        break;
    case Remington:
        setType(CARD_REMINGTON);
        m_range = 3;
        break;
    case Carabine:
        setType(CARD_CARABINE);
        m_range = 4;
        break;
    case Winchester:
        setType(CARD_WINCHESTER);
        m_range = 5;
        break;
    case Guitar:
        setType(CARD_GUITAR);
        m_range = 0;
        break;
    case HalfZatochi:
        setType(CARD_HALF_ZATOCHI);
        m_range = 1;
        break;
    case MediGun:
        setType(CARD_MEDI_GUN);
        m_range = 2;
        break;
    case Sandman:
        setType(CARD_SANDMAN);
        m_range = 2;
        break;
    case Shotgun:
        setType(CARD_SHOTGUN);
        m_range = 1;
        break;
     case Walker:
        setType(CARD_WALKER);
        m_range = 1;
        break;
    case Bulldog1:
        setType(CARD_BULLDOG_1);
        m_range = 1;
        break;
    }
}

WeaponCard::~WeaponCard()
{
}

void WeaponCard::play()
{
    gameCycle()->assertTurn();

    if (this->pocket() != POCKET_HAND)
        throw BadUsageException();
    
    if (type() == CARD_GUITAR){
    throw BadUsageException();
    }
    foreach(PlayingCard* card, owner()->table()) {
        if (card->type() == CARD_SHOCK) throw BadUsageException();
    }
    int weaponNumber = owner()->getWeaponNumber();
    int ownedWeapons = 0;
    if ((!(game()->gameInfo().ourFlag())) || (!(owner()->isCharmed()) && (owner()->character()->characterType() == CHARACTER_SUZY_LAFAYETTE))){
      foreach(PlayingCard* card, owner()->table()) {
         if (card == 0)
            continue;
         if (card->type() == CARD_GUITAR){
            gameTable()->playerDiscardCard(card);
         }
         WeaponCard* weaponCard = qobject_cast<WeaponCard*>(card);
         if (weaponCard == 0)
            continue;
         ownedWeapons++;
         if (weaponCard->type() == type()){
            throw TwoSameOnTableException();
         }
         else {
              if (ownedWeapons >= weaponNumber){
                gameTable()->playerDiscardCard(weaponCard);
             }
          } 
       }
     gameTable()->playerPlayCardOnTable(this);
     }
     //We allow replaceing for everyone except of Suzy Lafayette
     //to stop her
      else {
        foreach(PlayingCard* card, owner()->table()) {
         if (card == 0)
            continue;
         if (card->isWeapon()){
            ownedWeapons++;
            if (ownedWeapons >= weaponNumber){
                gameTable()->playerDiscardCard(card);
            }
          }
          if (card->type() == CARD_GUITAR){
            gameTable()->playerDiscardCard(card);
          }
        }
    gameTable()->playerPlayCardOnTable(this);
    }
}


void WeaponCard::play(Player* targetPlayer){
    if (type() == CARD_GUITAR){
        gameCycle()->assertTurn();
        assertInHand();
        if (targetPlayer->hasIdenticalCardOnTable(this)) {
            throw TwoSameOnTableException();
        }
        foreach(PlayingCard* card, targetPlayer->table()) {
            if (card == 0)
                continue;
            if (card->isWeapon()){
                gameTable()->playerDiscardCard(card);
            }
    
        }
        gameTable()->playerPlayCardOnTable(this, targetPlayer);
    }
    else {
        throw BadUsageException();
    }
}
    



void WeaponCard::play(PlayingCard* targetCard, Player* targetPlayer){
    if (type () == CARD_MEDI_GUN){
        if (targetCard->type() == CARD_BANG){
            CardBang* healing = new CardTeamFortressBang(owner()->game(), 0, CardBang::HealingBang, targetCard->suit(), targetCard->rank());
            healing->setVirtual(targetCard);
            healing->play(targetPlayer);
        }
        else throw BadUsageException();
    }
    else if (type () == CARD_BULLDOG_1){
        if (targetCard->type() == CARD_BANG){
            CardMultiShoot* gatling = new CardMultiShoot(owner()->game(), 0, CardMultiShoot::Gatling, targetCard->suit(), targetCard->rank());
            gatling->setVirtual(targetCard);
            gatling->play();
        }
        else throw BadUsageException();
    }
    else throw BadUsageException();
}

CardColor WeaponCard::color() const {
    return COLOR_BLUE;
}

void WeaponCard::registerPlayer(Player* player)
{
    player->setWeaponRange(m_range);
    int infinityDistance = 99;
    player->setWeaponRange(m_range);
    if (!(owner()->isCharmed()) && (owner()->character()->characterType() == CHARACTER_SNIPER)){
        player->setWeaponRange(infinityDistance);
    }
    //We let Suzy to fire only one weapon in a turn
    if ((game()->gameInfo().ourFlag()) && !(owner()->isCharmed()) && (owner()->character()->characterType() == CHARACTER_SUZY_LAFAYETTE)){
        if (type() == CARD_VOLCANIC) {
          bool canPlayBang = owner()->canPlayBang();
          if (!canPlayBang) {
            player->modifyUnlimitedBangs(-1); // unlimitedBangs = -1
          }
          else {
            player->modifyUnlimitedBangs(1); // unlimitedBangs = 1
          }
        }
    }
    if (type() == CARD_VOLCANIC) {
        player->modifyUnlimitedBangs(1); // unlimitedBangs = 1
    }
}

void WeaponCard::unregisterPlayer(Player* player)
{
    player->setWeaponRange(1);
    if (type() == CARD_VOLCANIC) {
        player->modifyUnlimitedBangs(-1); // unlimitedBangs = 0
    }
}


