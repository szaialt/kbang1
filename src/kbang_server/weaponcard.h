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
#ifndef WEAPONCARD_H
#define WEAPONCARD_H

#include "playingcard.h"
#include "parser/parserstructs.h"

/**
 * The WeaponCard represents any weapon card.
 * @author MacJariel <MacJariel@gmail.com>
 */
class WeaponCard: public PlayingCard
{
Q_OBJECT
public:
    /**
     * the range
     * parameter:
     *  * 0 - Guitar
     *  * 1 - Volcanic, HalfZatochi
     *  * 2 - Schofield, MediGun
     *  * 3 - Remington
     *  * 4 - Carabine
     *  * 5 - Winchester
     */
    enum WeaponType {
        Guitar,
        HalfZatochi,
        Volcanic,
        Schofield,
        MediGun,
        Sandman,
        Remington,
        Carabine,
        Winchester
    }; 
    
    WeaponCard(Game *game, int id, WeaponType type, CardSuit, CardRank);
    virtual ~WeaponCard();

    virtual void play();
    virtual void play(Player* targetPlayer);
    virtual void play(PlayingCard* targetCard, Player* targetPlayer); 
    virtual CardColor color() const;
    virtual void registerPlayer(Player* player);
    virtual void unregisterPlayer(Player* player);


protected:
    int m_range;
    WeaponType m_type;
};

#endif
