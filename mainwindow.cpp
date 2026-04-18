#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Геометрические фигуры");
    resize(700, 500);

    ui->shapeTypeCombo->addItem("Круг", (int)ShapeFactory::ShapeType::Circle);
    ui->shapeTypeCombo->addItem("Прямоугольник", (int)ShapeFactory::ShapeType::Rectangle);
    ui->shapeTypeCombo->addItem("Треугольник", (int)ShapeFactory::ShapeType::Triangle);
    ui->shapeTypeCombo->addItem("Квадрат", (int)ShapeFactory::ShapeType::Square);

    connect(ui->shapeTypeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onShapeTypeChanged);
    connect(ui->addBtn, &QPushButton::clicked, this, &MainWindow::onAddShape);
    connect(ui->calculateBtn, &QPushButton::clicked, this, &MainWindow::onCalculateSelected);
    connect(ui->totalBtn, &QPushButton::clicked, this, &MainWindow::onCalculateTotal);
    connect(ui->deleteBtn, &QPushButton::clicked, this, &MainWindow::onDeleteShape);

    ui->param1Edit->setValidator(new QDoubleValidator(0, 1e9, 3, this));
    ui->param2Edit->setValidator(new QDoubleValidator(0, 1e9, 3, this));
    ui->param3Edit->setValidator(new QDoubleValidator(0, 1e9, 3, this));

    onShapeTypeChanged(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onShapeTypeChanged(int index)
{
    int typeInt = ui->shapeTypeCombo->currentData().toInt();
    ShapeFactory::ShapeType type = static_cast<ShapeFactory::ShapeType>(typeInt);

    auto paramNames = ShapeFactory::getParamNames(type);

    ui->param1Label->setVisible(paramNames.size() >= 1);
    ui->param1Edit->setVisible(paramNames.size() >= 1);
    ui->param2Label->setVisible(paramNames.size() >= 2);
    ui->param2Edit->setVisible(paramNames.size() >= 2);
    ui->param3Label->setVisible(paramNames.size() >= 3);
    ui->param3Edit->setVisible(paramNames.size() >= 3);

    if (paramNames.size() >= 1) ui->param1Label->setText(QString::fromStdString(paramNames[0]));
    if (paramNames.size() >= 2) ui->param2Label->setText(QString::fromStdString(paramNames[1]));
    if (paramNames.size() >= 3) ui->param3Label->setText(QString::fromStdString(paramNames[2]));

    ui->param1Edit->clear();
    ui->param2Edit->clear();
    ui->param3Edit->clear();
}

void MainWindow::onAddShape()
{
    int typeInt = ui->shapeTypeCombo->currentData().toInt();
    ShapeFactory::ShapeType type = static_cast<ShapeFactory::ShapeType>(typeInt);

    std::vector<double> params;

    bool ok1 = true, ok2 = true, ok3 = true;
    double p1 = ui->param1Edit->text().toDouble(&ok1);
    double p2 = ui->param2Edit->text().toDouble(&ok2);
    double p3 = ui->param3Edit->text().toDouble(&ok3);

    switch (type) {
    case ShapeFactory::ShapeType::Circle:
        if (!ok1 || p1 <= 0) {
            QMessageBox::warning(this, "Ошибка", "Введите положительный радиус!");
            return;
        }
        params = {p1};
        break;
    case ShapeFactory::ShapeType::Rectangle:
        if (!ok1 || p1 <= 0 || !ok2 || p2 <= 0) {
            QMessageBox::warning(this, "Ошибка", "Введите положительные ширину и высоту!");
            return;
        }
        params = {p1, p2};
        break;
    case ShapeFactory::ShapeType::Triangle:
        if (!ok1 || p1 <= 0 || !ok2 || p2 <= 0 || !ok3 || p3 <= 0) {
            QMessageBox::warning(this, "Ошибка", "Введите положительные стороны!");
            return;
        }
        if (p1 + p2 <= p3 || p1 + p3 <= p2 || p2 + p3 <= p1) {
            QMessageBox::warning(this, "Ошибка", "Треугольник с такими сторонами не существует!");
            return;
        }
        params = {p1, p2, p3};
        break;
    case ShapeFactory::ShapeType::Square:
        if (!ok1 || p1 <= 0) {
            QMessageBox::warning(this, "Ошибка", "Введите положительную сторону!");
            return;
        }
        params = {p1};
        break;
    }

    auto shape = ShapeFactory::createShape(type, params);
    if (shape) {
        m_shapes.push_back(std::move(shape));
        updateShapeList();
    }
}

void MainWindow::updateShapeList()
{
    ui->shapeList->clear();
    for (size_t i = 0; i < m_shapes.size(); ++i) {
        ui->shapeList->addItem(QString::fromStdString(m_shapes[i]->toString()));
    }
}

void MainWindow::onCalculateSelected()
{
    int index = ui->shapeList->currentRow();
    if (index < 0 || index >= (int)m_shapes.size()) {
        QMessageBox::warning(this, "Ошибка", "Выберите фигуру!");
        return;
    }

    Shape* shape = m_shapes[index].get();

    QString result = QString::fromStdString(shape->getType()) + "\n" +
                     QString::fromStdString(shape->getParams()) + "\n\n" +
                     "Площадь: " + QString::number(shape->getArea()) + "\n" +
                     "Периметр: " + QString::number(shape->getPerimeter());

    QMessageBox::information(this, "Информация о фигуре", result);
}

void MainWindow::onCalculateTotal()
{
    if (m_shapes.empty()) {
        QMessageBox::warning(this, "Ошибка", "Нет добавленных фигур!");
        return;
    }

    double totalArea = 0;
    double totalPerimeter = 0;

    for (const auto& shape : m_shapes) {
        totalArea += shape->getArea();
        totalPerimeter += shape->getPerimeter();
    }

    QString result = "Всего фигур: " + QString::number(m_shapes.size()) + "\n\n" +
                     "Суммарная площадь: " + QString::number(totalArea) + "\n" +
                     "Суммарный периметр: " + QString::number(totalPerimeter);

    QMessageBox::information(this, "Суммарные значения", result);
}

void MainWindow::onDeleteShape()
{
    int index = ui->shapeList->currentRow();
    if (index < 0 || index >= (int)m_shapes.size()) {
        QMessageBox::warning(this, "Ошибка", "Выберите фигуру для удаления!");
        return;
    }

    m_shapes.erase(m_shapes.begin() + index);
    updateShapeList();
}
