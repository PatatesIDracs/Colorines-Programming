#ifndef RENDERER_H
#define RENDERER_H

#include <QWidget>

class QLabel;
class QComboBox;
class GameObject;
class QVBoxLayout;

class Renderer : public QWidget
{
    Q_OBJECT
public:
    explicit Renderer(QWidget *parent = nullptr);
    ~Renderer();

    void LabelInit();
    void InitDefaultLayout();

public:
    GameObject* current_go;

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

    QVBoxLayout* layout;
signals:

public slots:
};

#endif // RENDERER_H
