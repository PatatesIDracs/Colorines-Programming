#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scene.h"
#include "inspector.h"
#include "hierarchy.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Scene();
    setCentralWidget(scene);

    //Add Inspector widget
    inspector = new Inspector();
    ui->dock_inspector->setWidget(inspector);

    //Add Hierarchy widget
    hierarchy = new Hierarchy();
    ui->dock_hierachy->setWidget(hierarchy);

    //Connect Actions triggered() signals to Slots
    connect(ui->actionCreate_new_scene, SIGNAL(triggered()), this, SLOT(CreateNewScene()));
    connect(ui->actionOpen_File, SIGNAL(triggered()), this, SLOT(OpenScene()));
    connect(ui->actionSave_Scene, SIGNAL(triggered()), this, SLOT(SaveScene()));
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));

    //Maybe we should change the reciver to editor/inspector class
    connect(ui->actionUndo, SIGNAL(triggered()), this, SLOT(UndoAction()));
    connect(ui->actionRedo, SIGNAL(triggered()), this, SLOT(RedoAction()));

    //Hide Icons from MenuBar
    qApp->instance()->setAttribute(Qt::AA_DontShowIconsInMenus, true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreateNewScene()
{
    std::cout << "Create New Scene" << std::endl;
}

void MainWindow::OpenScene()
{
    std::cout << "Open Scene" << std::endl;
}

void MainWindow::SaveScene()
{
    std::cout << "Save Scene" << std::endl;
}

void MainWindow::UndoAction()
{
    std::cout << "Undo Action" << std::endl;
}

void MainWindow::RedoAction()
{
    std::cout << "Redo Action" << std::endl;
}
