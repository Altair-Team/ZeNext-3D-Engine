/****************************************************************************
** Copyright (C) 2020 GydriumEngine Team
** Settings window class
** Date: 15.03.2020
** Developed: SpaceMaN
****************************************************************************/
#pragma once
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QMessageBox>
#include "ui_settngs.h"
#include "PcInfo.h"

class Settngs : public QDialog
{
	Q_OBJECT
public:
	explicit Settngs(QWidget *parent = nullptr);
	~Settngs();
private:
	Ui::Settings ui;
};