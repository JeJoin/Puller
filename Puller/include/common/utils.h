#ifndef __UTILS_H__
#define __UTILS_H__

#include <common/typedefs.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(WIN_PLATFORM)
#include <io.h>
#endif

#define SAFE_DELETE(ptr)        \
    do {                        \
        if (ptr != NULL) {      \
            delete ptr;         \
            ptr = NULL;         \
        }                       \
    } while (0)

#define SAFE_FREE(ptr)          \
    do {                        \
        if (ptr != NULL) {      \
            free(ptr);          \
            ptr = NULL;         \
        }                       \
    } while (0)

#if defined(IOS_PLATFORM)
#define RELEASE_REF(ref)        \
    do {                        \
        if (ref != NULL) {      \
            CFRelease(ref);     \
            ref = NULL;         \
        }                       \
    } while (0)
//#else
//#define RELEASE_REF(ref)
#endif

#define SAFE_CLOSE(fd)          \
    do {                        \
        if (fd >= 0) {          \
            close(fd);          \
            fd = -1;            \
        }                       \
    } while (0)

#define SWITCH_ENDIAN(n)                       

/*\
    (((((uint32_t)(n)) >> 24) & 0x000000FF)  |   \
    ((((uint32_t)(n)) >> 8)   & 0x0000FF00)  |   \
    ((((uint32_t)(n)) << 8)   & 0x00FF0000)  |   \
    ((((uint32_t)(n)) << 24)  & 0xFF000000))*/

#define ARRAY_SIZE(array)       (sizeof(array) / sizeof(array[0]))

#ifndef FABS
#define FABS(n)                 ((n) < 0 ? -(n) : (n))
#endif

/* Macros for min/max. */
#ifndef MIN
#define	MIN(a,b) (((a)<(b))?(a):(b))
#endif /* MIN */
#ifndef MAX
#define	MAX(a,b) (((a)>(b))?(a):(b))
#endif	/* MAX */


#ifdef __cplusplus
extern "C" {
#endif
    
int32_t sdk_atoi(const char * sz);
#define __atoi  sdk_atoi

#if defined(WIN_PLATFORM)
void bzero(void * ptr, size_t n);

#ifndef INVALID_SOCKET
#define INVALID_SOCKET          (-1)
#endif

#define ISVALID_SOCKET(sock)    ((int)sock != INVALID_SOCKET)
    
#define SAFE_CLOSESOCKET(sock)      \
    do {                            \
        if (ISVALID_SOCKET(sock)) { \
            closesocket(sock);      \
            sock = -1;              \
        }                           \
    } while (0)
#else
    
#define INVALID_SOCKET          (-1)
#define ISVALID_SOCKET(sock)    (sock >= 0)
    
#define SAFE_CLOSESOCKET(sock)      \
    do {                            \
        if (ISVALID_SOCKET(sock)) { \
            close(sock);            \
            sock = -1;              \
        }                           \
    } while (0)
#endif

#ifdef __cplusplus
}
#endif

#endif
