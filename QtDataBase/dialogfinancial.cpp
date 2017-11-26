#include "dialogfinancial.h"
#include "ui_dialogfinancial.h"
#include <QRegularExpression>
#include <QDateTime>
#include <QMessageBox>
#include <QSqlError>
#include <cstdio>
#define LINESIZE 80
#define MONTHSTR "%s %20d %20d %20d"
#define SECTSTR "                     %20d %20d %20d"
#define TOTALSTR "TOTAL:         %20d %20d %20d"


DialogFinancial::DialogFinancial(QSqlDatabase *db, QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::DialogFinancial();
	ui->setupUi(this);
	QRegExp reg("[1-2]{1}[0-9]{1,3}");
	ui->lineEdit->setValidator(new QRegExpValidator(reg, this));
	ui->buttonCreate->setEnabled(false);
	connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(LineChanged(QString)));
}

void DialogFinancial::LineChanged(QString str)
{
	ui->buttonCreate->setEnabled(str.size() == 4);
}

void DialogFinancial::YearInserted(void)
{
	QSqlQuery theater;
	theater.exec("SELECT name_th, id_theater "
			     "FROM theater"
	);

	char *months[] = {
		"     JANUARY",
		"   FEBRUARY",
		"        MARCH",
		"           APRIL",
		"             MAY",
		"            JUNE",
		"            JULY",
		"       AUGUST",
		" SEPTEMBER",
		"    OCTOBER",
		"  NOVEMBER",
		"  DECEMBER"
	};

	ui->textEdit->clear();

	
	ui->textEdit->append(QString(LINESIZE, '-'));
	ui->textEdit->append(QString(LINESIZE / 3, ' ') + "FINANCIAL REPRORT FOR " + ui->lineEdit->text());
	ui->textEdit->append(QString(LINESIZE, '-'));
	while (theater.next())
	{
		int indMonth = 1;
		int totalSell = 0, totalRetu = 0;
		int sectSell = 0, sectRetu = 0;

		ui->textEdit->append("");
		ui->textEdit->append("");
		ui->textEdit->append(QString(LINESIZE, '-'));
		ui->textEdit->append(theater.value(0).toString());
		ui->textEdit->append(QString(LINESIZE, '-'));
		for (indMonth = 1; indMonth <= 12; ++indMonth)
		{
			QSqlQuery query;
			int sellSum = 0;
			int retuSum = 0;

			if (indMonth % 3 == 1)
			{
				ui->textEdit->append(QString().sprintf("%d section", indMonth / 3 + 1));
				ui->textEdit->append(QString(LINESIZE, '-'));
			}

			query.prepare("SELECT sl.id_sale, sl.sum "
						  "FROM staging st INNER JOIN category using(id_staging)"
						  "INNER JOIN position using(id_category)"
						  "INNER JOIN sale sl using(id_sale)"
						  "WHERE st.id_theater = ? " 
						  "AND YEAR(sl.datetime) = ? "
						  "AND MONTH(sl.datetime) = ? "
						  "AND (type = 'soldEn' OR type = 'soldNotEn')"
			);
			query.addBindValue(theater.value(1).toInt());
			query.addBindValue(ui->lineEdit->text().toInt());
			query.addBindValue(indMonth);
			query.exec();
			for (int i = 0; query.next(); i = query.value(0).toInt())
			{
				if (i != query.value(0).toInt())
					sellSum += query.value(1).toInt();
			}
			

			query.prepare("SELECT sl.id_sale, sl.sum "
						  "FROM staging st INNER JOIN category using(id_staging)"
						  "INNER JOIN position using(id_category)"
						  "INNER JOIN sale sl using(id_sale)"
						  "WHERE st.id_theater = ? "
						  "AND YEAR(sl.datetime) = ? "
						  "AND MONTH(sl.datetime) = ? "
						  "AND type = 'return'"
			);
			query.addBindValue(theater.value(1).toInt());
			query.addBindValue(ui->lineEdit->text().toInt());
			query.addBindValue(indMonth);
			query.exec();

			for (int i = 0; query.next(); i = query.value(0).toInt())
			{
				if (i != query.value(0).toInt())
					retuSum += query.value(1).toInt();
			}

			ui->textEdit->append(QString().sprintf(MONTHSTR, months[indMonth - 1],
				sellSum, retuSum, sellSum - retuSum));
			sectSell += sellSum;
			sectRetu += retuSum;

			if (indMonth % 3 == 0 && indMonth != 0)
			{
				ui->textEdit->append(QString(LINESIZE, '-'));
				ui->textEdit->append(QString().sprintf(SECTSTR, sectSell, sectRetu, sectSell - sectRetu));
				totalSell += sectSell;
				totalRetu += sectRetu;
				sectSell = 0;
				sectRetu = 0;
			}
		}

		ui->textEdit->append(QString(LINESIZE, '-'));
		ui->textEdit->append(QString().sprintf(TOTALSTR, totalSell, totalRetu, totalSell - totalRetu));
	}
}

DialogFinancial::~DialogFinancial()
{
	delete ui;
}

