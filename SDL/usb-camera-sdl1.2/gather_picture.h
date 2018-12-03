#ifndef GATHER_PICTURE_H
#define GATHER_PICTURE_H
#define VIDEO_DEV    "/dev/video0"    //视频设备
#define WIDTH            640
#define HEIGHT           480

struct frame_buf{  //一帧图像缓冲区
        int length[4];
        void * start[4];
    };

extern struct frame_buf frame_buf;

int init_V4L2();
int gather_picture_init();
int gather_on();
int gather_off();
int video_getframe(int i);
int video_enqueue(int i);

#endif // GATHER_PICTURE_H
