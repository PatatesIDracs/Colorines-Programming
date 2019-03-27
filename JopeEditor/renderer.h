#ifndef RENDERER_H
#define RENDERER_H

#include <QWidget>


class QLabel;
class QComboBox;
class QDoubleSpinBox;
class GameObject;
class QVBoxLayout;
class QHBoxLayout;
class QPushButton;

class Renderer : public QWidget
{
    Q_OBJECT
public:
    explicit Renderer(QWidget *parent = nullptr);
    ~Renderer();

    void Init();
    void InitDefaultLayout();

public:
    GameObject* current_go;

    QColor fill_color;
    QColor stroke_color;

//UI Elements
    //Labels----
    QLabel* shape_label;
    QLabel* height_label;
    QLabel* width_label;
    QLabel* radius_label;
    QLabel* fill_color_label;
    QLabel* stroke_color_label;
    QLabel* stroke_thick_label;
    QLabel* stroke_style_label;

    //Selectors---
    QComboBox* shape_box;
    QDoubleSpinBox* height_box;
    QDoubleSpinBox* width_box;
    QDoubleSpinBox* radius_box;
    QPushButton* fill_color_box;
    QPushButton* stroke_color_box;
    QDoubleSpinBox* stroke_thick_box;
    QComboBox* stroke_style_box;

    QVBoxLayout* layout;

public:
    Qt::PenStyle GetPenStyle() const;

signals:

public slots:
    void SelectFillColor();
    void SelectStrokeColor();

};

#endif // RENDERER_H
