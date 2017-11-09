#include "qtdatabase.h"
#include <stdio.h>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtDataBase w;
	w.show();
	return a.exec();
}
