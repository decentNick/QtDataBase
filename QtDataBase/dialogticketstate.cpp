#include "dialogticketstate.h"
#include "ui_dialogticketstate.h"
#include <QSqlQuery>
#include <QTreeWidget>
#include <QDateTime>
#include <QMessageBox>
#include <QSqlError>

DialogTicketState::DialogTicketState(QSqlDatabase *db, QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::DialogTicketState();
	ui->setupUi(this);
	model = new QSqlQueryModel(this);

	model->setQuery("SELECT name_th FROM theater", *db);

	ui->comboBox->setModel(model);
	ui->comboBox->setModelColumn(0);

	database = db;
}

void DialogTicketState::TheaterSelected(QString theat)
{
	QSqlQuery stage(*database);
	QSqlQuery datetime(*database);
	QSqlQuery category(*database);
	QSqlQuery query(*database);


	QDateTime dateTime = QDateTime::currentDateTime();
	QStringList headerLabels;
	headerLabels.push_back(tr("SPECTACLE"));
	headerLabels.push_back(tr("DATE & TIME"));
	headerLabels.push_back(tr("CATEGORY"));
	headerLabels.push_back(tr("BUY"));
	headerLabels.push_back(tr("RETURN"));

	ui->treeWidget->clear();
	ui->treeWidget->setColumnCount(headerLabels.size());
	ui->treeWidget->setHeaderLabels(headerLabels);
	ui->treeWidget->header()->resizeSection(1, 150);

	stage.prepare("SELECT DISTINCT sp.name_spec "
				  "FROM theater th INNER JOIN staging st using(id_theater)"
				  "INNER JOIN spectacle sp using(id_spec)"
				  "WHERE th.name_th = ? AND st.datetime > ?"
				  "ORDER BY 1"
	);
	stage.addBindValue(theat);
	stage.addBindValue(dateTime);
	stage.exec();

	while (stage.next())
	{
		QTreeWidgetItem *st = new QTreeWidgetItem;
		QString spect = stage.value(0).toString();
		ui->treeWidget->addTopLevelItem(st);
		st->setText(0, spect);
		
		datetime.prepare("SELECT st.datetime, st.id_staging "
						 "FROM theater th INNER JOIN staging st using(id_theater)"
						 "INNER JOIN spectacle sp using(id_spec)"
						 "WHERE th.name_th = ? AND sp.name_spec = ? AND st.datetime > ?"
						 "ORDER BY 1"
		);
		datetime.addBindValue(theat);
		datetime.addBindValue(spect);
		datetime.addBindValue(dateTime);
		datetime.exec();
		
		while (datetime.next())
		{
			QTreeWidgetItem *dt = new QTreeWidgetItem;
			st->addChild(dt);
			dt->setText(1, datetime.value(0).toString());

			category.prepare("SELECT name_cat, id_category "
							 "FROM category "
							 "WHERE id_staging = ? "
							 "ORDER BY 1"
			);
			category.addBindValue(datetime.value(1).toInt());
			category.exec();

			while (category.next())
			{
				QTreeWidgetItem *ct = new QTreeWidgetItem(dt);
				int buyQuantity = 0, returnQuantity = 0;

				//количество купленных
				query.prepare("SELECT SUM(ps.quantity) "
							  "FROM position ps INNER JOIN sale using(id_sale)"
							  "WHERE ps.id_category = ? AND "
							  "(sale.type = 'soldEn' OR sale.type = 'soldAc')"
				);
				query.addBindValue(category.value(1));
				query.exec();
				query.next();

				buyQuantity = query.value(0).toInt();

				query.prepare("SELECT SUM(ps.quantity) "
							  "FROM position ps INNER JOIN sale using(id_sale)"
							  "WHERE ps.id_category = ? AND sale.type = 'return'"
				);
				query.addBindValue(category.value(1));
				query.exec();
				query.next();

				returnQuantity = query.value(0).toInt();


				ct->setText(2, category.value(0).toString());
				ct->setText(3, QString::number(buyQuantity));
				ct->setText(4, QString::number(returnQuantity));
			}
		}
	}
}

DialogTicketState::~DialogTicketState()
{
	delete ui;
}

