#include "Settings.h"

Settngs::Settngs(QWidget *parent) : QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowIcon(QIcon("./res/Settings.png"));
	ui.horizontalSlider_3->setMinimum(1024);
	ui.horizontalSlider_3->setMaximum((PcInfo::getRamSize() + 1) * 1024);
}

Settngs::~Settngs()
{
}