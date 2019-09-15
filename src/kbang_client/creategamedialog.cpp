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

#include <QRegExpValidator>
#include <QRegExp>
#include "creategamedialog.h"
#include "config.h"

using namespace client;

const int minPlayers = 4, maxPlayers = 7;
const int maxCharacterNumber = 3;

CreateGameDialog::CreateGameDialog(QWidget *parent)
 : QDialog(parent), Ui::CreateGameDialog()
{
    setupUi(this);

    pushButtonCreate->setEnabled(0);

    spinBoxMinPlayers->setRange(minPlayers, maxPlayers);
    spinBoxMaxPlayers->setRange(minPlayers, maxPlayers);
    spinBoxAIPlayers->setRange(0, maxPlayers - 1); 

    //spinBoxCharacterNumber->setRange(1, maxCharacterNumber);
    
     if (Config::instance().hasGroup("create-game-dialog")) {
         loadConfigValues();
     } else {
        spinBoxMinPlayers->setValue(minPlayers);
        spinBoxMaxPlayers->setValue(maxPlayers);
        spinBoxAIPlayers->setValue(0);
        spinBoxMaxSpectators->setValue(-1);
    }

    connect(spinBoxMinPlayers, SIGNAL(valueChanged(int)),
            this, SLOT(playerCountsChanged()));
    connect(spinBoxMaxPlayers, SIGNAL(valueChanged(int)),
            this, SLOT(playerCountsChanged()));

    connect(lineEditGameName,   SIGNAL(textChanged(const QString&)),
            this, SLOT(validateInput()));
    connect(lineEditPlayerName, SIGNAL(textChanged(const QString&)),
            this, SLOT(validateInput()));
}


CreateGameDialog::~CreateGameDialog()
{
}

void CreateGameDialog::playerCountsChanged()
{
    spinBoxMinPlayers->setMaximum(spinBoxMaxPlayers->value());
    spinBoxMaxPlayers->setMinimum(spinBoxMinPlayers->value());
    spinBoxAIPlayers->setMaximum(spinBoxMaxPlayers->value() - 1);
}

void CreateGameDialog::validateInput()
{
    pushButtonCreate->setEnabled(!lineEditGameName->text().isEmpty() &&
                                 !lineEditPlayerName->text().isEmpty());
}

void CreateGameDialog::on_pushButtonCreate_clicked()
{
    CreateGameData createGameData;
    createGameData.name                 = lineEditGameName->text();
    createGameData.description          = lineEditGameDescription->text();
    createGameData.minPlayers           = spinBoxMinPlayers->value();
    createGameData.maxPlayers           = spinBoxMaxPlayers->value();
    createGameData.maxSpectators        = spinBoxMaxSpectators->value();
    createGameData.AIPlayers            = spinBoxAIPlayers->value();
    createGameData.playerPassword       = lineEditGamePasswordPlayers->text();
    createGameData.spectatorPassword    = lineEditGamePasswordSpectators->text();
    createGameData.flagShufflePlayers   = radioButtonOrderRandom->isChecked();
    //createGameData.numberOfCharacterOfAPlayer = spinBoxCharacterNumber->value();
    //createGameData.canChooseCharacter = checkBoxEnableCharacterChoice->isChecked();
     createGameData.lifePointsMaxFlag = checkBoxLifePointsMaxFlag->isChecked();
     createGameData.ourFlag = checkBoxOurFlag->isChecked();
     createGameData.dodgeCityFlag = checkDodgeCity->isChecked();
     createGameData.teamFortressFlag = checkTeamFortress->isChecked();
     createGameData.stackingDynamiteFlag = checkStackingDynamite->isChecked();
     createGameData.teamFortressCharactersFlag = checkTeamFortressCharacters->isChecked();
     createGameData.directorsCutsFlag = checkDirectorsCuts->isChecked();
     createGameData.directorsCutsCharactersFlag = checkDirectorsCutsCharacters->isChecked();
     createGameData.martinCityFlag = checkMartinCity->isChecked();
     createGameData.martinCityCharactersFlag = checkMartinCityCharacters->isChecked();
     createGameData.cuspOfCarabelliFlag = checkCuspOfCarabelli->isChecked();
     createGameData.cuspOfCarabelliCharactersFlag = checkCuspOfCarabelliCharacters->isChecked();
     createGameData.robberRoostFlag = checkRobberRoost->isChecked();
     createGameData.robberRoostCharactersFlag = checkRobberRoostCharacters->isChecked();
     
    createGameData.aiLevel              = spinBoxAiLevel->value();
     
    qDebug() << "Level " << createGameData.aiLevel;
    
    CreatePlayerData createPlayerData;
    createPlayerData.name               = lineEditPlayerName->text();
    createPlayerData.password           = lineEditPlayerPassword->text();
    createPlayerData.avatar             = selectPlayerIconWidget->image();
    
    saveConfigValues(createGameData);

    emit createGame(createGameData, createPlayerData);
    close();
    
}


void CreateGameDialog::loadConfigValues()
{
    Config& cfg = Config::instance();
    cfg.refresh();
    QString grp("create-game-dialog");
    lineEditGameName->setText(cfg.readString(grp, "name"));
    lineEditGameDescription->setText(cfg.readString(grp, "description"));
    spinBoxMinPlayers->setValue(cfg.readInt(grp, "min-players"));
    spinBoxMaxPlayers->setValue(cfg.readInt(grp, "max-players"));
    spinBoxMaxSpectators->setValue(cfg.readInt(grp, "max-spectators"));
    spinBoxAIPlayers->setValue(cfg.readInt(grp, "ai-players"));
    int shufflePlayers = cfg.readInt(grp, "flag-shuffle-players");
    if (shufflePlayers)
        radioButtonOrderRandom->setChecked(1);
    else
        radioButtonOrderChronological->setChecked(1);
    
    //spinBoxCharacterNumber->setValue(cfg.readInt(grp, "number-of-character-of-a-player"));
    //int canChooseCharacter = cfg.readInt(grp, "can-choose-character");
    //if (canChooseCharacter)
    //    checkBoxEnableCharacterChoice->setChecked(1);
    //else
    //    checkBoxEnableCharacterChoice->setChecked(0);    
    
     bool lifePointsMaxFlag  = cfg.readInt(grp, "lifePointsMaxFlag");
     if (lifePointsMaxFlag)
         checkBoxLifePointsMaxFlag->setChecked(1);
     else
         checkBoxLifePointsMaxFlag->setChecked(0);
     bool ourFlag  = cfg.readInt(grp, "ourFlag");
     if (ourFlag)
         checkBoxOurFlag->setChecked(1);
     else
         checkBoxOurFlag->setChecked(0);
     bool dodgeCityFlag  = cfg.readInt(grp, "dodgeCityFlag");
     if (dodgeCityFlag)
         checkDodgeCity->setChecked(1);
     else
         checkDodgeCity->setChecked(0);
     bool teamFortressFlag  = cfg.readInt(grp, "teamFortressFlag");
     if (teamFortressFlag)
         checkTeamFortress->setChecked(1);
     else
         checkTeamFortress->setChecked(0);
     bool stackingDynamiteFlag  = cfg.readInt(grp, "stackingDynamiteFlag");
     if (stackingDynamiteFlag)
         checkStackingDynamite->setChecked(1);
     else
         checkStackingDynamite->setChecked(0);
     bool teamFortressCharactersFlag  = cfg.readInt(grp, "teamFortressCharactersFlag");
     if (teamFortressCharactersFlag)
         checkTeamFortressCharacters->setChecked(1);
     else
         checkTeamFortressCharacters->setChecked(0);
     
     bool directorsCutsFlag  = cfg.readInt(grp, "directorsCutsFlag");
     if (directorsCutsFlag)
         checkDirectorsCuts->setChecked(1);
     else
         checkDirectorsCuts->setChecked(0);
     bool directorsCutsCharactersFlag  = cfg.readInt(grp, "directorsCutsCharactersFlag");
     if (directorsCutsCharactersFlag)
         checkDirectorsCutsCharacters->setChecked(1);
     else
         checkDirectorsCutsCharacters->setChecked(0);
     
    bool martinCityFlag  = cfg.readInt(grp, "martinCityFlag");
     if (martinCityFlag)
         checkMartinCity->setChecked(1);
     else
         checkMartinCity->setChecked(0);
     bool martinCityCharactersFlag  = cfg.readInt(grp, "martinCityCharactersFlag");
     if (martinCityCharactersFlag)
         checkMartinCityCharacters->setChecked(1);
     else
         checkMartinCityCharacters->setChecked(0);
     
     bool cuspOfCarabelliFlag  = cfg.readInt(grp, "cuspOfCarabelliFlag");
     if (cuspOfCarabelliFlag)
         checkCuspOfCarabelli->setChecked(1);
     else
         checkCuspOfCarabelli->setChecked(0);
     bool cuspOfCarabelliCharactersFlag  = cfg.readInt(grp, "cuspOfCarabelliCharactersFlag");
     if (cuspOfCarabelliCharactersFlag)
         checkCuspOfCarabelliCharacters->setChecked(1);
     else
         checkCuspOfCarabelliCharacters->setChecked(0);
     
     bool robberRoostFlag  = cfg.readInt(grp, "robberRoostFlag");
     if (robberRoostFlag)
         checkRobberRoost->setChecked(1);
     else
         checkRobberRoost->setChecked(0);
     bool robberRoostCharactersFlag  = cfg.readInt(grp, "robberRoostCharactersFlag");
     if (robberRoostCharactersFlag)
         checkRobberRoostCharacters->setChecked(1);
     else
         checkRobberRoostCharacters->setChecked(0);
     
    lineEditPlayerName->setText(cfg.readString("player", "name"));
    lineEditPlayerPassword->setText(cfg.readString("player", "password"));
    selectPlayerIconWidget->setImageFileName(cfg.readString("player", "image"));
    spinBoxMinPlayers->setValue(cfg.readInt(grp, "aiLevel"));
    validateInput();
}

void CreateGameDialog::saveConfigValues(const CreateGameData& game)
{
    Config& cfg = Config::instance();
    QString grp("create-game-dialog");
    cfg.writeString(grp, "name", game.name);
    cfg.writeString(grp, "description", game.description);
    cfg.writeInt(grp, "min-players", game.minPlayers);
    cfg.writeInt(grp, "max-players", game.maxPlayers);
    cfg.writeInt(grp, "max-spectators", game.maxSpectators);
    cfg.writeInt(grp, "ai-players", game.AIPlayers);
    cfg.writeInt(grp, "flag-shuffle-players", game.flagShufflePlayers);
//     cfg.writeInt(grp, "number-of-character-of-a-player", game.numberOfCharacterOfAPlayer);
//     cfg.writeInt(grp, "can-choose-character", game.canChooseCharacter);
     cfg.writeInt(grp, "lifePointsMaxFlag", game.lifePointsMaxFlag);
     cfg.writeInt(grp, "ourFlag", game.ourFlag); 
     cfg.writeInt(grp, "dodgeCityFlag", game.dodgeCityFlag);
     cfg.writeInt(grp, "teamFortressFlag", game.teamFortressFlag); 
    cfg.writeInt(grp, "teamFortressCharactersFlag", game.teamFortressCharactersFlag); 

    cfg.writeInt(grp, "martinCityFlag", game.martinCityFlag); 
    cfg.writeInt(grp, "martinCityCharactersFlag", game.martinCityCharactersFlag); 
    
    cfg.writeInt(grp, "cuspOfCarabelliFlag", game.cuspOfCarabelliFlag); 
    cfg.writeInt(grp, "cuspOfCarabelliCharactersFlag", game.cuspOfCarabelliCharactersFlag); 
    
    cfg.writeInt(grp, "robberRoostFlag", game.robberRoostFlag); 
    cfg.writeInt(grp, "robberRoostharactersFlag", game.robberRoostCharactersFlag); 
    
    cfg.writeInt(grp, "stackingDynamiteFlag", game.stackingDynamiteFlag);
    cfg.writeString("player", "name", lineEditPlayerName->text());
    cfg.writeString("player", "password", lineEditPlayerPassword->text());
    cfg.writeString("player", "image", selectPlayerIconWidget->imageFileName());
    cfg.writeInt(grp, "aiLevel", game.aiLevel);

    cfg.store();
}

