#include "gameobject.h"

GameObject::GameObject(int i)
{
    name = "New GameObject ";
    name.append(QString::number(i));
}
