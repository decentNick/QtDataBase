/********************************************************************************
** Form generated from reading UI file 'dialogticketstate.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTICKETSTATE_H
#define UI_DIALOGTICKETSTATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogTicketState
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QTreeWidget *treeWidget;

    void setupUi(QDialog *DialogTicketState)
    {
        if (DialogTicketState->objectName().isEmpty())
            DialogTicketState->setObjectName(QStringLiteral("DialogTicketState"));
        DialogTicketState->resize(587, 429);
        verticalLayout = new QVBoxLayout(DialogTicketState);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(DialogTicketState);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(DialogTicketState);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        treeWidget = new QTreeWidget(DialogTicketState);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setColumnCount(0);

        verticalLayout->addWidget(treeWidget);


        retranslateUi(DialogTicketState);
        QObject::connect(comboBox, SIGNAL(activated(QString)), DialogTicketState, SLOT(TheaterSelected(QString)));

        QMetaObject::connectSlotsByName(DialogTicketState);
    } // setupUi

    void retranslateUi(QDialog *DialogTicketState)
    {
        DialogTicketState->setWindowTitle(QApplication::translate("DialogTicketState", "DialogTicketState", Q_NULLPTR));
        label->setText(QApplication::translate("DialogTicketState", "\320\242\320\225\320\220\320\242\320\240", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogTicketState: public Ui_DialogTicketState {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTICKETSTATE_H
