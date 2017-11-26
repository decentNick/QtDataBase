#include "dialogbuy.h"
#include <QMessageBox>
#include <QSqlError>

DialogBuy::DialogBuy(QSqlDatabase *db, QWidget *parent)
	: QDialog(parent), ui(new Ui::DialogBuy)
{
	ui->setupUi(this);
	database = db;

	theater = new QSqlTableModel(this, *db);
	spectacle = new QSqlQueryModel(this);
	datetime = new QSqlQueryModel(this);
	prices = new QSqlQueryModel(this);
	category = new QSqlQuery(*db);

	theater->setTable("theater");
	theater->select();

	ui->theaterBox->setModel(theater);
	ui->theaterBox->setModelColumn(1);

	ui->GetBillButton->setEnabled(false);
	ui->BuyButton->setEnabled(false);
	ui->spectacleBox->setEnabled(false);
	ui->datetimeBox->setEnabled(false);
	ui->quantityBox->setEnabled(false);
	ui->priceBox->setEnabled(false);

	id_category = 0;
	saleId = 0;
	ui->quantityBox->setMinimum(1);

}

void DialogBuy::TheaterSelected(QString th)
{
	QString query = "SELECT DISTINCT sp.name_spec "
					"FROM theater th INNER JOIN staging st using(id_theater)"
					"INNER JOIN spectacle sp using(id_spec)" 
					"WHERE th.name_th = '" + th + "'";

	spectacle->setQuery(query, *database);
	id_theater = ui->theaterBox->currentIndex() + 1; // если нет пропусков в списке театров

	ui->BuyButton->setEnabled(false);
	ui->spectacleBox->setEnabled(true);
	ui->datetimeBox->setEnabled(false);
	ui->quantityBox->setEnabled(false);
	ui->priceBox->setEnabled(false);

	ui->spectacleBox->setModel(spectacle);
	ui->spectacleBox->setModelColumn(0);
}

void DialogBuy::SpectacleSelected(QString spec)
{
	QSqlQuery query(*database);
	QDateTime dt = QDateTime::currentDateTime();

	ui->BuyButton->setEnabled(false);
	ui->datetimeBox->setEnabled(true);
	ui->quantityBox->setEnabled(false);
	ui->priceBox->setEnabled(false);

	query.prepare("SELECT st.id_staging, st.datetime FROM staging st "
				  "INNER JOIN spectacle sp using(id_spec) "
				  "WHERE st.id_theater = ? AND sp.name_spec = ? AND st.datetime > ?");
	query.addBindValue(id_theater);
	query.addBindValue(spec);
	query.addBindValue(dt);
	query.exec();

	datetime->setQuery(query);
	ui->datetimeBox->setModel(datetime);
	ui->datetimeBox->setModelColumn(1);
}

void DialogBuy::DatetimeSelected(QString dt)
{
	category->prepare("SELECT ct.id_category, ct.name_cat "
					  "FROM theater th INNER JOIN staging st using(id_theater) INNER JOIN spectacle sp " 
					  "using(id_spec) INNER JOIN category ct using(id_staging) " 
					  "WHERE th.name_th = ? AND sp.name_spec = ? AND st.datetime = ? ");
	category->addBindValue(ui->theaterBox->currentText());
	category->addBindValue(ui->spectacleBox->currentText());
	category->addBindValue(ui->datetimeBox->currentText());
	category->exec();

	prices->setQuery(*category);
	ui->priceBox->setModel(prices);
	ui->priceBox->setModelColumn(1);

	ui->priceBox->setEnabled(true);
	ui->BuyButton->setEnabled(false);
	ui->quantityBox->setEnabled(false);
}


void DialogBuy::PriceSelected(int ind)
{
	
	for (int i = 1; i < ind && category->next(); ++i)
		;

	id_category = category->value(0).toInt();

	QSqlQuery query;
	query.prepare("SELECT ct.price, ct.free_seats "
				  "FROM category ct "
				  "WHERE ct.id_category = ? "
	);
	query.addBindValue(id_category);
	query.exec();

	query.next();
	catPrice = query.value(0).toInt();
	freeSeats = query.value(1).toInt();
	ui->quantityBox->setMaximum(freeSeats);

	ui->BuyButton->setEnabled(true);
	ui->quantityBox->setEnabled(true);
}

void DialogBuy::BuyClicked(void)
{
	QSqlQuery query;
	QDateTime dt = QDateTime::currentDateTime();
	int k = 10;//коэффициент скидки(10%)

	if (ui->quantityBox->value() == 0)
	{
		QMessageBox::information(this, "INFO", "TICKET QUANTITY = 0");
		return;
	}

	ui->spectacleBox->setEnabled(false);
	ui->datetimeBox->setEnabled(false);
	ui->quantityBox->setEnabled(false);
	ui->priceBox->setEnabled(false);
	ui->BuyButton->setEnabled(false);

	if (saleId == 0)
	{
		k = 0;

		//добавл€ем чек в базу
		query.prepare("INSERT INTO sale (sum, datetime, type) VALUE('0',?, 'soldEn')");
		query.addBindValue(dt);
		query.exec();

		//создаем таблицу
		ui->tableWidget->setColumnCount(6); // ”казываем число колонок
		ui->tableWidget->setShowGrid(true); // ¬ключаем сетку
		ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "THEATER"
																 << "SPECTACLE"
																 << "DATE AND TIME"
																 << "CATEGORY"
																 << "QUANTITY"
																 << "BALANCE"
		);

		saleId = query.lastInsertId().toInt();
	}

	//уменьшаем количество свободных мест
	query.prepare("UPDATE category SET free_seats = free_seats - ? WHERE id_category = ?");
	query.addBindValue(ui->quantityBox->value());
	query.addBindValue(id_category);
	query.exec();

	if (ui->quantityBox->value() >= 10) //скидка за количество
		k += 10;

	//добавл€ем позицию в базу
	query.prepare("INSERT INTO position (id_category, quantity, id_sale, balance) VALUES (?,?,?,?)");
	query.addBindValue(id_category);
	query.addBindValue(ui->quantityBox->value());
	query.addBindValue(saleId);
	query.addBindValue(ui->quantityBox->value() * catPrice * (100 - k) / 100);
	query.exec();

	//прибавл€ем сумму в чеке
	query.prepare("UPDATE sale SET sum = sum + ? WHERE id_sale = ?");
	query.addBindValue(ui->quantityBox->value() * catPrice * (100 - k) / 100);
	query.addBindValue(saleId);
	query.exec();

	//добавл€ем строку в таблицу счета
	int i = ui->tableWidget->rowCount();
	ui->tableWidget->insertRow(i);
	ui->tableWidget->setItem(i, 0, new QTableWidgetItem(ui->theaterBox->currentText()));
	ui->tableWidget->setItem(i, 1, new QTableWidgetItem(ui->spectacleBox->currentText()));
	ui->tableWidget->setItem(i, 2, new QTableWidgetItem(ui->datetimeBox->currentText()));
	ui->tableWidget->setItem(i, 3, new QTableWidgetItem(category->value(1).toString()));
	ui->tableWidget->setItem(i, 4, new QTableWidgetItem(ui->quantityBox->text()));
	ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(ui->quantityBox->value() * catPrice * (100 - k) / 100)));

	ui->GetBillButton->setEnabled(true);
}

void DialogBuy::GetBillClicked(void)
{
	ui->BuyButton->setEnabled(false);
	ui->GetBillButton->setEnabled(false);

	QMessageBox::information(this, "BILL","sale_Id: " + QString::number(saleId));
}


DialogBuy::~DialogBuy()
{
	delete category;
	delete ui;
}
