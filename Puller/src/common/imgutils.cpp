#include <common/imgutils.h>


int ARGBToI420(const uint8_t* srcARGB, uint8_t* dstI420, int32_t w, int32_t h)
{
    if (srcARGB == NULL ||
        dstI420 == NULL ||
        w <= 0 || h <= 0) {
        return -1;
    }
    uint8_t * pdsty = dstI420;
    uint8_t * pdstu = pdsty + w*h;
    uint8_t * pdstv = pdstu + (w*h >> 2);;

    int stride_y = w;
    int stride_u = w >> 1;
    int stride_v = w >> 1;

    return libyuv::ARGBToI420(srcARGB, w * 4, pdsty, stride_y,
        pdstu, stride_u, pdstv, stride_v, w, h);
}

int I420ToARGB(const uint8_t* srcI420, uint8_t* dstARGB, int32_t w, int32_t h)
{
    if (srcI420 == NULL ||
        dstARGB == NULL ||
        w <= 0 || h <= 0) {
        return -1;
    }
    const uint8_t * psrcy = srcI420;
    const uint8_t * psrcu = psrcy + w*h;
    const uint8_t * psrcv = psrcu + (w*h >> 2);;

    int stride_y = w;
    int stride_u = w >> 1;
    int stride_v = w >> 1;

    return libyuv::I420ToARGB(psrcy, stride_y, psrcu, stride_u,
        psrcv, stride_v, dstARGB, w * 4, w, h);
}
