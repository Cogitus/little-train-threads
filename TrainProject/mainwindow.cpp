#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColor>
#include <QStyle>
#include <QTimer>

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
    repaint_timer->start(50);
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

void MainWindow::resetColorLine(int path_id)
{
    QColor color = Qt::gray;
    QPalette *newPalette = new QPalette();
    trackObjects[path_id]->setPalette(*newPalette);
}

void MainWindow::repaintTracks()
{
    for (int i=0; i<13 ;i++) {
        setColorLine(i, tracks[i]);
    }
}

