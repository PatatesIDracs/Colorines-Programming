#ifndef HIERARCHY_H
#define HIERARCHY_H

#include <QWidget>
#include <QVector>
#include <QListWidgetItem>

namespace Ui {
class Hierarchy;
}

class Inspector;
class GameObject;

class Hierarchy : public QWidget
{
    Q_OBJECT

public:
    explicit Hierarchy(QWidget *parent = nullptr);
    ~Hierarchy();

    void DrawHierarchy(QWidget* scene);

signals:

    void SigHierarchyUpdate(GameObject*);

public slots:
    void CreateNewGO();
    void RemoveGO();

    void OnItemClicked();
    void OnNameChanged();

    void CreateNewScene();
    void OpenScene();
    void SaveScene();

public:
    Inspector* inspector;

private:
    Ui::Hierarchy *ui;
    QVector<GameObject*> objects;

    GameObject* selected;

    uint count;
private:
    void PrintObjects();
    void ConnectGameObject(GameObject* target);

};

#endif // HIERARCHY_H
