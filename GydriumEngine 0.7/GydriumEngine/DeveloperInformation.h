/****************************************************************************
** Copyright (C) 2020 GydriumEngine Team
** Developer Information Window Class
** Date: 14.03.2020
** Developed: SpaceMaN
****************************************************************************/
#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_developer_information.h"
class DeveloperInformation : public QWidget
{
	Q_OBJECT
public:
	explicit DeveloperInformation(QWidget *parent = nullptr);
	~DeveloperInformation();
private:
	Ui::DeveloperInformation ui;
};
