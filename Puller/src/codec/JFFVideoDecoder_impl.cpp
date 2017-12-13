#include <codec/impl/JFFVideoDecoder_impl.h>
namespace jcodec {

JFFVideoDecoderImpl::JFFVideoDecoderImpl(JIVideoDecodeCallback* cb)
    : m_pDecodeCB(cb)
{

}

JFFVideoDecoderImpl::~JFFVideoDecoderImpl()
{

}

bool JFFVideoDecoderImpl::Init(AVCodecID codecID)
{
    return true;
}

int32_t JFFVideoDecoderImpl::Decode(uint8_t* data, int32_t size, void * arg)
{
    return 0;
}

}
