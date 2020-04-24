#include "CodeEditor.h"

CodeEditor::CodeEditor(QString pathToFile, QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowIcon(QIcon("./res/Editors.png"));
	ui.OpenFileQAction->setIcon(QIcon("./res/open.png"));
	ui.SaveFileQAction->setIcon(QIcon("./res/save.png"));
	ui.SaveAsQAction->setIcon(QIcon("./res/save.png"));
	ui.QuitQAction->setIcon(QIcon("./res/exit.png"));
	ui.OpenInVisualStudioQAction->setIcon(QIcon("./res/Visual_Studio.png"));
	connect(ui.OpenFileQAction, &QAction::triggered, this, &CodeEditor::OpenFileOnQActionCliked);
	connect(ui.SaveFileQAction, &QAction::triggered, this, &CodeEditor::SaveFileOnQActionCliked);
	connect(ui.SaveAsQAction, &QAction::triggered, this, &CodeEditor::SaveAsFileOnQActionCliked);
	connect(ui.TextPlaceQTextEdit, SIGNAL(textChanged()), this, SLOT(ChangeContentOnChangingText()));
	if (pathToFile != nullptr) {
		QFileInfo onlyFileName(pathToFile);
		this->setWindowTitle("Gydrium code editor " + onlyFileName.fileName());
		ui.TextPlaceQTextEdit->setText(File::getFileContens(pathToFile));
		ui.lab_WhatIsGoinOn->setText(pathToFile);
		pathToFile_ = pathToFile;
		fileName_ = onlyFileName.fileName();
	}
}

void CodeEditor::OpenFileOnQActionCliked()
{
	this->setWindowTitle("");
	QFileDialog dialog(this);
	dialog.setFileMode(QFileDialog::AnyFile);
	QString pathToFile = dialog.getOpenFileName(this, tr("Select a file"));
	QFileInfo onlyFileName(pathToFile);
	ui.TextPlaceQTextEdit->setText(File::getFileContens(pathToFile));
	ui.lab_WhatIsGoinOn->setText(pathToFile);
	this->setWindowTitle("Gydrium code editor " + onlyFileName.fileName());
	fileName_ = onlyFileName.fileName();
	pathToFile_ = pathToFile;
}

void CodeEditor::ChangeContentOnChangingText()
{
	this->setWindowTitle("Gydrium code editor " + fileName_ + "*");
}


void CodeEditor::SaveFileOnQActionCliked()
{
	this->setWindowTitle("Gydrium code editor " + fileName_ );
	File::saveFile(pathToFile_, ui.TextPlaceQTextEdit->toPlainText());
}

void CodeEditor::SaveAsFileOnQActionCliked()
{
	QString pathToFile = QFileDialog::getSaveFileName(this, tr("Select a file name"));
	File::saveFile(pathToFile, ui.TextPlaceQTextEdit->toPlainText());
}

CodeEditor::~CodeEditor()
{
}