#include "xplay2.h"
#include <QApplication>
#include <iostream>
#include "xdemux.h"
int main(int argc, char *argv[])
{
   // char *url = "rtmp://live.hkstv.hk.lxdns.com:1935/live/hks";
    char *nv = "/home/jon/v1080.mp4";
    QApplication a(argc, argv);
    xplay2 w;
    xdemux x;
    int ret;

    ret = x.open(nv);
    w.show();

    return a.exec();
}
