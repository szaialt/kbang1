#include "playerreaper.h"
#include "player.h"
#include "game.h"
#include "gametable.h"
#include "charactervulturesam.h"
#include "playingcard.h"
#include "gameeventmanager.h"

PlayerReaper::PlayerReaper(Game* game):
        mp_game(game),
        vultureIndex(0)
{
}


void PlayerReaper::cleanUpCards(Player* corpse)
{
    //Clean m_vultures from no vulture characters
    foreach (CharacterBase* character, m_vultures){
        if (character->characterType() != CHARACTER_VULTURE_SAM) {
            m_vultures.removeAll(character);
        }
    }
    if (m_vultures.empty()){
      foreach(PlayingCard* card, corpse->hand()){
        mp_game->gameTable().cancelCard(card);
      }
      foreach(PlayingCard* card, corpse->table()){
          if (card != 0){
              mp_game->gameTable().cancelCard(card);
          }
      }
    }
    else if (m_vultures.size() == 1){
        CharacterBase* vulture = m_vultures.at(0);
        if (vulture->characterType() == CHARACTER_VULTURE_SAM) {
            CharacterVultureSam * vultureSam = qobject_cast<CharacterVultureSam*>(vulture);
            vultureSam->cleanUpCards(corpse);
        }
    }
    else {
        Q_ASSERT(m_selection.isEmpty());
        foreach(PlayingCard* card, corpse->hand()){
            Q_ASSERT(!card->isVirtual());
            m_selection.append(card);
        }
        foreach(PlayingCard* card, corpse->table()){
            Q_ASSERT(!card->isVirtual());
            m_selection.append(card);
        }
        while (!m_selection.isEmpty()){
            QList<CharacterBase*> vultures = m_vultures;
            CharacterBase* vulture = vultures.at(vultureIndex % vultures.size());
            int index = rand() % m_selection.size();
            PlayingCard* card = m_selection.at(index);
            GameTable gameTable = vulture->player()->game()->gameTable();
            gameTable.playerStealCard(vulture->player(), card);
            m_selection.removeAll(card);
            vultureIndex++;
        }
        foreach(CharacterBase* vulture, m_vultures){
            mp_game->gameEventManager().onPlayerUpdated(vulture->player());
        }
    }
    
}

 void PlayerReaper::registerVulture(CharacterBase* vulture) {
          m_vultures.push_back(vulture);
      }

 void PlayerReaper::unregisterVulture(CharacterBase* vulture) {
          m_vultures.removeAll(vulture);
      }
