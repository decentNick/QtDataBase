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
	int indMonth = 1;
	int totalSell = 0, totalRetu = 0;
	int sectSell = 0, sectRetu = 0;

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

		query.prepare("SELECT SUM(sum)"
					  "FROM sale "
					  "WHERE YEAR(datetime) = ? "
					  "AND MONTH(datetime) = ? "
					  "AND type = 'sell'"
		);
		query.addBindValue(ui->lineEdit->text().toInt());
		query.addBindValue(indMonth);
		query.exec();
		query.next();

		sellSum = query.value(0).toInt();

		query.prepare("SELECT SUM(sum)"
					  "FROM sale "
					  "WHERE YEAR(datetime) = ? "
					  "AND MONTH(datetime) = ? "
					  "AND type = 'return'"
		);
		query.addBindValue(ui->lineEdit->text().toInt());
		query.addBindValue(indMonth);
		query.exec();
		query.next();

		retuSum = query.value(0).toInt();

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

DialogFinancial::~DialogFinancial()
{
	delete ui;
}

