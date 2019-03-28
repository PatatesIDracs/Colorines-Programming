#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QString>
#include <QVector2D>

class QDataStream;
class QPainter;
class Renderer;



enum ShapeType
{
    UNKNOWN_SHAPE,
    POINT_SHAPE,
    LINE_SHAPE,
    RECT_SHAPE,
    CIRCLE_SHAPE,
    ELLIPSE_SHAPE
};

class GameObject
{
public:
    GameObject(int i);

    void DrawGeo(QBrush &brush, QPen &pen);

    void Save(QDataStream &stream);
    void Load(QDataStream &stream);

    // Transform Methods
    void SetPos(float x, float y);
    void SetScale(float x, float y);

    // Shape Methods
    ShapeType GetShape() const;
    QRect GetRect() const;
    QRect GetCircle() const;
    QRect GetEllipse() const;
    QColor GetFillColor() const;
    QColor GetStrokeColor() const;
    float GetStrokeThickness() const;
    Qt::PenStyle GetStrokeStyle() const;

    float GetHeight() const;
    float GetWidth() const;
    float GetRadius() const;

public:
    // Transform
    QString name;
    QVector2D pos;
    QVector2D scale;

    // Shape
    ShapeType type;
    QVector2D size;

    Renderer* renderer = nullptr;
};

#endif // GAMEOBJECT_H
