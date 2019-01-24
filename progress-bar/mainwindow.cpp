#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    percent = 0;
    ui->progressBar->set
    ui->progressBar->setValue(0);
    timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(do_progressbar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Start_clicked()
{

    timer->start(100);
}

void MainWindow::on_Pause_clicked()
{
    timer->stop();
}

void MainWindow::do_progressbar()
{
    percent = (percent +1)%100;
    ui->progressBar->setValue(percent);
}
