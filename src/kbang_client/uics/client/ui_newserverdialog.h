/********************************************************************************
** Form generated from reading UI file 'newserverdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSERVERDIALOG_H
#define UI_NEWSERVERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewServerDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditHost;
    QLabel *label_2;
    QSpinBox *spinBoxPort;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewServerDialog)
    {
        if (NewServerDialog->objectName().isEmpty())
            NewServerDialog->setObjectName(QStringLiteral("NewServerDialog"));
        NewServerDialog->resize(219, 95);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NewServerDialog->sizePolicy().hasHeightForWidth());
        NewServerDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(NewServerDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(NewServerDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditHost = new QLineEdit(NewServerDialog);
        lineEditHost->setObjectName(QStringLiteral("lineEditHost"));

        gridLayout->addWidget(lineEditHost, 0, 1, 1, 1);

        label_2 = new QLabel(NewServerDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBoxPort = new QSpinBox(NewServerDialog);
        spinBoxPort->setObjectName(QStringLiteral("spinBoxPort"));

        gridLayout->addWidget(spinBoxPort, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(NewServerDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEditHost);
        label_2->setBuddy(spinBoxPort);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(lineEditHost, spinBoxPort);
        QWidget::setTabOrder(spinBoxPort, buttonBox);

        retranslateUi(NewServerDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewServerDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewServerDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewServerDialog);
    } // setupUi

    void retranslateUi(QDialog *NewServerDialog)
    {
        label->setText(QApplication::translate("NewServerDialog", "Server &Host:", Q_NULLPTR));
        label_2->setText(QApplication::translate("NewServerDialog", "Server &Port:", Q_NULLPTR));
        Q_UNUSED(NewServerDialog);
    } // retranslateUi

};

namespace Ui {
    class NewServerDialog: public Ui_NewServerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSERVERDIALOG_H
