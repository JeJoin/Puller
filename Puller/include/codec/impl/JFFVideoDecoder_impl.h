#ifndef __JFFVIDEODECODER_H__
#define __JFFVIDEODECODER_H__

#include <common/typedefs.h>
#include <codec/JFFVideoDecoder.h>

extern "C" {
#include <3rd\ffmpeg\libavcodec\avcodec.h>
}

class JIVideoDecodeCallback;

namespace jcodec {

class JFFVideoDecoderImpl
{
public:
    JFFVideoDecoderImpl(JIVideoDecodeCallback* cb, void * arg);

    virtual ~JFFVideoDecoderImpl();

    bool Init(VideoDecodeType type);

    int32_t Decode(uint8_t* data, int32_t size, void * arg);

private:
	bool _InitDecoder(AVCodecID codecID);

    void _Release();

private:
    JIVideoDecodeCallback * m_pDecodeCB;
    AVCodecContext *        m_pAVContext;
    AVPacket *              m_pAVPacket;
    AVFrame *               m_pAVFrame;
    AVCodec *               m_pAVCodec;
    uint8_t *               m_pYUV420;
    void *                  m_pOnDecArg;
    bool                    m_bInit;
};


}
#endif // !__JFFVIDEODECODER_H__
