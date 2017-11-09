#ifndef DIALOGBUY_H
#define DIALOGBUY_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QDateTime>
#include "ui_dialogbuy.h"

class DialogBuy : public QDialog
{
	Q_OBJECT

public:
	DialogBuy(QSqlDatabase *db, QWidget *parent = 0);
	~DialogBuy();

private slots:
	void TheaterSelected(QString th);
	void SpectacleSelected(QString spec);
	void DatetimeSelected(QString dt);
	void PriceSelected(void);
	void BuyClicked(void);
	void GetBillClicked(void);

private:
	Ui::DialogBuy *ui;
	QSqlDatabase *database;
	QSqlTableModel *theater;
	QSqlQueryModel *spectacle;
	QSqlQueryModel *datetime;
	QSqlQueryModel *prices;
	QSqlQuery *category;
	int id_category;
	int id_theater;
	int freeSeats;
	int price;
	int saleId;
};

#endif // DIALOGBUY_H
