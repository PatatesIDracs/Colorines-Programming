#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class Inspector;
class Scene;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void CreateNewScene();
    void OpenScene();
    void SaveScene();
    void UndoAction();
    void RedoAction();

private:
    Ui::MainWindow *ui;
    Inspector* inspector;
    Scene* scene;
};

#endif // MAINWINDOW_H
