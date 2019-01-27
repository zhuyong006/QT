#ifndef FIRSTWIN_H
#define FIRSTWIN_H

#include <QMainWindow>
#include "secondwin.h"
namespace Ui {
class FirstWin;
}

class FirstWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit FirstWin(QWidget *parent = 0);
    ~FirstWin();
private slots:
    void GoSecondWin(void);
    void DoRequest(QString number);
private:
    void init();
    Ui::FirstWin *ui;
    SecondWin *S_W = NULL;
};

#endif // FIRSTWIN_H
