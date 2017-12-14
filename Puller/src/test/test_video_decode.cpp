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
    FILE* vfp = fopen("../../res/sintel.h264", "rb");
    VideoDecodeCallback cb;
    jcodec::JFFVideoDecoder JVideoDecoder(&cb);
    JVideoDecoder.Init(jcodec::enH264);
    
    fclose(vfp);
}
