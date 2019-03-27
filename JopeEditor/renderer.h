#ifndef RENDERER_H
#define RENDERER_H

#include <QWidget>
#include <QComboBox>

class QLabel;
//class QComboBox;
class GameObject;
class QVBoxLayout;
class QHBoxLayout;

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
   // QHBoxLayout* shape_layout;

    QVBoxLayout* layout;
signals:

public slots:
};

#endif // RENDERER_H
