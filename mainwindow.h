#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include <vector>
#include "Shape.h"
#include "shapefactory.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onShapeTypeChanged(int index);
    void onAddShape();
    void onCalculateSelected();
    void onCalculateTotal();
    void onDeleteShape();

private:
    Ui::MainWindow *ui;
    std::vector<std::unique_ptr<Shape>> m_shapes;

    void updateShapeList();
    void updateParamFields();
};

#endif // MAINWINDOW_H
