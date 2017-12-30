
#include <render/D3DVideoRender.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/QtWidgets>

#define WIDTH  640
#define HEIGHT 360
void test_video_renderer(int argc, char * argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    w.show();
    HWND hwnd = (HWND)w.winId();

    FILE* fp = fopen("sintel_640_360.yuv", "rb");
    if (fp == NULL) {
        printf("open file error\n");
        return;
    }
    int yuvsize = WIDTH * HEIGHT * 3 >> 1;
    D3DVideoRender renderer;
    renderer.Open(WIDTH, HEIGHT, hwnd);
    uint8_t * frame = new uint8_t[yuvsize];

    while (fread(frame, yuvsize, 1, fp)) {
        renderer.Render(WIDTH, HEIGHT, frame, yuvsize);
        Sleep(40);
    }

    a.exec();
}