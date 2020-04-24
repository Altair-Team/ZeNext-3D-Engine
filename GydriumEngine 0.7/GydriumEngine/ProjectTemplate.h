/****************************************************************************
** Copyright (C) 2020 GydriumEngine Team
** Project Create Window Class
** Date: 15.03.2020
** Developed: SpaceMaN
****************************************************************************/
#pragma once
#include <QWidget>
#include "ui_project_template.h"
#include "Dir.h"
#include "GMessageBox.h"
#include "GydriumEngine.h"

class ProjectTemplate : public QMainWindow
{
	Q_OBJECT
public:
	explicit ProjectTemplate(QWidget *parent = nullptr);
	~ProjectTemplate();
	 Dir dir;
private:
	Ui::project_tamplate ui;
private slots:
	void getPathToProjectOnPushButtonCliked();
	void CreateNewProjectOnPushButtonCliked();
};
