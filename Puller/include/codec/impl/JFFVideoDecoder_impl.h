#ifndef __JFFVIDEODECODER_H__
#define __JFFVIDEODECODER_H__

#include <typedefs.h>
#include <codec/JFFVideoDecoder.h>

namespace jcodec {

class JIVideoDecodeCallback;

class JFFVideoDecoderImpl
{
public:
    JFFVideoDecoderImpl(JIVideoDecodeCallback* cb);

    virtual ~JFFVideoDecoderImpl();

    bool Init(AVCodecID codecID);

    int32_t Decode(uint8_t* data, int32_t size, void * arg);
private:
    JIVideoDecodeCallback * m_pDecodeCB;
};


}
#endif // !__JFFVIDEODECODER_H__
