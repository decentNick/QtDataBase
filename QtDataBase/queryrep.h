#ifndef QUERYREP_H
#define QUERYREP_H

#include <QWidget>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "ui_queryrep.h"

class queryRep : public QDialog
{
	Q_OBJECT

public:
	queryRep(QSqlDatabase *db, QWidget *parent = 0);
	~queryRep();

	private slots:
	void TextChanged(QString str);
	void SearchClicked(void);

private:
	Ui::queryRep *uii;
	QSqlDatabase *database;
	QSqlQueryModel *model;
};

#endif // QUERYREP_H
