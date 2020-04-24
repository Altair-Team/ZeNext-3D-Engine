#include "Texture.h"

Texture::Texture(QWidget *parent) : QWidget(parent)
{
}
Texture::~Texture()
{
}

void Texture::displayTextures(QString path, QListWidget& widget)
{
	QDir dir(path);
	QFileInfoList fileList = dir.entryInfoList();
	widget.clear();
	foreach(QFileInfo file, fileList)
	{
		QString fileName = file.fileName();
		if (file.suffix() == "jpg") {
			QString absolutePathToTexture = file.absoluteFilePath();
			QPixmap textureIcon(absolutePathToTexture);
			textureIcon.scaled(16, 16);
			widget.addItem(new QListWidgetItem(QIcon(textureIcon), fileName));
		}
	}
}

QString Texture::getTextureExtension(QString textureName)
{
	QFileInfo textureInfo(textureName);
	return textureInfo.suffix();
}

QString Texture::getTextureResolution(QString pathToTexture)
{
	QImageReader reader(pathToTexture);
	QSize textureSize = reader.size();
	int heigth = textureSize.height();
	int width = textureSize.width();
	return QString::number(heigth) + "X" + QString::number(width);
}

void Texture::texturesResolutionSorting(QString path, int h, int w, QListWidget& widget)
{
	widget.clear();
	QDir dir(path);
	QFileInfoList fileList = dir.entryInfoList();

	foreach(QFileInfo file, fileList)
	{
		QString fileName = file.fileName();
		QString textureAbsolutePath = file.absoluteFilePath();

		QImageReader reader(textureAbsolutePath);
		QSize textureSize = reader.size();
		int heigth = textureSize.height();
		int width = textureSize.width();

		if (file.suffix() == "jpg" && fileName != ".." && fileName != ".") {
			if (heigth <= h && width <= w) {
				QString absolutePathToTexture = file.absoluteFilePath();
				QPixmap textureIcon(absolutePathToTexture);
				textureIcon.scaled(16, 16);
				widget.addItem(new QListWidgetItem(QIcon(textureIcon), fileName));
			}
		}
	}
}

void Texture::searchTexture(QString path, QString textureName, QListWidget& widget)
{
	widget.clear();
	QDir dir(path);
	QFileInfoList fileList = dir.entryInfoList();

	foreach(QFileInfo file, fileList)
	{
		QString fileName = file.fileName();
		if (fileName.contains(textureName) && fileName != ".." && fileName != "." ) {
			QString absolutePathToTexture = file.absoluteFilePath();
			QPixmap textureIcon(absolutePathToTexture);
			textureIcon.scaled(16, 16);
			widget.addItem(new QListWidgetItem(QIcon(textureIcon), fileName));
		}
	}
}