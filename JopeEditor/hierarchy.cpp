#include "hierarchy.h"
#include "ui_hierarchy.h"
#include "inspector.h"
#include "gameobject.h"
#include <iostream>

Hierarchy::Hierarchy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hierarchy)
{
    ui->setupUi(this);

    connect(ui->button_addEntity,SIGNAL(clicked()),this,SLOT(CreateNewGO()));
    connect(ui->button_removeEntity, SIGNAL(clicked()), this, SLOT(RemoveGO()));

    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(OnItemClicked()));
}

Hierarchy::~Hierarchy()
{
    qDeleteAll(objects.begin(), objects.end());
    objects.clear();

    delete ui;
}

void Hierarchy::DrawHierarchy(QPainter* painter)
{
    for(int i = 0; i < objects.size(); i++)
    {
        objects[i]->DrawGeo(painter);
    }
}

void Hierarchy::CreateNewGO()
{
    int numObj = objects.size();

    selected = new GameObject(numObj);
    objects.push_back(selected);
    ui->listWidget->addItem(selected->name);
}

void Hierarchy::RemoveGO()
{
    for(int i = 0; i < objects.size(); i++)
    {
        if(objects[i] == selected)
        {
            objects.remove(i);
            delete ui->listWidget->takeItem(ui->listWidget->row(ui->listWidget->currentItem()));
            break;
        }
    }
}

void Hierarchy::OnItemClicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();

    int size = ui->listWidget->count();
    for(int i = 0; i < size; i++)
    {
        if(item == ui->listWidget->item(i))
        {
            selected = objects[i];
            break;
        }
    }
    inspector->SetSelectedGO(selected);
}

void Hierarchy::CreateNewScene()
{
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
