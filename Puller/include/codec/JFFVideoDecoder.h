#ifndef _JFFVIDEODECODEC_H__
#define _JFFVIDEODECODEC_H__
/*
* Description: ...
* Aulthor: Jein(Jejoin)
* Create on 12/8/2017
**/

#include <typedefs.h>

namespace jcodec {

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

private:
    JIVideoDecodeCallback*      m_pCB;
};

}      // namespace jcodec

#endif // !_JFFVIDEODECODEC_H__
