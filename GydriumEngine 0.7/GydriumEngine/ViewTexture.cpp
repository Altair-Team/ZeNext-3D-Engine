#include "ViewTexture.h"

ViewTexture::ViewTexture(QString pathToTexture, QWidget *parent) : QWidget(parent)
{
	pathToTexture_ = pathToTexture;

	ui.setupUi(this);
	this->setWindowIcon(QIcon("./res/Texture.png"));
	ui.TexturesQListWidget->setIconSize(QSize(64, 64));
	Texture::displayTextures(pathToTexture_, *ui.TexturesQListWidget);
	connect(ui.TexturesQListWidget, SIGNAL(itemSelectionChanged()), this, SLOT(SelectTextureOnClickItem()));
	connect(ui.ChangeSizeMatFileQComboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(SelectSizeOnComboBoxCurrentTextChanged()));
	connect(ui.SearchsizeQComboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(SelectTextureResolution()));
	connect(ui.SearchNameQLineEdit, SIGNAL(textChanged(QString)), this, SLOT(findtextureOnChangingText()));
	connect(ui.OKPushButton, SIGNAL(clicked()), this, SLOT(CloseViewTexturesOnPushButtonClicked()));
	connect(ui.CancelPushButton, SIGNAL(clicked()), this, SLOT(CloseViewTexturesOnPushButtonClicked()));
}
ViewTexture::~ViewTexture()
{
}

void ViewTexture::SelectTextureOnClickItem()
{
	selectedTexture_ = ui.TexturesQListWidget->currentItem()->text();
	ui.TypeQLineEdit->setText(Texture::getTextureExtension(selectedTexture_));
	ui.TextureViewLabel->setPixmap(QPixmap(pathToTexture_ + "\\" + selectedTexture_).scaled(800, 600));
	ui.SizeMaterialQLineEdit->setText(Texture::getTextureResolution(pathToTexture_ + "\\" + selectedTexture_));
	QFileInfo file = pathToTexture_ + "\\" + selectedTexture_;
	ui.SizeMaterialFileQLineEdit->setText(QString::number(file.size() / 1024));
	ui.ChangeSizeMatFileQComboBox->setCurrentIndex(0);
}

void ViewTexture::SelectSizeOnComboBoxCurrentTextChanged()
{
	QFileInfo file = pathToTexture_ + "\\" + selectedTexture_;
		if (ui.ChangeSizeMatFileQComboBox->currentText() == "MBs") {
			ui.SizeMaterialFileQLineEdit->setText(QString::number(file.size() / 1024 / 1024));
		}
		else if (ui.ChangeSizeMatFileQComboBox->currentText() == "GBs") {
			ui.SizeMaterialFileQLineEdit->setText(QString::number(file.size() / 1024 / 1024 / 1024));
		}
		else {
			ui.SizeMaterialFileQLineEdit->setText(QString::number(file.size() / 1024));
	}
}

void ViewTexture::SelectTextureResolution()
{
	if (ui.SearchsizeQComboBox->currentText() == "512X512") {
		Texture::texturesResolutionSorting(pathToTexture_, 512, 512, *ui.TexturesQListWidget);
	} else if (ui.SearchsizeQComboBox->currentText() == "1024X1024") {
		Texture::texturesResolutionSorting(pathToTexture_, 1024, 1024, *ui.TexturesQListWidget);
	} else if (ui.SearchsizeQComboBox->currentText() == "2048X2048") {
		Texture::texturesResolutionSorting(pathToTexture_, 2048, 2048, *ui.TexturesQListWidget);
	} else if (ui.SearchsizeQComboBox->currentText() == "4096X4096") {
		Texture::texturesResolutionSorting(pathToTexture_, 4096, 4096, *ui.TexturesQListWidget);
	}
	else {
		Texture::displayTextures(pathToTexture_, *ui.TexturesQListWidget);
	}
}

void ViewTexture::findtextureOnChangingText()
{
	if (ui.SearchNameQLineEdit->text() == nullptr) Texture::displayTextures(pathToTexture_, *ui.TexturesQListWidget);
	Texture::searchTexture(pathToTexture_, ui.SearchNameQLineEdit->text(), *ui.TexturesQListWidget);
}

void ViewTexture::CloseViewTexturesOnPushButtonClicked()
{
	this->close();
}