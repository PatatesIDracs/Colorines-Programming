#include "gameobject.h"
#include <QPainter>

GameObject::GameObject(int i) : type(POINT_SHAPE)
{
    name = "New GameObject ";
    name.append(QString::number(i));

}

void GameObject::DrawGeo(QBrush &brush,QPen &pen)
{
    brush.setColor(QColor::fromRgb(127,190,220));
    brush.setStyle(Qt::BrushStyle::SolidPattern);

    pen.setWidth(4);
    pen.setColor(QColor::fromRgb(127,190,220));
    pen.setStyle(Qt::PenStyle::NoPen);

}

void GameObject::SetPos(float x, float y)
{
    pos.setX(x);
   // qDebug("Pos X: %f", pos.x());
    pos.setY(y);
   // qDebug("Pos Y: %f", pos.y());
}
