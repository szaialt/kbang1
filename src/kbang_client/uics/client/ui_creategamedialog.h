/********************************************************************************
** Form generated from reading UI file 'creategamedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGAMEDIALOG_H
#define UI_CREATEGAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include "selectplayericonwidget.h"

QT_BEGIN_NAMESPACE

class Ui_CreateGameDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBoxMinPlayers;
    QLabel *label_4;
    QSpinBox *spinBoxMaxPlayers;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonOrderChronological;
    QRadioButton *radioButtonOrderRandom;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *lineEditGameName;
    QLabel *label_2;
    QLineEdit *lineEditGameDescription;
    QLabel *label_3;
    QLineEdit *lineEditGamePasswordPlayers;
    QLineEdit *lineEditPlayerName;
    QPushButton *pushButtonCreate;
    QPushButton *pushButtonCancel;
    QLabel *label_8;
    QSpinBox *spinBoxAIPlayers;
    QLabel *label_7;
    QLabel *label_9;
    client::SelectPlayerIconWidget *selectPlayerIconWidget;
    QLineEdit *lineEditPlayerPassword;
    QFrame *line_2;
    QLabel *label_11;
    QLineEdit *lineEditGamePasswordSpectators;
    QSpinBox *spinBoxMaxSpectators;
    QLabel *label_6;
    QLabel *label_12;
    QFrame *line;
    QLabel *label_5;
    QCheckBox *checkBoxLifePointsMaxFlag;
    QLabel *labelLifePointsMaxFlag;
    QCheckBox *checkBoxOurFlag;
    QLabel *labelCheckBoxOurFlag;
    QCheckBox *checkDodgeCity;
    QLabel *labelDodgeCity;
    QCheckBox *checkTeamFortress;
    QLabel *labelTeamFortress;
    QCheckBox *checkTeamFortressCharacters;
    QLabel *labelTeamFortressCharacters;
    QCheckBox *checkStackingDynamite;
    QLabel *labelStackingDynamite;
    QSpinBox *spinBoxAiLevel;
    QLabel *labelAiLevel;

    void setupUi(QDialog *CreateGameDialog)
    {
        if (CreateGameDialog->objectName().isEmpty())
            CreateGameDialog->setObjectName(QStringLiteral("CreateGameDialog"));
        CreateGameDialog->resize(374, 550);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateGameDialog->sizePolicy().hasHeightForWidth());
        CreateGameDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(CreateGameDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        spinBoxMinPlayers = new QSpinBox(CreateGameDialog);
        spinBoxMinPlayers->setObjectName(QStringLiteral("spinBoxMinPlayers"));

        horizontalLayout->addWidget(spinBoxMinPlayers);

        label_4 = new QLabel(CreateGameDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(16, 16777215));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);

        spinBoxMaxPlayers = new QSpinBox(CreateGameDialog);
        spinBoxMaxPlayers->setObjectName(QStringLiteral("spinBoxMaxPlayers"));

        horizontalLayout->addWidget(spinBoxMaxPlayers);


        gridLayout->addLayout(horizontalLayout, 2, 2, 1, 4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButtonOrderChronological = new QRadioButton(CreateGameDialog);
        radioButtonOrderChronological->setObjectName(QStringLiteral("radioButtonOrderChronological"));
        radioButtonOrderChronological->setChecked(true);

        verticalLayout->addWidget(radioButtonOrderChronological);

        radioButtonOrderRandom = new QRadioButton(CreateGameDialog);
        radioButtonOrderRandom->setObjectName(QStringLiteral("radioButtonOrderRandom"));

        verticalLayout->addWidget(radioButtonOrderRandom);


        gridLayout->addLayout(verticalLayout, 10, 2, 1, 4);

        horizontalSpacer = new QSpacerItem(213, 28, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 16, 0, 1, 3);

        label = new QLabel(CreateGameDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        lineEditGameName = new QLineEdit(CreateGameDialog);
        lineEditGameName->setObjectName(QStringLiteral("lineEditGameName"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditGameName->sizePolicy().hasHeightForWidth());
        lineEditGameName->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lineEditGameName, 0, 2, 1, 4);

        label_2 = new QLabel(CreateGameDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        lineEditGameDescription = new QLineEdit(CreateGameDialog);
        lineEditGameDescription->setObjectName(QStringLiteral("lineEditGameDescription"));
        sizePolicy1.setHeightForWidth(lineEditGameDescription->sizePolicy().hasHeightForWidth());
        lineEditGameDescription->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lineEditGameDescription, 1, 2, 1, 4);

        label_3 = new QLabel(CreateGameDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 2);

        lineEditGamePasswordPlayers = new QLineEdit(CreateGameDialog);
        lineEditGamePasswordPlayers->setObjectName(QStringLiteral("lineEditGamePasswordPlayers"));
        sizePolicy1.setHeightForWidth(lineEditGamePasswordPlayers->sizePolicy().hasHeightForWidth());
        lineEditGamePasswordPlayers->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lineEditGamePasswordPlayers, 7, 2, 2, 4);

        lineEditPlayerName = new QLineEdit(CreateGameDialog);
        lineEditPlayerName->setObjectName(QStringLiteral("lineEditPlayerName"));

        gridLayout->addWidget(lineEditPlayerName, 12, 1, 1, 4);

        pushButtonCreate = new QPushButton(CreateGameDialog);
        pushButtonCreate->setObjectName(QStringLiteral("pushButtonCreate"));

        gridLayout->addWidget(pushButtonCreate, 27, 3, 1, 1);

        pushButtonCancel = new QPushButton(CreateGameDialog);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        gridLayout->addWidget(pushButtonCancel, 27, 4, 1, 2);

        label_8 = new QLabel(CreateGameDialog);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 2);

        spinBoxAIPlayers = new QSpinBox(CreateGameDialog);
        spinBoxAIPlayers->setObjectName(QStringLiteral("spinBoxAIPlayers"));

        gridLayout->addWidget(spinBoxAIPlayers, 3, 2, 1, 4);

        label_7 = new QLabel(CreateGameDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_7, 12, 0, 1, 1);

        label_9 = new QLabel(CreateGameDialog);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 14, 0, 1, 1);

        selectPlayerIconWidget = new client::SelectPlayerIconWidget(CreateGameDialog);
        selectPlayerIconWidget->setObjectName(QStringLiteral("selectPlayerIconWidget"));
        selectPlayerIconWidget->setFrameShape(QFrame::Box);
        selectPlayerIconWidget->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(selectPlayerIconWidget, 12, 5, 3, 1);

        lineEditPlayerPassword = new QLineEdit(CreateGameDialog);
        lineEditPlayerPassword->setObjectName(QStringLiteral("lineEditPlayerPassword"));

        gridLayout->addWidget(lineEditPlayerPassword, 16, 1, 1, 4);

        line_2 = new QFrame(CreateGameDialog);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 24, 0, 1, 4);

        label_11 = new QLabel(CreateGameDialog);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 9, 0, 1, 2);

        lineEditGamePasswordSpectators = new QLineEdit(CreateGameDialog);
        lineEditGamePasswordSpectators->setObjectName(QStringLiteral("lineEditGamePasswordSpectators"));
        sizePolicy1.setHeightForWidth(lineEditGamePasswordSpectators->sizePolicy().hasHeightForWidth());
        lineEditGamePasswordSpectators->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lineEditGamePasswordSpectators, 9, 2, 1, 4);

        spinBoxMaxSpectators = new QSpinBox(CreateGameDialog);
        spinBoxMaxSpectators->setObjectName(QStringLiteral("spinBoxMaxSpectators"));
        spinBoxMaxSpectators->setEnabled(false);
        spinBoxMaxSpectators->setMinimum(-1);

        gridLayout->addWidget(spinBoxMaxSpectators, 4, 2, 1, 4);

        label_6 = new QLabel(CreateGameDialog);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 10, 0, 1, 2);

        label_12 = new QLabel(CreateGameDialog);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 4, 0, 1, 2);

        line = new QFrame(CreateGameDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 13, 0, 1, 4);

        label_5 = new QLabel(CreateGameDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 7, 0, 2, 2);

        checkBoxLifePointsMaxFlag = new QCheckBox(CreateGameDialog);
        checkBoxLifePointsMaxFlag->setObjectName(QStringLiteral("checkBoxLifePointsMaxFlag"));

        gridLayout->addWidget(checkBoxLifePointsMaxFlag, 17, 2, 1, 2);

        labelLifePointsMaxFlag = new QLabel(CreateGameDialog);
        labelLifePointsMaxFlag->setObjectName(QStringLiteral("labelLifePointsMaxFlag"));

        gridLayout->addWidget(labelLifePointsMaxFlag, 17, 0, 1, 2);

        checkBoxOurFlag = new QCheckBox(CreateGameDialog);
        checkBoxOurFlag->setObjectName(QStringLiteral("checkBoxOurFlag"));

        gridLayout->addWidget(checkBoxOurFlag, 18, 2, 1, 2);

        labelCheckBoxOurFlag = new QLabel(CreateGameDialog);
        labelCheckBoxOurFlag->setObjectName(QStringLiteral("labelCheckBoxOurFlag"));

        gridLayout->addWidget(labelCheckBoxOurFlag, 18, 0, 1, 2);

        checkDodgeCity = new QCheckBox(CreateGameDialog);
        checkDodgeCity->setObjectName(QStringLiteral("checkDodgeCity"));

        gridLayout->addWidget(checkDodgeCity, 19, 2, 1, 2);

        labelDodgeCity = new QLabel(CreateGameDialog);
        labelDodgeCity->setObjectName(QStringLiteral("labelDodgeCity"));

        gridLayout->addWidget(labelDodgeCity, 19, 0, 1, 2);

        checkTeamFortress = new QCheckBox(CreateGameDialog);
        checkTeamFortress->setObjectName(QStringLiteral("checkTeamFortress"));

        gridLayout->addWidget(checkTeamFortress, 21, 2, 1, 2);

        labelTeamFortress = new QLabel(CreateGameDialog);
        labelTeamFortress->setObjectName(QStringLiteral("labelTeamFortress"));

        gridLayout->addWidget(labelTeamFortress, 21, 0, 1, 2);

        checkTeamFortressCharacters = new QCheckBox(CreateGameDialog);
        checkTeamFortressCharacters->setObjectName(QStringLiteral("checkTeamFortressCharacters"));

        gridLayout->addWidget(checkTeamFortressCharacters, 22, 2, 1, 2);

        labelTeamFortressCharacters = new QLabel(CreateGameDialog);
        labelTeamFortressCharacters->setObjectName(QStringLiteral("labelTeamFortressCharacters"));

        gridLayout->addWidget(labelTeamFortressCharacters, 22, 0, 1, 2);

        checkStackingDynamite = new QCheckBox(CreateGameDialog);
        checkStackingDynamite->setObjectName(QStringLiteral("checkStackingDynamite"));

        gridLayout->addWidget(checkStackingDynamite, 23, 2, 1, 2);

        labelStackingDynamite = new QLabel(CreateGameDialog);
        labelStackingDynamite->setObjectName(QStringLiteral("labelStackingDynamite"));

        gridLayout->addWidget(labelStackingDynamite, 23, 0, 1, 2);

        spinBoxAiLevel = new QSpinBox(CreateGameDialog);
        spinBoxAiLevel->setObjectName(QStringLiteral("spinBoxAiLevel"));

        gridLayout->addWidget(spinBoxAiLevel, 26, 2, 1, 2);

        labelAiLevel = new QLabel(CreateGameDialog);
        labelAiLevel->setObjectName(QStringLiteral("labelAiLevel"));

        gridLayout->addWidget(labelAiLevel, 26, 0, 1, 2);

#ifndef QT_NO_SHORTCUT
        label_4->setBuddy(spinBoxMaxPlayers);
        label->setBuddy(lineEditGameName);
        label_2->setBuddy(lineEditGameDescription);
        label_3->setBuddy(spinBoxMinPlayers);
        label_8->setBuddy(spinBoxAIPlayers);
        label_7->setBuddy(lineEditPlayerName);
        label_9->setBuddy(lineEditPlayerPassword);
        label_11->setBuddy(lineEditGamePasswordSpectators);
        label_6->setBuddy(radioButtonOrderChronological);
        label_12->setBuddy(spinBoxMaxSpectators);
        label_5->setBuddy(lineEditGamePasswordPlayers);
        labelLifePointsMaxFlag->setBuddy(checkBoxLifePointsMaxFlag);
        labelCheckBoxOurFlag->setBuddy(checkBoxOurFlag);
        labelDodgeCity->setBuddy(checkDodgeCity);
        labelTeamFortress->setBuddy(checkTeamFortress);
        labelTeamFortressCharacters->setBuddy(checkTeamFortressCharacters);
        labelStackingDynamite->setBuddy(checkStackingDynamite);
        labelAiLevel->setBuddy(spinBoxAiLevel);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(lineEditGameName, lineEditGameDescription);
        QWidget::setTabOrder(lineEditGameDescription, spinBoxMinPlayers);
        QWidget::setTabOrder(spinBoxMinPlayers, spinBoxMaxPlayers);
        QWidget::setTabOrder(spinBoxMaxPlayers, spinBoxAIPlayers);
        QWidget::setTabOrder(spinBoxAIPlayers, spinBoxMaxSpectators);
        QWidget::setTabOrder(spinBoxMaxSpectators, lineEditGamePasswordPlayers);
        QWidget::setTabOrder(lineEditGamePasswordPlayers, lineEditGamePasswordSpectators);
        QWidget::setTabOrder(lineEditGamePasswordSpectators, radioButtonOrderChronological);
        QWidget::setTabOrder(radioButtonOrderChronological, radioButtonOrderRandom);
        QWidget::setTabOrder(radioButtonOrderRandom, lineEditPlayerName);
        QWidget::setTabOrder(lineEditPlayerName, lineEditPlayerPassword);
        QWidget::setTabOrder(lineEditPlayerPassword, checkBoxLifePointsMaxFlag);
        QWidget::setTabOrder(checkBoxLifePointsMaxFlag, checkBoxOurFlag);
        QWidget::setTabOrder(checkBoxOurFlag, checkDodgeCity);
        QWidget::setTabOrder(checkDodgeCity, checkTeamFortress);
        QWidget::setTabOrder(checkTeamFortress, checkTeamFortressCharacters);
        QWidget::setTabOrder(checkTeamFortressCharacters, checkStackingDynamite);
        QWidget::setTabOrder(checkStackingDynamite, pushButtonCreate);
        QWidget::setTabOrder(pushButtonCreate, pushButtonCancel);

        retranslateUi(CreateGameDialog);
        QObject::connect(pushButtonCancel, SIGNAL(clicked()), CreateGameDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(CreateGameDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateGameDialog)
    {
        CreateGameDialog->setWindowTitle(QApplication::translate("CreateGameDialog", "Create a game", Q_NULLPTR));
        label_4->setText(QApplication::translate("CreateGameDialog", "-", Q_NULLPTR));
        radioButtonOrderChronological->setText(QApplication::translate("CreateGameDialog", "Chronological", Q_NULLPTR));
        radioButtonOrderRandom->setText(QApplication::translate("CreateGameDialog", "Random", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("CreateGameDialog", "Game Name", Q_NULLPTR));
        label_2->setText(QApplication::translate("CreateGameDialog", "Game Description", Q_NULLPTR));
        label_3->setText(QApplication::translate("CreateGameDialog", "Number of Players", Q_NULLPTR));
        pushButtonCreate->setText(QApplication::translate("CreateGameDialog", "Create", Q_NULLPTR));
        pushButtonCancel->setText(QApplication::translate("CreateGameDialog", "Cancel", Q_NULLPTR));
        label_8->setText(QApplication::translate("CreateGameDialog", "Number of AI Players", Q_NULLPTR));
        label_7->setText(QApplication::translate("CreateGameDialog", "Player Name", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_9->setToolTip(QApplication::translate("CreateGameDialog", "You can set your password here. This password will be required to reconnect to your player in case of disconnection.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_9->setText(QApplication::translate("CreateGameDialog", "Player Password", Q_NULLPTR));
        selectPlayerIconWidget->setText(QApplication::translate("CreateGameDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Avatar</span></p></body></html>", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_11->setToolTip(QApplication::translate("CreateGameDialog", "This is the password that is required to join the game as a spectator.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_11->setText(QApplication::translate("CreateGameDialog", "Password for Spectators", Q_NULLPTR));
        spinBoxMaxSpectators->setSpecialValueText(QApplication::translate("CreateGameDialog", "Infinity", Q_NULLPTR));
        label_6->setText(QApplication::translate("CreateGameDialog", "Order of Players", Q_NULLPTR));
        label_12->setText(QApplication::translate("CreateGameDialog", "Max. Number of Spectators", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_5->setToolTip(QApplication::translate("CreateGameDialog", "This is the password that is required to join the game as a player.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("CreateGameDialog", "Password for Players", Q_NULLPTR));
        labelLifePointsMaxFlag->setText(QApplication::translate("CreateGameDialog", "Use maximal lifepoint in character combinations", Q_NULLPTR));
        labelCheckBoxOurFlag->setText(QApplication::translate("CreateGameDialog", "Use our rules", Q_NULLPTR));
        labelDodgeCity->setText(QApplication::translate("CreateGameDialog", "Dodge City", Q_NULLPTR));
        labelTeamFortress->setText(QApplication::translate("CreateGameDialog", "Team Fortress", Q_NULLPTR));
        labelTeamFortressCharacters->setText(QApplication::translate("CreateGameDialog", "Team Fortress characters", Q_NULLPTR));
        labelStackingDynamite->setText(QApplication::translate("CreateGameDialog", "Stacking dynamite", Q_NULLPTR));
        labelAiLevel->setText(QApplication::translate("CreateGameDialog", "Ai level", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CreateGameDialog: public Ui_CreateGameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGAMEDIALOG_H