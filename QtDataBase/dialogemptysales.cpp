#include "dialogemptysales.h"
#include "ui_dialogemptysales.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

DialogEmptySales::DialogEmptySales(QSqlDatabase *db, QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::DialogEmptySales();
	ui->setupUi(this);
}

void DialogEmptySales::RefreshClicked(void)
{
	ui->tableWidget->clear();
	ui->tableWidget->setRowCount(0);

	//создаем таблицу
	ui->tableWidget->setColumnCount(2); // ”казываем число колонок
	ui->tableWidget->setShowGrid(true); // ¬ключаем сетку
	ui->tableWidget->setHorizontalHeaderLabels(QStringList()
		<< "THEATER"
		<< "K"
	);

	QSqlQuery theater;
	theater.prepare("SELECT name_th, id_theater "
					"FROM theater"
	);
	theater.exec();

	QSqlQuery query;
	for (int i = 0; theater.next(); ++i)
	{
		int returnedCount = 0;
		int saleCount = 0;

		query.prepare("SELECT SUM(ps.quantity) "
					  "FROM staging st INNER JOIN category ct using(id_staging)"
					  "INNER JOIN position ps using(id_category) INNER JOIN sale "
					  "sl using(id_sale) "
					  "WHERE st.id_theater = ? AND (sl.type = 'soldEn' OR sl.type = 'soldAc')"
		);
		query.addBindValue(theater.value(1).toInt());
		query.exec();
		query.next();

		saleCount = query.value(0).toInt();

		query.prepare("SELECT SUM(ps.quantity) "
					  "FROM staging st INNER JOIN category ct using(id_staging)"
					  "INNER JOIN position ps using(id_category) INNER JOIN sale "
					  "sl using(id_sale) "
					  "WHERE st.id_theater = ? AND sl.type = 'return'"
		);
		query.addBindValue(theater.value(1).toInt());
		query.exec();
		query.next();

		returnedCount = query.value(0).toInt();

		ui->tableWidget->insertRow(i);
		ui->tableWidget->setItem(i, 0, new QTableWidgetItem(theater.value(0).toString()));
		if (returnedCount + saleCount == 0)
			ui->tableWidget->setItem(i, 1, new QTableWidgetItem("NULL"));
		else
			ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString().sprintf("%g", (double)returnedCount / (returnedCount + saleCount))));
	}
}

DialogEmptySales::~DialogEmptySales()
{
	delete ui;
}

