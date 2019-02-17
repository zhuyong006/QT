#include "oneform.h"
#include "gettwoform.h"
#include "getthreeform.h"
#include "ui_oneform.h"

OneForm::OneForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OneForm)
{
    ui->setupUi(this);
}

OneForm::~OneForm()
{
    delete ui;
}

void OneForm::on_btn_go2_clicked()
{
    TwoForm* form = GetTwoForm::getobject();
    this->hide();
    form->show();

}

void OneForm::on_btn_go3_clicked()
{
    ThreeForm* form = GetThreeForm::getobject();
    this->hide();
    form->show();
}
