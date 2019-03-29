#include "scene.h"
#include "hierarchy.h"

#include <QPainter>
#include <iostream>
// TODO delete QPainter


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

void Scene::paintEvent(QPaintEvent *)
{
    // Draw Hierarchy with QPainter
    hierarchy->DrawHierarchy(this);
}
