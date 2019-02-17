#include "oneform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OneForm w;
    w.show();

    return a.exec();
}
