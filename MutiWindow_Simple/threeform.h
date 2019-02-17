#ifndef THREEFORM_H
#define THREEFORM_H

#include <QWidget>

namespace Ui {
class ThreeForm;
}

class ThreeForm : public QWidget
{
    Q_OBJECT

public:
    explicit ThreeForm(QWidget *parent = 0);
    ~ThreeForm();

private slots:
    void on_btn_go1_clicked();

    void on_btn_go2_clicked();

private:
    Ui::ThreeForm *ui;
};

#endif // THREEFORM_H
