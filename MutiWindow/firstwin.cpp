#include "firstwin.h"
#include "secondwin.h"
#include "ui_firstwin.h"
#include <QMovie>
#include <QDebug>
FirstWin::FirstWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FirstWin)
{
    ui->setupUi(this);
    init();
}

FirstWin::~FirstWin()
{
    delete ui;
}

void FirstWin::init()
{
    QMovie* mv = new QMovie("/home/jon/code/qt/MutiWindow/1.gif");

    S_W = new SecondWin();
    mv->start();
    ui->movie->setMovie(mv);
    ui->movie->setScaledContents(true);
    connect(ui->SecondWin,SIGNAL(clicked(bool)),this,SLOT(GoSecondWin()));
    connect(S_W,SIGNAL(SignalShowFirstWin(QString)),this,SLOT(DoRequest(QString)));

}

void FirstWin::GoSecondWin(void)
{
    S_W->show();
    this->hide();
    qDebug()<<"GoSecondWin"<<endl;

}
void FirstWin::DoRequest(QString number)
{


    S_W->hide();
    this->show();
    qDebug()<<"DoRequest"<<endl;

}
