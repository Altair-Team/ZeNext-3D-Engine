/****************************************************************************
** Copyright (C) 2020 GydriumEngine Team
** File class
** Date: 20.03.2020
** Developed: SpaceMaN
****************************************************************************/
#pragma once
#include <QtWidgets>
#include <QDebug>
#include "Dir.h"
class File : public QWidget
{
	Q_OBJECT
public:
	explicit File(QWidget *parent = nullptr);
	~File();
public:
	static void copyFile(QString copyFrom, QString copyTo, QString fileName);
	static void createFile(QString path, QString fileName);
	static void changeFileName(QString pathToFile, QString oldFileName, QString fileName);
	static void readFilesFromProject(QString pathToProject, QListWidget& widget);
	static bool ñheckFileOrFolder(QString fileName);
	static void goThroughAllFilesAndFolders(QString path);
	static QString getFileextension(QString fileName);
	static void removeFileFromProject(QString pathToFile);
	static void displayProjectFiles(QString fileName, QListWidget& widget);
	static void findFile(QString path, QString fileName, QListWidget& widget);
	static QString getFileContens(QString pathToFile);
	static void saveFile(QString pathToFile, QString content);
};