#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->cb_0,SIGNAL(clicked(bool)),this,SLOT(cb_do_process()));
    connect(ui->cb_1,SIGNAL(clicked(bool)),this,SLOT(cb_do_process()));
    connect(ui->rb_man,SIGNAL(clicked(bool)),this,SLOT(rb_do_process()));
    connect(ui->rb_woman,SIGNAL(clicked(bool)),this,SLOT(rb_do_process()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cb_do_process()
{
    QCheckBox *cb = (QCheckBox *)this->sender();

    if(cb->isChecked()){
        qDebug()<<cb->text()<<endl;
        qDebug()<<cb->objectName()<<endl;
    }
}

void MainWindow::rb_do_process()
{
    QRadioButton *rb = (QRadioButton *)this->sender();

    if(rb->isChecked())
        qDebug()<<rb->text()<<endl;
}
