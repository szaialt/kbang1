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

#ifndef GAMEINFO_H
#define GAMEINFO_H

#include "parser/parserstructs.h"


class GameInfo
{
public:
    GameInfo(const CreateGameData&);

    inline QString  name()                  const { return m_name; }
//     inline QString  description()           const { return m_description; }
    inline int      minPlayers()            const { return m_minPlayers; }
    inline int      maxPlayers()            const { return m_maxPlayers; }
    inline int      maxSpectators()         const { return m_maxSpectators; }
    inline int      AIPlayers()             const { return m_AIPlayers; }
    inline bool      lifePointsMaxFlag()            const { return m_lifePointsMaxFlag; }
    inline bool      ourFlag()            const { return m_ourFlag; }
    inline bool      dodgeCityFlag()            const { return m_dodgeCityFlag; }
    inline bool      teamFortressFlag()            const { return m_teamFortressFlag; }
    inline bool      stackingDynamiteFlag()            const { return m_stackingDynamiteFlag; }
    inline bool      teamFortressCharactersFlag()            const { return m_teamFortressCharactersFlag; }
    inline bool      directorsCutsFlag()            const { return m_directorsCutsFlag; }
    inline bool      directorsCutsCharactersFlag()            const { return m_directorsCutsCharactersFlag; }
    inline bool      martinCityFlag()            const { return m_martinCityFlag; }
    inline bool      martinCityCharactersFlag()            const { return m_martinCityCharactersFlag; }
    inline bool      cuspOfCarabelliFlag()            const { return m_cuspOfCarabelliFlag; }
    inline bool      cuspOfCarabelliCharactersFlag()            const { return m_cuspOfCarabelliCharactersFlag; }
    
    inline bool      robberRoostFlag()            const { return m_robberRoostFlag; }
    inline bool      robberRoostCharactersFlag()            const { return m_robberRoostCharactersFlag; }
    inline bool      bootHillCharactersFlag()            const { return m_bootHillCharactersFlag; }
    inline bool      twentyCharactersFlag()            const { return m_twentyCharactersFlag; }
    inline bool      thirtythreeCharactersFlag()            const { return m_thirtythreeCharactersFlag; }
    
    inline int      aiLevel()             const { return m_aiLevel; }
    
//     inline bool     hasPlayerPassword()     const { return !m_playerPassword.isNull(); }
//     inline bool     hasSpectatorPassword()  const { return !m_spectatorPassword.isNull(); } 
    inline int      creatorId()             const { return m_creatorId; }
    inline bool     hasShufflePlayers()     const { return m_shufflePlayersFlag; }

//     inline bool comparePlayerPassword(const QString& password) const {
//         return password == m_playerPassword;
//     }
// 
//     inline bool compareSpectatorPassword(const QString& password) const {
//         return (password == m_playerPassword || password == m_spectatorPassword);
//     }

    //StructGame structGame() const;

    void setCreatorId(int creatorId) {
        m_creatorId = creatorId;
    }


private:
    QString m_name;
//     QString m_description;
    int     m_creatorId;
    int     m_minPlayers;
    int     m_maxPlayers;
    int     m_maxSpectators;
    int     m_AIPlayers;
//     QString m_playerPassword;
//     QString m_spectatorPassword;
    bool    m_shufflePlayersFlag;
    //int m_numberOfCharacterOfAPlayer;
    //bool m_canChooseCharacter;
     bool m_lifePointsMaxFlag;
     bool m_ourFlag;
     bool m_dodgeCityFlag;
     bool m_teamFortressFlag;
     bool m_stackingDynamiteFlag;
     bool m_teamFortressCharactersFlag;
     bool m_directorsCutsFlag;
     bool m_directorsCutsCharactersFlag;
     bool m_martinCityFlag;
     bool m_martinCityCharactersFlag;
     bool m_cuspOfCarabelliFlag;
     bool m_cuspOfCarabelliCharactersFlag;
     bool m_robberRoostFlag;
     bool m_robberRoostCharactersFlag;
     bool m_bootHillCharactersFlag;
     bool m_twentyCharactersFlag;
     bool m_thirtythreeCharactersFlag;
     int m_aiLevel;

};

#endif // GAMEINFO_H
