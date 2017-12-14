#include <codec/impl/JFFVideoDecoder_impl.h>
#include <utils.h>

#define MAX_IMAGE_WIDTH          1920
#define MAX_IMAGE_HEIGHT         1080 
#define MAX_YUV420_IMAGE_SIZE    (MAX_IMAGE_WIDTH*MAX_IMAGE_HEIGHT*3>>1)

namespace jcodec {

#pragma comment(lib, "PC/x86/libgcc.a")
#pragma comment(lib, "PC/x86/libavcodec.a")
#pragma comment(lib, "PC/x86/libavutil.a")
#pragma comment(lib, "PC/x86/libfdk-aac.a")
#pragma comment(lib, "PC/x86/libx264.a")


JFFVideoDecoderImpl::JFFVideoDecoderImpl(JIVideoDecodeCallback* cb)
    : m_pDecodeCB(cb)
    , m_pAVContext(NULL)
    , m_pAVPacket(NULL)
    , m_pAVFrame(NULL)
    , m_pAVCodec(NULL)
    , m_pYUV420(NULL)
    , m_bInit(false)
{
	avcodec_register_all();
}

JFFVideoDecoderImpl::~JFFVideoDecoderImpl()
{
}

bool JFFVideoDecoderImpl::Init(VideoDecodeType type)
{
    AVCodecID codecID = AV_CODEC_ID_NONE;
	switch (type)
	{
	case jcodec::enH261:
        codecID = AV_CODEC_ID_H261;
		break;
	case jcodec::enH263:
        codecID = AV_CODEC_ID_H263;
		break;
	case jcodec::enH264:
        codecID = AV_CODEC_ID_H264;
		break;
	case jcodec::enH265:
        codecID = AV_CODEC_ID_H265;
		break;
	case jcodec::enAVS:
        codecID = AV_CODEC_ID_AVS;
		break;
	default:
		break;
	}
    return _InitDecoder(codecID);
}

bool JFFVideoDecoderImpl::_InitDecoder(AVCodecID codecID)
{
    if (codecID == AV_CODEC_ID_NONE) {
        return false;
    }

    m_pYUV420 = new uint8_t[MAX_YUV420_IMAGE_SIZE];
    if (m_pYUV420 == NULL) {
        goto failed;
    }

    m_pAVPacket = av_packet_alloc();
    if (m_pAVPacket == NULL) {
        goto failed;
    }

    m_pAVFrame = av_frame_alloc();
    if (m_pAVFrame == NULL) {
        goto failed;
    }

    m_pAVCodec = avcodec_find_decoder(AV_CODEC_ID_H264);
    if (m_pAVCodec == NULL) {
        goto failed;
    }

    m_pAVContext = avcodec_alloc_context3(m_pAVCodec);
    if (m_pAVContext == NULL) {
        goto failed;
    }

    if (avcodec_open2(m_pAVContext, m_pAVCodec, NULL) < 0) {
        goto failed;
    }
    return m_bInit = true;

failed:
    _Release();
    return false;
}

void JFFVideoDecoderImpl::_Release()
{
    if (m_bInit) {
        m_bInit = false;
        avcodec_close(m_pAVContext);
    }

    if (m_pAVContext != NULL) {
        avcodec_free_context(&m_pAVContext);
        m_pAVContext = NULL;
    }

    m_pAVCodec = NULL;

    if (m_pAVFrame != NULL) {
        av_frame_free(&m_pAVFrame);
        m_pAVFrame = NULL;
    }

    if (m_pAVPacket != NULL) {
        av_packet_free(&m_pAVPacket);
        m_pAVPacket = NULL;
    }

    SAFE_DELETE(m_pYUV420);
    m_bInit = false;
    m_pDecodeCB = NULL;
}

int32_t JFFVideoDecoderImpl::Decode(uint8_t* data, int32_t size, void * arg)
{
    return 0;
}

}
