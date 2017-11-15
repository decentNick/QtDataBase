#ifndef DIALOGTICKETSTATE_H
#define DIALOGTICKETSTATE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQueryModel>

namespace Ui {class DialogTicketState;};

class DialogTicketState : public QDialog
{
	Q_OBJECT

public:
	DialogTicketState(QSqlDatabase *db, QWidget *parent = 0);
	~DialogTicketState();

private slots:
	void TheaterSelected(QString);

private:
	Ui::DialogTicketState *ui;
	QSqlDatabase *database;
	QSqlQueryModel *model;
};

#endif // DIALOGTICKETSTATE_H
