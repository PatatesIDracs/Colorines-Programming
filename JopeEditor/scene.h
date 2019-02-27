#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QWidget>

class Scene : public QWidget
{
    Q_OBJECT
public:
    explicit Scene(QWidget *parent = nullptr);

    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

signals:

public slots:


private:

    void paintEvent(QPaintEvent* event) override;
};

#endif // SCENE_H