#ifndef _JFFVIDEODECODEC_H__
#define _JFFVIDEODECODEC_H__
/*
* Description: ...
* Aulthor: Jein(Jejoin)
* Create on 12/8/2017
**/

#include <typedefs.h>

extern "C" {
#include <3rd\ffmpeg\libavcodec\avcodec.h>
}

namespace jcodec {

class JFFVideoDecoderImpl;

class DLL_EXPORT JIVideoDecodeCallback
{
public:
    virtual ~JIVideoDecodeCallback() {}
    virtual void OnVideoDecodeCallback(int32_t width, int32_t height,
                        uint8_t * pdata, int32_t size, void * arg) = 0;
};

class DLL_EXPORT JFFVideoDecoder
{
public:
    JFFVideoDecoder(JIVideoDecodeCallback* cb);
    virtual ~JFFVideoDecoder();

    bool Init(AVCodecID codecID);

    int32_t Decode(uint8_t* data, int32_t size, void * arg);

private:
    JFFVideoDecoderImpl * m_pImpl;
};

}      // namespace jcodec

#endif // !_JFFVIDEODECODEC_H__
