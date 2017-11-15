#include "queryrep.h"
#include <QMessageBox>
#include <QSqlError>
#include <QRegularExpression>


queryRep::queryRep(QSqlDatabase *db, QWidget *parent)
	: QDialog(parent), uii(new Ui::queryRep), model(new QSqlQueryModel)
{
	uii->setupUi(this);

	QRegExp reg("[a-zA-Z0-9]{1,19}");
	uii->lineEdit->setValidator(new QRegExpValidator(reg, this));

	uii->buttonSearch->setDefault(true);
	uii->buttonSearch->setEnabled(false);

	connect(uii->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(TextChanged(QString)));

	database = db;
}

void queryRep::TextChanged(QString str)
{
	uii->buttonSearch->setEnabled(!str.isEmpty());
}

void queryRep::SearchClicked(void)
{
	QString strQuery = "SELECT th.name_th, st.datetime " 
					   "FROM theater th INNER JOIN staging st using(id_theater)"
					   "INNER JOIN spectacle sp using(id_spec) ";
					 + "WHERE sp.name_spec = '" + uii->lineEdit->text() + "'";

	model->setQuery(strQuery, *database);
	model->setHeaderData(0, Qt::Horizontal, "THEATER");
	model->setHeaderData(1, Qt::Horizontal, "DATE AND TIME");
	uii->tableView->setModel(model);
}

queryRep::~queryRep()
{
	delete model;
	delete uii;
}
