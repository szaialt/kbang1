/********************************************************************************
** Form generated from reading UI file 'joingamedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOINGAMEDIALOG_H
#define UI_JOINGAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include "selectplayericonwidget.h"

QT_BEGIN_NAMESPACE

class Ui_JoinGameDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *gameListView;
    QFrame *line_2;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *labelName;
    QLabel *label_14;
    QLabel *labelDescription;
    QLabel *label_15;
    QLabel *labelState;
    QLabel *label_16;
    QLabel *labelPlayers;
    QLabel *label_18;
    QLabel *labelAIPlayers;
    QLabel *label_19;
    QLabel *labelPassword;
    QLabel *label_20;
    QLabel *labelLifePoint;
    QLabel *label_21;
    QLabel *labelDodgeCity;
    QLabel *label_22;
    QLabel *labelWalleyOfShadows;
    QLabel *label_23;
    QLabel *labelTeamFortress;
    QLabel *label_24;
    QLabel *labelOurFlag;
    QLabel *label_25;
    QLabel *labelStackingDynamite;
    QTreeWidget *playerListView;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLineEdit *lineEditPlayerName;
    client::SelectPlayerIconWidget *selectPlayerIconWidget;
    QLabel *label_9;
    QLineEdit *lineEditPlayerPassword;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonRefresh;
    QPushButton *pushButtonPlay;
    QPushButton *pushButtonSpectate;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *JoinGameDialog)
    {
        if (JoinGameDialog->objectName().isEmpty())
            JoinGameDialog->setObjectName(QStringLiteral("JoinGameDialog"));
        JoinGameDialog->resize(575, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(JoinGameDialog->sizePolicy().hasHeightForWidth());
        JoinGameDialog->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(JoinGameDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gameListView = new QTreeWidget(JoinGameDialog);
        gameListView->headerItem()->setText(3, QString());
        gameListView->setObjectName(QStringLiteral("gameListView"));
        gameListView->setFocusPolicy(Qt::NoFocus);
        gameListView->setAutoScroll(true);
        gameListView->setAlternatingRowColors(true);
        gameListView->setIndentation(15);
        gameListView->setRootIsDecorated(false);
        gameListView->setItemsExpandable(false);
        gameListView->setSortingEnabled(true);
        gameListView->setAnimated(true);
        gameListView->setAllColumnsShowFocus(false);

        horizontalLayout_2->addWidget(gameListView);

        line_2 = new QFrame(JoinGameDialog);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(JoinGameDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_12 = new QLabel(frame);
        label_12->setObjectName(QStringLiteral("label_12"));
        QFont font;
        font.setPointSize(12);
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_12, 0, 0, 1, 2);

        label_13 = new QLabel(frame);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_2->addWidget(label_13, 1, 0, 1, 1);

        labelName = new QLabel(frame);
        labelName->setObjectName(QStringLiteral("labelName"));

        gridLayout_2->addWidget(labelName, 1, 1, 1, 1);

        label_14 = new QLabel(frame);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_2->addWidget(label_14, 2, 0, 1, 1);

        labelDescription = new QLabel(frame);
        labelDescription->setObjectName(QStringLiteral("labelDescription"));

        gridLayout_2->addWidget(labelDescription, 2, 1, 1, 1);

        label_15 = new QLabel(frame);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_2->addWidget(label_15, 3, 0, 1, 1);

        labelState = new QLabel(frame);
        labelState->setObjectName(QStringLiteral("labelState"));

        gridLayout_2->addWidget(labelState, 3, 1, 1, 1);

        label_16 = new QLabel(frame);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_2->addWidget(label_16, 4, 0, 1, 1);

        labelPlayers = new QLabel(frame);
        labelPlayers->setObjectName(QStringLiteral("labelPlayers"));

        gridLayout_2->addWidget(labelPlayers, 4, 1, 1, 1);

        label_18 = new QLabel(frame);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_2->addWidget(label_18, 5, 0, 1, 1);

        labelAIPlayers = new QLabel(frame);
        labelAIPlayers->setObjectName(QStringLiteral("labelAIPlayers"));

        gridLayout_2->addWidget(labelAIPlayers, 5, 1, 1, 1);

        label_19 = new QLabel(frame);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_2->addWidget(label_19, 6, 0, 1, 1);

        labelPassword = new QLabel(frame);
        labelPassword->setObjectName(QStringLiteral("labelPassword"));

        gridLayout_2->addWidget(labelPassword, 6, 1, 1, 1);

        label_20 = new QLabel(frame);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_2->addWidget(label_20, 7, 0, 1, 1);

        labelLifePoint = new QLabel(frame);
        labelLifePoint->setObjectName(QStringLiteral("labelLifePoint"));

        gridLayout_2->addWidget(labelLifePoint, 7, 1, 1, 1);

        label_21 = new QLabel(frame);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_2->addWidget(label_21, 8, 0, 1, 1);

        labelDodgeCity = new QLabel(frame);
        labelDodgeCity->setObjectName(QStringLiteral("labelDodgeCity"));

        gridLayout_2->addWidget(labelDodgeCity, 8, 1, 1, 1);

        label_22 = new QLabel(frame);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_2->addWidget(label_22, 9, 0, 1, 1);

        labelWalleyOfShadows = new QLabel(frame);
        labelWalleyOfShadows->setObjectName(QStringLiteral("labelWalleyOfShadows"));

        gridLayout_2->addWidget(labelWalleyOfShadows, 9, 1, 1, 1);

        label_23 = new QLabel(frame);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_2->addWidget(label_23, 10, 0, 1, 1);

        labelTeamFortress = new QLabel(frame);
        labelTeamFortress->setObjectName(QStringLiteral("labelTeamFortress"));

        gridLayout_2->addWidget(labelTeamFortress, 10, 1, 1, 1);

        label_24 = new QLabel(frame);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_2->addWidget(label_24, 11, 0, 1, 1);

        labelOurFlag = new QLabel(frame);
        labelOurFlag->setObjectName(QStringLiteral("labelOurFlag"));

        gridLayout_2->addWidget(labelOurFlag, 11, 1, 1, 1);

        label_25 = new QLabel(frame);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_2->addWidget(label_25, 12, 0, 1, 1);

        labelStackingDynamite = new QLabel(frame);
        labelStackingDynamite->setObjectName(QStringLiteral("labelStackingDynamite"));

        gridLayout_2->addWidget(labelStackingDynamite, 12, 1, 1, 1);


        verticalLayout->addWidget(frame);

        playerListView = new QTreeWidget(JoinGameDialog);
        new QTreeWidgetItem(playerListView);
        playerListView->setObjectName(QStringLiteral("playerListView"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(playerListView->sizePolicy().hasHeightForWidth());
        playerListView->setSizePolicy(sizePolicy1);
        playerListView->setFocusPolicy(Qt::NoFocus);
        playerListView->setEditTriggers(QAbstractItemView::EditKeyPressed);
        playerListView->setAlternatingRowColors(true);
        playerListView->setSelectionMode(QAbstractItemView::SingleSelection);
        playerListView->setIndentation(15);
        playerListView->setRootIsDecorated(false);
        playerListView->setUniformRowHeights(true);
        playerListView->setItemsExpandable(false);
        playerListView->setSortingEnabled(false);
        playerListView->setAnimated(false);
        playerListView->setAllColumnsShowFocus(false);
        playerListView->setHeaderHidden(false);
        playerListView->setExpandsOnDoubleClick(true);

        verticalLayout->addWidget(playerListView);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_7 = new QLabel(JoinGameDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        lineEditPlayerName = new QLineEdit(JoinGameDialog);
        lineEditPlayerName->setObjectName(QStringLiteral("lineEditPlayerName"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEditPlayerName->sizePolicy().hasHeightForWidth());
        lineEditPlayerName->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(lineEditPlayerName, 0, 1, 1, 1);

        selectPlayerIconWidget = new client::SelectPlayerIconWidget(JoinGameDialog);
        selectPlayerIconWidget->setObjectName(QStringLiteral("selectPlayerIconWidget"));
        selectPlayerIconWidget->setMinimumSize(QSize(64, 64));
        selectPlayerIconWidget->setMaximumSize(QSize(64, 64));
        selectPlayerIconWidget->setFrameShape(QFrame::Box);
        selectPlayerIconWidget->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(selectPlayerIconWidget, 0, 2, 2, 1);

        label_9 = new QLabel(JoinGameDialog);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 1, 0, 1, 1);

        lineEditPlayerPassword = new QLineEdit(JoinGameDialog);
        lineEditPlayerPassword->setObjectName(QStringLiteral("lineEditPlayerPassword"));
        sizePolicy3.setHeightForWidth(lineEditPlayerPassword->sizePolicy().hasHeightForWidth());
        lineEditPlayerPassword->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(lineEditPlayerPassword, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        line = new QFrame(JoinGameDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonRefresh = new QPushButton(JoinGameDialog);
        pushButtonRefresh->setObjectName(QStringLiteral("pushButtonRefresh"));

        horizontalLayout->addWidget(pushButtonRefresh);

        pushButtonPlay = new QPushButton(JoinGameDialog);
        pushButtonPlay->setObjectName(QStringLiteral("pushButtonPlay"));

        horizontalLayout->addWidget(pushButtonPlay);

        pushButtonSpectate = new QPushButton(JoinGameDialog);
        pushButtonSpectate->setObjectName(QStringLiteral("pushButtonSpectate"));
        pushButtonSpectate->setEnabled(false);

        horizontalLayout->addWidget(pushButtonSpectate);

        pushButtonCancel = new QPushButton(JoinGameDialog);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout->addWidget(pushButtonCancel);


        verticalLayout_2->addLayout(horizontalLayout);

#ifndef QT_NO_SHORTCUT
        label_7->setBuddy(lineEditPlayerName);
        label_9->setBuddy(lineEditPlayerPassword);
#endif // QT_NO_SHORTCUT

        retranslateUi(JoinGameDialog);
        QObject::connect(pushButtonCancel, SIGNAL(clicked()), JoinGameDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(JoinGameDialog);
    } // setupUi

    void retranslateUi(QDialog *JoinGameDialog)
    {
        JoinGameDialog->setWindowTitle(QApplication::translate("JoinGameDialog", "Join Game", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = gameListView->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("JoinGameDialog", "Players", Q_NULLPTR));
        ___qtreewidgetitem->setText(1, QApplication::translate("JoinGameDialog", "State", Q_NULLPTR));
        ___qtreewidgetitem->setText(0, QApplication::translate("JoinGameDialog", "Name", Q_NULLPTR));
        label_12->setText(QApplication::translate("JoinGameDialog", "Game Info", Q_NULLPTR));
        label_13->setText(QApplication::translate("JoinGameDialog", "Name:", Q_NULLPTR));
        labelName->setText(QApplication::translate("JoinGameDialog", "[Name]", Q_NULLPTR));
        label_14->setText(QApplication::translate("JoinGameDialog", "Description:", Q_NULLPTR));
        labelDescription->setText(QApplication::translate("JoinGameDialog", "[Description]", Q_NULLPTR));
        label_15->setText(QApplication::translate("JoinGameDialog", "State:", Q_NULLPTR));
        labelState->setText(QApplication::translate("JoinGameDialog", "[State]", Q_NULLPTR));
        label_16->setText(QApplication::translate("JoinGameDialog", "Players:", Q_NULLPTR));
        labelPlayers->setText(QApplication::translate("JoinGameDialog", "[Players]", Q_NULLPTR));
        label_18->setText(QApplication::translate("JoinGameDialog", "AI Players:", Q_NULLPTR));
        labelAIPlayers->setText(QApplication::translate("JoinGameDialog", "[AI Players]", Q_NULLPTR));
        label_19->setText(QApplication::translate("JoinGameDialog", "Password:", Q_NULLPTR));
        labelPassword->setText(QApplication::translate("JoinGameDialog", "[Password]", Q_NULLPTR));
        label_20->setText(QApplication::translate("JoinGameDialog", "Lifepoints in combinations:", Q_NULLPTR));
        labelLifePoint->setText(QApplication::translate("JoinGameDialog", "[Lifepoints]", Q_NULLPTR));
        label_21->setText(QApplication::translate("JoinGameDialog", "DodgeCity:", Q_NULLPTR));
        labelDodgeCity->setText(QApplication::translate("JoinGameDialog", "[DodgeCity]", Q_NULLPTR));
        label_22->setText(QApplication::translate("JoinGameDialog", "WalleyOfShadows:", Q_NULLPTR));
        labelWalleyOfShadows->setText(QApplication::translate("JoinGameDialog", "[WalleyOfShadows]", Q_NULLPTR));
        label_23->setText(QApplication::translate("JoinGameDialog", "TeamFortress:", Q_NULLPTR));
        labelTeamFortress->setText(QApplication::translate("JoinGameDialog", "[TeamFortress]", Q_NULLPTR));
        label_24->setText(QApplication::translate("JoinGameDialog", "Our rules:", Q_NULLPTR));
        labelOurFlag->setText(QApplication::translate("JoinGameDialog", "[Our rules]", Q_NULLPTR));
        label_25->setText(QApplication::translate("JoinGameDialog", "Stacking dynamite:", Q_NULLPTR));
        labelStackingDynamite->setText(QApplication::translate("JoinGameDialog", "[Stacking dynamite]", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem1 = playerListView->headerItem();
        ___qtreewidgetitem1->setText(3, QApplication::translate("JoinGameDialog", "Z", Q_NULLPTR));
        ___qtreewidgetitem1->setText(2, QApplication::translate("JoinGameDialog", "Y", Q_NULLPTR));
        ___qtreewidgetitem1->setText(1, QApplication::translate("JoinGameDialog", "X", Q_NULLPTR));
        ___qtreewidgetitem1->setText(0, QApplication::translate("JoinGameDialog", "Players", Q_NULLPTR));

        const bool __sortingEnabled = playerListView->isSortingEnabled();
        playerListView->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem2 = playerListView->topLevelItem(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("JoinGameDialog", "Create new player", Q_NULLPTR));
        playerListView->setSortingEnabled(__sortingEnabled);

        label_7->setText(QApplication::translate("JoinGameDialog", "Player Name", Q_NULLPTR));
        selectPlayerIconWidget->setText(QApplication::translate("JoinGameDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Avatar</span></p></body></html>", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_9->setToolTip(QApplication::translate("JoinGameDialog", "You can set your password here. This password will be required to reconnect to your player in case of disconnection.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_9->setText(QApplication::translate("JoinGameDialog", "Player Password", Q_NULLPTR));
        pushButtonRefresh->setText(QApplication::translate("JoinGameDialog", "Refresh", Q_NULLPTR));
        pushButtonPlay->setText(QApplication::translate("JoinGameDialog", "Play", Q_NULLPTR));
        pushButtonSpectate->setText(QApplication::translate("JoinGameDialog", "Spectate", Q_NULLPTR));
        pushButtonCancel->setText(QApplication::translate("JoinGameDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class JoinGameDialog: public Ui_JoinGameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOINGAMEDIALOG_H
