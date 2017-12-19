#include <codec\JFFVideoDecoder.h>

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

}

void test_video_decode()
{
    uint8_t nal_header = 0;
    VideoDecodeCallback cb;
    jcodec::JFFVideoDecoder JVideoDecoder(&cb);
    JVideoDecoder.Init(jcodec::enH264);

    FILE* vfp = fopen("pic_640_480.h264", "rb");
    if (vfp == NULL) {
        printf("open file error.\n");
        return;
    }
    fseek(vfp, 4, SEEK_SET);
    fread(&nal_header, 1, 1, vfp);

    uint8_t nul_unit_type = nal_header & 0x1F;
    printf("nul_unit_type: %d\n", nul_unit_type);

    fclose(vfp);
}
