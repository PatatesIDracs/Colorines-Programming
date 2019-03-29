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
    spacer = new QSpacerItem(1,1,QSizePolicy::Expanding,QSizePolicy::Expanding);
    transform = new Transform();



    //Set the layout
    layout = new QVBoxLayout;
    layout->addWidget(name);
    layout->addWidget(transform);
    layout->addItem(spacer);
    setLayout(layout);


    //Slot connections
    connect(name,SIGNAL(editingFinished()),this, SLOT(TextChanged()));
    connect(transform->GetTranslationXUI(), SIGNAL(valueChanged(double)), this, SLOT(TransformChanged()));
    connect(transform->GetTranslationYUI(), SIGNAL(valueChanged(double)), this, SLOT(TransformChanged()));
    connect(transform->GetScaleXUI(),SIGNAL(valueChanged(double)),this, SLOT(TransformChanged()));
    connect(transform->GetScaleYUI(),SIGNAL(valueChanged(double)),this, SLOT(TransformChanged()));
}

Inspector::~Inspector()
{
}

void Inspector::TextChanged()
{
    if(current_go != nullptr)
    {
        current_go->name = name->text();
        emit SigNameChanged();
    }
}

void Inspector::TransformChanged()
{
    if(current_go != nullptr)
    {
        current_go->SetPos(transform->GetPosX(), transform->GetPosY());
        current_go->SetScale(transform->GetScaleX(),transform->GetScaleY());
    }

    emit SigGObjUpdate();

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
        layout->addItem(spacer);
        current_go = nullptr;
    }

    if(new_go != nullptr)
    {
        name->setText(new_go->name);
        transform->show();
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
    }
    else
    {
        name->setText("");
        transform->hide();
    }

}
