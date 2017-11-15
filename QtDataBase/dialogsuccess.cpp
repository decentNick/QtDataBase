#include "dialogsuccess.h"
#include "ui_dialogsuccess.h"

DialogSuccess::DialogSuccess(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::DialogSuccess();
	ui->setupUi(this);
}

DialogSuccess::~DialogSuccess()
{
	delete ui;
}

