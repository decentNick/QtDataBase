#ifndef DIALOGSUCCESS_H
#define DIALOGSUCCESS_H

#include <QDialog>
#include <QSqlDatabase>
namespace Ui {class DialogSuccess;};

class DialogSuccess : public QDialog
{
	Q_OBJECT

private slots:
	void EnterClicked(void);

public:
	DialogSuccess(QSqlDatabase *db, QWidget *parent = 0);
	~DialogSuccess();

private:
	Ui::DialogSuccess *ui;
	QSqlDatabase *database;
};

#endif // DIALOGSUCCESS_H
