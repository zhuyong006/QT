#include "xdemux.h"
#include <iostream>

extern "C"{
#include "libavformat/avformat.h"
}

using namespace std;
#pragma comment(lib,"avformat.lib")
#pragma comment(lib,"avutil.lib")
#pragma comment(lib,"avcodec.lib")

static double r2d(AVRational r)
{
    return r.den == 0 ? 0 : (double)r.num / (double)r.den;
}

xdemux::xdemux()
{
    static bool isFirst = true;
    if (isFirst)
    {
        //初始化封装库
        av_register_all();

        //初始化网络库 （可以打开rtsp rtmp http 协议的流媒体视频）
        avformat_network_init();
        isFirst = false;
    }
}

bool xdemux:: open(const char *url)
{
    //参数设置
    AVDictionary *opts = NULL;
    //设置rtsp流已tcp协议打开
    av_dict_set(&opts, "rtsp_transport", "tcp", 0);

    //网络延时时间
    av_dict_set(&opts, "max_delay", "500", 0);

    int re = avformat_open_input(
        &ic,
        url,
        0,  // 0表示自动选择解封器
        &opts //参数设置，比如rtsp的延时时间
    );
    if (re != 0)
    {
        char buf[1024] = { 0 };
        av_strerror(re, buf, sizeof(buf) - 1);
        cout << "open " << url << " failed! :" << buf << endl;
        return false;
    }
    cout << "open " << url << " success! " << endl;

    //获取流信息
    re = avformat_find_stream_info(ic, 0);

    //总时长 毫秒
    int totalMs = ic->duration / (AV_TIME_BASE / 1000);
    cout << "totalMs = " << totalMs << endl;

    //打印视频流详细信息
    av_dump_format(ic, 0, url, 0);


    //获取视频流
    videoStream = av_find_best_stream(ic, AVMEDIA_TYPE_VIDEO, -1, -1, NULL, 0);
    AVStream *as = ic->streams[videoStream];
    width = as->codec->width;
    height = as->codec->height;

    cout << "=======================================================" << endl;
    cout << videoStream << "视频信息" << endl;
    cout << "codec_id = " << as->codecpar->codec_id << endl;
    cout << "format = " << as->codecpar->format << endl;
    cout << "width=" << as->codecpar->width << endl;
    cout << "height=" << as->codecpar->height << endl;
    //帧率 fps 分数转换
    cout << "video fps = " << r2d(as->avg_frame_rate) << endl;

    cout << "=======================================================" << endl;
    cout << audioStream << "音频信息" << endl;
    //获取音频流
    audioStream = av_find_best_stream(ic, AVMEDIA_TYPE_AUDIO, -1, -1, NULL, 0);
    as = ic->streams[audioStream];
    sampleRate = as->codecpar->sample_rate;
    channels = as->codecpar->channels;

    cout << "codec_id = " << as->codecpar->codec_id << endl;
    cout << "format = " << as->codecpar->format << endl;
    cout << "sample_rate = " << as->codecpar->sample_rate << endl;
    //AVSampleFormat;
    cout << "channels = " << as->codecpar->channels << endl;
    //一帧数据？？ 单通道样本数
    cout << "frame_size = " << as->codecpar->frame_size << endl;
    //1024 * 2 * 2 = 4096  fps = sample_rate/frame_size
    return true;
}
//空间需要调用者释放 ，释放AVPacket对象空间，和数据空间 av_packet_free
AVPacket *xdemux::Read()
{
    mux.lock();
    if (!ic) //容错
    {
        mux.unlock();
        return 0;
    }
    AVPacket *pkt = av_packet_alloc();
    //读取一帧，并分配空间
    int re = av_read_frame(ic, pkt);
    if (re != 0)
    {
        mux.unlock();
        av_packet_free(&pkt);
        return 0;
    }
    //pts转换为毫秒
    pkt->pts = pkt->pts*(1000 * (r2d(ic->streams[pkt->stream_index]->time_base)));
    pkt->dts = pkt->dts*(1000 * (r2d(ic->streams[pkt->stream_index]->time_base)));
    mux.unlock();
    cout << pkt->pts << " "<<flush;
    return pkt;

}


xdemux::~xdemux()
{

}
