/****************************************************************************
** Copyright (C) 2020 GydriumEngine Team
** Texture class
** Date: 21.03.2020
** Developed: SpaceMaN
****************************************************************************/
#pragma once
#include <QtWidgets>
#include <QDebug>
#include <QListWidget>
class Texture : public QWidget
{
	Q_OBJECT
public:
	explicit Texture(QWidget *parent = nullptr);
	~Texture();
public:
	static void displayTextures(QString path, QListWidget& widget);
	static QString getTextureExtension(QString textureName);
	static QString getTextureResolution(QString pathToTexture);
	static void texturesResolutionSorting(QString path, int h, int w, QListWidget& widget);
	static void searchTexture(QString path, QString textureName, QListWidget& widget);
};