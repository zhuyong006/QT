/**
 * 最简单的基于FFmpeg的视频播放器
 * Simplest FFmpeg Player
 *
 * 雷霄骅 Lei Xiaohua
 * leixiaohua1020@126.com
 * 中国传媒大学/数字电视技术
 * Communication University of China / Digital TV Technology
 * http://blog.csdn.net/leixiaohua1020
 *
 * 本程序实现了视频文件的解码和显示（支持HEVC，H.264，MPEG2等）。
 * 是最简单的FFmpeg视频解码方面的教程。
 * 通过学习本例子可以了解FFmpeg的解码流程。
 * This software is a simplest video player based on FFmpeg.
 * Suitable for beginner of FFmpeg.
 */


#include <stdio.h>

#define __STDC_CONSTANT_MACROS

#ifdef _WIN32
//Windows
extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "SDL/SDL.h"
};
#else
//Linux...
#ifdef __cplusplus
extern "C"
{
#endif
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <SDL/SDL.h>
#ifdef __cplusplus
};
#endif
#endif


//Full Screen
#define SHOW_FULLSCREEN 0
//Output YUV420P
#define OUTPUT_YUV420P 0


int main(int argc, char* argv[])
{
    //FFmpeg
    AVFormatContext *pFormatCtx;
    int             i, videoindex;
    AVCodecContext  *pCodecCtx;
    AVCodec         *pCodec;
    AVFrame *pFrame,*pFrameYUV;
    AVPacket *packet;
    struct SwsContext *img_convert_ctx;
    //SDL
    int screen_w,screen_h;
    SDL_Surface *screen;
    SDL_VideoInfo *vi;
    SDL_Overlay *bmp;
    SDL_Rect rect;

    FILE *fp_yuv;
    int ret, got_picture;
    char filepath[]="/home/jon/v1080.mp4";

    av_register_all();
    avformat_network_init();

    pFormatCtx = avformat_alloc_context();

    if(avformat_open_input(&pFormatCtx,filepath,NULL,NULL)!=0){
        printf("Couldn't open input stream.\n");
        return -1;
    }
    if(avformat_find_stream_info(pFormatCtx,NULL)<0){
        printf("Couldn't find stream information.\n");
        return -1;
    }
    videoindex=-1;
    for(i=0; i<pFormatCtx->nb_streams; i++)
        if(pFormatCtx->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO){
            videoindex=i;
            break;
        }
    if(videoindex==-1){
        printf("Didn't find a video stream.\n");
        return -1;
    }
    pCodecCtx=pFormatCtx->streams[videoindex]->codec;
    pCodec=avcodec_find_decoder(pCodecCtx->codec_id);
    if(pCodec==NULL){
        printf("Codec not found.\n");
        return -1;
    }
    if(avcodec_open2(pCodecCtx, pCodec,NULL)<0){
        printf("Could not open codec.\n");
        return -1;
    }

    pFrame=av_frame_alloc();
    pFrameYUV=av_frame_alloc();
    uint8_t *out_buffer=(uint8_t *)av_malloc(avpicture_get_size(AV_PIX_FMT_YUV420P, pCodecCtx->width, pCodecCtx->height));
    avpicture_fill((AVPicture *)pFrameYUV, out_buffer, AV_PIX_FMT_YUV420P, pCodecCtx->width, pCodecCtx->height);
    //SDL----------------------------
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)) {
        printf( "Could not initialize SDL - %s\n", SDL_GetError());
        return -1;
    }



#if SHOW_FULLSCREEN
    vi = SDL_GetVideoInfo();
    screen_w = vi->current_w;
    screen_h = vi->current_h;
    screen = SDL_SetVideoMode(screen_w, screen_h, 0,SDL_FULLSCREEN);
#else
    screen_w = 640;//pCodecCtx->width;
    screen_h = 480;//pCodecCtx->height;
    screen = SDL_SetVideoMode(screen_w, screen_h, 0,0);
#endif

    if(!screen) {
        printf("SDL: could not set video mode - exiting:%s\n",SDL_GetError());
        return -1;
    }

    bmp = SDL_CreateYUVOverlay(screen_w, screen_h,SDL_YV12_OVERLAY, screen);

    rect.x = 0;
    rect.y = 0;
    rect.w = screen_w;
    rect.h = screen_h;
    //SDL End------------------------


    packet=(AVPacket *)av_malloc(sizeof(AVPacket));
    //Output Information-----------------------------
    printf("------------- File Information ------------------\n");
    av_dump_format(pFormatCtx,0,filepath,0);
    printf("-------------------------------------------------\n");

#if OUTPUT_YUV420P
    fp_yuv=fopen("output.yuv","wb+");
#endif

    SDL_WM_SetCaption("Simplest FFmpeg Player",NULL);

    img_convert_ctx = sws_getContext(pCodecCtx->width, pCodecCtx->height, pCodecCtx->pix_fmt, screen_w, screen_h, AV_PIX_FMT_YUV420P, SWS_BICUBIC, NULL, NULL, NULL);
    //------------------------------
    while(av_read_frame(pFormatCtx, packet)>=0){
        if(packet->stream_index==videoindex){
            //Decode
            ret = avcodec_decode_video2(pCodecCtx, pFrame, &got_picture, packet);
            if(ret < 0){
                printf("Decode Error.\n");
                return -1;
            }
            if(got_picture){
                SDL_LockYUVOverlay(bmp);
                pFrameYUV->data[0]=bmp->pixels[0];
                pFrameYUV->data[1]=bmp->pixels[2];
                pFrameYUV->data[2]=bmp->pixels[1];
                pFrameYUV->linesize[0]=bmp->pitches[0];
                pFrameYUV->linesize[1]=bmp->pitches[2];
                pFrameYUV->linesize[2]=bmp->pitches[1];
                sws_scale(img_convert_ctx, (const uint8_t* const*)pFrame->data, pFrame->linesize, 0,
                    pCodecCtx->height, pFrameYUV->data, pFrameYUV->linesize);
#if OUTPUT_YUV420P
                int y_size=pCodecCtx->width*pCodecCtx->height;
                fwrite(pFrameYUV->data[0],1,y_size,fp_yuv);    //Y
                fwrite(pFrameYUV->data[1],1,y_size/4,fp_yuv);  //U
                fwrite(pFrameYUV->data[2],1,y_size/4,fp_yuv);  //V
#endif

                SDL_UnlockYUVOverlay(bmp);

                SDL_DisplayYUVOverlay(bmp, &rect);
                //Delay 40ms
                SDL_Delay(40);
            }
        }
        av_free_packet(packet);
    }

    //FIX: Flush Frames remained in Codec
    while (1) {
        ret = avcodec_decode_video2(pCodecCtx, pFrame, &got_picture, packet);
        if (ret < 0)
            break;
        if (!got_picture)
            break;
        sws_scale(img_convert_ctx, (const uint8_t* const*)pFrame->data, pFrame->linesize, 0, pCodecCtx->height, pFrameYUV->data, pFrameYUV->linesize);

        SDL_LockYUVOverlay(bmp);
        pFrameYUV->data[0]=bmp->pixels[0];
        pFrameYUV->data[1]=bmp->pixels[2];
        pFrameYUV->data[2]=bmp->pixels[1];
        pFrameYUV->linesize[0]=bmp->pitches[0];
        pFrameYUV->linesize[1]=bmp->pitches[2];
        pFrameYUV->linesize[2]=bmp->pitches[1];
#if OUTPUT_YUV420P
        int y_size=pCodecCtx->width*pCodecCtx->height;
        fwrite(pFrameYUV->data[0],1,y_size,fp_yuv);    //Y
        fwrite(pFrameYUV->data[1],1,y_size/4,fp_yuv);  //U
        fwrite(pFrameYUV->data[2],1,y_size/4,fp_yuv);  //V
#endif

        SDL_UnlockYUVOverlay(bmp);
        SDL_DisplayYUVOverlay(bmp, &rect);
        //Delay 40ms
        SDL_Delay(40);
    }

    sws_freeContext(img_convert_ctx);

#if OUTPUT_YUV420P
    fclose(fp_yuv);
#endif

    SDL_Quit();

    //av_free(out_buffer);
    av_free(pFrameYUV);
    avcodec_close(pCodecCtx);
    avformat_close_input(&pFormatCtx);

    return 0;
}
