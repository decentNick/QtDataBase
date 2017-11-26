#include "dialogsuccess.h"
#include "ui_dialogsuccess.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

DialogSuccess::DialogSuccess(QSqlDatabase *db, QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::DialogSuccess();
	ui->setupUi(this);

	database = db;
}

void DialogSuccess::EnterClicked(void)
{
	QSqlQuery query(*database);
	QSqlQuery selled(*database), space(*database);

	ui->tableWidget->clear();
	ui->tableWidget->setRowCount(0);

	//создаем таблицу
	ui->tableWidget->setColumnCount(5); // Указываем число колонок
	ui->tableWidget->setShowGrid(false); // Выключаем сетку
	ui->tableWidget->setHorizontalHeaderLabels(QStringList()
		<< "THEATER"
		<< "SPECTACLE"
		<< "DATE AND TIME"
		<< "CATEGORY"
		<< "K"
		);

	ui->tableWidget->setColumnWidth(2, 150);

	query.prepare("SELECT th.name_th, sp.name_spec, st.datetime, ct.name_cat, ct.id_category "
				  "FROM theater th INNER JOIN staging st using(id_theater)"
				  "INNER JOIN spectacle sp using(id_spec) INNER JOIN category ct using(id_staging)"
				  "WHERE st.datetime >= ? AND st.datetime <= ? "
				  "GROUP BY 1, 2, 3, 4"
	);
	query.addBindValue(ui->fromDateTimeEdit->dateTime());
	query.addBindValue(ui->toDateTimeEdit->dateTime());
	query.exec();

	QString theater, spectacle, datetime;

	for (int i = 0; query.next(); ++i)
	{
		ui->tableWidget->insertRow(i);
		if (theater != query.value(0).toString())
		{
			theater = query.value(0).toString();
			ui->tableWidget->setItem(i, 0, new QTableWidgetItem(theater));
		}
		if (spectacle != query.value(1).toString())
		{
			spectacle = query.value(1).toString();
			ui->tableWidget->setItem(i, 1, new QTableWidgetItem(spectacle));
		}
		if (datetime != query.value(2).toString())
		{
			datetime = query.value(2).toString();
			ui->tableWidget->setItem(i, 2, new QTableWidgetItem(datetime));
		}
		ui->tableWidget->setItem(i, 3, new QTableWidgetItem(query.value(3).toString()));
		
		space.prepare("SELECT seats "
					  "FROM space "
					  "WHERE id_category = ?"
		);
		space.addBindValue(query.value(4).toInt());
		space.exec();
		space.next();

		selled.prepare("SELECT SUM(ps.quantity) "
					   "FROM sale sl INNER JOIN position ps using(id_sale)"
					   "WHERE ps.id_category = ? AND "
					   "(sl.type = 'soldAc' OR sl.type = 'soldEn')"
		);
		selled.addBindValue(query.value(4).toInt());
		selled.exec();
		selled.next();

		int sellQuantity = selled.value(0).toInt();

		ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString().sprintf("%g", (double)sellQuantity / space.value(0).toInt())));
	}
}

DialogSuccess::~DialogSuccess()
{
	delete ui;
}

