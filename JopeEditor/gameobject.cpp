#include "gameobject.h"
#include "renderer.h"
#include <QPainter>
#include <QDataStream>
#include <iostream>

//Renderer includes (To read renderer data)
#include <QComboBox>
#include <QDoubleSpinBox>

GameObject::GameObject(int i) : type(ELLIPSE_SHAPE)
{
    name = "New GameObject ";
    name.append(QString::number(i));

    //test
    pos.setX(50);
    pos.setY(75);

    scale.setX(1);
    scale.setY(2);

    size.setX(50);
    size.setY(50);

    //Init Renderer
   // renderer = new Renderer();
}

void GameObject::DrawGeo(QBrush &brush,QPen &pen)
{
    brush.setColor(GetFillColor());
    brush.setStyle(Qt::BrushStyle::SolidPattern);

    pen.setWidth(GetStrokeThickness());
    pen.setColor(GetStrokeColor());
    pen.setStyle(GetStrokeStyle());

}

void GameObject::Save(QDataStream &outstream)
{
    outstream << name;
    outstream << static_cast<int>(type);

    outstream << pos;
    outstream << scale;
    outstream << size;
}

void GameObject::Load(QDataStream &stream)
{
    stream >> name;

    int i = 0;
    stream >> i;
    type = static_cast<ShapeType>(i);

    stream >> pos;
    stream >> scale;
    stream >> size;
}


void GameObject::SetPos(float x, float y)
{
    pos.setX(x);
   // qDebug("Pos X: %f", pos.x());
    pos.setY(y);
    // qDebug("Pos Y: %f", pos.y());

}

void GameObject::SetScale(float x, float y)
{
    scale.setX(x);
    scale.setY(y);
}

ShapeType GameObject::GetShape() const
{
    if(renderer != nullptr)
    {
        return (ShapeType)renderer->shape_box->currentData().toInt();
    }
    return UNKNOWN_SHAPE;
}

QRect GameObject::GetRect() const
{
    return QRect(pos.x(),pos.y(), GetWidth()*scale.x(), GetHeight()*scale.y());
}

QRect GameObject::GetCircle() const
{
    int x = static_cast<int>(pos.x() - size.x()*scale.x());
    int y = static_cast<int>(pos.y() - size.x()*scale.x());
    int w = static_cast<int>(GetRadius()*2*scale.x());
    return  QRect(x,y,w,w);
}

QRect GameObject::GetEllipse() const
{
    int x = static_cast<int>(pos.x() - size.x()*scale.x());
    int y = static_cast<int>(pos.y() - size.x()*scale.y());
    int w = static_cast<int>(size.x()*scale.x())*2;
    int h = static_cast<int>(size.x()*scale.y())*2;
    return  QRect(x,y,w,h);

}

QColor GameObject::GetFillColor() const
{
    if(renderer != nullptr)
    {
    return renderer->fill_color;
    }
    return Qt::blue;

}

QColor GameObject::GetStrokeColor() const
{
    if(renderer != nullptr)
    {
    return  renderer->stroke_color;
    }
    return Qt::black;
}

float GameObject::GetStrokeThickness() const
{
    if(renderer != nullptr)
    {
    return  renderer->stroke_thick_box->value();
    }
    return 0.f;
}

Qt::PenStyle GameObject::GetStrokeStyle() const
{
    if(renderer != nullptr)
    {
    return  renderer->GetPenStyle();
    }
    return Qt::SolidLine;
}

float GameObject::GetHeight() const
{
    if(renderer != nullptr)
    {
        return (float)renderer->height_box->value();
    }
    return 0.f;
}

float GameObject::GetWidth() const
{
    if(renderer != nullptr)
    {
        return (float)renderer->width_box->value();
    }
    return 0.f;
}

float GameObject::GetRadius() const
{
    if(renderer != nullptr)
    {
        return (float)renderer->radius_box->value();
    }
    return 0.f;
}
