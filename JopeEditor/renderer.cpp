#include "renderer.h"
#include "gameobject.h"

#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QColorDialog>
#include <QDoubleSpinBox>
#include <QVBoxLayout>
#include <QHBoxLayout>

Renderer::Renderer(QWidget *parent) :
    QWidget(parent)
{

    Init();
    InitDefaultLayout();
    InitDefaultValues();

    connect(fill_color_box, SIGNAL(released()),this, SLOT(SelectFillColor()));
    connect(stroke_color_box, SIGNAL(released()),this, SLOT(SelectStrokeColor()));
}

Renderer::~Renderer()
{
}

void Renderer::Init()
{
    shape_label = new QLabel("Shape");
    shape_box = new QComboBox();
    height_box = new QDoubleSpinBox();
    width_box = new QDoubleSpinBox();
    radius_box = new QDoubleSpinBox();
    fill_color_box = new QPushButton();
    stroke_color_box = new QPushButton();
    stroke_thick_box = new QDoubleSpinBox();
    stroke_style_box = new QComboBox();

    height_box->setMaximum(9999);
    width_box->setMaximum(9999);
    radius_box->setMaximum(9999);

    //Create shape Combo
    shape_box->addItem("Point", ShapeType::POINT_SHAPE);
    shape_box->addItem("Line", ShapeType::LINE_SHAPE);
    shape_box->addItem("Rect", ShapeType::RECT_SHAPE);
    shape_box->addItem("Circle", ShapeType::CIRCLE_SHAPE);
    shape_box->addItem("Ellipse", ShapeType::ELLIPSE_SHAPE);

    //Style Combo
    stroke_style_box->addItem("Solid", 1);
    stroke_style_box->addItem("Dash", 2);
    stroke_style_box->addItem("Dot", 3);
    stroke_style_box->addItem("Dash-Dot", 4);
    stroke_style_box->addItem("Dash-Dot-Dot", 5);

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

      QHBoxLayout* height_layout = new QHBoxLayout();
      QHBoxLayout* width_layout = new QHBoxLayout();
      height_layout->addWidget(height_label);
      height_layout->addWidget(height_box);
      width_layout->addWidget(width_label);
      width_layout->addWidget(width_box);
      layout->addLayout(height_layout);
      layout->addLayout(width_layout);

      QHBoxLayout* radius_layout = new QHBoxLayout();
      radius_layout->addWidget(radius_label);
      radius_layout->addWidget(radius_box);
      layout->addLayout(radius_layout);

      QHBoxLayout* fill_color_layout = new QHBoxLayout();
      QHBoxLayout* stroke_color_layout = new QHBoxLayout();
      QHBoxLayout* stroke_thick_layout = new QHBoxLayout();
      QHBoxLayout* stroke_style_layout = new QHBoxLayout();
      fill_color_layout->addWidget(fill_color_label);
      fill_color_layout->addWidget(fill_color_box);
      stroke_color_layout->addWidget(stroke_color_label);
      stroke_color_layout->addWidget(stroke_color_box);
      stroke_thick_layout->addWidget(stroke_thick_label);
      stroke_thick_layout->addWidget(stroke_thick_box);
      stroke_style_layout->addWidget(stroke_style_label);
      stroke_style_layout->addWidget(stroke_style_box);
      layout->addLayout(fill_color_layout);
      layout->addLayout(stroke_color_layout);
      layout->addLayout(stroke_thick_layout);
      layout->addLayout(stroke_style_layout);

      setLayout(layout);
}

void Renderer::InitDefaultValues()
{
    fill_color = Qt::blue;
    QString bg_color = QString("background-color:%1").arg(fill_color.name());
    fill_color_box->setStyleSheet(bg_color);
    fill_color_box->clicked();

    stroke_color = Qt::black;
    bg_color = QString("background-color:%1").arg(stroke_color.name());
    stroke_color_box->setStyleSheet(bg_color);
    stroke_color_box->clicked();

    shape_box->setCurrentIndex(2);//Rect
    height_box->setValue(50.f);
    width_box->setValue(50.f);
    radius_box->setValue(50.f);
}

void Renderer::Save(QDataStream &outstream)
{
    //Shape
    outstream << shape_box->currentIndex();
    //Height
    outstream << height_box->value();
    //Width
    outstream << width_box->value();
    //Radius
    outstream << radius_box->value();
    //FillColor
    outstream << fill_color;
    //StrokeColor
    outstream << stroke_color;
    //StrokeThickness
    outstream << stroke_thick_box->value();
    //StrokeStyle
    outstream << stroke_style_box->currentIndex();
}

void Renderer::Load(QDataStream &instream)
{
    int temp_index = 0;
    //Shape
    instream >> temp_index;
    shape_box->setCurrentIndex(temp_index);

    //Height, width and radius
    double temp;
    instream >> temp;
    height_box->setValue(temp);
    instream >> temp;
    width_box->setValue(temp);
    instream >> temp;
    radius_box->setValue(temp);

    instream >> fill_color;
    instream >> stroke_color;
    instream >> temp;
    stroke_thick_box->setValue(temp);
    instream >> temp_index;
    stroke_style_box->setCurrentIndex(temp_index);

}

Qt::PenStyle Renderer::GetPenStyle() const
{
    return (Qt::PenStyle)stroke_style_box->currentData().toInt();
}

void Renderer::SelectFillColor()
{
    fill_color = QColorDialog::getColor(Qt::white, this);
    QString bg_color = QString("background-color:%1").arg(fill_color.name());
    fill_color_box->setStyleSheet(bg_color);
    fill_color_box->clicked();
}

void Renderer::SelectStrokeColor()
{
    stroke_color = QColorDialog::getColor(stroke_color, this);
    QString bg_color = QString("background-color:%1").arg(stroke_color.name());
    stroke_color_box->setStyleSheet(bg_color);
    stroke_color_box->clicked();
}
