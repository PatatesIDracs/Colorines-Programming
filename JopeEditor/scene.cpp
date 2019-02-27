#include "scene.h"
#include <QPainter>


Scene::Scene(QWidget *parent) : QWidget (parent)
{
    setAutoFillBackground(true);
}

QSize Scene::sizeHint() const
{
    return QSize(256,256);
}

QSize Scene::minimumSizeHint() const
{
    return QSize(64,64);
}

void Scene::paintEvent(QPaintEvent *event)
{



}
