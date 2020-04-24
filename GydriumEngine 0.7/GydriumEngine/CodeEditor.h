#pragma once
#pragma once
#include <QtWidgets>
#include "ui_code_editor.h"
#include "File.h"

class CodeEditor : public QMainWindow
{
	Q_OBJECT
public:
	explicit CodeEditor(QString pathToFile, QWidget *parent = nullptr);
	~CodeEditor();
private:
	Ui::CodeEditorForm ui;
private:
	QString fileName_;
	QString pathToFile_;
private slots:
	void OpenFileOnQActionCliked();
	void ChangeContentOnChangingText();
	void SaveFileOnQActionCliked();
	void SaveAsFileOnQActionCliked();
};