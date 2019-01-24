#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTime>
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

void MainWindow:: init(void)
{
    qsrand(QTime(0,0,0,0).secsTo(QTime::currentTime()));
    connect(ui->btn_0,SIGNAL(clicked(bool)),this,SLOT(do_process_click()));
    connect(ui->btn_1,SIGNAL(clicked(bool)),this,SLOT(do_process_click()));
    connect(ui->btn_2,SIGNAL(clicked(bool)),this,SLOT(do_process_click()));
    connect(ui->btn_3,SIGNAL(clicked(bool)),this,SLOT(do_process_click()));
    connect(ui->btn_4,SIGNAL(clicked(bool)),this,SLOT(do_process_click()));
    connect(ui->btn_5,SIGNAL(clicked(bool)),this,SLOT(do_process_click()));
    connect(ui->btn_6,SIGNAL(clicked(bool)),this,SLOT(do_process_click()));
    connect(ui->btn_7,SIGNAL(clicked(bool)),this,SLOT(do_process_click()));
    connect(ui->btn_8,SIGNAL(clicked(bool)),this,SLOT(do_process_click()));
    connect(ui->btn_9,SIGNAL(clicked(bool)),this,SLOT(do_process_click()));

    rand = qrand()%100;
}

void MainWindow:: do_process_click()
{
    QString msg;
    static QString guess;
    QPushButton *btn = (QPushButton *)this->sender();

   // qDebug()<< "E,guess length : "<<guess.length();

    if(guess.length() < 1)
        guess.append(btn->text());
    else if(guess.length() == 1)
    {
        guess.append(btn->text());
        if(guess.toInt() > rand)
            msg = "猜错了，大了";
        else if(guess.toInt() < rand)
            msg = "猜错了，小了";
        else{
            msg = "猜对了";
            rand = qrand()%100;
        }

    }

  //  qDebug()<< "X,guess length : "<<guess.length();

    ui->lcdNumber->display(guess.toInt());

    if(guess.length() >= 2)
         guess.clear();

    ui->textEdit->setText(msg);
}
