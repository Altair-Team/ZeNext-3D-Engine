#include "GydriumEngine.h"

GydriumEngine::GydriumEngine(QString currentPath, QWidget *parent) : QMainWindow(parent)
{
	currentPath_ = currentPath;
	pathToProject_ = currentPath;

	ui.setupUi(this);
	this->setWindowIcon(QIcon("./res/icon.ico"));
	ui.SaveProgressBar->hide();
	ui.FileListWidget->setContextMenuPolicy(Qt::CustomContextMenu); 
	ui.FileListWidget->setIconSize(QSize(32, 32));
	ui.InputFieldLineEdit->hide();
	ui.CancelPushButton->hide();
	ui.OkayPushButton->hide();
	ui.SaveAllQAction->setIcon(QIcon("./res/save.png"));
	ui.OpenProjectQAction->setIcon(QIcon("./res/open.png"));
	ui.SaveProjectQAction->setIcon(QIcon("./res/save.png"));
	ui.SaveProjectAsQAction->setIcon(QIcon("./res/save.png"));
	ui.QuitQAction->setIcon(QIcon("./res/exit.png"));
	ui.OpenSceneQAction->setIcon(QIcon("./res/OpenScene.png"));
	ui.SaveSceneQAction->setIcon(QIcon("./res/SaveScene.png"));
	ui.CreateNewSceneQAction->setIcon(QIcon("./res/NewScene.png"));
	ui.SceneSettingsQAction->setIcon(QIcon("./res/SettingsScene.png"));
	ui.ProjectSettingsQAction->setIcon(QIcon("./res/ProjectSettings.png"));
	ui.MenuCompileProjectQMenu->setIcon(QIcon("./res/Compilation.png"));
	ui.DebugQAction->setIcon(QIcon("./res/CompilationDebug.png"));
	ui.ReleaseQAction->setIcon(QIcon("./res/CompilationRealse.png"));
	ui.EditorsQMenu->setIcon(QIcon("./res/Create_New.ico"));
	ui.CodeEditorQAction->setIcon(QIcon("./res/Editors.png"));
	ui.MaterialsEditorQAction->setIcon(QIcon("./res/ui.ico"));
	ui.SoundQAction->setIcon(QIcon("./res/ViewSounds.png"));
	ui.ModelsQAction->setIcon(QIcon("./res/ViewModel.png"));
	ui.TexturesViewQAction->setIcon(QIcon("./res/Texture.png"));
	ui.SettingsQAction->setIcon(QIcon("./res/Settings.png"));
	ui.DeveloperInfoQAction->setIcon(QIcon("./res/icon.ico"));
	File::readFilesFromProject(currentPath_, *ui.FileListWidget);

	connect(ui.FileListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(GoToFolderOnPushButtonDoubleClicked()));
	connect(ui.FileListWidget, SIGNAL(itemSelectionChanged()), this, SLOT(SelectItemWhenClickItem()));
	connect(ui.GoToPreviousFolderPushButton, SIGNAL(clicked()), this, SLOT(goToPreviousFolderOnPushButtonClicked()));
	connect(ui.GoToFolderPushButton, SIGNAL(clicked()), this, SLOT(GoToFolderOnPushButtonClicked()));
	connect(ui.CancelPushButton, SIGNAL(clicked()), this, SLOT(CancelInputOnPushButtonCliked()));
	connect(ui.OkayPushButton, SIGNAL(clicked()), this, SLOT(createFileOnPushButtonCliked()));
	connect(ui.FileListWidget, SIGNAL(customContextMenuRequested(QPoint)), SLOT(ContextMenuforFileManager(QPoint)));
	connect(ui.InputFieldLineEdit, SIGNAL(textChanged(QString)), this, SLOT(findFolderOrFileWhenChangingText()));
	connect(ui.SettingsQAction, &QAction::triggered, this, &GydriumEngine::OpenSettingsOnPushButtonCliked);
	connect(ui.DeveloperInfoQAction, &QAction::triggered, this, &GydriumEngine::OpenAboutDeveloperssOnQActionCliked);
	connect(ui.TexturesViewQAction, &QAction::triggered, this, &GydriumEngine::OpenViewTextureOnPushButtonCliked);
	connect(ui.CodeEditorQAction, &QAction::triggered, this, &GydriumEngine::OpenCodeEditorOnQActionCliked);
}

void GydriumEngine::ContextMenuforFileManager(const QPoint &pos)
{
	QModelIndex index = ui.FileListWidget->indexAt(pos);
	QMenu* fileManagerQMenu = new QMenu(this);
	fileManagerQMenu->setAttribute(Qt::WA_DeleteOnClose);

	QAction* codeEditorQAction = new QAction(QPixmap("./res/icon.ico"), "&Open in Gydrium code editor", this);
	QAction* createNewFileOrFolderQAction = new QAction(QPixmap("./res/create.ico"), "&Create a file", this);
	QAction* findToFolderOrFileQAction = new QAction(QPixmap("./res/Search.ico"), "&Find", this);
	QAction* removeFolderOrFileQAction = new QAction(QPixmap("./res/delete.ico"), "&Remove", this);
	QAction* removeAllFilesInFolderQAction = new QAction(QPixmap("./res/delete.ico"), "&Remove all", this);
	QAction* renameFileOrFolderQAction = new QAction(QPixmap("./res/change.ico"), "&Rename", this);
	QAction* updateFileListQAction = new QAction(QPixmap("./res/Update.ico"), "&Update", this);
	QAction* copyFileOrFolderQAction = new QAction(QPixmap("./res/copy.ico"), "&Copy", this);
	QAction* cutFileorFolderQAction = new QAction(QPixmap("./res/cut.png"), "&Cut", this);
	QAction* insertFileOrFolderQAction = new QAction(QPixmap("./res/past.ico"), "&Insert", this);
	QAction* FileOrFolderPropertiesQAction = new QAction(QPixmap("./res/property.ico"), "&Properties", this);

	fileManagerQMenu->addAction(createNewFileOrFolderQAction);
	if (File::ñheckFileOrFolder(selectedItemInFileListWidget_) == false) { fileManagerQMenu->addAction(codeEditorQAction);}
	fileManagerQMenu->addAction(findToFolderOrFileQAction);
	fileManagerQMenu->addAction(removeFolderOrFileQAction);
	fileManagerQMenu->addAction(removeAllFilesInFolderQAction);
	fileManagerQMenu->addAction(renameFileOrFolderQAction);
	fileManagerQMenu->addAction(updateFileListQAction);
	fileManagerQMenu->addAction(copyFileOrFolderQAction);
	fileManagerQMenu->addAction(cutFileorFolderQAction);
	fileManagerQMenu->addAction(insertFileOrFolderQAction);
	fileManagerQMenu->addAction(FileOrFolderPropertiesQAction);
	fileManagerQMenu->popup(ui.FileListWidget->viewport()->mapToGlobal(pos));

	connect(createNewFileOrFolderQAction, &QAction::triggered, this, &GydriumEngine::createFileOnActionCreateFile);
	connect(findToFolderOrFileQAction, &QAction::triggered, this, &GydriumEngine::findFolderOrFileOnQActionCliked);
	connect(removeFolderOrFileQAction, &QAction::triggered, this, &GydriumEngine::removeFileOrFolderOnPushButtonClicked);
	connect(removeAllFilesInFolderQAction, &QAction::triggered, this, &GydriumEngine::removeAllFilesOrFoldersOnPushButtonClicked);
	connect(renameFileOrFolderQAction, &QAction::triggered, this, &GydriumEngine::changeFileNameOnActionCreateFile);
	connect(updateFileListQAction, &QAction::triggered, this, &GydriumEngine::updateFileListOnActionCreateFile);
	connect(copyFileOrFolderQAction, &QAction::triggered, this, &GydriumEngine::CopyFileOrFolderOnQActionCliked);
	connect(insertFileOrFolderQAction, &QAction::triggered, this, &GydriumEngine::InsertFileOrFolderOnQActionCliked);
	connect(cutFileorFolderQAction, &QAction::triggered, this, &GydriumEngine::CutFileorFolderOnQActionCliked);
	connect(FileOrFolderPropertiesQAction, &QAction::triggered, this, &GydriumEngine::FileOrFolderPropertiesQActionCliked);
	connect(codeEditorQAction, &QAction::triggered, this, &GydriumEngine::OpenFileInCodeEditorOnQActionCliked);
}

void GydriumEngine::goToPreviousFolderOnPushButtonClicked()
{
	currentPath_ = directory.goToPreviousFolder(currentPath_, pathToProject_, *ui.FileListWidget);
}

void GydriumEngine::GoToFolderOnPushButtonDoubleClicked()
{
	selectedItemInFileListWidget_ = ui.FileListWidget->currentItem()->text();
	if (File::ñheckFileOrFolder(selectedItemInFileListWidget_) == false) return;
	currentPath_ = directory.getNextFolder(currentPath_, selectedItemInFileListWidget_, *ui.FileListWidget);
}

void GydriumEngine::GoToFolderOnPushButtonClicked()
{
	if (currentPath_.contains(selectedItemInFileListWidget_)) return;
	currentPath_ = directory.getNextFolder(currentPath_, selectedItemInFileListWidget_, *ui.FileListWidget);
}

void GydriumEngine::createFileOnActionCreateFile()
{
	ui.InputFieldLineEdit->show();
	ui.CancelPushButton->show();
	ui.OkayPushButton->show();
	ui.FileListWidget->clear();
	ui.InputFieldLineEdit->setText("");
	isStatusCreateOrRename = true;
}

void GydriumEngine::createFileOnPushButtonCliked()
{
	if (isStatusCreateOrRename == true) {
		if (File::ñheckFileOrFolder(ui.InputFieldLineEdit->text()) == true) {
			Dir::createFolder(currentPath_, ui.InputFieldLineEdit->text());
		}
		else if (File::ñheckFileOrFolder(ui.InputFieldLineEdit->text()) == false) {
			File::createFile(currentPath_, ui.InputFieldLineEdit->text());
		}
		ui.InputFieldLineEdit->hide();
		ui.CancelPushButton->hide();
		ui.OkayPushButton->hide();
	} else if (isStatusCreateOrRename == false) {
		if (File::ñheckFileOrFolder(ui.InputFieldLineEdit->text()) == true) {
			Dir::changeFolderName(currentPath_, selectedItemInFileListWidget_, ui.InputFieldLineEdit->text());
		} else if(File::ñheckFileOrFolder(ui.InputFieldLineEdit->text()) == false) {
			File::changeFileName(currentPath_, selectedItemInFileListWidget_, ui.InputFieldLineEdit->text());
		}
	}
	ui.InputFieldLineEdit->hide();
	ui.CancelPushButton->hide();
	ui.OkayPushButton->hide();
	File::readFilesFromProject(currentPath_, *ui.FileListWidget);
}

void GydriumEngine::removeFileOrFolderOnPushButtonClicked()
{
	if (File::ñheckFileOrFolder(selectedItemInFileListWidget_) == false) {
		File::removeFileFromProject(currentPath_ + "\\" + selectedItemInFileListWidget_);
	} else if (File::ñheckFileOrFolder(selectedItemInFileListWidget_) == true) {
		Dir::removeFolderFromProject(currentPath_ + "\\" + selectedItemInFileListWidget_);
	}
	File::readFilesFromProject(currentPath_, *ui.FileListWidget);
}

void GydriumEngine::removeAllFilesOrFoldersOnPushButtonClicked()
{
	File::goThroughAllFilesAndFolders(currentPath_);
	File::readFilesFromProject(currentPath_, *ui.FileListWidget);
}


void GydriumEngine::findFolderOrFileOnQActionCliked()
{
	ui.InputFieldLineEdit->show();
	ui.CancelPushButton->show();
}

void GydriumEngine::findFolderOrFileWhenChangingText()
{
	if(ui.InputFieldLineEdit->text() == nullptr) File::readFilesFromProject(currentPath_, *ui.FileListWidget);
	File::findFile(currentPath_, ui.InputFieldLineEdit->text(), *ui.FileListWidget);
}

void GydriumEngine::changeFileNameOnActionCreateFile()
{
	isStatusCreateOrRename = false;

	ui.InputFieldLineEdit->show();
	ui.CancelPushButton->show();
	ui.OkayPushButton->show();
	ui.FileListWidget->clear();
	ui.InputFieldLineEdit->setText(selectedItemInFileListWidget_);
}

void GydriumEngine::updateFileListOnActionCreateFile()
{
	File::readFilesFromProject(currentPath_, *ui.FileListWidget);
}

void GydriumEngine::CancelInputOnPushButtonCliked()
{
	ui.InputFieldLineEdit->hide();
	ui.CancelPushButton->hide();
	ui.OkayPushButton->hide();
	File::readFilesFromProject(currentPath_, *ui.FileListWidget);
}

void GydriumEngine::CopyFileOrFolderOnQActionCliked()
{
	isStatusCopyOrCut = true;
	copyOrCutFrom = currentPath_;
	nameFileOrFolderToCopyOrCut = ui.FileListWidget->currentItem()->text();
}

void GydriumEngine::InsertFileOrFolderOnQActionCliked()
{
	copyOrCutTo = currentPath_;
	if (File::ñheckFileOrFolder(nameFileOrFolderToCopyOrCut) == false) {
		File::copyFile(copyOrCutFrom, copyOrCutTo, nameFileOrFolderToCopyOrCut);
		if (isStatusCopyOrCut == false) File::removeFileFromProject(copyOrCutFrom + "\\" + nameFileOrFolderToCopyOrCut);
	} else if (File::ñheckFileOrFolder(nameFileOrFolderToCopyOrCut) == true) {
		QDir dir(copyOrCutTo);
		dir.mkdir(nameFileOrFolderToCopyOrCut);
		Dir::copyFolder(copyOrCutFrom + "\\" + nameFileOrFolderToCopyOrCut, copyOrCutTo + "\\" + nameFileOrFolderToCopyOrCut);
		if (isStatusCopyOrCut == false) Dir::removeFolderFromProject(copyOrCutFrom + "\\" + nameFileOrFolderToCopyOrCut);
	}
	File::readFilesFromProject(currentPath_, *ui.FileListWidget);
}

void GydriumEngine::CutFileorFolderOnQActionCliked()
{
	isStatusCopyOrCut = false;
	copyOrCutFrom = currentPath_;
	nameFileOrFolderToCopyOrCut = ui.FileListWidget->currentItem()->text();
}

void GydriumEngine::SelectItemWhenClickItem()
{
	selectedItemInFileListWidget_ = ui.FileListWidget->currentItem()->text();
}

void GydriumEngine::FileOrFolderPropertiesQActionCliked()
{
	FileInformation* fileinfo = new FileInformation(currentPath_, selectedItemInFileListWidget_);
	fileinfo->setAttribute(Qt::WA_DeleteOnClose);
	fileinfo->show();
}

void GydriumEngine::OpenSettingsOnPushButtonCliked()
{
	Settngs* settings = new Settngs;
	settings->setAttribute(Qt::WA_DeleteOnClose);
	settings->show();
}

void GydriumEngine::OpenAboutDeveloperssOnQActionCliked()
{
	DeveloperInformation* dev = new DeveloperInformation;
	dev->setAttribute(Qt::WA_DeleteOnClose);
	dev->show();
}

void GydriumEngine::OpenViewTextureOnPushButtonCliked()
{
	ViewTexture* texture = new ViewTexture(pathToProject_ + "\\" + "textures");
	texture->setAttribute(Qt::WA_DeleteOnClose);
	texture->show();
}

void GydriumEngine::OpenCodeEditorOnQActionCliked()
{
	CodeEditor* code = new CodeEditor("");
	code->setAttribute(Qt::WA_DeleteOnClose);
	code->show();
}

void GydriumEngine::OpenFileInCodeEditorOnQActionCliked()
{
	CodeEditor* code = new CodeEditor(currentPath_ + "\\" + selectedItemInFileListWidget_);
	code->setAttribute(Qt::WA_DeleteOnClose);
	code->show();
}

GydriumEngine::~GydriumEngine()
{
}