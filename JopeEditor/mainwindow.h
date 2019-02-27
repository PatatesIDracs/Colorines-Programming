#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class Inspector;

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
};

#endif // MAINWINDOW_H
