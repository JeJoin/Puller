#include "Puller.h"
#include <render/D3DVideoRender.h>

#define WIDTH  640
#define HEIGHT 360

Puller::Puller(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);


    //HWND hwnd = (HWND)this->winId();

    //FILE* fp = fopen("sintel_640_360.yuv", "rb");
    //if (fp == NULL) {
    //    printf("open file error\n");
    //    return;
    //}
    //int yuvsize = WIDTH * HEIGHT * 3 >> 1;
    //D3DVideoRender renderer;
    //renderer.Open(WIDTH, HEIGHT, hwnd);
    //uint8_t * frame = new uint8_t[yuvsize];

    //while (fread(frame, yuvsize, 1, fp)) {
    //    renderer.Render(WIDTH, HEIGHT, frame, yuvsize);
    //    Sleep(40);
    //}

}
