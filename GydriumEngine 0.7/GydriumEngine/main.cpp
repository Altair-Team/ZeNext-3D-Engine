#include "ProjectTemplate.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ProjectTemplate w;
	w.show();
	return a.exec();
}
