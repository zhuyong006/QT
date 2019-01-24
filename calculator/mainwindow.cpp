#include "mainwindow.h"
#include "ui_mainwindow.h"
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

void MainWindow::on_calculate_clicked()
{
    QString param1;
    QString param2;
    QString symbol;
    int answer;

    param1 = ui->param1->text();
    param2 = ui->param2->text();
    symbol = ui->symbol->text();

    //qDebug() << "on_calculate_clicked:" <<endl;

    if(symbol == "+")
    {
        answer = param1.toInt()+param2.toInt();
        ui->result->setText(QString::number(answer));
    }else if(symbol == "*")
    {
        answer = param1.toInt()*param2.toInt();
        ui->result->setText(QString::number(answer));
    }else if(symbol == "-")
    {
        answer = param1.toInt()-param2.toInt();
        ui->result->setText(QString::number(answer));
    }else if(symbol == "/")
    {
        answer = param1.toInt()/param2.toInt();
        ui->result->setText(QString::number(answer));
    }

}
