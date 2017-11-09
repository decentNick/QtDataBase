/********************************************************************************
** Form generated from reading UI file 'dialogreturn.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGRETURN_H
#define UI_DIALOGRETURN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogReturn
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QFormLayout *formLayout;
    QLabel *saleIdLabel;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *enterBillId;
    QLabel *theaterLabel;
    QComboBox *thBox;
    QLabel *specLabel;
    QComboBox *spBox;
    QLabel *datetimeLabel;
    QComboBox *dtBox;
    QLabel *categoryLabel;
    QComboBox *ctBox;
    QLabel *quantityLabel;
    QSpinBox *qnBox;
    QHBoxLayout *horizontalLayout_8;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *returnButton;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QPushButton *closeButton;

    void setupUi(QDialog *DialogReturn)
    {
        if (DialogReturn->objectName().isEmpty())
            DialogReturn->setObjectName(QStringLiteral("DialogReturn"));
        DialogReturn->resize(588, 443);
        verticalLayout_2 = new QVBoxLayout(DialogReturn);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(156, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(DialogReturn);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI Black"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(156, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        saleIdLabel = new QLabel(DialogReturn);
        saleIdLabel->setObjectName(QStringLiteral("saleIdLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, saleIdLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(DialogReturn);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        enterBillId = new QPushButton(DialogReturn);
        enterBillId->setObjectName(QStringLiteral("enterBillId"));

        horizontalLayout->addWidget(enterBillId);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        theaterLabel = new QLabel(DialogReturn);
        theaterLabel->setObjectName(QStringLiteral("theaterLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, theaterLabel);

        thBox = new QComboBox(DialogReturn);
        thBox->setObjectName(QStringLiteral("thBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, thBox);

        specLabel = new QLabel(DialogReturn);
        specLabel->setObjectName(QStringLiteral("specLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, specLabel);

        spBox = new QComboBox(DialogReturn);
        spBox->setObjectName(QStringLiteral("spBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, spBox);

        datetimeLabel = new QLabel(DialogReturn);
        datetimeLabel->setObjectName(QStringLiteral("datetimeLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, datetimeLabel);

        dtBox = new QComboBox(DialogReturn);
        dtBox->setObjectName(QStringLiteral("dtBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, dtBox);

        categoryLabel = new QLabel(DialogReturn);
        categoryLabel->setObjectName(QStringLiteral("categoryLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, categoryLabel);

        ctBox = new QComboBox(DialogReturn);
        ctBox->setObjectName(QStringLiteral("ctBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, ctBox);

        quantityLabel = new QLabel(DialogReturn);
        quantityLabel->setObjectName(QStringLiteral("quantityLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, quantityLabel);

        qnBox = new QSpinBox(DialogReturn);
        qnBox->setObjectName(QStringLiteral("qnBox"));

        formLayout->setWidget(5, QFormLayout::FieldRole, qnBox);


        verticalLayout_2->addLayout(formLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        tableWidget = new QTableWidget(DialogReturn);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        horizontalLayout_8->addWidget(tableWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        returnButton = new QPushButton(DialogReturn);
        returnButton->setObjectName(QStringLiteral("returnButton"));

        verticalLayout->addWidget(returnButton);

        pushButton = new QPushButton(DialogReturn);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        closeButton = new QPushButton(DialogReturn);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        verticalLayout->addWidget(closeButton);


        horizontalLayout_8->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_8);


        retranslateUi(DialogReturn);
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), DialogReturn, SLOT(TextChanged(QString)));
        QObject::connect(closeButton, SIGNAL(clicked()), DialogReturn, SLOT(reject()));
        QObject::connect(enterBillId, SIGNAL(clicked()), DialogReturn, SLOT(SaleIdEntered()));
        QObject::connect(thBox, SIGNAL(activated(QString)), DialogReturn, SLOT(TheaterSelected(QString)));
        QObject::connect(spBox, SIGNAL(activated(QString)), DialogReturn, SLOT(SpectacleSelected(QString)));
        QObject::connect(dtBox, SIGNAL(activated(QString)), DialogReturn, SLOT(DatetimeSelected(QString)));
        QObject::connect(ctBox, SIGNAL(activated(int)), DialogReturn, SLOT(CategorySelected(int)));

        QMetaObject::connectSlotsByName(DialogReturn);
    } // setupUi

    void retranslateUi(QDialog *DialogReturn)
    {
        DialogReturn->setWindowTitle(QApplication::translate("DialogReturn", "DialogReturn", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogReturn", "\320\222\320\236\320\227\320\222\320\240\320\220\320\242", Q_NULLPTR));
        saleIdLabel->setText(QApplication::translate("DialogReturn", "\320\222\320\222\320\225\320\224\320\230\320\242\320\225 ID \320\247\320\225\320\232\320\220", Q_NULLPTR));
        enterBillId->setText(QApplication::translate("DialogReturn", "Enter", Q_NULLPTR));
        theaterLabel->setText(QApplication::translate("DialogReturn", "\320\242\320\225\320\220\320\242\320\240", Q_NULLPTR));
        specLabel->setText(QApplication::translate("DialogReturn", "\320\241\320\237\320\225\320\232\320\242\320\220\320\232\320\233\320\254", Q_NULLPTR));
        datetimeLabel->setText(QApplication::translate("DialogReturn", "\320\224\320\220\320\242\320\220 \320\230 \320\222\320\240\320\225\320\234\320\257", Q_NULLPTR));
        categoryLabel->setText(QApplication::translate("DialogReturn", "\320\232\320\220\320\242\320\225\320\223\320\236\320\240\320\230\320\257", Q_NULLPTR));
        quantityLabel->setText(QApplication::translate("DialogReturn", "\320\232\320\236\320\233\320\230\320\247\320\225\320\241\320\242\320\222\320\236", Q_NULLPTR));
        returnButton->setText(QApplication::translate("DialogReturn", "\320\222\320\225\320\240\320\235\320\243\320\242\320\254", Q_NULLPTR));
        pushButton->setText(QApplication::translate("DialogReturn", "PushButton", Q_NULLPTR));
        closeButton->setText(QApplication::translate("DialogReturn", "\320\227\320\220\320\232\320\240\320\253\320\242\320\254", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogReturn: public Ui_DialogReturn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGRETURN_H
