#include "hierarchy.h"
#include "ui_hierarchy.h"
#include "inspector.h"
#include "gameobject.h"
#include <iostream>
#include "QPainter"

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

void Hierarchy::DrawHierarchy(QWidget* scene)
{
    QPainter painter(scene);

    QBrush  brush;
    QPen    pen;

    GameObject* drawnObject = nullptr;
    for(int i = 0; i < objects.size(); i++)
    {
        drawnObject = objects[i];
        drawnObject->DrawGeo(brush, pen);
        painter.setBrush(brush);
        painter.setPen(pen);

        switch (drawnObject->GetShape()) {
        case ShapeType::RECT_SHAPE:
            painter.drawRect(drawnObject->GetRect());
            break;
        case ShapeType::CIRCLE_SHAPE:
            painter.drawEllipse(drawnObject->GetCircle());
            break;
        case ShapeType::ELLIPSE_SHAPE:
            painter.drawEllipse(drawnObject->GetEllipse());
            break;
        default:
            break;
        }
    }
}

void Hierarchy::CreateNewGO()
{
    int numObj = objects.size();

    GameObject* temp = new GameObject(numObj);
    objects.push_back(temp);
    ui->listWidget->addItem(temp->name);

    emit SigObjectAdded(temp);


}

void Hierarchy::RemoveGO()
{
    for(int i = 0; i < objects.size(); i++)
    {
        if(objects[i] == selected)
        {
            objects.remove(i);
            delete ui->listWidget->takeItem(ui->listWidget->row(ui->listWidget->currentItem()));
            selected =nullptr;
            break;
        }
    }
    emit SigObjectAdded(nullptr);
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
