#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QString>
#include <QVector2D>

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

    void DrawGeo(QBrush &brush, QPen &pen);

    void SetPos(float x, float y);
    void SetScale(float x, float y);

public:
    QString name;
    QVector2D pos;
    QVector2D scale;
    ShapeType type;

};

#endif // GAMEOBJECT_H
