#ifndef TWOFORM_H
#define TWOFORM_H

#include <QWidget>

namespace Ui {
class TwoForm;
}

class TwoForm : public QWidget
{
    Q_OBJECT

public:
    explicit TwoForm(QWidget *parent = 0);
    ~TwoForm();

private slots:
    void on_btn_go1_clicked();

    void on_btn_go3_clicked();

private:
    Ui::TwoForm *ui;
};

#endif // TWOFORM_H
