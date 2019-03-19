#ifndef INSPECTOR_H
#define INSPECTOR_H

#include <QWidget>

class QLineEdit;
class QPushButton;
class Transform;
class QVBoxLayout;
class QSpacerItem;
class GameObject;
class Renderer;

class Inspector : public QWidget
{
    Q_OBJECT

public:
    explicit Inspector(QWidget *parent = nullptr);
    ~Inspector();

    void SetSelectedGO(GameObject* new_go);

signals:

    void SigGObjUpdate();

public:
    QLineEdit* name;
    QPushButton* add_renderer_butt;
    Transform* transform = nullptr;
    Renderer* renderer = nullptr;
    QVBoxLayout* layout;
    QSpacerItem* spacer;

    GameObject* current_go = nullptr;

public slots:

    void TextChanged(QString new_name);
    void TransformChanged();
    void AddRenderer();

};

#endif // INSPECTOR_H
