/********************************************************************************
** Form generated from reading UI file 'queryrep.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYREP_H
#define UI_QUERYREP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_queryRep
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *buttonSearch;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonClose;

    void setupUi(QDialog *queryRep)
    {
        if (queryRep->objectName().isEmpty())
            queryRep->setObjectName(QStringLiteral("queryRep"));
        queryRep->resize(395, 385);
        gridLayout = new QGridLayout(queryRep);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(queryRep);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(queryRep);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        buttonSearch = new QPushButton(queryRep);
        buttonSearch->setObjectName(QStringLiteral("buttonSearch"));

        horizontalLayout->addWidget(buttonSearch);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableView = new QTableView(queryRep);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonClose = new QPushButton(queryRep);
        buttonClose->setObjectName(QStringLiteral("buttonClose"));

        horizontalLayout_2->addWidget(buttonClose);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        QWidget::setTabOrder(lineEdit, buttonSearch);
        QWidget::setTabOrder(buttonSearch, buttonClose);
        QWidget::setTabOrder(buttonClose, tableView);

        retranslateUi(queryRep);
        QObject::connect(buttonClose, SIGNAL(clicked()), queryRep, SLOT(reject()));
        QObject::connect(buttonSearch, SIGNAL(clicked()), queryRep, SLOT(SearchClicked()));

        QMetaObject::connectSlotsByName(queryRep);
    } // setupUi

    void retranslateUi(QDialog *queryRep)
    {
        queryRep->setWindowTitle(QApplication::translate("queryRep", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276\321\201\321\202\320\260\320\275\320\276\320\262\320\276\320\272", Q_NULLPTR));
        label->setText(QApplication::translate("queryRep", "\320\235\320\220\320\227\320\222\320\220\320\235\320\230\320\225 \320\241\320\237\320\225\320\232\320\242\320\220\320\232\320\233\320\257", Q_NULLPTR));
        lineEdit->setText(QString());
        buttonSearch->setText(QApplication::translate("queryRep", "\320\230\320\241\320\232\320\220\320\242\320\254", Q_NULLPTR));
        buttonClose->setText(QApplication::translate("queryRep", "\320\227\320\220\320\232\320\240\320\253\320\242\320\254", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class queryRep: public Ui_queryRep {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYREP_H
