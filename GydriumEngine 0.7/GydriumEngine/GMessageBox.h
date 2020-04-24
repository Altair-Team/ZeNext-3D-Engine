/****************************************************************************
** Copyright (C) 2020 GydriumEngine Team
** Native window class
** Date: 15.03.2020
** Developed: SpaceMaN
****************************************************************************/
#pragma once
#include <QtWidgets>
#include <QMessageBox>
#include "ui_gmessage_box.h"
class GMessageBox : public QWidget
{
	Q_OBJECT
public:
	explicit GMessageBox(QWidget *parent = nullptr);
	~GMessageBox();
private:
	Ui::GMessageBoxForm ui;
public:
	static void Show(QString title, QString text, int icon);
private slots:
	void QuitOnPushButtonCliked();
};