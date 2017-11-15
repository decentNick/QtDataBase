/********************************************************************************
** Form generated from reading UI file 'dialogemptysales.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGEMPTYSALES_H
#define UI_DIALOGEMPTYSALES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogEmptySales
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *DialogEmptySales)
    {
        if (DialogEmptySales->objectName().isEmpty())
            DialogEmptySales->setObjectName(QStringLiteral("DialogEmptySales"));
        DialogEmptySales->resize(240, 489);
        verticalLayout = new QVBoxLayout(DialogEmptySales);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget = new QTableWidget(DialogEmptySales);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(338, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(DialogEmptySales);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(DialogEmptySales);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DialogEmptySales);
        QObject::connect(pushButton, SIGNAL(clicked()), DialogEmptySales, SLOT(reject()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), DialogEmptySales, SLOT(RefreshClicked()));

        QMetaObject::connectSlotsByName(DialogEmptySales);
    } // setupUi

    void retranslateUi(QDialog *DialogEmptySales)
    {
        DialogEmptySales->setWindowTitle(QApplication::translate("DialogEmptySales", "DialogEmptySales", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("DialogEmptySales", "REFRESH", Q_NULLPTR));
        pushButton->setText(QApplication::translate("DialogEmptySales", "CLOSE", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogEmptySales: public Ui_DialogEmptySales {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEMPTYSALES_H
