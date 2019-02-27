#include "hierarchy.h"
#include "ui_hierarchy.h"
#include "gameobject.h"
#include <iostream>

Hierarchy::Hierarchy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hierarchy)
{
    ui->setupUi(this);


    connect(ui->button_addEntity,SIGNAL(clicked()),this,SLOT(CreateNewGO()));
}

Hierarchy::~Hierarchy()
{
    delete ui;
}

void Hierarchy::CreateNewGO()
{
    objects.push_back(GameObject());

    std::cout << "Added GO" << std::endl;
}
