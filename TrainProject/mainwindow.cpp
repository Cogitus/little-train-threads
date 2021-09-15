#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColor>
#include <QStyle>
#include <QTimer>
#include <unistd.h>     // for sleep()

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMap<int, QFrame*> tempTrack = {{1, ui->L1},
                                    {2, ui->L2},
                                    {3, ui->L3},
                                    {4, ui->L4},
                                    {5, ui->L5},
                                    {6, ui->L6},
                                    {7, ui->L7},
                                    {8, ui->L8},
                                    {9, ui->L9},
                                    {10, ui->L10},
                                    {11, ui->L11},
                                    {12, ui->L12},
                                    {13, ui->L13}};
    trackObjects = tempTrack;

    QTimer* repaint_timer = new QTimer(this);
    connect(repaint_timer, SIGNAL(timeout()), this, SLOT(repaintTracks()));
    repaint_timer->start(10);

    ui->train1HorizontalSlider->setMaximum(4);
    ui->train1HorizontalSlider->setMinimum(1);

    ui->train2HorizontalSlider->setMaximum(4);
    ui->train2HorizontalSlider->setMinimum(1);

    ui->train3HorizontalSlider->setMaximum(4);
    ui->train3HorizontalSlider->setMinimum(1);

    ui->train4horizontalSlider->setMaximum(4);
    ui->train4horizontalSlider->setMinimum(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setColorLine(int path_id, int train)
{
    QColor color = trainColors[train];
    QPalette *newPalette = new QPalette(color, color, color, color, color, color, color);
    trackObjects[path_id]->setPalette(*newPalette);
}

void MainWindow::sleepTime(int train)
{
    switch (train) {
        case 1:
            sleep(ui->train1HorizontalSlider->value());
            break;
        case 2:
            sleep(ui->train2HorizontalSlider->value());
            break;
        case 3:
            sleep(ui->train3HorizontalSlider->value());
            break;
        case 4:
            sleep(ui->train4horizontalSlider->value());
            break;
    }
}

void MainWindow::repaintTracks()
{
    for (int i=0; i<13 ;i++) {
        setColorLine(i+1, tracks[i]);
    }
}

