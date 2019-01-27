#include "secondwin.h"
#include "ui_secondwin.h"
#include <QMovie>
#include <QDebug>
SecondWin::SecondWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SecondWin)
{
    ui->setupUi(this);
    init();
}

SecondWin::~SecondWin()
{
    delete ui;
}
void SecondWin:: init ()
{
    QMovie* mv = new QMovie("/home/jon/code/qt/MutiWindow/2.gif");
    mv->start();
    ui->movie->setMovie(mv);
    ui->movie->setScaledContents(true);
    connect(ui->FirstWin,SIGNAL(clicked(bool)),this,SLOT(GoFirstWin()));
}
void SecondWin:: GoFirstWin ()
{
    qDebug()<<"GoFirstWin"<<endl;
    emit SignalShowFirstWin(QString::number(1));
}
