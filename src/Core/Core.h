#pragma once

#if defined(_WIN32) || defined(__WINRT__)
    #define NQ_System_Windows
    #if _WIN64
        #define NQ_System_Windows_64
    #else 
        #define NQ_System_Windows_32
    #endif
#elif defined(ANDROID) || defined(__ANDROID__)
    #define NQ_System_Android
#elif defined(__APPLE__) || defined(__MACH__)
    #include <AvailabilityMacros.h>
    #include "TargetConditionals.h"
    #define NQ_System_AppleOS
    #if TARGET_OS_IPHONE
        #if TARGET_IPHONE_SIMULATOR
            #define NQ_System_IOS_Simulator
        #endif
        #define NQ_System_Iphone
    #elif TARGET_OS_MAC
        #define NQ_System_MacOS
        // if MAC_OS_X_VERSION_MIN_REQUIRED < 1070
        //  #error NQ for Mac OS X only supports deploying on 10.7 and above.
    #else
        #define NQ_System_Unidentified_Apple_OS
    #endif
#elif defined(__linux__) || defined(__linux) || defined(linux)
    #define NQ_System_Linux
#elif defined(__unix__) || defined(__unix) 
    #define NQ_System_Unix
#elif defined(__FreeBSD__)
    #define NQ_System_FreeBSD
#elif defined(BSD)
    #define NQ_System_BSD
#elif defined(__OpenBSD__)
    #define NQ_System_OpenBSD
#elif defined(__EMSCRIPTEN__)
   #define NQ_System_Emscripten
else
    #define NQ_System_Unidentified
#endif

#define BIT(x) (1 << x)

#ifdef NQ_System_Windows
    #ifdef NQ_Build_Dll
        #define NQ_API __declspec(dllexport)
    #else
        #define NQ_API __declspec(dllimport)
    #endif
#endif

/**
 * \brief A signed 8-bit integer type. Ranges between 127, -128
 */
typedef signed char Sint8;
#define B3KR_MAX_SINT8   ((Sint8)0x7F)           /* 127 */
#define B3KR_MIN_SINT8   ((Sint8)(~0x7F))        /* -128 */
/**
 * \brief An unsigned 8-bit integer type. Ranges between 255, 0
 */
typedef unsigned char Uint8;
#define B3KR_MAX_UINT8   ((Uint8)0xFF)           /* 255 */
#define B3KR_MIN_UINT8   ((Uint8)0x00)           /* 0 */
/**
 * \brief A signed 16-bit integer type. Ranges between 32767, -32768
 */
typedef short Sint16;
#define B3KR_MAX_SINT16  ((Sint16)0x7FFF)        /* 32767 */
#define B3KR_MIN_SINT16  ((Sint16)(~0x7FFF))     /* -32768 */
/**
 * \brief An unsigned 16-bit integer type. Ranges between 65535, 0
 */
typedef unsigned short Uint16;
#define B3KR_MAX_UINT16  ((Uint16)0xFFFF)        /* 65535 */
#define B3KR_MIN_UINT16  ((Uint16)0x0000)        /* 0 */
/**
 * \brief A signed 32-bit integer type. Ranges between 2147483647, -2147483648
 */
typedef int Sint32;
#define B3KR_MAX_SINT32  ((Sint32)0x7FFFFFFF)    /* 2147483647 */
#define B3KR_MIN_SINT32  ((Sint32)(~0x7FFFFFFF)) /* -2147483648 */
/**
 * \brief An unsigned 32-bit integer type. Ranges between 4294967295, 0
 */
typedef unsigned int Uint32;
#define B3KR_MAX_UINT32  ((Uint32)0xFFFFFFFFu)   /* 4294967295 */
#define B3KR_MIN_UINT32  ((Uint32)0x00000000)    /* 0 */

/**
 * \brief A signed 64-bit integer type. Ranges between 9223372036854775807, -9223372036854775808
 */
typedef long long Sint64;
#define B3KR_MAX_SINT64  ((Sint64)0x7FFFFFFFFFFFFFFFll)      /* 9223372036854775807 */
#define B3KR_MIN_SINT64  ((Sint64)(~0x7FFFFFFFFFFFFFFFll))   /* -9223372036854775808 */
/**
 * \brief An unsigned 64-bit integer type. Ranges between 18446744073709551615, 0
 */
typedef unsigned long long Uint64;
#define B3KR_MAX_UINT64  ((Uint64)0xFFFFFFFFFFFFFFFFull)     /* 18446744073709551615 */
#define B3KR_MIN_UINT64  ((Uint64)(0x0000000000000000ull))   /* 0 */