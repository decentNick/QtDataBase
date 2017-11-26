#include "dialogreturn.h"
#include "ui_dialogreturn.h"
#include <QMessageBox>
#include <QSqlError>
#include <QDateTime>

#define ID_POS(i) ui->tableWidget->item((i), 6)->text().toInt()
#define QN_SOLD(i) ui->tableWidget->item((i), 5)->text().toInt()
#define QN_RETU(i) ui->tableWidget->item((i), 4)->text().toInt()

DialogReturn::DialogReturn(QSqlDatabase *db, QWidget *parent)
	: QDialog(parent), ui(new Ui::DialogReturn())
{
	ui->setupUi(this);

	theater = new QSqlQueryModel(this);
	spectacle = new QSqlQueryModel(this);
	datetime = new QSqlQueryModel(this);
	category = new QSqlQueryModel(this);
	categoryQuery = new QSqlQuery(*db);

	QRegExp reg("[0-9]{1,10}");
	ui->lineEdit->setValidator(new QRegExpValidator(reg, this));

	ui->thBox->setEnabled(false);
	ui->spBox->setEnabled(false);
	ui->dtBox->setEnabled(false);
	ui->ctBox->setEnabled(false);
	ui->qnBox->setEnabled(false);
	ui->enterBillId->setEnabled(false);
	ui->addButton->setEnabled(false);
	ui->returnButton->setEnabled(false);
	ui->totalButton->setEnabled(false);

	//создаем таблицу
	ui->tableWidget->setColumnCount(7); // Указываем число колонок
	ui->tableWidget->setShowGrid(true); // Включаем сетку
	ui->tableWidget->setColumnHidden(6, true);

	ui->tableWidget->setHorizontalHeaderLabels(QStringList()
		<< trUtf8("THEATER")
		<< trUtf8("SPECTACLE")
		<< trUtf8("DATE AND TIME")
		<< trUtf8("CATEGORY")
		<< trUtf8("RETURNED AMOUNT")
		<< trUtf8("SOLD AMOUNT")
	);

	ui->tableWidget->setColumnWidth(2, 130);
	ui->tableWidget->setColumnWidth(4, 140);
	database = db;
	ui->qnBox->setMinimum(1);

}

void DialogReturn::TextChanged(QString str)
{
	ui->enterBillId->setEnabled(!str.isEmpty());
}

void DialogReturn::SaleIdEntered(void)
{
	QSqlQuery query;
	ui->thBox->setEnabled(true);
	ui->spBox->setEnabled(false);
	ui->dtBox->setEnabled(false);
	ui->ctBox->setEnabled(false);
	ui->qnBox->setEnabled(false);
	ui->addButton->setEnabled(false);
	ui->returnButton->setEnabled(false);

	query.prepare("SELECT DISTINCT th.name_th "
				  "FROM sale sl INNER JOIN position ps using(id_sale)"
				  "INNER JOIN category ct using(id_category)"
				  "INNER JOIN staging st using(id_staging)"
				  "INNER JOIN theater th using(id_theater)"
				  "WHERE sl.id_sale = ? AND "
				  "(sl.type = 'soldEn' OR sl.type = 'soldAc')"
	);
	query.addBindValue(ui->lineEdit->text());
	query.exec();

	theater->setQuery(query);
	ui->thBox->setModel(theater);
	ui->thBox->setModelColumn(0);
}

void DialogReturn::TheaterSelected(QString th)
{
	QSqlQuery query;
	ui->spBox->setEnabled(true);
	ui->dtBox->setEnabled(false);
	ui->ctBox->setEnabled(false);
	ui->qnBox->setEnabled(false);
	ui->addButton->setEnabled(false);

	query.prepare("SELECT DISTINCT sp.name_spec "
				  "FROM sale sl INNER JOIN position ps using(id_sale)" 
				  "INNER JOIN category ct using(id_category)"
				  "INNER JOIN staging st using(id_staging)" 
				  "INNER JOIN theater th using(id_theater)" 
				  "INNER JOIN spectacle sp using(id_spec)"
				  "WHERE sl.id_sale = ? AND th.name_th = ?"
	);
	query.addBindValue(ui->lineEdit->text());
	query.addBindValue(th);
	query.exec();
	
	spectacle->setQuery(query);
	ui->spBox->setModel(spectacle);
	ui->spBox->setModelColumn(0);
}

void DialogReturn::SpectacleSelected(QString sp)
{
	QSqlQuery query;
	QDateTime dt = QDateTime::currentDateTime();
	ui->dtBox->setEnabled(true);
	ui->ctBox->setEnabled(false);
	ui->qnBox->setEnabled(false);
	ui->addButton->setEnabled(false);

	query.prepare("SELECT DISTINCT st.datetime "
				  "FROM sale sl INNER JOIN position ps using(id_sale)" 
				  "INNER JOIN category ct using(id_category)"
				  "INNER JOIN staging st using(id_staging)" 
				  "INNER JOIN theater th using(id_theater)"
				  "INNER JOIN spectacle sp using(id_spec)"
				  "WHERE sl.id_sale = ? AND th.name_th = ? "
				  "AND sp.name_spec = ? AND st.datetime > ?"
	);
	query.addBindValue(ui->lineEdit->text());
	query.addBindValue(ui->thBox->currentText());
	query.addBindValue(sp);
	query.addBindValue(dt);
	query.exec();

	datetime->setQuery(query);
	ui->dtBox->setModel(datetime);
	ui->dtBox->setModelColumn(0);
}

void DialogReturn::DatetimeSelected(QString dt)
{
	ui->ctBox->setEnabled(true);
	ui->qnBox->setEnabled(false);
	ui->addButton->setEnabled(false);

	categoryQuery->prepare("SELECT ct.name_cat, ps.id_pos, ct.id_category "
						   "FROM sale sl INNER JOIN position ps using(id_sale)"
						   "INNER JOIN category ct using(id_category)"
					       "INNER JOIN staging st using(id_staging)"
						   "INNER JOIN theater th using(id_theater)"
						   "INNER JOIN spectacle sp using(id_spec)"
						   "WHERE sl.id_sale = ? AND th.name_th = ? "
						   "AND sp.name_spec = ? AND st.datetime = ? "
	);
	categoryQuery->addBindValue(ui->lineEdit->text());
	categoryQuery->addBindValue(ui->thBox->currentText());
	categoryQuery->addBindValue(ui->spBox->currentText());
	categoryQuery->addBindValue(dt);
	categoryQuery->exec();

	category->setQuery(*categoryQuery);
	ui->ctBox->setModel(category);
	ui->ctBox->setModelColumn(0);
}

void DialogReturn::CategorySelected(int ind)
{
	for (int i = 1; i < ind && categoryQuery->next(); ++i)
		;
	
	id_position = categoryQuery->value(1).toInt();
	id_category = categoryQuery->value(2).toInt();

	QSqlQuery info;
	info.prepare("SELECT ps.quantity "
				 "FROM position ps INNER JOIN category ct using(id_category)"
				 "WHERE ps.id_pos = ?"
	);
	info.addBindValue(id_position);
	info.exec();
	info.next();

	posQuantity = info.value(0).toInt();

	ui->qnBox->setMaximum(posQuantity);
	ui->qnBox->setEnabled(true);
	ui->addButton->setEnabled(true);
}

void DialogReturn::AddClicked(void)
{
	QSqlQuery query;

	if (ui->qnBox->value() == 0)
	{
		QMessageBox::information(this, "INFO", "QUANTITY = 0");
		return;
	}

	ui->thBox->setEnabled(false);
	ui->spBox->setEnabled(false);
	ui->dtBox->setEnabled(false);
	ui->ctBox->setEnabled(false);
	ui->qnBox->setEnabled(false);
	ui->enterBillId->setEnabled(false);
	ui->addButton->setEnabled(false);
	ui->returnButton->setEnabled(true);

	//добавляем строку в таблицу счета
	int i = ui->tableWidget->rowCount();
	ui->tableWidget->insertRow(i);
	ui->tableWidget->setItem(i, 0, new QTableWidgetItem(ui->thBox->currentText()));
	ui->tableWidget->setItem(i, 1, new QTableWidgetItem(ui->spBox->currentText()));
	ui->tableWidget->setItem(i, 2, new QTableWidgetItem(ui->dtBox->currentText()));
	ui->tableWidget->setItem(i, 3, new QTableWidgetItem(ui->ctBox->currentText()));
	ui->tableWidget->setItem(i, 4, new QTableWidgetItem(ui->qnBox->text()));
	ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(posQuantity - ui->qnBox->value())));
	ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(id_position)));

}

void DialogReturn::ReturnClicked(void)
{
	QSqlQuery query;
	QSqlQuery position;
	QDateTime dt = QDateTime::currentDateTime();

	ui->lineEdit->setEnabled(false);
	ui->thBox->setEnabled(false);
	ui->spBox->setEnabled(false);
	ui->dtBox->setEnabled(false);
	ui->ctBox->setEnabled(false);
	ui->qnBox->setEnabled(false);
	ui->enterBillId->setEnabled(false);
	ui->addButton->setEnabled(false);
	ui->returnButton->setEnabled(false);
	ui->totalButton->setEnabled(true);

	int retuId = 0;
	saleId = 0;

	//обновляем наш чек(чтобы больше нельзя было по нему вернуть)
	query.prepare("UPDATE sale SET type = 'soldNotEn' WHERE id_sale = ? AND type = 'soldEn'");
	query.addBindValue(ui->lineEdit->text());
	query.exec();
	query.prepare("UPDATE sale SET type = 'soldNotAc' WHERE id_sale = ? AND type = 'soldAc'");
	query.addBindValue(ui->lineEdit->text());
	query.exec();

	//добавляем чек продажи в базу
	query.prepare("INSERT INTO sale (sum, datetime, type) VALUE('0', ?, 'soldAc')");
	query.addBindValue(dt);
	query.exec();
	saleId = query.lastInsertId().toInt();

	//добавляем чек возврата в базу
	query.prepare("INSERT INTO sale (sum, datetime, type) VALUE('0', ?, 'return')");
	query.addBindValue(dt);
	query.exec();
	retuId = query.lastInsertId().toInt();

	position.prepare("SELECT ps.id_pos, ps.id_category, ps.quantity, ps.balance, ct.price "
					 "FROM position ps INNER JOIN category ct using(id_category)"
					 "WHERE ps.id_sale = ? "
					 "GROUP BY 1 "
	);
	position.addBindValue(ui->lineEdit->text());
	position.exec();

	int sumSell = 0;
	returnSum = 0;

	while (position.next())
	{
		int qnSell, qnRetu = 0;
		int balanceSell = 0;
		int sellSum = 0;
		int k = 10;

		id_position = position.value(0).toInt();
		id_category = position.value(1).toInt();
		posQuantity = position.value(2).toInt();
		posBalance  = position.value(3).toInt();
		catPrice    = position.value(4).toInt();

		qnSell = posQuantity;

		for (int i = 0; i < ui->tableWidget->rowCount(); ++i)
		{
			if (id_position == ui->tableWidget->item(i, 6)->text().toInt())
			{
				qnSell = QN_SOLD(i);
				qnRetu = QN_RETU(i);

				//увеливаем количество свободных мест
				query.prepare("UPDATE category SET free_seats = free_seats + ? WHERE id_category = ?");
				query.addBindValue(QN_RETU(i));
				query.addBindValue(id_category);
				query.exec();
				
				break;
			}
		}

		if (sumSell == 0)
			k = 0;

		if (qnSell >= 10)
			k += 10;

		QStringList list = ui->dtBox->currentText().split('T');
		list = list.at(0).split('-');

		balanceSell = qnSell * catPrice * (double)(100 - k) / 100;

		if (qnSell > 0)
		{
			//добавляем позицию покупки в базу
			query.prepare("INSERT INTO position (id_category, quantity, id_sale, balance) VALUES (?,?,?,?)");
			query.addBindValue(id_category);
			query.addBindValue(qnSell);
			query.addBindValue(saleId);
			query.addBindValue(balanceSell);
			query.exec();
		}

		sumSell += balanceSell;

		//удержание цены
		if (dt.date().daysTo(QDate(list.at(0).toInt(), list.at(1).toInt(), list.at(2).toInt())) < 2)
		{
			balanceSell += (posBalance - balanceSell) / 2;
		}

		returnSum += posBalance - balanceSell;

		if (qnRetu > 0)
		{
			//добавляем позицию возврата в базу
			query.prepare("INSERT INTO position (id_category, quantity, id_sale, balance) VALUES (?,?,?,?)");
			query.addBindValue(id_category);
			query.addBindValue(qnRetu);
			query.addBindValue(retuId);
			query.addBindValue(posBalance - balanceSell);
			query.exec();
		}

	}

	query.prepare("SELECT sum FROM sale WHERE id_sale = ?");
	query.addBindValue(ui->lineEdit->text());
	query.exec();
	query.next();
	int sum = query.value(0).toInt();

	//обновляем сумму "купленного"
	query.prepare("UPDATE sale SET sum = ? WHERE id_sale = ?");
	query.addBindValue(sumSell);
	query.addBindValue(saleId);
	query.exec();

	//обновляем сумму возврата
	query.prepare("UPDATE sale SET sum = ? WHERE id_sale = ?");
	query.addBindValue(returnSum);
	query.addBindValue(retuId);
	query.exec();

}


void DialogReturn::TotalClicked(void)
{
	QMessageBox::information(this, "RESULT", "RETURNED SUM: " +
							                 QString::number(returnSum) +
											 " BILL ID: " +
											 QString::number(saleId)
	);
}


DialogReturn::~DialogReturn()
{
	delete categoryQuery;
	delete ui;
}

