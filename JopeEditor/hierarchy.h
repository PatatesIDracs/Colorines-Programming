#ifndef HIERARCHY_H
#define HIERARCHY_H

#include <QWidget>
#include <QVector>

namespace Ui {
class Hierarchy;
}

class GameObject;

class Hierarchy : public QWidget
{
    Q_OBJECT

public:
    explicit Hierarchy(QWidget *parent = nullptr);
    ~Hierarchy();

public slots:
    void CreateNewGO();

private:
    Ui::Hierarchy *ui;
    QVector<GameObject> objects;

private:
    void PrintObjects();

};

#endif // HIERARCHY_H
