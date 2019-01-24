#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->toolButton->setIcon(QIcon("/home/jon/code/tool-pic/start.jpg"));
    ui->toolButton->setIconSize(QSize(200,200));

    QMenu *menu = new QMenu();
    QAction * action0;
    QAction * action1;

    action0 = menu->addAction(QIcon("/home/jon/code/tool-pic/start.jpg"),"event 0",this,SLOT(toolbutton_do_process()));
    action0->setObjectName("object event0");
    action1 = menu->addAction(QIcon("/home/jon/code/tool-pic/pause.jpg"),"event 1",this,SLOT(toolbutton_do_process()));
    action1->setObjectName("object event1");
    ui->toolButton->setMenu(menu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toolbutton_do_process()
{
    QAction * action = (QAction *)this->sender();

    qDebug()<<action->text()<<endl;
    qDebug()<<action->objectName()<<endl;

}
