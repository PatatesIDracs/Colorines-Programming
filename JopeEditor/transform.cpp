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

void Transform::SetScale(double x, double y)
{
    ui->scale_x->setValue(x);
    ui->scale_y->setValue(y);
}

void Transform::SetPosition(double x, double y)
{
    ui->translate_x->setValue(x);
    ui->translate_y->setValue(y);
}

double Transform::GetPosX()
{
    return ui->translate_x->value();
}

double Transform::GetPosY()
{
    return ui->translate_y->value();
}

double Transform::GetScaleX()
{
    return ui->scale_x->value();
}

double Transform::GetScaleY()
{
    return ui->scale_y->value();
}

QWidget *Transform::GetTranslationXUI()
{
    return ui->translate_x;
}

QWidget *Transform::GetTranslationYUI()
{
    return ui->translate_y;
}

QWidget *Transform::GetScaleXUI()
{
    return ui->scale_x;
}

QWidget *Transform::GetScaleYUI()
{
    return  ui->scale_y;
}
