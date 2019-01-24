/**
 * SDL YUV422 USB CAMERA APPLICATION FOR SDL2.0
 *
 * 朱勇 Jon
 * zhuyong_006@163.com
 * https://blog.csdn.net/zhuyong006
 *
 * 本程序实现了USB CAMERA基于UVC模式的显示(当前仅仅支持YUV422即YUYV格式的图像输出)
 * 2018.12.3
 * V1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <linux/videodev2.h>
#include <linux/fb.h>
#include <pthread.h>



extern "C"
{
#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>
}
#include "gather_picture.h"

#define PRINT                 printf("LINE: %d\n",__LINE__)

struct frame_buf frame_buf;

int main(int argc, char **argv)
{
    int n = 1, i;
    unsigned char frmrate;
    char* status = NULL;
    SDL_Rect rect;
    SDL_Event event;
    SDL_Window *screen;
    SDL_Renderer* sdlRenderer;
    SDL_Texture* sdlTexture;
    struct SwsContext *sws_ctx = NULL;


    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)) {
        fprintf(stderr, "Could not initialize SDL - %s\n", SDL_GetError());
        exit(1);
    }


    screen = SDL_CreateWindow("usb camera", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_OPENGL);

    if(!screen) {
        fprintf(stderr, "SDL: could not set video mode - exiting\n");
        exit(1);
    }

    sdlRenderer = SDL_CreateRenderer(screen, -1, 0);


    rect.x = 0;
    rect.y = 0;
    rect.w = WIDTH;
    rect.h = HEIGHT;

    sdlTexture = SDL_CreateTexture(sdlRenderer, SDL_PIXELFORMAT_YUY2, SDL_TEXTUREACCESS_STREAMING,WIDTH,HEIGHT);

    init_V4L2();
    gather_picture_init();
    gather_on();

    while(1){
        for(i = 0; i < 4; i++){
            video_getframe(i);
            /* SDL_UpdateTexture
             * 最后一个参数：窗口每行显示的字节数
             */
            SDL_UpdateTexture(sdlTexture,NULL,frame_buf.start[i],WIDTH*2);

            SDL_RenderClear(sdlRenderer);
            SDL_RenderCopy(sdlRenderer, sdlTexture,  NULL, &rect);
            SDL_RenderPresent(sdlRenderer);

            if(video_enqueue(i) < 0){
                printf("video_enqueue() failed\n");
                return -1;
            }

            SDL_PollEvent(&event);
                switch(event.type) {
                    case SDL_QUIT:
                          SDL_Quit();
                          return 0;
                          break;
                    default:
                          break;
            }
        }
    }

    return 0;
}
