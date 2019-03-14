#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QWidget>

namespace Ui {
class Transform;
}

class Transform : public QWidget
{
    Q_OBJECT

public:
    explicit Transform(QWidget *parent = 0);
    ~Transform();

    void SetPosition(double x, double y);
    void SetScale(double x, double y);

    double GetPosX();
    double GetPosY();
    double GetScaleX();
    double GetScaleY();

    //Get UI elements
    QWidget* GetTranslationXUI();
    QWidget* GetTranslationYUI();
    QWidget* GetScaleXUI();
    QWidget* GetScaleYUI();

private:
    Ui::Transform *ui;
};

#endif // TRANSFORM_H
