#include <common/utils.h>
#include <ctype.h>
#include <string.h>

int32_t sdk_atoi(const char * sz)
{
    int32_t n = 0;
    if (sz != NULL) {
        while (isdigit(*sz)) {
            n = n * 10 + (*sz ++) - '0';
        }
    }
    return n;
}

#if defined(WIN_PLATFORM)
void bzero(void * ptr, size_t n)
{
    memset(ptr, 0, n);
}


#ifdef __cplusplus 
extern "C" {
#endif 

#if _MSC_VER >= 1900
    #pragma comment(lib, "legacy_stdio_definitions.lib")

    _ACRTIMP_ALT FILE* __cdecl __acrt_iob_func(unsigned _Ix);

    FILE* __cdecl __iob_func(unsigned i) {
        return __acrt_iob_func(i);
    }

    FILE * __cdecl _imp___iob(unsigned i) {
        return __acrt_iob_func(i);
    }
#endif

    // ffmpegshim.c  
    // this file is part of Context Free  
    // ---------------------  
    // Copyright (C) 2012 John Horigan - john@glyphic.com  
    // Copyright (C) 2000 Free Software Foundation, Inc.  
    //  
    // This program is free software; you can redistribute it and/or  
    // modify it under the terms of the GNU General Public License  
    // as published by the Free Software Foundation; either version 2  
    // of the License, or (at your option) any later version.  
    //  
    // This program is distributed in the hope that it will be useful,  
    // but WITHOUT ANY WARRANTY; without even the implied warranty of  
    // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  
    // GNU General Public License for more details.  
    //  
    // You should have received a copy of the GNU General Public License  
    // along with this program; if not, write to the Free Software  
    // Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.  
    //  
    // John Horigan can be contacted at john@glyphic.com or at  
    // John Horigan, 1209 Villa St., Mountain View, CA 94041-1123, USA  
    //  
    //  


#include <windows.h>  
#include <stdio.h>  
#include <stdarg.h>  
#include <stdlib.h>  
#include <time.h>  
#include <errno.h>  
#include <math.h>  
#include <string.h>
#include <io.h>
#include <fcntl.h>

    float __cdecl _sqrtf(float x)
    {
        return sqrtf(x);
    }

    float __cdecl _powf(float x, float y)
    {
        return powf(x, y);
    }

    int __cdecl __fpclassify(float x)
    {
        return fpclassify(x);
    }

    int __cdecl __isnan(float x)
    {
        return isnan(x) ? 0 : -1;
    }

    int __cdecl __mingw_vsnprintf(
        char *buffer,
        size_t count,
        const char *format,
        va_list argptr
    )
    {
        return vsnprintf_s(buffer, count, _TRUNCATE, format, argptr);
    }

    int __cdecl __ms_vsnprintf(
        char *buffer,
        size_t count,
        const char *format,
        va_list argptr
    )
    {
        return vsnprintf_s(buffer, count, _TRUNCATE, format, argptr);
    }

    int __cdecl __mingw_vfprintf(
        FILE *stream,
        const char *format,
        va_list argptr
    )
    {
        return vfprintf_s(stream, format, argptr);
    }

    int __cdecl __mingw_vsprintf(char * s, const char * format, va_list arg)
    {
        return vsprintf(s, format, arg);
    }

    int __cdecl __mingw_vprintf(const char * format, va_list arg)
    {
        return vprintf(format, arg);
    }

#if _MSC_VER < 1900
    struct timespec
    {
        int tv_sec;
        int tv_nsec;
    };
#endif

#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)  
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000Ui64  
#else  
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000ULL  
#endif

    struct timezone
    {
        int  tz_minuteswest; /* minutes W of Greenwich */
        int  tz_dsttime;     /* type of dst correction */
    };

    int __cdecl gettimeofday(
        struct timeval  *tv,
        struct timezone *tz
    )
    {
        FILETIME ft;
        unsigned __int64 tmpres = 0;
        static int tzflag;

        if (NULL != tv) {
            GetSystemTimeAsFileTime(&ft);

            tmpres |= ft.dwHighDateTime;
            tmpres <<= 32;
            tmpres |= ft.dwLowDateTime;

            /*converting file time to unix epoch*/
            tmpres -= DELTA_EPOCH_IN_MICROSECS;
            tmpres /= 10;  /*convert into microseconds*/
            tv->tv_sec = (long)(tmpres / 1000000UL);
            tv->tv_usec = (long)(tmpres % 1000000UL);
        }

        if (NULL != tz) {
            int i;
            long l = 0;
            if (!tzflag) {
                _tzset();
                tzflag++;
            }
            _get_timezone(&l);
            tz->tz_minuteswest = l / 60;
            _get_daylight(&i);
            tz->tz_dsttime = i;
        }

        return 0;
    }

    int __cdecl usleep(
        unsigned int useconds
    )
    {
        if (useconds == 0)
            return 0;

        if (useconds >= 1000000)
            return EINVAL;

        Sleep((useconds + 999) / 1000);

        return 0;
    }

    double __cdecl __strtod(
        const char *nptr,
        char **endptr
    )
    {
        return strtod(nptr, endptr);
    }

    double __cdecl __mingw_strtod(
        const char *nptr,
        char **endptr)
    {
        return strtod(nptr, endptr);
    }

    /*double __cdecl trunc(
        double n
    )
    {
        return n > 0.0 ? floor(n) : ceil(n);
    }*/

    int __cdecl __mingw_vsscanf(
        const char *s,
        const char *fmt,
        va_list ap
    )
    {
        void *a[5];
        int i;
        for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
            a[i] = va_arg(ap, void *);
        return sscanf(s, fmt, a[0], a[1], a[2], a[3], a[4]);
    }

    unsigned __int64 __cdecl udivmodsi4(
        unsigned __int64 num,
        unsigned __int64 den,
        int modwanted
    )
    {
        unsigned __int64 bit = 1;
        unsigned __int64 res = 0;

        while (den < num && bit && !(den & (1L << 31))) {
            den <<= 1;
            bit <<= 1;
        }
        while (bit) {
            if (num >= den) {
                num -= den;
                res |= bit;
            }
            bit >>= 1;
            den >>= 1;
        }
        return modwanted ? num : res;
    }

    __int64 __cdecl __divdi3(
        __int64 a,
        __int64 b
    )
    {
        int neg = 0;
        __int64 res;

        if (a < 0) {
            a = -a;
            neg = !neg;
        }

        if (b < 0) {
            b = -b;
            neg = !neg;
        }

        res = udivmodsi4(a, b, 0);

        if (neg)
            res = -res;

        return res;
    }

    __int64 __cdecl __moddi3(
        __int64 a,
        __int64 b
    )
    {
        int neg = 0;
        __int64 res;

        if (a < 0) {
            a = -a;
            neg = 1;
        }

        if (b < 0)
            b = -b;

        res = udivmodsi4(a, b, 1);

        if (neg)
            res = -res;

        return res;
    }

    unsigned __int64 __cdecl __udivdi3(
        unsigned __int64 a,
        unsigned __int64 b
    )
    {
        return udivmodsi4(a, b, 0);
    }

    unsigned __int64 __cdecl __umoddi3(
        unsigned __int64 a,
        unsigned __int64 b
    )
    {
        return udivmodsi4(a, b, 1);
    }

    //https://github.com/sudokuhk/core/blob/master/libcompat/clock_gettime.c
    long clock_gettime(int clockid, struct timespec * tp)
    {
        tp->tv_sec = time(NULL);
        tp->tv_nsec = 0;
        return 0;
    }

    //https://github.com/sudokuhk/core/blob/master/libcompat/nanosleep.c
    int nanosleep(const struct timespec *rqtp, struct timespec *rmtp)
    {
        if (rmtp) {
            rmtp->tv_sec = 0;
            rmtp->tv_nsec = 0;
        }

        DWORD timeout = (DWORD)rqtp->tv_sec * 1000L;
        timeout += (rqtp->tv_nsec + 999999) / 1000000;

        Sleep(timeout);
        return 0;
    }

    //https://github.com/sudokuhk/core/blob/master/libcompat/mkdtemp.c
    int mkstemp(char * templatename)
    {
        #define MAXTRY 999999

        if (templatename == NULL || strlen(templatename) < 6) {
            errno = EINVAL;
            return -1;
        }

        int nname = strlen(templatename);
        char *xxx = templatename + nname - 6;

        if (strcmp(xxx, "XXXXXX") != 0) {
            errno = EINVAL;
            return -1;
        }

        for (int i = 0; i <= MAXTRY; i ++) {
            snprintf(xxx, 7, "%06d", i);

            if (_access(templatename, 0) == 0) {
                continue;
            }
            int fd = open(templatename, O_CREAT | O_WRONLY, 0600);
            if (fd >= 0) {
                return fd;
            }
        }

        errno = EEXIST;
        return -1;
    }

    int fsdkprintf(FILE * stream, const char * format, ...)
    {
        int cnt = 0;

        va_list args;
        va_start(args, format);
        cnt =  vfprintf_s(stream, format, args);
        va_end(args);
        return cnt;
    }

    int64_t fseeko64(FILE *stream, int64_t offset, int fromwhere)
    {
        return _fseeki64(stream, offset, fromwhere);
    }

    int64_t ftello64(FILE *stream)
    {
        return ftell(stream);
    }
#ifdef __cplusplus 
}
#endif 

#endif
