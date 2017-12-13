#include <codec/impl/JFFVideoDecoder_impl.h>
namespace jcodec {

#pragma comment(lib, "PC/x86/libavcodec.a")
#pragma comment(lib, "PC/x86/libavutil.a")
#pragma comment(lib, "PC/x86/libfdk-aac.a")
#pragma comment(lib, "PC/x86/libx264.a")


JFFVideoDecoderImpl::JFFVideoDecoderImpl(JIVideoDecodeCallback* cb)
    : m_pDecodeCB(cb)
{
	avcodec_register_all();
}

JFFVideoDecoderImpl::~JFFVideoDecoderImpl()
{

}

bool JFFVideoDecoderImpl::Init(VideoDecodeType type)
{
	bool ret = false;
	switch (type)
	{
	case jcodec::enH262:
		break;
	case jcodec::enH263:
		break;
	case jcodec::enH264:
		ret = _InitH264Decoder();
		break;
	case jcodec::enH265:
		break;
	case jcodec::enAVS:
		break;
	case jcodec::enWMS:
		break;
	default:
		break;
	}
    return ret;
}

bool JFFVideoDecoderImpl::_InitH264Decoder()
{
	return true;
}

int32_t JFFVideoDecoderImpl::Decode(uint8_t* data, int32_t size, void * arg)
{
    return 0;
}

}
