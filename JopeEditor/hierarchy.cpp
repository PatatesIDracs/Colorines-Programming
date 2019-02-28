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
    connect(ui->button_removeEntity, SIGNAL(clicked()), this, SLOT(RemoveGO()));

    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(itemClicked(QListWidgetItem*)));
}

Hierarchy::~Hierarchy()
{
    qDeleteAll(objects.begin(), objects.end());
    objects.clear();

    delete ui;
}

void Hierarchy::CreateNewGO()
{
    int numObj = objects.size();

    objects.push_back(new GameObject(numObj));
    ui->listWidget->addItem(objects[numObj]->name);

    std::cout << "Added GO: " << numObj << std::endl;
}

void Hierarchy::RemoveGO()
{
    for(uint i = objects.size(); i > 0; i--)
    {
        if(objects[i] == selected)
        {
            for(uint j = i; j < objects.size()-1; j++)
            {
                objects[j] = objects[j+1];
            }
            objects.pop_back();
            break;
        }
    }
}

void Hierarchy::OnItemClicked(QListWidgetItem *itemSelected)
{
    //QModelIndex index = ui->listWidget->indexFromItem(itemSelected);
    //selected = objects[index];
}

void Hierarchy::CreateNewScene()
{
    std::cout << "Create New Scene" << std::endl;

    // Clear objects QVector
    qDeleteAll(objects.begin(), objects.end());
    objects.clear();

    // Clear listWidget items
    ui->listWidget->clear();
}

void Hierarchy::OpenScene()
{
    std::cout << "Open Scene" << std::endl;

    // Open file widget

}

void Hierarchy::SaveScene()
{
    std::cout << "Save Scene" << std::endl;
}

void Hierarchy::UndoAction()
{
    std::cout << "Undo Action" << std::endl;

}

void Hierarchy::RedoAction()
{
    std::cout << "Redo Action" << std::endl;
}
