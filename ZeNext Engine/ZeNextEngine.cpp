#include "ZeNextEngine.h"

//Инициализация окон.
ZeNextEngine::ZeNextEngine(QMainWindow *parent)
	: QMainWindow(parent) {
	ui.setupUi(this);
	SetStandartGameObjInfo();
}

//Исполнение команд в Главном окне редактора Движка.
void ZeNextEngine::SetStandartGameObjInfo()
{
	ui.pro_Save->hide();
	ui.lineEd_objName->setText("#Obj_name");
	ui.checkBox_objActiv->setChecked(true);
	ui.checkBox_objVisib->setChecked(true);
	ui.fpsCounter->display(5051);
}

chooseworld::chooseworld(QDialog *parent)
	: QDialog(parent) {
	ui.setupUi(this);
	QFile worldtype;
	worldtype.setFileName("./wt.znd");
	//if (worldtype.isOpen) {
	worldtype.write("World Type is: %d");
	worldtype.close();
	//}
}

info::info(QWidget *parent)
	: QWidget(parent) {
	ui.setupUi(this);}

CodeEditor::CodeEditor(QMainWindow * parent)
	: QMainWindow(parent) {
	
	ui.setupUi(this);
}

settings::settings(QDialog * parent)
	: QDialog(parent) {
	
	ui.setupUi(this);
}


	void ZeNextEngine::initializeGL()
	{
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	void ZeNextEngine::resizeGL(int nW, int nH)
	{
		glViewport(0, 0, nW, nH);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
	}

	void ZeNextEngine::paintGL()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		QColor hg(0, 128, 0, 255);
		glBegin(GL_QUADS);
		glVertex3f(0.5, 0.5, 0.5);
		glVertex3f(-0.5, 0.5, 0.5);
		glVertex3f(-0.5, -0.5, 0.5);
		glVertex3f(0.5, -0.5, 0.5);
		glEnd;
	}

