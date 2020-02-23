/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "chatwidget.h"
#include "localplayerwidget.h"
#include "logwidget.h"
#include "opponentwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *mp_actionConnectToServer;
    QAction *mp_actionExit;
    QAction *mp_actionDisconnectFromServer;
    QAction *mp_actionJoinGame;
    QAction *mp_actionLeaveGame;
    QAction *actionCreateGame;
    QAction *mp_actionAbout;
    QWidget *mp_centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_5;
    client::OpponentWidget *mp_opponent2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_6;
    client::OpponentWidget *mp_opponent3;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_7;
    client::OpponentWidget *mp_opponent4;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_4;
    client::OpponentWidget *mp_opponent5;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_9;
    client::OpponentWidget *mp_opponent1;
    QSpacerItem *verticalSpacer_11;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_10;
    QWidget *mp_middleWidget;
    QSpacerItem *verticalSpacer_10;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer_8;
    client::OpponentWidget *mp_opponent6;
    QSpacerItem *verticalSpacer_12;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    client::ChatWidget *mp_chatWidget;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    client::LocalPlayerWidget *mp_localPlayerWidget;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *mp_statusLabel;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    client::LogWidget *mp_logWidget;
    QMenuBar *menubar;
    QMenu *menuGame;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(388, 378);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/kbang.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        mp_actionConnectToServer = new QAction(MainWindow);
        mp_actionConnectToServer->setObjectName(QStringLiteral("mp_actionConnectToServer"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        mp_actionConnectToServer->setIcon(icon1);
        mp_actionExit = new QAction(MainWindow);
        mp_actionExit->setObjectName(QStringLiteral("mp_actionExit"));
        mp_actionDisconnectFromServer = new QAction(MainWindow);
        mp_actionDisconnectFromServer->setObjectName(QStringLiteral("mp_actionDisconnectFromServer"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        mp_actionDisconnectFromServer->setIcon(icon2);
        mp_actionJoinGame = new QAction(MainWindow);
        mp_actionJoinGame->setObjectName(QStringLiteral("mp_actionJoinGame"));
        mp_actionLeaveGame = new QAction(MainWindow);
        mp_actionLeaveGame->setObjectName(QStringLiteral("mp_actionLeaveGame"));
        actionCreateGame = new QAction(MainWindow);
        actionCreateGame->setObjectName(QStringLiteral("actionCreateGame"));
        mp_actionAbout = new QAction(MainWindow);
        mp_actionAbout->setObjectName(QStringLiteral("mp_actionAbout"));
        mp_centralWidget = new QWidget(MainWindow);
        mp_centralWidget->setObjectName(QStringLiteral("mp_centralWidget"));
        mp_centralWidget->setAutoFillBackground(false);
        mp_centralWidget->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(mp_centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_6 = new QSpacerItem(15, 15, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalSpacer_5 = new QSpacerItem(15, 10, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_5->addItem(verticalSpacer_5);

        mp_opponent2 = new client::OpponentWidget(mp_centralWidget);
        mp_opponent2->setObjectName(QStringLiteral("mp_opponent2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mp_opponent2->sizePolicy().hasHeightForWidth());
        mp_opponent2->setSizePolicy(sizePolicy);
        mp_opponent2->setMinimumSize(QSize(0, 0));

        verticalLayout_5->addWidget(mp_opponent2);


        horizontalLayout_5->addLayout(verticalLayout_5);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_7 = new QSpacerItem(10, 15, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        mp_opponent3 = new client::OpponentWidget(mp_centralWidget);
        mp_opponent3->setObjectName(QStringLiteral("mp_opponent3"));
        sizePolicy.setHeightForWidth(mp_opponent3->sizePolicy().hasHeightForWidth());
        mp_opponent3->setSizePolicy(sizePolicy);
        mp_opponent3->setMinimumSize(QSize(0, 0));

        verticalLayout_6->addWidget(mp_opponent3);

        verticalSpacer_6 = new QSpacerItem(15, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_6);


        horizontalLayout_6->addLayout(verticalLayout_6);


        gridLayout->addLayout(horizontalLayout_6, 0, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(50, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 0, 2, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        mp_opponent4 = new client::OpponentWidget(mp_centralWidget);
        mp_opponent4->setObjectName(QStringLiteral("mp_opponent4"));
        sizePolicy.setHeightForWidth(mp_opponent4->sizePolicy().hasHeightForWidth());
        mp_opponent4->setSizePolicy(sizePolicy);
        mp_opponent4->setMinimumSize(QSize(0, 0));

        verticalLayout_7->addWidget(mp_opponent4);

        verticalSpacer_7 = new QSpacerItem(15, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_7);


        horizontalLayout_7->addLayout(verticalLayout_7);

        horizontalSpacer_8 = new QSpacerItem(10, 15, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);


        gridLayout->addLayout(horizontalLayout_7, 0, 3, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalSpacer_4 = new QSpacerItem(15, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_4->addItem(verticalSpacer_4);

        mp_opponent5 = new client::OpponentWidget(mp_centralWidget);
        mp_opponent5->setObjectName(QStringLiteral("mp_opponent5"));
        sizePolicy.setHeightForWidth(mp_opponent5->sizePolicy().hasHeightForWidth());
        mp_opponent5->setSizePolicy(sizePolicy);
        mp_opponent5->setMinimumSize(QSize(0, 0));

        verticalLayout_4->addWidget(mp_opponent5);


        horizontalLayout_4->addLayout(verticalLayout_4);

        horizontalSpacer_5 = new QSpacerItem(15, 15, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_4, 0, 4, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalSpacer_9 = new QSpacerItem(15, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_9);

        mp_opponent1 = new client::OpponentWidget(mp_centralWidget);
        mp_opponent1->setObjectName(QStringLiteral("mp_opponent1"));
        sizePolicy.setHeightForWidth(mp_opponent1->sizePolicy().hasHeightForWidth());
        mp_opponent1->setSizePolicy(sizePolicy);

        verticalLayout_9->addWidget(mp_opponent1);

        verticalSpacer_11 = new QSpacerItem(15, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_11);


        horizontalLayout_3->addLayout(verticalLayout_9);

        horizontalSpacer_4 = new QSpacerItem(50, 15, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        mp_middleWidget = new QWidget(mp_centralWidget);
        mp_middleWidget->setObjectName(QStringLiteral("mp_middleWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mp_middleWidget->sizePolicy().hasHeightForWidth());
        mp_middleWidget->setSizePolicy(sizePolicy1);

        verticalLayout_10->addWidget(mp_middleWidget);

        verticalSpacer_10 = new QSpacerItem(15, 15, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_10->addItem(verticalSpacer_10);


        gridLayout->addLayout(verticalLayout_10, 1, 1, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(50, 15, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalSpacer_8 = new QSpacerItem(15, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_8);

        mp_opponent6 = new client::OpponentWidget(mp_centralWidget);
        mp_opponent6->setObjectName(QStringLiteral("mp_opponent6"));
        sizePolicy.setHeightForWidth(mp_opponent6->sizePolicy().hasHeightForWidth());
        mp_opponent6->setSizePolicy(sizePolicy);
        mp_opponent6->setMinimumSize(QSize(0, 0));

        verticalLayout_8->addWidget(mp_opponent6);

        verticalSpacer_12 = new QSpacerItem(15, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_12);


        horizontalLayout_2->addLayout(verticalLayout_8);


        gridLayout->addLayout(horizontalLayout_2, 1, 4, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(15, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer);

        mp_chatWidget = new client::ChatWidget(mp_centralWidget);
        mp_chatWidget->setObjectName(QStringLiteral("mp_chatWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mp_chatWidget->sizePolicy().hasHeightForWidth());
        mp_chatWidget->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(mp_chatWidget);


        horizontalLayout_8->addLayout(verticalLayout_2);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(30, 237, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        mp_localPlayerWidget = new client::LocalPlayerWidget(mp_centralWidget);
        mp_localPlayerWidget->setObjectName(QStringLiteral("mp_localPlayerWidget"));
        sizePolicy.setHeightForWidth(mp_localPlayerWidget->sizePolicy().hasHeightForWidth());
        mp_localPlayerWidget->setSizePolicy(sizePolicy);
        mp_localPlayerWidget->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(mp_localPlayerWidget);

        horizontalSpacer_2 = new QSpacerItem(30, 237, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_11->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(10, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_11->addItem(verticalSpacer_2);

        mp_statusLabel = new QLabel(mp_centralWidget);
        mp_statusLabel->setObjectName(QStringLiteral("mp_statusLabel"));
        sizePolicy2.setHeightForWidth(mp_statusLabel->sizePolicy().hasHeightForWidth());
        mp_statusLabel->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(10);
        mp_statusLabel->setFont(font);
        mp_statusLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(mp_statusLabel);


        horizontalLayout_8->addLayout(verticalLayout_11);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(15, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_3);

        mp_logWidget = new client::LogWidget(mp_centralWidget);
        mp_logWidget->setObjectName(QStringLiteral("mp_logWidget"));
        sizePolicy2.setHeightForWidth(mp_logWidget->sizePolicy().hasHeightForWidth());
        mp_logWidget->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(mp_logWidget);


        horizontalLayout_8->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_8, 2, 0, 1, 5);

        MainWindow->setCentralWidget(mp_centralWidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 388, 24));
        menubar->setAutoFillBackground(false);
        menuGame = new QMenu(menubar);
        menuGame->setObjectName(QStringLiteral("menuGame"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuGame->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuGame->addAction(mp_actionConnectToServer);
        menuGame->addAction(mp_actionDisconnectFromServer);
        menuGame->addSeparator();
        menuGame->addAction(actionCreateGame);
        menuGame->addAction(mp_actionJoinGame);
        menuGame->addAction(mp_actionLeaveGame);
        menuGame->addAction(mp_actionExit);
        menuHelp->addAction(mp_actionAbout);

        retranslateUi(MainWindow);
        QObject::connect(mp_actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "KBang Client", nullptr));
        MainWindow->setStyleSheet(QApplication::translate("MainWindow", "#mp_centralWidget {\n"
"	background-image: url(\"data/gfx/misc/bang-artwork.png\");\n"
"	background-position: center center;\n"
"	background-repeat: no-repeat;\n"
"\n"
"}", nullptr));
        mp_actionConnectToServer->setText(QApplication::translate("MainWindow", "&Connect to Server", nullptr));
        mp_actionExit->setText(QApplication::translate("MainWindow", "&Exit", nullptr));
        mp_actionDisconnectFromServer->setText(QApplication::translate("MainWindow", "&Disconnect from Server", nullptr));
        mp_actionJoinGame->setText(QApplication::translate("MainWindow", "&Join Game", nullptr));
        mp_actionLeaveGame->setText(QApplication::translate("MainWindow", "&Leave Game", nullptr));
        actionCreateGame->setText(QApplication::translate("MainWindow", "C&reate Game", nullptr));
        mp_actionAbout->setText(QApplication::translate("MainWindow", "&About KBang", nullptr));
        mp_statusLabel->setText(QString());
        menuGame->setTitle(QApplication::translate("MainWindow", "&Game", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
