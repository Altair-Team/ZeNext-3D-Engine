/****************************************************************************
** Copyright (C) 2020 GydriumEngine Team
** Dir class
** Date: 20.03.2020
** Developed: SpaceMaN
****************************************************************************/
#pragma once
#include <QtWidgets>
#include <QDebug>
#include "File.h"
class Dir : public QWidget
{
	Q_OBJECT
public:
	explicit Dir(QWidget *parent = nullptr);
	~Dir();
public:
	static void copyFolder(QString copyFrom, QString copyTo);
	static void createFolder(QString path, QString folderName);
	QString getNextFolder(QString path, QString fileName, QListWidget& widget);
	QString goToPreviousFolder(QString path, QString pathToProject, QListWidget& widget);
	static int getFolderSize(QString pathToFolder);
	static void removeFolderFromProject(QString pathToFolder);
	static void changeFolderName(QString pathToFolder, QString oldFolderName, QString newFolderName);
	void createNewProject(QString path, QString projectName);
	QString getPathToProject();
};