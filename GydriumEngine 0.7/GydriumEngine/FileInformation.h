/****************************************************************************
** Copyright (C) 2020 GydriumEngine Team
** File/folder Properties Class 
** Date: 18.03.2020
** Developed: SpaceMaN
****************************************************************************/
#pragma once
#include <QtWidgets>
#include "ui_file_info.h"
#include "File.h"
#include "Dir.h"
class FileInformation : public QWidget
{
	Q_OBJECT
public:
	explicit FileInformation(QString pathToFile, QString fileName, QWidget *parent = nullptr);
	~FileInformation();
private:
	Ui::info_File ui;
private:
	QString pathToFile_;
	QString fileName_;
private slots:
	void SelectSizeOnComboBoxCurrentTextChanged();
};