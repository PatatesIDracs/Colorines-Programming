#include "inspector.h"
#include "transform.h"
#include "gameobject.h"
#include "renderer.h"

#include <QLayout>
#include <QBoxLayout>
#include <QSpacerItem>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <iostream>


Inspector::Inspector(QWidget *parent) :
    QWidget(parent)
{

    //Subwidgets --> Add transform and others
    name = new QLineEdit();
    add_renderer_butt = new QPushButton("Add renderer");
    spacer = new QSpacerItem(1,1,QSizePolicy::Expanding,QSizePolicy::Expanding);
    transform = new Transform();



    //Set the layout
    layout = new QVBoxLayout;
    layout->addWidget(name);
    layout->addWidget(transform);
    layout->addWidget(add_renderer_butt);
    layout->addItem(spacer);
    setLayout(layout);


    //Slot connections
    connect(name,SIGNAL(textEdited(QString)),this, SLOT(TextChanged(QString)));
    connect(add_renderer_butt, SIGNAL(pressed()),this,SLOT(AddRenderer()));
    connect(transform->GetTranslationXUI(), SIGNAL(valueChanged(double)), this, SLOT(TransformChanged()));
    connect(transform->GetTranslationYUI(), SIGNAL(valueChanged(double)), this, SLOT(TransformChanged()));
    connect(transform->GetScaleXUI(),SIGNAL(valueChanged(double)),this, SLOT(TransformChanged()));
    connect(transform->GetScaleYUI(),SIGNAL(valueChanged(double)),this, SLOT(TransformChanged()));
}

Inspector::~Inspector()
{
}

void Inspector::TextChanged(QString new_name)
{
    name->setText(new_name);
    if(current_go != nullptr)
    {
        current_go->name = new_name;
    }
}

void Inspector::TransformChanged()
{
    std::cout << "Transform Changed" << std::endl;

    if(current_go != nullptr)
    {
        current_go->SetPos(transform->GetPosX(), transform->GetPosY());
        current_go->SetScale(transform->GetScaleX(),transform->GetScaleY());
    }

    emit SigGObjUpdate();

}

void Inspector::AddRenderer()
{
    if(current_go == nullptr)
        return;
    if(current_go->renderer == nullptr)
    {
        current_go->renderer = new Renderer();
        connect(current_go->renderer->shape_box, SIGNAL(currentIndexChanged(int)),this,SLOT(EmitUpdate()));
        connect(current_go->renderer->height_box, SIGNAL(valueChanged(double)),this,SLOT(EmitUpdate()));
        connect(current_go->renderer->width_box, SIGNAL(valueChanged(double)),this,SLOT(EmitUpdate()));
        connect(current_go->renderer->radius_box, SIGNAL(valueChanged(double)),this,SLOT(EmitUpdate()));
        connect(current_go->renderer->fill_color_box, SIGNAL(clicked()),this,SLOT(EmitUpdate()));
        connect(current_go->renderer->stroke_color_box, SIGNAL(clicked()),this,SLOT(EmitUpdate()));
        connect(current_go->renderer->stroke_thick_box, SIGNAL(valueChanged(double)),this,SLOT(EmitUpdate()));
        connect(current_go->renderer->stroke_style_box, SIGNAL(currentIndexChanged(int)),this,SLOT(EmitUpdate()));
        layout->removeItem(spacer);
        layout->removeWidget(add_renderer_butt);
        add_renderer_butt->hide();
        layout->addWidget(current_go->renderer);
        layout->addItem(spacer);
    }
}

void Inspector::EmitUpdate()
{
    emit SigGObjUpdate();
}

void Inspector::SetSelectedGO(GameObject* new_go)
{
    if(current_go != nullptr)
    {
        layout->removeItem(spacer);
        if(current_go->renderer != nullptr)
        {
            layout->removeWidget(current_go->renderer);
            current_go->renderer->hide();
        }
        else
        {
         layout->removeWidget(add_renderer_butt);
         add_renderer_butt->hide();
        }
        layout->addItem(spacer);

        current_go = nullptr;
    }

    if(new_go != nullptr)
    {
        name->setText(new_go->name);
        transform->SetPosition(new_go->pos.x(), new_go->pos.y());
        transform->SetScale(new_go->scale.x(), new_go->scale.y());
        current_go = new_go;
        if(current_go->renderer != nullptr)
        {
            layout->removeItem(spacer);
            layout->addWidget(current_go->renderer);
            current_go->renderer->show();
            layout->addItem(spacer);
        }
        else
        {
            layout->removeItem(spacer);
            layout->addWidget(add_renderer_butt);
            add_renderer_butt->show();
            layout->addItem(spacer);
        }
    }

}
