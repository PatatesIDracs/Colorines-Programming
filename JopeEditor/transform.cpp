#include "transform.h"
#include "ui_transform.h"

Transform::Transform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transform)
{
    ui->setupUi(this);
}

Transform::~Transform()
{
    delete ui;
}

void Transform::SetPosition(float x, float y)
{
    ui->translate_x->setValue(x);
    ui->translate_y->setValue(y);
}

float Transform::GetPosX()
{
    return ui->translate_x->value();
}

float Transform::GetPosY()
{
    return ui->translate_y->value();
}

QWidget *Transform::GetTranslationXUI()
{
    return ui->translate_x;
}

QWidget *Transform::GetTranslationYUI()
{
    return ui->translate_y;
}
