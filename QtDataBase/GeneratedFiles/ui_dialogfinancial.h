/********************************************************************************
** Form generated from reading UI file 'dialogfinancial.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFINANCIAL_H
#define UI_DIALOGFINANCIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogFinancial
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *buttonCreate;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *DialogFinancial)
    {
        if (DialogFinancial->objectName().isEmpty())
            DialogFinancial->setObjectName(QStringLiteral("DialogFinancial"));
        DialogFinancial->resize(383, 526);
        verticalLayout = new QVBoxLayout(DialogFinancial);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(DialogFinancial);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(DialogFinancial);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        buttonCreate = new QPushButton(DialogFinancial);
        buttonCreate->setObjectName(QStringLiteral("buttonCreate"));

        horizontalLayout_2->addWidget(buttonCreate);


        verticalLayout->addLayout(horizontalLayout_2);

        textEdit = new QTextEdit(DialogFinancial);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(611, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(DialogFinancial);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DialogFinancial);
        QObject::connect(pushButton, SIGNAL(clicked()), DialogFinancial, SLOT(reject()));
        QObject::connect(buttonCreate, SIGNAL(clicked()), DialogFinancial, SLOT(YearInserted()));

        QMetaObject::connectSlotsByName(DialogFinancial);
    } // setupUi

    void retranslateUi(QDialog *DialogFinancial)
    {
        DialogFinancial->setWindowTitle(QApplication::translate("DialogFinancial", "DialogFinancial", Q_NULLPTR));
        label->setText(QApplication::translate("DialogFinancial", "YEAR", Q_NULLPTR));
        buttonCreate->setText(QApplication::translate("DialogFinancial", "CREATE", Q_NULLPTR));
        pushButton->setText(QApplication::translate("DialogFinancial", "CLOSE", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogFinancial: public Ui_DialogFinancial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFINANCIAL_H
