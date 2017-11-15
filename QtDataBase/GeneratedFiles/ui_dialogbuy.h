/********************************************************************************
** Form generated from reading UI file 'dialogbuy.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGBUY_H
#define UI_DIALOGBUY_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogBuy
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QFormLayout *formLayout;
    QLabel *theaterLabel;
    QComboBox *theaterBox;
    QLabel *specLabel;
    QComboBox *spectacleBox;
    QLabel *datetimeLabel;
    QComboBox *datetimeBox;
    QLabel *priceLabel;
    QComboBox *priceBox;
    QLabel *quantityLabel;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *quantityBox;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *BuyButton;
    QPushButton *GetBillButton;
    QPushButton *CloseButton;

    void setupUi(QDialog *DialogBuy)
    {
        if (DialogBuy->objectName().isEmpty())
            DialogBuy->setObjectName(QStringLiteral("DialogBuy"));
        DialogBuy->resize(636, 485);
        DialogBuy->setMinimumSize(QSize(599, 485));
        DialogBuy->setMaximumSize(QSize(1000, 1000));
        verticalLayout_2 = new QVBoxLayout(DialogBuy);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(DialogBuy);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI Black"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        theaterLabel = new QLabel(DialogBuy);
        theaterLabel->setObjectName(QStringLiteral("theaterLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, theaterLabel);

        theaterBox = new QComboBox(DialogBuy);
        theaterBox->setObjectName(QStringLiteral("theaterBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, theaterBox);

        specLabel = new QLabel(DialogBuy);
        specLabel->setObjectName(QStringLiteral("specLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, specLabel);

        spectacleBox = new QComboBox(DialogBuy);
        spectacleBox->setObjectName(QStringLiteral("spectacleBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, spectacleBox);

        datetimeLabel = new QLabel(DialogBuy);
        datetimeLabel->setObjectName(QStringLiteral("datetimeLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, datetimeLabel);

        datetimeBox = new QComboBox(DialogBuy);
        datetimeBox->setObjectName(QStringLiteral("datetimeBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, datetimeBox);

        priceLabel = new QLabel(DialogBuy);
        priceLabel->setObjectName(QStringLiteral("priceLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, priceLabel);

        priceBox = new QComboBox(DialogBuy);
        priceBox->setObjectName(QStringLiteral("priceBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, priceBox);

        quantityLabel = new QLabel(DialogBuy);
        quantityLabel->setObjectName(QStringLiteral("quantityLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, quantityLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        quantityBox = new QSpinBox(DialogBuy);
        quantityBox->setObjectName(QStringLiteral("quantityBox"));

        horizontalLayout_3->addWidget(quantityBox);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_3);


        verticalLayout_2->addLayout(formLayout);

        tableWidget = new QTableWidget(DialogBuy);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout_2->addWidget(tableWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        BuyButton = new QPushButton(DialogBuy);
        BuyButton->setObjectName(QStringLiteral("BuyButton"));

        verticalLayout->addWidget(BuyButton);

        GetBillButton = new QPushButton(DialogBuy);
        GetBillButton->setObjectName(QStringLiteral("GetBillButton"));

        verticalLayout->addWidget(GetBillButton);

        CloseButton = new QPushButton(DialogBuy);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));

        verticalLayout->addWidget(CloseButton);


        verticalLayout_2->addLayout(verticalLayout);

        QWidget::setTabOrder(theaterBox, spectacleBox);
        QWidget::setTabOrder(spectacleBox, datetimeBox);
        QWidget::setTabOrder(datetimeBox, priceBox);
        QWidget::setTabOrder(priceBox, quantityBox);
        QWidget::setTabOrder(quantityBox, BuyButton);
        QWidget::setTabOrder(BuyButton, GetBillButton);
        QWidget::setTabOrder(GetBillButton, CloseButton);
        QWidget::setTabOrder(CloseButton, tableWidget);

        retranslateUi(DialogBuy);
        QObject::connect(CloseButton, SIGNAL(clicked()), DialogBuy, SLOT(reject()));
        QObject::connect(theaterBox, SIGNAL(activated(QString)), DialogBuy, SLOT(TheaterSelected(QString)));
        QObject::connect(spectacleBox, SIGNAL(activated(QString)), DialogBuy, SLOT(SpectacleSelected(QString)));
        QObject::connect(datetimeBox, SIGNAL(activated(QString)), DialogBuy, SLOT(DatetimeSelected(QString)));
        QObject::connect(BuyButton, SIGNAL(clicked()), DialogBuy, SLOT(BuyClicked()));
        QObject::connect(GetBillButton, SIGNAL(clicked()), DialogBuy, SLOT(GetBillClicked()));
        QObject::connect(priceBox, SIGNAL(activated(int)), DialogBuy, SLOT(PriceSelected(int)));

        QMetaObject::connectSlotsByName(DialogBuy);
    } // setupUi

    void retranslateUi(QDialog *DialogBuy)
    {
        DialogBuy->setWindowTitle(QApplication::translate("DialogBuy", "DialogBuy", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogBuy", "\320\237\320\236\320\232\320\243\320\237\320\232\320\220", Q_NULLPTR));
        theaterLabel->setText(QApplication::translate("DialogBuy", "\320\242\320\225\320\220\320\242\320\240", Q_NULLPTR));
        specLabel->setText(QApplication::translate("DialogBuy", "\320\241\320\237\320\225\320\232\320\242\320\220\320\232\320\233\320\254", Q_NULLPTR));
        datetimeLabel->setText(QApplication::translate("DialogBuy", "\320\224\320\220\320\242\320\220 \320\230 \320\222\320\240\320\225\320\234\320\257", Q_NULLPTR));
        priceLabel->setText(QApplication::translate("DialogBuy", "\320\246\320\225\320\235\320\220", Q_NULLPTR));
        quantityLabel->setText(QApplication::translate("DialogBuy", "\320\232\320\236\320\233\320\230\320\247\320\225\320\241\320\242\320\222\320\236", Q_NULLPTR));
        BuyButton->setText(QApplication::translate("DialogBuy", "\320\232\320\243\320\237\320\230\320\242\320\254", Q_NULLPTR));
        GetBillButton->setText(QApplication::translate("DialogBuy", "\320\237\320\236\320\233\320\243\320\247\320\230\320\242\320\254 \320\247\320\225\320\232", Q_NULLPTR));
        CloseButton->setText(QApplication::translate("DialogBuy", "\320\227\320\220\320\232\320\240\320\253\320\242\320\254", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogBuy: public Ui_DialogBuy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGBUY_H
