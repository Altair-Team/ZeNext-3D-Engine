#include "ZeNextEngine.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
	//�������������
	QApplication a(argc, argv);
	ZeNextEngine MainW;
	chooseworld Diow;
	CodeEditor Codeedit;
	settings seti;
	info inf;

	//������
	MainW.show();
	Diow.show();

	//inf.show();
	//Codeedit.show();
	//seti.show();
	return a.exec();
}
