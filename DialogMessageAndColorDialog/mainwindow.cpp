#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QColorDialog>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //QMessageBox::about(this,"About","Powered By Jon");
    /*
    int ret = QMessageBox::warning(this, tr("My Application"),
                                   tr("The document has been modified.\n"
                                      "Do you want to save your changes?"),
                                   QMessageBox::Save | QMessageBox::Discard
                                   | QMessageBox::Cancel,
                                   QMessageBox::Save);
    if(ret == QMessageBox::Save)
        qDebug()<<"QMessageBox::Save";
    else if(ret == QMessageBox::Discard)
        qDebug()<<"QMessageBox::Discard";
    else if(ret == QMessageBox::Cancel)
        qDebug()<<"QMessageBox::Cancel";
    */
    QMessageBox::information(this,"information","Powered By Jon",QMessageBox::Yes | QMessageBox::No);

}

void MainWindow::on_pushButton_2_clicked()
{
    QColor mycolor = QColorDialog::getColor(Qt::red,this,"get color");
    if(mycolor.isValid())
    {
        QPalette pal = ui->label->palette();
        pal.setColor(QPalette::WindowText,mycolor);
        ui->label->setPalette(pal);
    }
}
