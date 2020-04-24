/****************************************************************************
** Copyright (C) 2020 GydriumEngine Team
** Main Window Class Gydrium Engine
** Date: 14.03.2020 
** Developed: SpaceMaN
****************************************************************************/
#pragma once
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QMessageBox>
#include <QTextCodec>
#include "ui_gydrium_engine.h"
#include "Settings.h"
#include "GMessageBox.h"
#include "File.h"
#include "FileInformation.h"
#include "Dir.h"
#include "DeveloperInformation.h"
#include "ViewTexture.h"
#include "CodeEditor.h"

class GydriumEngine : public QMainWindow
{
	Q_OBJECT
public:
	explicit GydriumEngine(QString currentPath, QWidget *parent = nullptr);
	~GydriumEngine();
	File read;
	Dir directory;
private:
	Ui::editro_GE ui;
private:
	QString currentPath_;
	QString pathToProject_;
	QString selectedItemInFileListWidget_;
	bool isStatusCreateOrRename; // true = create file/folder, false = rename file/folder
	bool isStatusCopyOrCut; // true = copy file/folder false = cut file/folder
	QString copyOrCutFrom;
	QString copyOrCutTo;
	QString nameFileOrFolderToCopyOrCut;
private slots:
	void ContextMenuforFileManager(const QPoint &pos);
	void GoToFolderOnPushButtonDoubleClicked();
	void goToPreviousFolderOnPushButtonClicked();
	void removeFileOrFolderOnPushButtonClicked();
	void removeAllFilesOrFoldersOnPushButtonClicked();
	void GoToFolderOnPushButtonClicked();
	void createFileOnActionCreateFile();
	void CancelInputOnPushButtonCliked();
	void createFileOnPushButtonCliked();
	void findFolderOrFileWhenChangingText();
	void findFolderOrFileOnQActionCliked();
	void changeFileNameOnActionCreateFile();
	void updateFileListOnActionCreateFile();
	void SelectItemWhenClickItem();
	void CopyFileOrFolderOnQActionCliked();
	void InsertFileOrFolderOnQActionCliked();
	void CutFileorFolderOnQActionCliked();
	void FileOrFolderPropertiesQActionCliked();
	void OpenSettingsOnPushButtonCliked();
	void OpenAboutDeveloperssOnQActionCliked();
	void OpenViewTextureOnPushButtonCliked();
	void OpenCodeEditorOnQActionCliked();
	void OpenFileInCodeEditorOnQActionCliked();
};