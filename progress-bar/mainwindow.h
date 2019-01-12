#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Start_clicked();

    void on_Pause_clicked();

    void do_progressbar();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int percent;
};

#endif // MAINWINDOW_H
