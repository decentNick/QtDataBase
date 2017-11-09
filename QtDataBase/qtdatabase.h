#ifndef QTDATABASE_H
#define QTDATABASE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include "ui_qtdatabase.h"

class QtDataBase : public QMainWindow
{
	Q_OBJECT

public:
	QtDataBase(QWidget *parent = 0);
	~QtDataBase();

private slots:
	void queryRepertoire(void);
	void searchStages(void);
	void BuyClicked(void);
	void ReturnClicked(void);

private:
	Ui::QtDataBaseClass *ui;
	QSqlDatabase db;
	QSqlQueryModel *repertoireModel;
};

#endif // QTDATABASE_H
