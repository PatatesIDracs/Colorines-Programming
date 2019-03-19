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
    QColor blueColor = QColor::fromRgb(127,190,220);
    QColor whiteColor = QColor::fromRgb(255,255,255);
    QColor blackColor = QColor::fromRgb(0,0,0);

    hierarchy->DrawHierarchy(this);

    std::cout << "Updated Scene" << std::endl;

}
