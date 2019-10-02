#pragma once

#include "qfile.h"
#include "QGLWidget"
#include "QtOpenGl"
#include "QTimer"

#include "ui_ZeNextEngine.h"
#include "ui_chooseworld.h"
#include "ui_settngs.h"
#include "ui_code_editor.h"
#include "ui_info.h"

//Главное окно
class ZeNextEngine : public QMainWindow{
public:
	ZeNextEngine(QMainWindow *parent = Q_NULLPTR);
	void SetStandartGameObjInfo();
	void initializeGL();
	void resizeGL(int nW, int nH);
	void paintGL();
private:
	Ui::MainWindow ui;
};

class CodeEditor : public QMainWindow {
public:
	CodeEditor(QMainWindow *parent = Q_NULLPTR);
private:
	Ui::CodeEditor ui;
};

//Меню выбора типа мира
class chooseworld : public QDialog {
public:
	chooseworld(QDialog *parent = Q_NULLPTR);
private:
	Ui:: CrateWorld ui;
};
//Информация
class info: public QWidget {
public:
	info(QWidget *parent = Q_NULLPTR);
private:
	Ui:: InfoPage ui;
};
class settings : public QDialog {
public:
	settings(QDialog *parent = Q_NULLPTR);
private:
	Ui::Settings ui;
};