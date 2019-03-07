#include "gameobject.h"
#include <QPainter>

GameObject::GameObject(int i) : type(POINT_SHAPE)
{
    name = "New GameObject ";
    name.append(QString::number(i));

}

void GameObject::DrawGeo(QPainter* painter)
{
    switch (type) {
    case POINT_SHAPE:
        DrawPoint(painter);
        break;
    case LINE_SHAPE:

        break;
    case RECT_SHAPE:

        break;
    case CIRCLE_SHAPE:

        break;
    case ELIPSE_SHAPE:

        break;
    default:
        break;
    }
}

void GameObject::DrawPoint(QPainter* painter)
{
    QColor blueColor = QColor::fromRgb(100,100,100);

    QBrush brush;
    QPen pen;

    //Brush/Pen configuration
    brush.setColor(blueColor);
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    pen.setStyle(Qt::PenStyle::NoPen);
    painter->drawPoint(50,75);

}

void GameObject::SetPos(float x, float y)
{
    pos.setX(x);
   // qDebug("Pos X: %f", pos.x());
    pos.setY(y);
   // qDebug("Pos Y: %f", pos.y());
}
