#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QFrame>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setColorLine(int path_id, int train);
    void sleepTime(int train);

    QMap<int, QColor> trainColors = {{0, Qt::gray},
                                     {1, Qt::cyan},
                                     {2, Qt::magenta},
                                     {3, Qt::red},
                                     {4, Qt::blue}};
    QMap<int, QFrame*> trackObjects;

    int tracks[13] = {0,1,0,0,0,0,2,3,0,0,0,0,4};

public slots:
    void repaintTracks();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
