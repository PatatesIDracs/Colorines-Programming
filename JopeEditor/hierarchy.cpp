#include "hierarchy.h"
#include "ui_hierarchy.h"
#include "inspector.h"
#include "gameobject.h"
#include <iostream>
#include <QFileDialog>
#include <QDir>
#include "QPainter"
#include "renderer.h"
#include <QDoubleSpinBox>
#include <QComboBox>

Hierarchy::Hierarchy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hierarchy), count(0)
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
        case ShapeType::POINT_SHAPE:
            {
            QRect rect = drawnObject->GetRect();
            painter.drawPoint(rect.x(),rect.y());
            }
            break;
        case ShapeType::LINE_SHAPE:
            {
            QRect rect2 = drawnObject->GetRect();
            painter.drawLine(rect2.x(),rect2.y(),rect2.width(),rect2.height());
            }
            break;
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
    count++;
    int numObj = objects.size();

    selected = new GameObject(count);
    objects.push_back(selected);
    selected->renderer = new Renderer();


    inspector->SetSelectedGO(selected);
    ConnectGameObject(selected);

    ui->listWidget->addItem(selected->name);
    ui->listWidget->scrollToBottom();
    ui->listWidget->currentRowChanged(numObj);
    ui->listWidget->setCurrentRow(numObj);

    emit SigHierarchyUpdate(selected);
}

void Hierarchy::RemoveGO()
{
    for(int i = 0; i < objects.size(); i++)
    {
        if(objects[i] == selected)
        {
            objects.remove(i);
            delete ui->listWidget->takeItem(i);

            (i > 0) ? (i < objects.size())? selected = objects[i]: selected = objects[i-1] : selected = nullptr;

            inspector->SetSelectedGO(selected);
            break;
        }
    }

    emit SigHierarchyUpdate(nullptr);
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

void Hierarchy::OnNameChanged()
{
    for(uint i = 0; i < objects.size(); i++)
    {
        if(objects[i] == selected)
        {
            ui->listWidget->item(i)->setText(selected->name);
        }
    }
}

void Hierarchy::CreateNewScene()
{
    // Clear objects QVector
    inspector->SetSelectedGO(nullptr);
    qDeleteAll(objects.begin(), objects.end());
    objects.clear();

    // Clear listWidget items
    ui->listWidget->clear();

    selected = nullptr;

    count = 0;

    emit SigHierarchyUpdate(nullptr);
}

void Hierarchy::OpenScene()
{
    std::cout << "Open Scene" << std::endl;

    inspector->SetSelectedGO(nullptr);
    qDeleteAll(objects.begin(), objects.end());
    objects.clear();

    // Clear listWidget items
    ui->listWidget->clear();

    selected = nullptr;

    // Open file widget
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath());

    QFile f(file_name);

    if(!f.open(QFile::ReadOnly))
    {
        return;
    }

    QDataStream stream(&f);
    stream.setVersion(QDataStream::Qt_4_0);

    QString text;
    int numObj;
    stream >> text;
    stream >> count;
    stream >> numObj;

    if(numObj > 0){
        objects.reserve(numObj);
        uint i = 0;
        for(; i < numObj; i++)
        {
            GameObject* temp = new GameObject(i);

            temp->Load(stream);

            objects.push_back(temp);
            ui->listWidget->addItem(temp->name);
        }
        ui->listWidget->scrollToBottom();
        ui->listWidget->currentRowChanged(i-1);
        ui->listWidget->setCurrentRow(i-1);

        selected = objects[i-1];
        inspector->SetSelectedGO(selected);
        ConnectGameObject(selected);
    }

    f.close();

    emit SigHierarchyUpdate(nullptr);
}

void Hierarchy::SaveScene()
{
    std::cout << "Save Scene" << std::endl;

    // SaveScene
    QString file_name = QFileDialog::getSaveFileName(this, "Save file", "");

    if(!file_name.endsWith(".jope"))
        file_name += ".jope";

    QFile f(file_name);

    if(!f.open(QFile::WriteOnly))
    {
        return;
    }

    QDataStream outstream(&f);
    outstream << QString("Scene Gameobjects");
    outstream << count;
    outstream << objects.size();

    outstream.setVersion(QDataStream::Qt_4_0);

    for(uint i = 0; i < objects.size(); i++)
    {
        objects[i]->Save(outstream);
    }

    f.close();
}

void Hierarchy::ConnectGameObject(GameObject *target)
{
    connect(target->renderer->shape_box, SIGNAL(currentIndexChanged(int)),inspector,SLOT(EmitUpdate()));
    connect(target->renderer->height_box, SIGNAL(valueChanged(double)),inspector,SLOT(EmitUpdate()));
    connect(target->renderer->width_box, SIGNAL(valueChanged(double)),inspector,SLOT(EmitUpdate()));
    connect(target->renderer->radius_box, SIGNAL(valueChanged(double)),inspector,SLOT(EmitUpdate()));
    connect(target->renderer->fill_color_box, SIGNAL(clicked()),inspector,SLOT(EmitUpdate()));
    connect(target->renderer->stroke_color_box, SIGNAL(clicked()),inspector,SLOT(EmitUpdate()));
    connect(target->renderer->stroke_thick_box, SIGNAL(valueChanged(double)),inspector,SLOT(EmitUpdate()));
    connect(target->renderer->stroke_style_box, SIGNAL(currentIndexChanged(int)),inspector,SLOT(EmitUpdate()));
}
