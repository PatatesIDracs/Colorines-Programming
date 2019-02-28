#ifndef INSPECTOR_H
#define INSPECTOR_H

#include <QWidget>

class QLineEdit;
class Transform;

class Inspector : public QWidget
{
    Q_OBJECT

public:
    explicit Inspector(QWidget *parent = nullptr);
    ~Inspector();


public:
    QLineEdit* name;
    Transform* transform;

public slots:

    void TextChanged(QString new_name);

};

#endif // INSPECTOR_H
