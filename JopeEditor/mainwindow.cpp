#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inspector.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //Add Inspector widget
    inspector = new Inspector();
    ui->dock_inspector->setWidget(inspector);
}

MainWindow::~MainWindow()
{
    delete ui;
}
