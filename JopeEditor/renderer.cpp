#include "renderer.h"
#include "gameobject.h"

#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>

Renderer::Renderer(QWidget *parent) :
    QWidget(parent)
{

    LabelInit();
    InitDefaultLayout();

}

Renderer::~Renderer()
{
}

void Renderer::LabelInit()
{
    shape_label = new QLabel("Shape");
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
      layout->addWidget(shape_label);
      layout->addWidget(height_label);
      layout->addWidget(width_label);
      layout->addWidget(radius_label);
      layout->addWidget(fill_color_label);
      layout->addWidget(stroke_color_label);
      layout->addWidget(stroke_thick_label);
      layout->addWidget(stroke_style_label);
      setLayout(layout);
}
