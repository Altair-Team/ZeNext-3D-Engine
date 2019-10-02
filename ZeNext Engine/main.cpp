#include "ZeNextEngine.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
	//Присоединение
	QApplication a(argc, argv);
	ZeNextEngine MainW;
	chooseworld Diow;
	CodeEditor Codeedit;
	settings seti;
	info inf;

	//Работа
	MainW.show();
	Diow.show();

	//inf.show();
	//Codeedit.show();
	//seti.show();
	return a.exec();
}
