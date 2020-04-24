#include "Dir.h"

Dir::Dir(QWidget *parent) : QWidget(parent)
{
}
Dir::~Dir()
{
}

void Dir::copyFolder(QString copyFrom, QString copyTo)
{
	QDir dir(copyFrom);
	if (!dir.exists())
		return;

	foreach(QString folderName, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
	{
		QString dst_path = copyTo + QDir::separator() + folderName;
		dir.mkpath(dst_path);
		copyFolder(copyFrom + QDir::separator() + folderName, dst_path);
	}

	foreach(QString fileName, dir.entryList(QDir::Files))
	{
		QFile::copy(copyFrom + QDir::separator() + fileName, copyTo + QDir::separator() + fileName);
	}
}

void Dir::createFolder(QString path, QString folderName)
{
	QDir dir(path);
	dir.mkdir(folderName);
}

QString Dir::getNextFolder(QString path, QString fileName, QListWidget& widget)
{
	File::readFilesFromProject(path + "\\" + fileName, widget);
	return path + "\\" + fileName;
}

QString Dir::goToPreviousFolder(QString path, QString pathToProject, QListWidget& widget)
{
	if (path == pathToProject) return path;
	QString shortPath = path.left(path.lastIndexOf('\\'));
	File::readFilesFromProject(shortPath, widget);
	return shortPath;
}

int Dir::getFolderSize(QString pathToFolder)
{
	QDirIterator it(pathToFolder, QDirIterator::Subdirectories);
	int folderSize = 0;
	while (it.hasNext()) {
		QFileInfo file = it.next();
		folderSize += file.size();
	}
	return folderSize;
}

void Dir::removeFolderFromProject(QString pathToFolder)
{
	QDir dir(pathToFolder);
	dir.removeRecursively();
}

void Dir::changeFolderName(QString pathToFolder, QString oldFolderName, QString newFolderName)
{
	QDir dir(pathToFolder + "\\" + oldFolderName);
	dir.rename(pathToFolder + "\\" + oldFolderName, pathToFolder + "\\" + newFolderName);
}

void Dir::createNewProject(QString path, QString projectName)
{
	QDir dir(path);
	dir.mkdir(projectName);
	QDir d(path + "\\" + projectName + "\\");
	d.mkdir("textures");
}

QString Dir::getPathToProject()
{
	QString pathToProject = QFileDialog::getExistingDirectory(this, tr("Select a Directory"));
	return pathToProject;
}