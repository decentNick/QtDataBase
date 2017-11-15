#ifndef DIALOGEMPTYSALES_H
#define DIALOGEMPTYSALES_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {class DialogEmptySales;};

class DialogEmptySales : public QDialog
{
	Q_OBJECT

private slots:
	void RefreshClicked(void);

public:
	DialogEmptySales(QSqlDatabase *db, QWidget *parent = 0);
	~DialogEmptySales();

private:
	Ui::DialogEmptySales *ui;
};

#endif // DIALOGEMPTYSALES_H
