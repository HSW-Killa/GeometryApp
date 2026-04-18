/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *shapeTypeCombo;
    QLabel *param1Label;
    QLineEdit *param1Edit;
    QLabel *param2Label;
    QLineEdit *param2Edit;
    QLineEdit *param3Edit;
    QLabel *param3Label;
    QPushButton *addBtn;
    QListWidget *shapeList;
    QPushButton *calculateBtn;
    QPushButton *totalBtn;
    QPushButton *deleteBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        shapeTypeCombo = new QComboBox(centralwidget);
        shapeTypeCombo->setObjectName("shapeTypeCombo");
        shapeTypeCombo->setGeometry(QRect(20, 10, 151, 32));
        param1Label = new QLabel(centralwidget);
        param1Label->setObjectName("param1Label");
        param1Label->setGeometry(QRect(30, 60, 81, 16));
        param1Edit = new QLineEdit(centralwidget);
        param1Edit->setObjectName("param1Edit");
        param1Edit->setGeometry(QRect(130, 60, 113, 21));
        param2Label = new QLabel(centralwidget);
        param2Label->setObjectName("param2Label");
        param2Label->setGeometry(QRect(30, 90, 81, 16));
        param2Edit = new QLineEdit(centralwidget);
        param2Edit->setObjectName("param2Edit");
        param2Edit->setGeometry(QRect(130, 90, 113, 21));
        param3Edit = new QLineEdit(centralwidget);
        param3Edit->setObjectName("param3Edit");
        param3Edit->setGeometry(QRect(130, 120, 113, 21));
        param3Label = new QLabel(centralwidget);
        param3Label->setObjectName("param3Label");
        param3Label->setGeometry(QRect(30, 120, 81, 16));
        addBtn = new QPushButton(centralwidget);
        addBtn->setObjectName("addBtn");
        addBtn->setGeometry(QRect(170, 10, 100, 32));
        shapeList = new QListWidget(centralwidget);
        shapeList->setObjectName("shapeList");
        shapeList->setGeometry(QRect(30, 150, 491, 192));
        calculateBtn = new QPushButton(centralwidget);
        calculateBtn->setObjectName("calculateBtn");
        calculateBtn->setGeometry(QRect(30, 360, 100, 32));
        totalBtn = new QPushButton(centralwidget);
        totalBtn->setObjectName("totalBtn");
        totalBtn->setGeometry(QRect(140, 360, 121, 32));
        deleteBtn = new QPushButton(centralwidget);
        deleteBtn->setObjectName("deleteBtn");
        deleteBtn->setGeometry(QRect(270, 360, 100, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 33));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        param1Label->setText(QCoreApplication::translate("MainWindow", "\321\200\320\260\320\264\320\270\321\203\321\201", nullptr));
        param2Label->setText(QCoreApplication::translate("MainWindow", "\321\210\320\270\321\200\320\270\320\275\320\260", nullptr));
        param3Label->setText(QCoreApplication::translate("MainWindow", "\321\201\321\202\320\276\321\200\320\276\320\275\320\260 \320\220", nullptr));
        addBtn->setText(QCoreApplication::translate("MainWindow", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        calculateBtn->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        totalBtn->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \320\262\321\201\320\265", nullptr));
        deleteBtn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
