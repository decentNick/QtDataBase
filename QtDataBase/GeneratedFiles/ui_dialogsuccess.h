/********************************************************************************
** Form generated from reading UI file 'dialogsuccess.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSUCCESS_H
#define UI_DIALOGSUCCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogSuccess
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QDateTimeEdit *fromDateTimeEdit;
    QDateTimeEdit *toDateTimeEdit;
    QPushButton *enterButton;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *closeButton;

    void setupUi(QDialog *DialogSuccess)
    {
        if (DialogSuccess->objectName().isEmpty())
            DialogSuccess->setObjectName(QStringLiteral("DialogSuccess"));
        DialogSuccess->resize(589, 394);
        verticalLayout = new QVBoxLayout(DialogSuccess);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(DialogSuccess);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        fromDateTimeEdit = new QDateTimeEdit(DialogSuccess);
        fromDateTimeEdit->setObjectName(QStringLiteral("fromDateTimeEdit"));

        horizontalLayout_3->addWidget(fromDateTimeEdit);

        toDateTimeEdit = new QDateTimeEdit(DialogSuccess);
        toDateTimeEdit->setObjectName(QStringLiteral("toDateTimeEdit"));

        horizontalLayout_3->addWidget(toDateTimeEdit);

        enterButton = new QPushButton(DialogSuccess);
        enterButton->setObjectName(QStringLiteral("enterButton"));

        horizontalLayout_3->addWidget(enterButton);


        verticalLayout->addLayout(horizontalLayout_3);

        tableWidget = new QTableWidget(DialogSuccess);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        closeButton = new QPushButton(DialogSuccess);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout_2->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(DialogSuccess);
        QObject::connect(closeButton, SIGNAL(clicked()), DialogSuccess, SLOT(reject()));
        QObject::connect(enterButton, SIGNAL(clicked()), DialogSuccess, SLOT(EnterClicked()));

        QMetaObject::connectSlotsByName(DialogSuccess);
    } // setupUi

    void retranslateUi(QDialog *DialogSuccess)
    {
        DialogSuccess->setWindowTitle(QApplication::translate("DialogSuccess", "DialogSuccess", Q_NULLPTR));
        label->setText(QApplication::translate("DialogSuccess", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \321\203\321\201\320\277\320\265\321\210\320\275\320\276\321\201\321\202\320\270", Q_NULLPTR));
        enterButton->setText(QApplication::translate("DialogSuccess", "\320\222\320\222\320\236\320\224", Q_NULLPTR));
        closeButton->setText(QApplication::translate("DialogSuccess", "\320\227\320\220\320\232\320\240\320\253\320\242\320\254", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogSuccess: public Ui_DialogSuccess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSUCCESS_H
