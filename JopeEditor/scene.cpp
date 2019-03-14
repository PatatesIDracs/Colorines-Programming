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

    /*QBrush brush;
    QPen pen;

    //Brush/Pen configuration
    brush.setColor(blueColor);
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    pen.setStyle(Qt::PenStyle::NoPen);
    painter.setBrush(brush);
    painter.setPen(pen);

    painter.drawRect(rect());

    //Brush/Pen configuration
    brush.setColor(whiteColor);
    pen.setWidth(4);
    pen.setColor(blackColor);
    pen.setStyle(Qt::PenStyle::DashLine);
    painter.setBrush(brush);
    painter.setPen(pen);

    int r = 64;
    int w = r * 2;
    int h = r * 2;
    int x = rect().width() / 3 - r;
    int y = rect().height() / 2 - r;
    QRect circleRect(x,y,w,h);
    painter.drawEllipse(circleRect);*/
}
