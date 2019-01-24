#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void init(void);
private slots:
    void do_process_click(void);
private:
    Ui::MainWindow *ui;
    int rand;
};

#endif // MAINWINDOW_H
