/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSlider *train1HorizontalSlider;
    QSlider *train2HorizontalSlider;
    QSlider *train3HorizontalSlider;
    QSlider *Train4horizontalSlider;
    QLabel *velocityLabel1;
    QLabel *velocityLabel2;
    QLabel *velocityLabel3;
    QLabel *velocityLabel4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        train1HorizontalSlider = new QSlider(centralwidget);
        train1HorizontalSlider->setObjectName(QString::fromUtf8("train1HorizontalSlider"));
        train1HorizontalSlider->setGeometry(QRect(10, 470, 160, 18));
        train1HorizontalSlider->setOrientation(Qt::Horizontal);
        train2HorizontalSlider = new QSlider(centralwidget);
        train2HorizontalSlider->setObjectName(QString::fromUtf8("train2HorizontalSlider"));
        train2HorizontalSlider->setGeometry(QRect(210, 470, 160, 18));
        train2HorizontalSlider->setOrientation(Qt::Horizontal);
        train3HorizontalSlider = new QSlider(centralwidget);
        train3HorizontalSlider->setObjectName(QString::fromUtf8("train3HorizontalSlider"));
        train3HorizontalSlider->setGeometry(QRect(410, 470, 160, 18));
        train3HorizontalSlider->setOrientation(Qt::Horizontal);
        Train4horizontalSlider = new QSlider(centralwidget);
        Train4horizontalSlider->setObjectName(QString::fromUtf8("Train4horizontalSlider"));
        Train4horizontalSlider->setGeometry(QRect(610, 470, 160, 18));
        Train4horizontalSlider->setOrientation(Qt::Horizontal);
        velocityLabel1 = new QLabel(centralwidget);
        velocityLabel1->setObjectName(QString::fromUtf8("velocityLabel1"));
        velocityLabel1->setGeometry(QRect(20, 490, 151, 21));
        velocityLabel2 = new QLabel(centralwidget);
        velocityLabel2->setObjectName(QString::fromUtf8("velocityLabel2"));
        velocityLabel2->setGeometry(QRect(220, 490, 151, 21));
        velocityLabel3 = new QLabel(centralwidget);
        velocityLabel3->setObjectName(QString::fromUtf8("velocityLabel3"));
        velocityLabel3->setGeometry(QRect(420, 490, 151, 21));
        velocityLabel4 = new QLabel(centralwidget);
        velocityLabel4->setObjectName(QString::fromUtf8("velocityLabel4"));
        velocityLabel4->setGeometry(QRect(620, 490, 151, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        velocityLabel1->setText(QCoreApplication::translate("MainWindow", "Velocity of train 1", nullptr));
        velocityLabel2->setText(QCoreApplication::translate("MainWindow", "Velocity of train 2", nullptr));
        velocityLabel3->setText(QCoreApplication::translate("MainWindow", "Velocity of train 3", nullptr));
        velocityLabel4->setText(QCoreApplication::translate("MainWindow", "Velocity of train 4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
