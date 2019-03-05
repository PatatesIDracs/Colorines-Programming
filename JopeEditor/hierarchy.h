#ifndef HIERARCHY_H
#define HIERARCHY_H

#include <QWidget>
#include <QVector>
#include <QListWidgetItem>

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

    void DrawHierarchy(QPainter* painter);

public slots:
    void CreateNewGO();
    void RemoveGO();

    void OnItemClicked();

    void CreateNewScene();
    void OpenScene();
    void SaveScene();
    void UndoAction();
    void RedoAction();


private:
    Ui::Hierarchy *ui;
    QVector<GameObject*> objects;

    GameObject* selected;

private:
    void PrintObjects();

};

#endif // HIERARCHY_H
