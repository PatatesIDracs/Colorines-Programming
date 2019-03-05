#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QString>

class QPainter;

enum ShapeType
{
    UNKNOWN_SHAPE,
    POINT_SHAPE,
    LINE_SHAPE,
    RECT_SHAPE,
    CIRCLE_SHAPE,
    ELIPSE_SHAPE
};

class GameObject
{
public:
    GameObject(int i);

    void DrawGeo(QPainter* painter);

private:
    void DrawPoint(QPainter* painter);

public:
    QString name;
    ShapeType type;

};

#endif // GAMEOBJECT_H
