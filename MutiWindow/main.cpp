#include "firstwin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstWin w;
    w.show();

    return a.exec();
}
