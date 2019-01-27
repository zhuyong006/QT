#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QMovie>
#include <QMainWindow>

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
    void DoProcess(void);
private:
    Ui::MainWindow *ui;
    void init(void);
    QTimer *mytimer = NULL;
    QMovie *mymovie = NULL;
    int index = 5;
};

#endif // MAINWINDOW_H
