
/**

 * 最简单的基于FFmpeg的视频编码器

 * Simplest FFmpeg Video Encoder

 *

 * 雷霄骅 Lei Xiaohua

 * leixiaohua1020@126.com

 * 中国传媒大学/数字电视技术

 * Communication University of China / Digital TV Technology

 * http://blog.csdn.net/leixiaohua1020

 *

 * 本程序实现了YUV像素数据编码为视频码流（HEVC(H.265)，H264，MPEG2，VP8等等）。

 * 是最简单的FFmpeg视频编码方面的教程。

 * 通过学习本例子可以了解FFmpeg的编码流程。

 * This software encode YUV420P data to HEVC(H.265) bitstream (or

 * H.264, MPEG2, VP8 etc.).

 * It's the simplest video encoding software based on FFmpeg.

 * Suitable for beginner of FFmpeg

 */



#include <stdio.h>



extern "C"

{


#include <libavutil/opt.h>

#include <libavcodec/avcodec.h>

#include <libavformat/avformat.h>

};





int flush_encoder(AVFormatContext *fmt_ctx,unsigned int stream_index)

{

    int ret;

    int got_frame;

    AVPacket enc_pkt;

    if (!(fmt_ctx->streams[stream_index]->codec->codec->capabilities &

        AV_CODEC_CAP_DELAY))

        return 0;

    while (1) {

        printf("Flushing stream #%u encoder\n", stream_index);

        //ret = encode_write_frame(NULL, stream_index, &got_frame);

        enc_pkt.data = NULL;

        enc_pkt.size = 0;

        av_init_packet(&enc_pkt);

        ret = avcodec_encode_video2 (fmt_ctx->streams[stream_index]->codec, &enc_pkt,

            NULL, &got_frame);

        av_frame_free(NULL);

        if (ret < 0)

            break;

        if (!got_frame){

            ret=0;

            break;

        }

        printf("Succeed to encode 1 frame! 编码成功1帧！\n");

        /* mux encoded frame */

        ret = av_write_frame(fmt_ctx, &enc_pkt);

        if (ret < 0)

            break;

    }

    return ret;

}



int main(int argc, char* argv[])

{

    AVFormatContext* pFormatCtx;

    AVOutputFormat* fmt;

    AVStream* video_st;

    AVCodecContext* pCodecCtx;

    AVCodec* pCodec;



    uint8_t* picture_buf;

    AVFrame* picture;

    int size;



    //FILE *in_file = fopen("src01_480x272.yuv", "rb");	//Input YUV data 视频YUV源文件

    FILE *in_file = fopen("/home/jon/yuv420.yuv", "rb");	//Input YUV data 视频YUV源文件

    int in_w=640,in_h=480;//宽高

    //Frames to encode

    int framenum=100;

    //const char* out_file = "src01.h264";	//Output Filepath 输出文件路径

    //const char* out_file = "src01.ts";

    //const char* out_file = "src01.hevc";

    const char* out_file = "ds.mp4";



    av_register_all();

    //Method1 方法1.组合使用几个函数

    pFormatCtx = avformat_alloc_context();

    //Guess Format 猜格式

    fmt = av_guess_format(NULL, out_file, NULL);

    pFormatCtx->oformat = fmt;



    //Method 2 方法2.更加自动化一些

    //avformat_alloc_output_context2(&pFormatCtx, NULL, NULL, out_file);

    //fmt = pFormatCtx->oformat;





    //Output Format 注意输出路径

    if (avio_open(&pFormatCtx->pb,out_file, AVIO_FLAG_READ_WRITE) < 0)

    {

        printf("Failed to open output file! 输出文件打开失败");

        return -1;

    }



    video_st = avformat_new_stream(pFormatCtx, 0);

    video_st->time_base.num = 1;

    video_st->time_base.den = 25;



    if (video_st==NULL)

    {

        return -1;

    }

    //Param that must set

    pCodecCtx = video_st->codec;

    //pCodecCtx->codec_id =AV_CODEC_ID_HEVC;

    pCodecCtx->codec_id = fmt->video_codec;

    pCodecCtx->codec_type = AVMEDIA_TYPE_VIDEO;

    pCodecCtx->pix_fmt =AV_PIX_FMT_YUV420P;

    pCodecCtx->width = in_w;

    pCodecCtx->height = in_h;

    pCodecCtx->time_base.num = 1;

    pCodecCtx->time_base.den = 25;

    pCodecCtx->bit_rate = 400000;

    pCodecCtx->gop_size=250;

    //H264

    //pCodecCtx->me_range = 16;

    //pCodecCtx->max_qdiff = 4;

    //pCodecCtx->qcompress = 0.6;

    pCodecCtx->qmin = 10;

    pCodecCtx->qmax = 51;



    //Optional Param

    pCodecCtx->max_b_frames=3;



    // Set Option

    AVDictionary *param = 0;

    //H.264

    if(pCodecCtx->codec_id == AV_CODEC_ID_H264) {

        av_dict_set(&param, "preset", "slow", 0);

        av_dict_set(&param, "tune", "zerolatency", 0);

    }

    //H.265

    if(pCodecCtx->codec_id == AV_CODEC_ID_H265){

        av_dict_set(&param, "x265-params", "qp=20", 0);

        av_dict_set(&param, "preset", "ultrafast", 0);

        av_dict_set(&param, "tune", "zero-latency", 0);

    }



    //Dump Information 输出格式信息

    av_dump_format(pFormatCtx, 0, out_file, 1);



    pCodec = avcodec_find_encoder(pCodecCtx->codec_id);

    if (!pCodec){

        printf("Can not find encoder! 没有找到合适的编码器！\n");

        return -1;

    }

    if (avcodec_open2(pCodecCtx, pCodec,&param) < 0){

        printf("Failed to open encoder! 编码器打开失败！\n");

        return -1;

    }







    picture = av_frame_alloc();

    size = avpicture_get_size(pCodecCtx->pix_fmt, pCodecCtx->width, pCodecCtx->height);

    picture_buf = (uint8_t *)av_malloc(size);

    avpicture_fill((AVPicture *)picture, picture_buf, pCodecCtx->pix_fmt, pCodecCtx->width, pCodecCtx->height);



    //Write File Header 写文件头

    avformat_write_header(pFormatCtx,NULL);



    AVPacket pkt;

    int y_size = pCodecCtx->width * pCodecCtx->height;

    av_new_packet(&pkt,y_size*3);



    for (int i=0; i<framenum; i++){

        //Read YUV 读入YUV

        if (fread(picture_buf, 1, y_size*3/2, in_file) < 0){

            printf("Failed to read YUV data! 文件读取错误\n");

            return -1;

        }else if(feof(in_file)){

            break;

        }

        picture->data[0] = picture_buf;  // 亮度Y

        picture->data[1] = picture_buf+ y_size;  // U

        picture->data[2] = picture_buf+ y_size*5/4; // V

        //PTS

        picture->pts=i;

        int got_picture=0;

        //Encode 编码

        int ret = avcodec_encode_video2(pCodecCtx, &pkt,picture, &got_picture);

        if(ret < 0){

            printf("Failed to encode! 编码错误！\n");

            return -1;

        }

        if (got_picture==1){

            printf("Succeed to encode 1 frame! 编码成功1帧！\n");

            pkt.stream_index = video_st->index;

            ret = av_write_frame(pFormatCtx, &pkt);

            av_free_packet(&pkt);

        }

    }

    //Flush Encoder

    int ret = flush_encoder(pFormatCtx,0);

    if (ret < 0) {

        printf("Flushing encoder failed\n");

        return -1;

    }



    //Write file trailer 写文件尾

    av_write_trailer(pFormatCtx);



    //Clean 清理

    if (video_st){

        avcodec_close(video_st->codec);

        av_free(picture);

        av_free(picture_buf);

    }

    avio_close(pFormatCtx->pb);

    avformat_free_context(pFormatCtx);



    fclose(in_file);



    return 0;

}
