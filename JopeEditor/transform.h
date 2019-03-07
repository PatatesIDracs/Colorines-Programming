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

    void SetPosition(float x, float y);    

    float GetPosX();
    float GetPosY();

    //Get UI elements
    QWidget* GetTranslationXUI();
    QWidget* GetTranslationYUI();

private:
    Ui::Transform *ui;
};

#endif // TRANSFORM_H
