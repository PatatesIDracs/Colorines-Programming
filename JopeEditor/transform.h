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

private:
    Ui::Transform *ui;
};

#endif // TRANSFORM_H
