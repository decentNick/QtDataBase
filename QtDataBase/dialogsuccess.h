#ifndef DIALOGSUCCESS_H
#define DIALOGSUCCESS_H

#include <QDialog>
namespace Ui {class DialogSuccess;};

class DialogSuccess : public QDialog
{
	Q_OBJECT

public:
	DialogSuccess(QWidget *parent = 0);
	~DialogSuccess();

private:
	Ui::DialogSuccess *ui;
};

#endif // DIALOGSUCCESS_H
