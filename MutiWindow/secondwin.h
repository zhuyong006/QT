#ifndef SECONDWIN_H
#define SECONDWIN_H
#include <QWidget>

namespace Ui {
class SecondWin;
}

class SecondWin : public QWidget
{
    Q_OBJECT

public:
    explicit SecondWin(QWidget *parent = 0);
    ~SecondWin();

signals:
    void SignalShowFirstWin(QString);
private slots:
    void GoFirstWin(void);
private:
    void init(void);
    Ui::SecondWin *ui;
};

#endif // SECONDWIN_H
