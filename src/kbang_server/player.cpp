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
#include "player.h"
#include "game.h"
#include "client.h"
#include "cards.h"
#include "playerctrl.h"
#include "gameeventmanager.h"
#include "characterbase.h"
#include "charactercassidygringo.h"
#include "characterfastfranz.h"

#include "gameinfo.h"
#include "gamecycle.h"
#include "gametable.h"
#include <stdexcept>
 
Player::Player(Game* game, int id, const CreatePlayerData& createPlayerData):
        QObject(game),
        m_id(id),
        m_lifePoints(0),
        m_name(createPlayerData.name),
        m_password(createPlayerData.password),
        m_avatar(createPlayerData.avatar),
        m_role(ROLE_UNKNOWN),
        mp_character(0),
        m_isAlive(1),
        m_isWinner(0),
        m_last_saved(0),
        mp_game(game),
        mp_gameEventListener(0),
        m_weaponRange(1),
        m_distanceIn(0),
        m_distanceOut(0),
        m_lastBangTurn(-1),
        m_unlimitedBangs(0),
        m_bangPower(1),
        m_publicPlayerView(this),
        m_privatePlayerView(this),
        m_weaponNumber(1),
        m_banged(0),
        m_is_HexxZombie(false),
        m_elixirPlayed(false)
{

    mp_playerCtrl = new PlayerCtrl(this);
    m_predrawChecks.append(0);
    //m_adversaries = new QList<PublicPlayerView*>();
}

Player::~Player()
{
    unregisterGameEventListener();
}


CharacterType Player::characterType() const
{
    if (mp_character == 0)
        return CHARACTER_UNKNOWN;
    return mp_character->characterType();
}

bool Player::isAI() const
{
    return mp_gameEventListener != 0 && mp_gameEventListener->isAI();
}

bool Player::isPublicRole() const
{
    return role() == ROLE_SHERIFF || !isAlive() || mp_game->isFinished();
}

bool Player::isCreator() const
{
    return (mp_game->gameInfo().creatorId() == m_id);
}

bool Player::isOnTurn() const
{
    return (mp_game->gameCycle().currentPlayer() == this);
}

bool Player::isRequested() const
{
    return (mp_game->gameCycle().requestedPlayer() == this);
}

bool Player::hasIdenticalCardOnTable(PlayingCard* card) const
{
    foreach(PlayingCard* c, m_table) {
        if (card->type() == c->type())
            return 1;
    }
    return 0;
}

bool Player::canPlayBang() const
{
    if (m_unlimitedBangs > 0) return true;
    if (m_lastBangTurn != mp_game->gameCycle().turnNumber())
    {
        m_banged = 1; 
        return true;
    }
    if (m_banged < m_weaponNumber) {
        m_banged++; 
        return true;
    }
    return false;
}

void Player::modifyLifePoints(int x, Player* causedBy)
{
    int modification = x;
    if ((x > 0) && (lifePoints() == maxLifePoints() - 1)){
        foreach (PlayingCard* card, table()){
            if (card->type() == CARD_BLEEDING_INJURY){
                modification--;
                mp_game->gameTable().playerDiscardCard(card);
            }
        }
    }
    if ((x < 0) && (characterType() == CHARACTER_FAST_FRANZ)){
        CharacterFastFranz* franz =  qobject_cast<CharacterFastFranz*>(character());
        PlayingCard* checkedCard = game()->gameTable().checkDeck();
        bool checkResult = franz->check(checkedCard);
        if (checkResult){
            return;
        }
    }
    // modify lifePoints member
    int oldLifePoints = m_lifePoints;
    m_lifePoints += modification;
    if ((m_lifePoints > m_maxLifePoints) && (characterType() != CHARACTER_BILLY_LONGLIFE) && (characterType() != CHARACTER_DAN_QUAKE)){
        if (!m_elixirPlayed){
            m_lifePoints = m_maxLifePoints;
        }
        else {
            setElixirPlayed(false);
        }
    }
        //Don't go into negative 
     if (game()->gameInfo().ourFlag()){
       if (m_lifePoints < 0){
          m_lifePoints = 0;
       }
     }
    
    // only if lifePoints actually changed, have the event sent
    if (oldLifePoints != m_lifePoints) {
        game()->gameEventManager().onLifePointsChange(this, m_lifePoints, causedBy);
    }
    int hitPoints = oldLifePoints - m_lifePoints;

    // allow last save
    if (m_lifePoints <= 0) {
        mp_game->beerRescue()->allowSaveWithBeer(causedBy, this, 1 - m_lifePoints, hitPoints);
        // onHit signal is emitted only if player saves himself with beer(s)
    }

    // emit onHit only if player was hit and is not dying
    if (m_lifePoints > 0 && hitPoints > 0) {
        emit onHit(hitPoints, causedBy);
    }
}

void Player::lastSaveSuccess(int hitPoints, Player* causedBy)
{
    modifyLifePoints(1, this);
    emit onHit(hitPoints, causedBy);
}

void Player::lastSaveFailure(int hitPoints, Player* causedBy)
{
    Q_UNUSED(hitPoints);
    //Teren Kill 
    if (character()->characterType() == CHARACTER_FAST_FRANZ){
        CharacterFastFranz* franz =  qobject_cast<CharacterFastFranz*>(character());
        PlayingCard* checkedCard = game()->gameTable().checkDeck();
        bool checkResult = franz->check(checkedCard);
        if (checkResult){
            m_lifePoints = 1;
            return;
        }
    }
    mp_game->buryPlayer(this, causedBy);
}



void Player::modifyDistanceIn(int delta)
{
    m_distanceIn += delta;
}

void Player::modifyDistanceOut(int delta)
{
    m_distanceOut += delta;
}

void Player::modifyUnlimitedBangs(int delta)
{
    m_unlimitedBangs += delta;
}

void Player::setBangPower(int bangPower)
{
    m_bangPower = bangPower;
}

void Player::setWeaponRange(int weaponRange)
{
    m_weaponRange = weaponRange;
}

void Player::setAlive(bool isAlive)
{
    m_isAlive = isAlive;
    if (isAlive == 0){
        mp_character->playerDied();
    }
    
}

void Player::setWinner(bool isWinner) {
    m_isWinner = isWinner;
}

void Player::appendCardToHand(PlayingCard * card)
{
    m_hand.append(card);
    //qDebug() << "Handsize: " << handSize();
}

void Player::appendCardToTable(PlayingCard* card)
{
    m_table.append(card);
}

void Player::appendCardToSelection(PlayingCard* card)
{
    m_selection.append(card);
}

void Player::setPassword(const QString& password)
{
    m_password = password;
}

bool Player::removeCardFromHand(PlayingCard* card)
{
    bool removed = m_hand.removeOne(card);
    qDebug() << "Handsize: " << handSize(); 
    foreach (card, hand()){
        qDebug() << "pocket: " << pocketTypeToString(card->pocket());
    }
    qDebug() << "Tablesize: " << table().size();
    //Player* player;
    foreach (card, table()){
        qDebug() << "pocket: " << pocketTypeToString(card->pocket());
    }
    return removed;
}

PlayingCard* Player::getRandomCardFromHand()
{
    int size = m_hand.size();
    if (size == 0) return 0;
    return m_hand[qrand() % size];
}

PlayingCard* Player::getRandomCardFromTable()
{
    int size = m_table.size();
    if (size == 0) return 0;
    return m_table[qrand() % size];
}

PlayingCard* Player::getRandomCard(){
    if (m_table.size() == 0) return getRandomCardFromHand();
    if (m_hand.size() == 0) return getRandomCardFromTable();
    int fromHand = qrand() % 2;
    if (fromHand > 0) return getRandomCardFromHand();
    return getRandomCardFromTable();
}

bool Player::removeCardFromTable(PlayingCard* card)
{
    return m_table.removeOne(card);
}

bool Player::removeCardFromSelection(PlayingCard* card)
{
    return m_selection.removeOne(card);
}

void Player::setRoleAndCharacter(CharacterBase* character, const PlayerRole& role)
{
    Q_ASSERT(mp_character == 0);
    
    mp_character = character;
    mp_character->setPlayer(this);
    m_maxLifePoints = character->maxLifePoints();
    //m_maxLifePoints = 9;
    m_role = role;
    if (m_role == ROLE_SHERIFF) {
        m_maxLifePoints++;
        //Give a plus lifePoint to CHARACTER_BIG_FAT_JOE, he is weak
        if (characterType() == CHARACTER_BIG_FAT_JOE)
            m_maxLifePoints++;
    }
    // Paul Regret is too weak character to have only 3 HP-s
    if ((game()->gameInfo().ourFlag()) && (character->characterType() == CHARACTER_PAUL_REGRET)) {
        m_maxLifePoints++;
    }
    m_lifePoints = m_maxLifePoints;
}

void Player::registerPredrawCheck(int priority)
{
    m_predrawChecks.append(priority);
    qSort(m_predrawChecks.begin(), m_predrawChecks.end());
}

void Player::unregisterPredrawCheck(int priority)
{
    m_predrawChecks.removeAll(priority);
}

void Player::predrawCheck(int checkId)
{
   
    if (m_currentPredraw > checkId){
         throw BadPredrawException();
    }
    if (checkId == 0){
        return;
    }
    int index = m_predrawChecks.indexOf(checkId);
    Q_ASSERT(index > 0);
    m_currentPredraw = m_predrawChecks[index - 1];
}

void Player::update(const CreatePlayerData& createPlayerData)
{
    m_name = createPlayerData.name;
    m_password = createPlayerData.password;
    m_avatar = createPlayerData.avatar;
}

int Player::getWeaponNumber(){
    return m_weaponNumber;
}

void Player::setWeaponNumber(int n){
    m_weaponNumber = n;
}

void Player::onBangPlayed(bool b)
{
    if (b){
        m_lastBangTurn = mp_game->gameCycle().turnNumber();
    }
    else {
        m_lastBangTurn = mp_game->gameCycle().turnNumber() - 1;
    }
}

void Player::onTurnStart()
{
    m_currentPredraw = m_predrawChecks.last();
}


void Player::registerGameEventListener(GameEventListener* gameEventListener)
{
    Q_ASSERT(mp_gameEventListener == 0);
    mp_gameEventListener = gameEventListener;
    mp_game->gameEventManager().registerHandler(mp_gameEventListener, this);
    
}

void Player::unregisterGameEventListener()
{
    if (mp_gameEventListener == 0) return;
    mp_game->gameEventManager().unregisterHandler(mp_gameEventListener);
    mp_gameEventListener = 0;
}


void Player::checkEmptyHand()
{
    if (m_hand.size() == 0) {
        if (game()->gameCycle().isCardEffect()) {
            QObject::connect(&game()->gameCycle(), SIGNAL(cardEffectOver()),
                             this, SLOT(checkEmptyHand()));
        } else {
            QObject::disconnect(&game()->gameCycle(), SIGNAL(cardEffectOver()),
                                this, SLOT(checkEmptyHand()));
            if ((game()->gameCycle().gamePlayState() != GAMEPLAYSTATE_DISCARD) || lifePoints() > 0){
                emit onEmptyHand();
            }
        }
    }
}

void Player::addAdversary(PublicPlayerView* p){
    m_adversaries.append(p);
}

bool Player::isCharmed(){
    return mp_playerCtrl->isCharmed();
}


void Player::charm(){
    mp_playerCtrl->charm();
}

void Player::unCharm(){
    mp_playerCtrl->unCharm();
}

void Player::setHexxZombie(bool b){
    m_is_HexxZombie = b;
}

void Player::setElixirPlayed(bool b){
    m_elixirPlayed = b;
}
