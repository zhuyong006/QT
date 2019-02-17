#include "twoform.h"
#include "ui_twoform.h"
#include "getoneform.h"
#include "getthreeform.h"
TwoForm::TwoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TwoForm)
{
    ui->setupUi(this);
}

TwoForm::~TwoForm()
{
    delete ui;
}

void TwoForm::on_btn_go1_clicked()
{
    OneForm* form = GetOneForm::getobject();
    this->hide();
    form->show();
}

void TwoForm::on_btn_go3_clicked()
{
    ThreeForm* form = GetThreeForm::getobject();
    this->hide();
    form->show();
}
