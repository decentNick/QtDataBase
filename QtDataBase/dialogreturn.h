#ifndef DIALOGRETURN_H
#define DIALOGRETURN_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {class DialogReturn;};

class DialogReturn : public QDialog
{
	Q_OBJECT

public:
	DialogReturn(QSqlDatabase *db, QWidget *parent = 0);
	~DialogReturn();

private slots:
	void TextChanged(QString);
	void SaleIdEntered(void);
	void TheaterSelected(QString);
	void SpectacleSelected(QString);
	void DatetimeSelected(QString);
	void CategorySelected(int);
	void ReturnClicked(void);

private:
	Ui::DialogReturn *ui;
	QSqlDatabase *database;
	QSqlQueryModel *theater;
	QSqlQueryModel *spectacle;
	QSqlQueryModel *datetime;
	QSqlQueryModel *category;
	QSqlQuery *categoryQuery;

	int saleId;
};

#endif // DIALOGRETURN_H
