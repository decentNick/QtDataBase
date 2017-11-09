#include "qtdatabase.h"
#include <QSqlError>
#include <QMessageBox>
#include "queryrep.h"
#include "dialogbuy.h"
#include "dialogreturn.h"

QtDataBase::QtDataBase(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::QtDataBaseClass),
	repertoireModel(new QSqlQueryModel)
{
	ui->setupUi(this);

	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setDatabaseName("box_office");
	db.setUserName("root");
	db.setPassword("hKPQ6NXQ");

	if (!db.open())
		QMessageBox::information(this, "ERROR",db.lastError().text());
}

void QtDataBase::queryRepertoire(void)
{
	QString strQuery = "SELECT th.name_th, sp.name_spec, st.datetime ";
	strQuery += "FROM theater th INNER JOIN staging st using(id_theater) INNER JOIN spectacle sp using(id_spec)";
	repertoireModel->setQuery(strQuery, db);
	repertoireModel->setHeaderData(0, Qt::Horizontal, "THEATER");
	repertoireModel->setHeaderData(1, Qt::Horizontal, "SPECTACLE");
	repertoireModel->setHeaderData(2, Qt::Horizontal, "DATE AND TIME");
	ui->tableView->setModel(repertoireModel);
}

void QtDataBase::searchStages(void) 
{
	queryRep *dialog = new queryRep(&db);
	dialog->exec();
	delete dialog;
}

void QtDataBase::BuyClicked(void)
{
	DialogBuy *dialog = new DialogBuy(&db);
	dialog->exec();
	delete dialog;
}

void QtDataBase::ReturnClicked(void)
{
	DialogReturn *dialog = new DialogReturn(&db);
	dialog->exec();
	delete dialog;
}

QtDataBase::~QtDataBase()
{
	db.close();
	delete repertoireModel;
	delete ui;
}
