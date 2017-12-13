#ifndef __TYPEDEFS_H__
#define __TYPEDEFS_H__

#include <stdio.h>          //define NULL.
// Define C99 equivalent types, since MSVC doesn't provide stdint.h.
typedef signed char         int8_t;
typedef signed short        int16_t;
typedef signed int          int32_t;
typedef signed __int64      int64_t;
typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;
typedef unsigned __int64    uint64_t;

#ifdef _WIN32

// Include winsock2.h before including <windows.h> to maintain consistency with
// win32.h.  We can't include win32.h directly here since it pulls in
// headers such as basictypes.h which causes problems in Chromium where webrtc
// exists as two separate projects, webrtc and libjingle.
#include <winsock2.h>   //SOCKET
#include <windows.h>

#define DLL_EXPORT     __declspec(dllexport)

#if _MSC_VER >= 1900
#define PI32        "zd"
#define PI64        "lld"
#define PU64        "llu"
#define snprintf    snprintf
#else
#define PI32        "d"
#define PI64        "I64d"
#define PU64        "I64u"
#define snprintf    _snprintf
#endif

#pragma  warning(disable:4996)
#pragma  warning(disable:4068)
#pragma  warning(disable:4146)
#pragma  warning(disable:4819)

#endif
#endif // typedef.h
