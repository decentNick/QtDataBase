#ifndef DIALOGFINANCIAL_H
#define DIALOGFINANCIAL_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {class DialogFinancial;};

class DialogFinancial : public QDialog
{
	Q_OBJECT

private slots:
	void LineChanged(QString);
	void YearInserted(void);

public:
	DialogFinancial(QSqlDatabase *db, QWidget *parent = 0);
	~DialogFinancial();

private:
	Ui::DialogFinancial *ui;

};

#endif // DIALOGFINANCIAL_H
