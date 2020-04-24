#include "DeveloperInformation.h"

DeveloperInformation::DeveloperInformation(QWidget *parent) : QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowIcon(QIcon("./res/icon.ico"));
}
DeveloperInformation::~DeveloperInformation()
{
}