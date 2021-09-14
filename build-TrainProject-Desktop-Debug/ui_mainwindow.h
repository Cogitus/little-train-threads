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
#include <QtWidgets/QFrame>
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
    QFrame *L2;
    QFrame *L7;
    QFrame *L8;
    QFrame *L4;
    QFrame *L6;
    QFrame *L10;
    QFrame *L13;
    QFrame *L1;
    QFrame *L3;
    QFrame *L5;
    QFrame *L9;
    QFrame *L12;
    QFrame *L11;
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
        L2 = new QFrame(centralwidget);
        L2->setObjectName(QString::fromUtf8("L2"));
        L2->setGeometry(QRect(90, 40, 211, 16));
        L2->setFrameShape(QFrame::HLine);
        L2->setFrameShadow(QFrame::Sunken);
        L7 = new QFrame(centralwidget);
        L7->setObjectName(QString::fromUtf8("L7"));
        L7->setGeometry(QRect(300, 40, 211, 16));
        L7->setFrameShape(QFrame::HLine);
        L7->setFrameShadow(QFrame::Sunken);
        L8 = new QFrame(centralwidget);
        L8->setObjectName(QString::fromUtf8("L8"));
        L8->setGeometry(QRect(510, 40, 211, 16));
        L8->setFrameShape(QFrame::HLine);
        L8->setFrameShadow(QFrame::Sunken);
        L4 = new QFrame(centralwidget);
        L4->setObjectName(QString::fromUtf8("L4"));
        L4->setGeometry(QRect(90, 180, 211, 16));
        L4->setFrameShape(QFrame::HLine);
        L4->setFrameShadow(QFrame::Sunken);
        L6 = new QFrame(centralwidget);
        L6->setObjectName(QString::fromUtf8("L6"));
        L6->setGeometry(QRect(300, 180, 211, 16));
        L6->setFrameShape(QFrame::HLine);
        L6->setFrameShadow(QFrame::Sunken);
        L10 = new QFrame(centralwidget);
        L10->setObjectName(QString::fromUtf8("L10"));
        L10->setGeometry(QRect(510, 180, 211, 16));
        L10->setFrameShape(QFrame::HLine);
        L10->setFrameShadow(QFrame::Sunken);
        L13 = new QFrame(centralwidget);
        L13->setObjectName(QString::fromUtf8("L13"));
        L13->setGeometry(QRect(90, 320, 631, 20));
        L13->setFrameShape(QFrame::HLine);
        L13->setFrameShadow(QFrame::Sunken);
        L1 = new QFrame(centralwidget);
        L1->setObjectName(QString::fromUtf8("L1"));
        L1->setGeometry(QRect(80, 50, 20, 141));
        L1->setFrameShape(QFrame::VLine);
        L1->setFrameShadow(QFrame::Sunken);
        L3 = new QFrame(centralwidget);
        L3->setObjectName(QString::fromUtf8("L3"));
        L3->setGeometry(QRect(290, 50, 20, 141));
        L3->setFrameShape(QFrame::VLine);
        L3->setFrameShadow(QFrame::Sunken);
        L5 = new QFrame(centralwidget);
        L5->setObjectName(QString::fromUtf8("L5"));
        L5->setGeometry(QRect(500, 50, 20, 141));
        L5->setFrameShape(QFrame::VLine);
        L5->setFrameShadow(QFrame::Sunken);
        L9 = new QFrame(centralwidget);
        L9->setObjectName(QString::fromUtf8("L9"));
        L9->setGeometry(QRect(710, 50, 20, 141));
        L9->setFrameShape(QFrame::VLine);
        L9->setFrameShadow(QFrame::Sunken);
        L12 = new QFrame(centralwidget);
        L12->setObjectName(QString::fromUtf8("L12"));
        L12->setGeometry(QRect(710, 190, 20, 141));
        L12->setFrameShape(QFrame::VLine);
        L12->setFrameShadow(QFrame::Sunken);
        L11 = new QFrame(centralwidget);
        L11->setObjectName(QString::fromUtf8("L11"));
        L11->setGeometry(QRect(80, 190, 20, 141));
        L11->setFrameShape(QFrame::VLine);
        L11->setFrameShadow(QFrame::Sunken);
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
