#include "xplay2.h"
#include "ui_xplay2.h"

xplay2::xplay2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::xplay2)
{
    ui->setupUi(this);
}

xplay2::~xplay2()
{
    delete ui;
}
