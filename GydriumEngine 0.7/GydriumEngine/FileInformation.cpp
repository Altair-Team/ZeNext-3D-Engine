#include "FileInformation.h"

FileInformation::FileInformation(QString pathToFile, QString fileName, QWidget *parent) : QWidget(parent)
{
	pathToFile_ = pathToFile;
	fileName_ = fileName;

	ui.setupUi(this);
	ui.FileNameLabel->setText(fileName_);
	QFileInfo file = pathToFile_ + "\\" + fileName_;
	if (File::ñheckFileOrFolder(fileName_) == false) {
		ui.ImageLabel->setPixmap(QPixmap("./res/filetitle.png"));
		ui.FileTypeLabel->setText(File::getFileextension(fileName_));
		ui.FileSizeLabel->setText(QString::number(file.size() / 1024));
	} else if (File::ñheckFileOrFolder(fileName_) == true) {
		ui.ImageLabel->setPixmap(QPixmap("./res/file.ico"));
		ui.FileTypeLabel->setText("Folder");
		ui.FileSizeLabel->setText(QString::number(Dir::getFolderSize(pathToFile_ + "\\" + fileName_) / 1024));
	}

	connect(ui.SelectFileSize, SIGNAL(currentTextChanged(QString)), this, SLOT(SelectSizeOnComboBoxCurrentTextChanged()));
}
FileInformation::~FileInformation()
{
}

void FileInformation::SelectSizeOnComboBoxCurrentTextChanged()
{
	QFileInfo file = pathToFile_ + "\\" + fileName_;
	if (File::ñheckFileOrFolder(fileName_) == false) {
		if (ui.SelectFileSize->currentText() == "MBs") {
			ui.FileSizeLabel->setText(QString::number(file.size() / 1024 / 1024));
		} else if (ui.SelectFileSize->currentText() == "GBs") {
			ui.FileSizeLabel->setText(QString::number(file.size() / 1024 / 1024 / 1024));
		} else {
			ui.FileSizeLabel->setText(QString::number(file.size() / 1024));
		}
	}

	if (File::ñheckFileOrFolder(fileName_) == true) {
		if (ui.SelectFileSize->currentText() == "MBs") {
			ui.FileSizeLabel->setText(QString::number(Dir::getFolderSize(pathToFile_ + "\\" + fileName_) / 1024 / 1024));
		} else if (ui.SelectFileSize->currentText() == "GBs") {
			ui.FileSizeLabel->setText(QString::number(Dir::getFolderSize(pathToFile_ + "\\" + fileName_) / 1024 / 1024 / 1024));
		} else {
			ui.FileSizeLabel->setText(QString::number(Dir::getFolderSize(pathToFile_ + "\\" + fileName_) / 1024));
		}
	}
}