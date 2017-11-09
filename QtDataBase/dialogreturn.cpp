#include "dialogreturn.h"
#include "ui_dialogreturn.h"
#include <QMessageBox>
#include <QSqlError>
#include <QDateTime>

DialogReturn::DialogReturn(QSqlDatabase *db, QWidget *parent)
	: QDialog(parent), saleId(0), ui(new Ui::DialogReturn())
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
				  "FROM sale sl INNER JOIN position ps using(id_sale) INNER JOIN category ct using(id_category) "
				  "INNER JOIN staging st using(id_staging) INNER JOIN theater th using(id_theater) WHERE id_sale = ?"
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
				  "FROM sale sl INNER JOIN position ps using(id_sale) INNER JOIN category ct using(id_category)"
				  "INNER JOIN staging st using(id_staging) INNER JOIN theater th using(id_theater)" 
				  "INNER JOIN spectacle sp using(id_spec)"
				  "WHERE sl.id_sale = ? AND th.name_th = ?"
	);
	query.addBindValue(ui->lineEdit->text());
	query.addBindValue(th);
	query.exec();
	//QMessageBox::information(this, "", query.lastError().text());
	spectacle->setQuery(query);
	ui->spBox->setModel(spectacle);
	ui->spBox->setModelColumn(0);
}

void DialogReturn::SpectacleSelected(QString sp)
{
	QSqlQuery query;
	ui->dtBox->setEnabled(true);
	ui->ctBox->setEnabled(false);
	ui->qnBox->setEnabled(false);
	ui->returnButton->setEnabled(false);

	query.prepare("SELECT DISTINCT st.datetime "
				  "FROM sale sl INNER JOIN position ps using(id_sale) INNER JOIN category ct using(id_category)"
				  "INNER JOIN staging st using(id_staging) INNER JOIN theater th using(id_theater) INNER JOIN spectacle sp using(id_spec)"
				  "WHERE sl.id_sale = ? AND th.name_th = ? AND sp.name_spec = ?"
	);
	query.addBindValue(ui->lineEdit->text());
	query.addBindValue(ui->thBox->currentText());
	query.addBindValue(sp);
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

	categoryQuery->prepare("SELECT ct.name_cat, ps.quantity, ct.id_category "
						   "FROM sale sl INNER JOIN position ps using(id_sale) INNER JOIN category ct using(id_category)"
					       "INNER JOIN staging st using(id_staging) INNER JOIN theater th using(id_theater) INNER JOIN spectacle sp using(id_spec)"
						   "WHERE sl.id_sale = ? AND th.name_th = ? AND sp.name_spec = ? AND st.datetime = ?"
	);
	categoryQuery->addBindValue(ui->lineEdit->text());
	categoryQuery->addBindValue(ui->thBox->currentText());
	categoryQuery->addBindValue(ui->spBox->currentText());
	categoryQuery->addBindValue(dt);
	categoryQuery->exec();

	QMessageBox::information(this, "", categoryQuery->lastError().text());
	category->setQuery(*categoryQuery);
	ui->ctBox->setModel(category);
	ui->ctBox->setModelColumn(0);
}

void DialogReturn::CategorySelected(int ind)
{
	for (int i = 1; i < ind && categoryQuery->next(); ++i)
		;

	ui->qnBox->setMaximum(categoryQuery->value(1).toInt());
	ui->qnBox->setEnabled(true);
	ui->returnButton->setEnabled(true);
}

void DialogReturn::ReturnClicked(void)
{
	QSqlQuery query;
	ui->thBox->setEnabled(false);
	ui->spBox->setEnabled(false);
	ui->dtBox->setEnabled(false);
	ui->ctBox->setEnabled(false);
	ui->qnBox->setEnabled(false);
	ui->enterBillId->setEnabled(false);
	ui->returnButton->setEnabled(false);

	if (saleId == 0)
	{
		QDateTime dt = QDateTime::currentDateTime();

		//добавл€ем чек в базу
		query.prepare("INSERT INTO sale (sum, datetime) VALUE('0',?)");
		query.addBindValue(dt);
		query.exec();
		QMessageBox::information(this, "", query.lastError().text());

		//создаем таблицу
		ui->tableWidget->setColumnCount(7); // ”казываем число колонок
		ui->tableWidget->hideColumn(6);
		ui->tableWidget->setShowGrid(true); // ¬ключаем сетку
		ui->tableWidget->setHorizontalHeaderLabels(QStringList() << trUtf8("THEATER")
			<< trUtf8("SPECTACLE")
			<< trUtf8("DATE AND TIME")
			<< trUtf8("CATEGORY")
			<< trUtf8("QUANTITY")
			<< trUtf8("PRICE")
		);

		saleId = query.lastInsertId().toInt();
	}
}


DialogReturn::~DialogReturn()
{
	//delete saleIdQuery;
	delete categoryQuery;
	delete ui;
}

