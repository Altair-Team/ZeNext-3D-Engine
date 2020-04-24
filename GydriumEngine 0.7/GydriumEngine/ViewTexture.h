/****************************************************************************
** Copyright (C) 2020 GydriumEngine Team
** View textures window class
** Date: 15.03.2020
** Developed: SpaceMaN
****************************************************************************/
#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_View_texture.h"
#include "Texture.h"
class ViewTexture : public QWidget
{
	Q_OBJECT
public:
	explicit ViewTexture(QString pathToTexture, QWidget *parent = nullptr);
	~ViewTexture();
private:
	Ui::ViewTexture ui;
private:
	QString pathToTexture_;
	QString selectedTexture_;
private slots:
	void SelectTextureOnClickItem();
	void SelectSizeOnComboBoxCurrentTextChanged();
	void SelectTextureResolution();
	void findtextureOnChangingText();
	void CloseViewTexturesOnPushButtonClicked();
};