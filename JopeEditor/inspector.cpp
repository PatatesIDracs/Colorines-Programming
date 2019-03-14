#include "inspector.h"
#include "transform.h"
#include "gameobject.h"

#include <QLayout>
#include <QBoxLayout>
#include <QSpacerItem>
#include <QLineEdit>
#include <QPushButton>
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
    connect(name,SIGNAL(textEdited(QString)),this, SLOT(TextChanged(QString)));
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

}

void Inspector::SetSelectedGO(GameObject* new_go)
{
    current_go = nullptr;
    name->setText(new_go->name);
    transform->SetPosition(new_go->pos.x(), new_go->pos.y());
    transform->SetScale(new_go->scale.x(), new_go->scale.y());
    current_go = new_go;
}
