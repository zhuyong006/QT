#ifndef XPLAY2_H
#define XPLAY2_H

#include <QWidget>

namespace Ui {
class xplay2;
}

class xplay2 : public QWidget
{
    Q_OBJECT

public:
    explicit xplay2(QWidget *parent = 0);
    ~xplay2();

private:
    Ui::xplay2 *ui;
};

#endif // XPLAY2_H
