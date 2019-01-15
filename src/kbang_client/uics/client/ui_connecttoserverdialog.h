/********************************************************************************
** Form generated from reading UI file 'connecttoserverdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTTOSERVERDIALOG_H
#define UI_CONNECTTOSERVERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConnectToServerDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *serverList;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonAddServer;
    QPushButton *pushButtonEditServer;
    QPushButton *pushButtonDeleteServer;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonConnect;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *ConnectToServerDialog)
    {
        if (ConnectToServerDialog->objectName().isEmpty())
            ConnectToServerDialog->setObjectName(QStringLiteral("ConnectToServerDialog"));
        ConnectToServerDialog->resize(440, 241);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ConnectToServerDialog->sizePolicy().hasHeightForWidth());
        ConnectToServerDialog->setSizePolicy(sizePolicy);
        ConnectToServerDialog->setMinimumSize(QSize(0, 0));
        ConnectToServerDialog->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(ConnectToServerDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        serverList = new QTreeWidget(ConnectToServerDialog);
        serverList->headerItem()->setText(2, QString());
        new QTreeWidgetItem(serverList);
        serverList->setObjectName(QStringLiteral("serverList"));
        serverList->setAlternatingRowColors(true);
        serverList->setIndentation(15);
        serverList->setRootIsDecorated(false);
        serverList->setUniformRowHeights(false);
        serverList->setItemsExpandable(false);
        serverList->setSortingEnabled(true);
        serverList->setAnimated(true);

        verticalLayout->addWidget(serverList);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButtonAddServer = new QPushButton(ConnectToServerDialog);
        pushButtonAddServer->setObjectName(QStringLiteral("pushButtonAddServer"));

        horizontalLayout_3->addWidget(pushButtonAddServer);

        pushButtonEditServer = new QPushButton(ConnectToServerDialog);
        pushButtonEditServer->setObjectName(QStringLiteral("pushButtonEditServer"));

        horizontalLayout_3->addWidget(pushButtonEditServer);

        pushButtonDeleteServer = new QPushButton(ConnectToServerDialog);
        pushButtonDeleteServer->setObjectName(QStringLiteral("pushButtonDeleteServer"));

        horizontalLayout_3->addWidget(pushButtonDeleteServer);


        verticalLayout->addLayout(horizontalLayout_3);

        line_2 = new QFrame(ConnectToServerDialog);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(228, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButtonConnect = new QPushButton(ConnectToServerDialog);
        pushButtonConnect->setObjectName(QStringLiteral("pushButtonConnect"));
        pushButtonConnect->setEnabled(false);
        pushButtonConnect->setDefault(true);

        horizontalLayout_2->addWidget(pushButtonConnect);

        pushButtonCancel = new QPushButton(ConnectToServerDialog);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout_2->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_2);

        QWidget::setTabOrder(serverList, pushButtonAddServer);
        QWidget::setTabOrder(pushButtonAddServer, pushButtonEditServer);
        QWidget::setTabOrder(pushButtonEditServer, pushButtonDeleteServer);
        QWidget::setTabOrder(pushButtonDeleteServer, pushButtonConnect);
        QWidget::setTabOrder(pushButtonConnect, pushButtonCancel);

        retranslateUi(ConnectToServerDialog);
        QObject::connect(pushButtonCancel, SIGNAL(clicked()), ConnectToServerDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(ConnectToServerDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectToServerDialog)
    {
        ConnectToServerDialog->setWindowTitle(QApplication::translate("ConnectToServerDialog", "Connect to Server", 0));
        QTreeWidgetItem *___qtreewidgetitem = serverList->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("ConnectToServerDialog", "Port", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("ConnectToServerDialog", "Server Address", 0));

        const bool __sortingEnabled = serverList->isSortingEnabled();
        serverList->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = serverList->topLevelItem(0);
        ___qtreewidgetitem1->setText(1, QApplication::translate("ConnectToServerDialog", "6543", 0));
        ___qtreewidgetitem1->setText(0, QApplication::translate("ConnectToServerDialog", "localhost", 0));
        serverList->setSortingEnabled(__sortingEnabled);

        pushButtonAddServer->setText(QApplication::translate("ConnectToServerDialog", "Add Server", 0));
        pushButtonEditServer->setText(QApplication::translate("ConnectToServerDialog", "Edit Server", 0));
        pushButtonDeleteServer->setText(QApplication::translate("ConnectToServerDialog", "Delete Server", 0));
        pushButtonConnect->setText(QApplication::translate("ConnectToServerDialog", "&Connect", 0));
        pushButtonCancel->setText(QApplication::translate("ConnectToServerDialog", "C&ancel", 0));
    } // retranslateUi

};

namespace Ui {
    class ConnectToServerDialog: public Ui_ConnectToServerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTTOSERVERDIALOG_H
