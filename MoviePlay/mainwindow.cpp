#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    mytimer = new QTimer(this);
    mymovie = new QMovie("/home/jon/code/qt/MutiWindow/1.gif");

    ui->lcdNumber->display(index);
    ui->movie->setMovie(mymovie);
    ui->movie->setScaledContents(mymovie);
    ui->movie->hide();
    mymovie->start();
    QObject::connect(mytimer,SIGNAL(timeout()),this,SLOT(DoProcess()));
    mytimer->start(1000);

}
void MainWindow::DoProcess()
{
    index--;
    if(index == 0)
    {
        ui->movie->showFullScreen();
        ui->lcdNumber->hide();
        this->showFullScreen();
        mytimer->stop();
    }
    ui->lcdNumber->display(index);
}
