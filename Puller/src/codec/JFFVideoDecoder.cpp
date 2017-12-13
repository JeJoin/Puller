#include <codec/JFFVideoDecoder.h>
#include <codec/impl/JFFVideoDecoder_impl.h>

namespace jcodec {
JFFVideoDecoder::JFFVideoDecoder(JIVideoDecodeCallback * cb)
    : m_pImpl(new JFFVideoDecoderImpl(cb))
{}

JFFVideoDecoder::~JFFVideoDecoder()
{

}

bool JFFVideoDecoder::Init(AVCodecID codecID)
{
    return m_pImpl->Init(codecID);
}

int32_t JFFVideoDecoder::Decode(uint8_t* data, int32_t size, void * arg)
{
    return m_pImpl->Decode(data, size, arg);
}


}