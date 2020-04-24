#include "ProjectTemplate.h"

ProjectTemplate::ProjectTemplate(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowIcon(QIcon("./res/icon.ico"));
	ui.ProjectNameQLineEdit->setText("Name");
	ui.PathToProjectQLineEdit->setText("D:\\test");
	connect(ui.ProjectDirectorySelectionPushButton, SIGNAL(clicked()), this, SLOT(getPathToProjectOnPushButtonCliked()));
	connect(ui.ApplyPushButton, SIGNAL(clicked()), this, SLOT(CreateNewProjectOnPushButtonCliked()));
}

ProjectTemplate::~ProjectTemplate()
{
}

void ProjectTemplate::getPathToProjectOnPushButtonCliked()
{
	ui.PathToProjectQLineEdit->setText(dir.getPathToProject());
}

void ProjectTemplate::CreateNewProjectOnPushButtonCliked()
{
	if (ui.ProjectNameQLineEdit->text() == nullptr || ui.PathToProjectQLineEdit->text() == nullptr) { GMessageBox::Show("Attention!", "Try to install!", 1); return; }
	dir.createNewProject(ui.PathToProjectQLineEdit->text(), ui.ProjectNameQLineEdit->text());
	GydriumEngine* engine = new GydriumEngine(ui.PathToProjectQLineEdit->text() + "\\" + ui.ProjectNameQLineEdit->text());
	engine->setAttribute(Qt::WA_DeleteOnClose);
	engine->show();
	this->close();
}