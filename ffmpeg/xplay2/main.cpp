#include "xplay2.h"
#include <QApplication>
#include <iostream>
#include "XDemux.h"
#include "XDecode.h"
#include <QDebug>
#include <QThread>

extern "C" {
    #include "libavformat/avformat.h"
}
#pragma comment(lib,"avformat.lib")
#pragma comment(lib,"avutil.lib")
#pragma comment(lib,"avcodec.lib")


#define VIDEO_PATH "/home/jon/v1080.mp4"

class TestThread :public QThread
{
public:
    XAudioThread at;
    XVideoThread vt;
    void Init()
    {
        //Ïã¸ÛÎÀÊÓ
        char *url = "rtmp://live.hkstv.hk.lxdns.com/live/hks";
        cout << "demux.Open = " << demux.Open(url);
        demux.Read();
        demux.Clear();
        demux.Close();
        url = "v1080.mp4";
        cout << "demux.Open = " << demux.Open(url);
        //cout << "CopyVPara = " << demux.CopyVPara() << endl;
        //cout << "CopyAPara = " << demux.CopyAPara() << endl;
        //cout << "seek=" << demux.Seek(0.95) << endl;

        /////////////////////////////
        //cout << "vdecode.Open() = " << vdecode.Open(demux.CopyVPara()) << endl;
        //vdecode.Clear();
        //vdecode.Close();
        //cout << "adecode.Open() = " << adecode.Open(demux.CopyAPara()) << endl;
        //cout << "resample.Open = " << resample.Open(demux.CopyAPara()) << endl;
        //XAudioPlay::Get()->channels = demux.channels;
        //XAudioPlay::Get()->sampleRate = demux.sampleRate;

        //cout << "XAudioPlay::Get()->Open() = " << XAudioPlay::Get()->Open()<<endl;

        cout << "at.Open = "<<at.Open(demux.CopyAPara(), demux.sampleRate, demux.channels);
        vt.Open(demux.CopyVPara(), video, demux.width, demux.height);
        at.start();
        vt.start();
    }
    unsigned char *pcm = new unsigned char[1024 * 1024];
    void run()
    {
        for (;;)
        {
            AVPacket *pkt = demux.Read();
            if (demux.IsAudio(pkt))
            {
                at.Push(pkt);
                /*adecode.Send(pkt);
                AVFrame *frame = adecode.Recv();
                int len = resample.Resample(frame, pcm);
                cout<<"Resample:"<<len<<" ";
                while (len > 0)
                {
                    if (XAudioPlay::Get()->GetFree() >= len)
                    {
                        XAudioPlay::Get()->Write(pcm, len);
                        break;
                    }
                    msleep(1);
                }*/
                //cout << "Audio:" << frame << endl;
            }
            else
            {
                vt.Push(pkt);
                //vdecode.Send(pkt);
                //AVFrame *frame = vdecode.Recv();
                //video->Repaint(frame);
                //msleep(40);
                //cout << "Video:" << frame << endl;
            }
            if (!pkt)
            {
                demux.Seek(0);
                //break;
            }
        }
    }
    XDemux demux;
    XVideoWidget *video = 0;

};

int main(int argc, char *argv[])
{
    int re = 0;
    XDemux demux;
    XDecode decode;
    AVPacket* packet;
    AVFrame* frame;

    QApplication a(argc, argv);

    re = demux.Open(VIDEO_PATH);
    if(re == false)
    {
        qDebug("demux open failed ");
        return -1;
    }

    re = decode.Open(demux.CopyVPara());
    if(re == false)
    {
        qDebug("decode open failed ");
        return -1;
    }


    packet = demux.Read();
    if(packet == NULL)
    {
         qDebug("demux open failed ");
         return -1;
    }

    re = decode.Send(packet);
    if(re == false)
    {
        qDebug("decode Send failed ");
        return -1;
    }

    frame = decode.Recv();
    if(frame == NULL)
    {
        qDebug("decode Recv failed ");
        return -1;
    }

    return a.exec();
}
