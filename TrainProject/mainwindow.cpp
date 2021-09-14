#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setColorLine(int path_id, int train)
{
    if(path_id == 1){
        QColor verde = QColor(0, 255, 0);
        QPalette *palhetanova = new QPalette(verde, verde, verde, verde, verde, verde, verde);
        ui->L1->setPalette(*palhetanova);
    }
}

