#include "File.h"

File::File(QWidget *parent) : QWidget(parent)
{
}
File::~File()
{
}

void File::copyFile(QString copyFrom, QString copyTo, QString fileName)
{
	QFile::copy(copyFrom + "\\" + fileName, copyTo + "\\" + fileName);
}

void File::createFile(QString path, QString fileName)
{
	QFile file(path + "\\" + fileName);
	file.open(QIODevice::WriteOnly);
	file.close();
}

void File::changeFileName(QString pathToFile, QString oldFileName, QString newFileName)
{
	QFile::rename(pathToFile + "\\" + oldFileName, pathToFile + "\\" + newFileName);
}

void File::readFilesFromProject(QString pathToProject, QListWidget& widget)
{
	QDir dir(pathToProject);
	QFileInfoList fileList = dir.entryInfoList();
	int i = 0;
	widget.clear();
	foreach(QFileInfo file, fileList)
	{
		QString fileName = file.fileName();
		if (fileName != ".." && fileName != "." && file.suffix() == nullptr) {
			File::displayProjectFiles(fileName, widget);
			i++;
		}
	}

	foreach(QFileInfo file, fileList)
	{
		QString fileName = file.fileName();
		if (fileName != ".." && fileName != "." && file.suffix() != nullptr) {
			File::displayProjectFiles(fileName, widget);
			i++;
		}
	}
}

bool File::ñheckFileOrFolder(QString fileName)
{
	QFileInfo file = fileName;
	if (file.suffix() == nullptr) {
		return true;
	}
	else if (file.suffix() != nullptr) {
		return false;;
	}
}

void File::goThroughAllFilesAndFolders(QString path)
{
	QDir dir(path);
	QFileInfoList fileList = dir.entryInfoList();
	foreach(QFileInfo file, fileList)
	{
		QString fileName = file.fileName();
		if (file.suffix() != nullptr && fileName != ".." && fileName != ".") {
			File::removeFileFromProject(file.absoluteFilePath());
		}
		else if (file.suffix() == nullptr && fileName != ".." && fileName != ".") {
			Dir::removeFolderFromProject(file.absoluteFilePath());
		}
	}
}

QString File::getFileextension(QString fileName)
{
	QFileInfo extension = fileName;
	return '.' + extension.suffix();
}

void File::removeFileFromProject(QString pathToFile)
{
	QFile file(pathToFile);
	file.remove();
	file.close();
}

void File::displayProjectFiles(QString fileName, QListWidget& widget)
{
	if (fileName == ".." || fileName == ".") return;
	QFileInfo file(fileName);
	if (file.suffix() == "js") {
		widget.addItem(new QListWidgetItem(QIcon("./res/JS.ico"), fileName));
		widget.setContextMenuPolicy(Qt::CustomContextMenu);
	}
	else if (file.suffix() == "cpp") {
		widget.addItem(new QListWidgetItem(QIcon("./res/CPlus.ico"), fileName));
	}
	else if (file.suffix() == "h") {
		widget.addItem(new QListWidgetItem(QIcon("./res/CPlus.ico"), fileName));
	}
	else if (file.suffix() == "txt") {
		widget.addItem(new QListWidgetItem(QIcon("./res/text.ico"), fileName));
	}
	else if (file.suffix() == "7z") {
		widget.addItem(new QListWidgetItem(QIcon("./res/zip.ico"), fileName));
	}
	else if (file.suffix() == "rar") {
		widget.addItem(new QListWidgetItem(QIcon("./res/zip.ico"), fileName));
	}
	else if (file.suffix() == "zip") {
		widget.addItem(new QListWidgetItem(QIcon("./res/zip.ico"), fileName));
	}
	else if (file.suffix() == "dll") {
		widget.addItem(new QListWidgetItem(QIcon("./res/dll.ico"), fileName));
	}
	else if (file.suffix() == "png") {
		widget.addItem(new QListWidgetItem(QIcon("./res/picture.ico"), fileName));
	}
	else if (file.suffix() == "jpg") {
		widget.addItem(new QListWidgetItem(QIcon("./res/picture.ico"), fileName));
	}
	else if (file.suffix() == "ico") {
		widget.addItem(new QListWidgetItem(QIcon("./res/picture.ico"), fileName));
	}
	else if (file.suffix() == "gif") {
		widget.addItem(new QListWidgetItem(QIcon("./res/picture.ico"), fileName));
	}
	else if (file.suffix() == "exe") {
		widget.addItem(new QListWidgetItem(QIcon("./res/exe.ico"), fileName));
	}
	else if (file.suffix() == "EXE") {
		widget.addItem(new QListWidgetItem(QIcon("./res/exe.ico"), fileName));
	}
	else if (file.suffix() == "mp4") {
		widget.addItem(new QListWidgetItem(QIcon("./res/video.ico"), fileName));
	}
	else if (file.suffix() == "avi") {
		widget.addItem(new QListWidgetItem(QIcon("./res/video.ico"), fileName));
	}
	else if (file.suffix() == "mp3") {
		widget.addItem(new QListWidgetItem(QIcon("./res/music.ico"), fileName));
	}
	else if (file.suffix() == "wav") {
		widget.addItem(new QListWidgetItem(QIcon("./res/music.ico"), fileName));
	}
	else if (file.suffix() == "css") {
		widget.addItem(new QListWidgetItem(QIcon("./res/css.ico"), fileName));
	}
	else if (file.suffix() == "doc") {
		widget.addItem(new QListWidgetItem(QIcon("./res/doc.ico"), fileName));
	}
	else if (file.suffix() == "docx") {
		widget.addItem(new QListWidgetItem(QIcon("./res/doc.ico"), fileName));
	}
	else if (file.suffix() == "html") {
		widget.addItem(new QListWidgetItem(QIcon("./res/html.ico"), fileName));
	}
	else if (file.suffix() == "torrent") {
		widget.addItem(new QListWidgetItem(QIcon("./res/torent.ico"), fileName));
	}
	else if (file.suffix() == "iso") {
		widget.addItem(new QListWidgetItem(QIcon("./res/iso.ico"), fileName));
	}
	else if (file.suffix() == "ui") {
		widget.addItem(new QListWidgetItem(QIcon("./res/ui.ico"), fileName));
	}
	else if (file.suffix() == "xml") {
		widget.addItem(new QListWidgetItem(QIcon("./res/xml.ico"), fileName));
	}
	else if (file.suffix() == "obj") {
		widget.addItem(new QListWidgetItem(QIcon("./res/obj.ico"), fileName));
	}
	else if (file.suffix() == "debug") {
		widget.addItem(new QListWidgetItem(QIcon("./res/CPlus.ico"), fileName));
	}
	else if (file.suffix() == "pro") {
		widget.addItem(new QListWidgetItem(QIcon("./res/CPlus.ico"), fileName));
	}
	else if (file.suffix() == "msi") {
		widget.addItem(new QListWidgetItem(QIcon("./res/msi.ico"), fileName));
	}
	else if (file.suffix() == "ini") {
		widget.addItem(new QListWidgetItem(QIcon("./res/ini.ico"), fileName));
	}
	else if (file.suffix() == "dat") {
		widget.addItem(new QListWidgetItem(QIcon("./res/dat.ico"), fileName));
	}
	else if (file.suffix() == "rtf") {
		widget.addItem(new QListWidgetItem(QIcon("./res/rtf.ico"), fileName));
	}
	else if (file.suffix() == "pdf") {
		widget.addItem(new QListWidgetItem(QIcon("./res/pdf.ico"), fileName));
	}
	else if (file.suffix() == "ttf") {
		widget.addItem(new QListWidgetItem(QIcon("./res/ttf.ico"), fileName));
	}
	else if (file.suffix() == "pptx") {
		widget.addItem(new QListWidgetItem(QIcon("./res/pptx.ico"), fileName));
	}
	else if (file.suffix() == "psd") {
		widget.addItem(new QListWidgetItem(QIcon("./res/psd.ico"), fileName));
	}
	else if (file.suffix() == "cfg") {
		widget.addItem(new QListWidgetItem(QIcon("./res/text.ico"), fileName));
	}
	else if (file.suffix() == nullptr) {
		widget.addItem(new QListWidgetItem(QIcon("./res/file.ico"), fileName));
	}
	else {
		widget.addItem(new QListWidgetItem(QIcon("./res/filetitle.png"), fileName));
	}
}

void File::findFile(QString path, QString fileName, QListWidget& widget)
{
	QDir dir(path);
	QFileInfoList fileList = dir.entryInfoList();
	widget.clear();
	foreach(QFileInfo file, fileList)
	{
		QString FileName = file.fileName();
		if (fileName != ".." && fileName != "." && FileName.contains(fileName)) {
			File::displayProjectFiles(FileName, widget);
		}
	}
}

QString File::getFileContens(QString pathToFile)
{
	QFile file(pathToFile);
	QString content = "";
	if ((file.exists()) && (file.open(QIODevice::ReadOnly))) {
		while (!file.atEnd()) {
			content += file.readLine();
		}
		file.close();
	}
	return content;
}

void File::saveFile(QString pathToFile, QString content)
{
	char text[4096];
	std::string sContent = "";
	sContent = content.toUtf8().constData();
	std::strcpy(text, sContent.c_str());
	QFile file(pathToFile);
	if (file.open(QIODevice::WriteOnly)) {
		file.write(text); 
		file.close();
	}
}