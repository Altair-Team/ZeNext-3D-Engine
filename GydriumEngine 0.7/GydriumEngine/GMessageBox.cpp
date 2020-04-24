#include "GMessageBox.h"

GMessageBox::GMessageBox(QWidget *parent) : QWidget(parent)
{
	ui.setupUi(this);
	Qt::WindowStaysOnTopHint;
	connect(ui.OkPushButton, SIGNAL(clicked()), this, SLOT(QuitOnPushButtonCliked()));
}
GMessageBox::~GMessageBox()
{
}

void GMessageBox::Show(QString title, QString text, int icon)
{
	GMessageBox* box = new GMessageBox;
	box->setWindowTitle(title);
	box->ui.TextLabel->setText(text);
	switch (icon) {
	case 0:
		box->ui.ImageLabel->setPixmap(QPixmap("./Resources/ok.png"));
		box->setAttribute(Qt::WA_DeleteOnClose);
		box->show();
		break;
	case 1:
		box->ui.ImageLabel->setPixmap(QPixmap("./Resources/Error.png"));
		box->setAttribute(Qt::WA_DeleteOnClose);
		box->show();
		break;
	default:
		break;
	}
}

void GMessageBox::QuitOnPushButtonCliked()
{
	this->close();
}