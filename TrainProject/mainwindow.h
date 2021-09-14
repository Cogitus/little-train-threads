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
    void resetColorLine(int path_id);

    QMap<int, QColor> trainColors = {{1, Qt::cyan},
                                     {2, Qt::magenta},
                                     {3, Qt::red},
                                     {4, Qt::blue}};
    QMap<int, QFrame*> trackObjects;

    int ocupado[12] = {0};

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
