#ifndef __IMGUTILS_H__
#define __IMGUTILS_H__
#include <common/typedefs.h>
#include <3rd/libyuv/libyuv.h>
#pragma comment(lib, "PC/x86/libyuv.lib")

int ARGBToI420(const uint8_t* srcARGB, uint8_t* dstI420, int32_t w, int32_t h);

int I420ToARGB(const uint8_t* srcI420, uint8_t* dstARGB, int32_t w, int32_t h);

#endif // !__IMGUTILS_H__
