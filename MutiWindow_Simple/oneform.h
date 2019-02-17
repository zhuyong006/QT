#ifndef ONEFORM_H
#define ONEFORM_H

#include <QWidget>

namespace Ui {
class OneForm;
}

class OneForm : public QWidget
{
    Q_OBJECT

public:
    explicit OneForm(QWidget *parent = 0);
    ~OneForm();
private slots:
    void on_btn_go2_clicked();

    void on_btn_go3_clicked();

private:
    Ui::OneForm *ui;
};

#endif // ONEFORM_H
