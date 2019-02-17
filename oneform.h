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

private:
    Ui::OneForm *ui;
};

#endif // ONEFORM_H
