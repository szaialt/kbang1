#include "gameinfo.h"
#include <iostream>

GameInfo::GameInfo(const CreateGameData& createGameData):
    m_name(createGameData.name),
//     m_description(createGameData.description),
    m_creatorId(0),
    m_minPlayers(createGameData.minPlayers),
    m_maxPlayers(createGameData.maxPlayers),
    m_maxSpectators(createGameData.maxSpectators),
    m_AIPlayers(createGameData.AIPlayers),
//     m_playerPassword(createGameData.playerPassword),
//     m_spectatorPassword(createGameData.spectatorPassword),
    m_shufflePlayersFlag(createGameData.flagShufflePlayers),
    // m_numberOfCharacterOfAPlayer(createGameData.numberOfCharacterOfAPlayer),
    // m_canChooseCharacter(createGameData.canChooseCharacter),
      m_lifePointsMaxFlag(createGameData.lifePointsMaxFlag),
      m_ourFlag(createGameData.ourFlag), 
      m_dodgeCityFlag(createGameData.dodgeCityFlag),
      m_teamFortressFlag(createGameData.teamFortressFlag),
      m_stackingDynamiteFlag(createGameData.stackingDynamiteFlag),
      m_teamFortressCharactersFlag(createGameData.teamFortressCharactersFlag),
      m_directorsCutsFlag(createGameData.directorsCutsFlag),
      m_directorsCutsCharactersFlag(createGameData.directorsCutsCharactersFlag),
      m_martinCityFlag(createGameData.martinCityFlag),
      m_martinCityCharactersFlag(createGameData.martinCityCharactersFlag),
      m_aiLevel(createGameData.aiLevel)
{
    
     std::cout << "AI level: " << m_aiLevel << std::endl;
     Q_ASSERT(!m_name.isEmpty());
     Q_ASSERT(m_minPlayers <= m_maxPlayers);

 } 


//StructGame GameInfo::structGame() const
//{
//    StructGame x;
//    x.id = m_id;
//    x.creatorId = m_creatorId;
//    x.name = m_name;
//    x.description = m_description;
//    x.minPlayers = m_minPlayers;
//    x.maxPlayers = m_maxPlayers;
//    x.maxSpectators = m_maxSpectators;
//    x.playerPassword = m_playerPassword;
//    x.spectatorPassword = m_spectatorPassword;
//    x.hasPlayerPassword = (!m_playerPassword.isNull());
//    x.hasSpectatorPassword = (!m_spectatorPassword.isNull());
//    x.flagShufflePlayers = m_shufflePlayersFlag;
//    return x;
//}
