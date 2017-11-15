#include "dialogreturn.h"
#include "ui_dialogreturn.h"
#include <QMessageBox>
#include <QSqlError>
#include <QDateTime>

DialogReturn::DialogReturn(QSqlDatabase *db, QWidget *parent)
	: QDialog(parent), saleId(0), ui(new Ui::DialogReturn()),
	returnSum(0)
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
	ui->returnButton->setEnabled(false);

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
	ui->returnButton->setEnabled(false);

	query.prepare("SELECT DISTINCT th.name_th "
				  "FROM sale sl INNER JOIN position ps using(id_sale)"
				  "INNER JOIN category ct using(id_category)"
				  "INNER JOIN staging st using(id_staging)"
				  "INNER JOIN theater th using(id_theater)"
				  "WHERE id_sale = ?"
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
	ui->returnButton->setEnabled(false);

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
	ui->returnButton->setEnabled(false);

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
	ui->returnButton->setEnabled(false);

	categoryQuery->prepare("SELECT ct.name_cat, ps.id_pos, ct.id_category "
						   "FROM sale sl INNER JOIN position ps using(id_sale)"
						   "INNER JOIN category ct using(id_category)"
					       "INNER JOIN staging st using(id_staging)"
						   "INNER JOIN theater th using(id_theater)"
						   "INNER JOIN spectacle sp using(id_spec)"
						   "WHERE sl.id_sale = ? AND th.name_th = ? "
						   "AND sp.name_spec = ? AND st.datetime = ?"
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
	info.prepare("SELECT ps.quantity, ct.price "
				 "FROM position ps INNER JOIN category ct using(id_category)"
				 "WHERE ps.id_pos = ?"
	);
	info.addBindValue(id_position);
	info.exec();
	info.next();

	posQuantity = info.value(0).toInt();
	catPrice = info.value(1).toInt();

	ui->qnBox->setMaximum(posQuantity);
	ui->qnBox->setEnabled(true);
	ui->returnButton->setEnabled(true);
}

void DialogReturn::ReturnClicked(void)
{
	QSqlQuery query;
	QDateTime dt = QDateTime::currentDateTime();

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
	ui->returnButton->setEnabled(false);

	if(saleId == 0)
	{
		//добавляем чек в базу
		query.prepare("INSERT INTO sale (sum, datetime, type) VALUE('0', ?, 'return')");
		query.addBindValue(dt);
		query.exec();

		//создаем таблицу
		ui->tableWidget->setColumnCount(6); // Указываем число колонок
		ui->tableWidget->setShowGrid(true); // Включаем сетку
		ui->tableWidget->setHorizontalHeaderLabels(QStringList() 
			<< trUtf8("THEATER")
			<< trUtf8("SPECTACLE")
			<< trUtf8("DATE AND TIME")
			<< trUtf8("CATEGORY")
			<< trUtf8("QUANTITY")
			<< trUtf8("BALANCE")
		);

		saleId = query.lastInsertId().toInt();
	}

	int balance = posQuantity * catPrice;
	if (posQuantity >= 10)
		balance = balance * 9 / 10;
	int sum  = balance;

	//скидка за опт
	if (posQuantity - ui->qnBox->value() >= 10)
	{
		sum -= (posQuantity - ui->qnBox->value()) * catPrice * 9 / 10;
	}
	else
	{
		sum -= (posQuantity - ui->qnBox->value()) * catPrice;
	}

	QStringList list = ui->dtBox->currentText().split('T');
	list = list.at(0).split('-');
	//удержание цены
	if (dt.date().daysTo(QDate(list.at(0).toInt(), list.at(1).toInt(),list.at(2).toInt())) < 2)
	{
		sum /= 2;
	}

	returnSum += sum;

	//увеличиваем количество свободных мест
	query.prepare("UPDATE category SET free_seats = free_seats + ? WHERE id_category = ?");
	query.addBindValue(ui->qnBox->value());
	query.addBindValue(id_category);
	query.exec();

	//уменьшаем количество купленного
	query.prepare("UPDATE position SET quantity = quantity - ? WHERE id_pos = ?");
	query.addBindValue(ui->qnBox->value());
	query.addBindValue(id_position);
	query.exec();
	
	//прибавляем сумму в чеке
	query.prepare("UPDATE sale SET sum = sum + ? WHERE id_sale = ?");
	query.addBindValue(sum);
	query.addBindValue(saleId);
	query.exec();

	//добавляем позицию в базу
	query.prepare("INSERT INTO position (id_category, quantity, id_sale) VALUES (?,?,?)");
	query.addBindValue(categoryQuery->value(2).toInt());
	query.addBindValue(ui->qnBox->value());
	query.addBindValue(saleId);
	query.exec();

	//добавляем строку в таблицу счета
	int i = ui->tableWidget->rowCount();
	ui->tableWidget->insertRow(i);
	ui->tableWidget->setItem(i, 0, new QTableWidgetItem(ui->thBox->currentText()));
	ui->tableWidget->setItem(i, 1, new QTableWidgetItem(ui->spBox->currentText()));
	ui->tableWidget->setItem(i, 2, new QTableWidgetItem(ui->dtBox->currentText()));
	ui->tableWidget->setItem(i, 3, new QTableWidgetItem(ui->ctBox->currentText()));
	ui->tableWidget->setItem(i, 4, new QTableWidgetItem(ui->qnBox->text()));
	ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(catPrice * ui->qnBox->value())));

}

void DialogReturn::ShowSum(void)
{
	QMessageBox::information(this, "RESULT", "RETURN SUM: " + QString::number(returnSum));
}


DialogReturn::~DialogReturn()
{
	delete categoryQuery;
	delete ui;
}

