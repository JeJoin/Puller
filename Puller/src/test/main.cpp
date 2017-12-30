#include <stdio.h>

extern void test_video_decode();
extern void test_video_renderer(int argc, char * argv[]);
int main(int argc, char * argv[])
{
    //test_video_decode();
    test_video_renderer(argc, argv);

    getchar();
    return 0;
}