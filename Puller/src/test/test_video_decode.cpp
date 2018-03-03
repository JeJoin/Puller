#include <codec/JFFVideoDecoder.h>
#include <io.h>

class VideoDecodeCallback : public JIVideoDecodeCallback
{
public:
    VideoDecodeCallback() {};
    virtual ~VideoDecodeCallback() {}
    virtual void OnVideoDecodeCallback(int32_t width, int32_t height,
                            uint8_t * pdata, int32_t size, void * arg);
};

void VideoDecodeCallback::OnVideoDecodeCallback(int32_t w, int32_t h,
                            uint8_t * data, int32_t size, void * arg)
{
    char filepath[128] = {0};
    sprintf(filepath, "yuv420_%d_%d.yuv", w, h);

    FILE* fp = fopen(filepath, "wb");
    if (NULL == fp) {
        return;
    }
    fwrite(data, size, 1, fp);
    fclose(fp);
}

void test_video_decode()
{
    uint8_t nal_header = 0;
    VideoDecodeCallback cb;
    int32_t width = 0, height = 0;
    uint8_t nul_unit_type = 0;

    jcodec::JFFVideoDecoder JVideoDecoder(&cb);
    JVideoDecoder.Init(jcodec::enH264);

    FILE* fp = fopen("pic_640_480.h264", "rb");
    if (fp == NULL) {
        printf("open file error.\n");
        return;
    }

    int filesize = filelength(fileno(fp));
    char *buf = new char[filesize];
    fread(buf, filesize, 1, fp);
    JVideoDecoder.Decode((uint8_t*)buf, filesize, NULL);
    
    delete[] buf;
    fclose(fp);
}
