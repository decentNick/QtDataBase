/********************************************************************************
** Form generated from reading UI file 'qtdatabase.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTDATABASE_H
#define UI_QTDATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtDataBaseClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *repertoire;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtDataBaseClass)
    {
        if (QtDataBaseClass->objectName().isEmpty())
            QtDataBaseClass->setObjectName(QStringLiteral("QtDataBaseClass"));
        QtDataBaseClass->resize(572, 496);
        centralWidget = new QWidget(QtDataBaseClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        repertoire = new QPushButton(centralWidget);
        repertoire->setObjectName(QStringLiteral("repertoire"));

        verticalLayout->addWidget(repertoire);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        QtDataBaseClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtDataBaseClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 572, 21));
        QtDataBaseClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtDataBaseClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtDataBaseClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtDataBaseClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtDataBaseClass->setStatusBar(statusBar);
        QWidget::setTabOrder(pushButton, pushButton_2);
        QWidget::setTabOrder(pushButton_2, repertoire);
        QWidget::setTabOrder(repertoire, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_4);
        QWidget::setTabOrder(pushButton_4, tableView);

        retranslateUi(QtDataBaseClass);
        QObject::connect(repertoire, SIGNAL(clicked()), QtDataBaseClass, SLOT(queryRepertoire()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), QtDataBaseClass, SLOT(close()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), QtDataBaseClass, SLOT(searchStages()));
        QObject::connect(pushButton, SIGNAL(clicked()), QtDataBaseClass, SLOT(BuyClicked()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), QtDataBaseClass, SLOT(ReturnClicked()));

        QMetaObject::connectSlotsByName(QtDataBaseClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtDataBaseClass)
    {
        QtDataBaseClass->setWindowTitle(QApplication::translate("QtDataBaseClass", "\320\242\320\265\320\260\321\202\321\200\320\260\320\273\321\214\320\275\320\260\321\217 \320\272\320\260\321\201\321\201\320\260", Q_NULLPTR));
        pushButton->setText(QApplication::translate("QtDataBaseClass", "\320\232\320\243\320\237\320\230\320\242\320\254", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("QtDataBaseClass", "\320\222\320\225\320\240\320\235\320\243\320\242\320\254", Q_NULLPTR));
        repertoire->setText(QApplication::translate("QtDataBaseClass", "\320\240\320\225\320\237\320\225\320\240\320\242\320\243\320\220\320\240", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("QtDataBaseClass", "\320\235\320\220\320\231\320\242\320\230 \320\237\320\240\320\225\320\224\320\241\320\242\320\220\320\233\320\225\320\235\320\230\320\257", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("QtDataBaseClass", "\320\227\320\220\320\232\320\240\320\253\320\242\320\254", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtDataBaseClass: public Ui_QtDataBaseClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTDATABASE_H
