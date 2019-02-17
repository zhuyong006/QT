#include "threeform.h"
#include "ui_threeform.h"
#include "getoneform.h"
#include "gettwoform.h"
ThreeForm::ThreeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ThreeForm)
{
    ui->setupUi(this);
}

ThreeForm::~ThreeForm()
{
    delete ui;
}

void ThreeForm::on_btn_go1_clicked()
{
    OneForm * form = GetOneForm::getobject();
    this->hide();
    form->show();
}

void ThreeForm::on_btn_go2_clicked()
{
    TwoForm * form = GetTwoForm::getobject();
    this->hide();
    form->show();
}
