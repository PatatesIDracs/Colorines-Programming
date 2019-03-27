#include "renderer.h"
#include "gameobject.h"

#include <QLabel>

#include <QVBoxLayout>
#include <QHBoxLayout>

Renderer::Renderer(QWidget *parent) :
    QWidget(parent)
{

    Init();
    InitDefaultLayout();
}

Renderer::~Renderer()
{
}

void Renderer::Init()
{
    shape_label = new QLabel("Shape");
    shape_box = new QComboBox();
    //Create shape Combo
    shape_box->addItem("Point", ShapeType::POINT_SHAPE);
    shape_box->addItem("Line", ShapeType::LINE_SHAPE);
    shape_box->addItem("Rect", ShapeType::RECT_SHAPE);
    shape_box->addItem("Circle", ShapeType::CIRCLE_SHAPE);
    shape_box->addItem("Ellipse", ShapeType::ELLIPSE_SHAPE);

    height_label = new QLabel("Height");
    width_label = new QLabel("Width");
    radius_label = new QLabel("Radius");
    fill_color_label = new QLabel("Fill color");
    stroke_color_label = new QLabel("Stroke color");
    stroke_thick_label = new QLabel("Stroke thick");
    stroke_style_label = new QLabel("Stroke style");
}

void Renderer::InitDefaultLayout()
{
      layout = new QVBoxLayout();
      QHBoxLayout* shape_layout = new QHBoxLayout();
      shape_layout->addWidget(shape_label);
      shape_layout->addWidget(shape_box);
      layout->addLayout(shape_layout);
      //layout->addWidget(shape_label);
      //layout->addWidget(shape_box);
      layout->addWidget(height_label);
      layout->addWidget(width_label);
      layout->addWidget(radius_label);
      layout->addWidget(fill_color_label);
      layout->addWidget(stroke_color_label);
      layout->addWidget(stroke_thick_label);
      layout->addWidget(stroke_style_label);
      setLayout(layout);
}
