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

    scene->hierarchy = hierarchy;

    //Connect Actions triggered() signals to Slots
    connect(ui->actionCreate_new_scene, SIGNAL(triggered()), hierarchy, SLOT(CreateNewScene()));
    connect(ui->actionOpen_File, SIGNAL(triggered()), hierarchy, SLOT(OpenScene()));
    connect(ui->actionSave_Scene, SIGNAL(triggered()), hierarchy, SLOT(SaveScene()));
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));

    //Maybe we should change the reciver to editor/inspector class
    connect(ui->actionUndo, SIGNAL(triggered()), hierarchy, SLOT(UndoAction()));
    connect(ui->actionRedo, SIGNAL(triggered()), hierarchy, SLOT(RedoAction()));

    //Hide Icons from MenuBar
    qApp->instance()->setAttribute(Qt::AA_DontShowIconsInMenus, true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

