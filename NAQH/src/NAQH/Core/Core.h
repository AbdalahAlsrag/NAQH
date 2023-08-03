#ifndef _NQ_CORE_H_
#define _NQ_CORE_H_

#include "PlatformDetection.h"
#include <stdint.h>

#ifdef NQ_DEBUG
    #if defined(NQ_PLATFORM_WINDOWS)
        #define NQ_DEBUGBREAK() __debugbreak()
    #elif defined(NQ_PLATFORM_LINUX)
        #include <signal.h>
        #define NQ_DEBUGBREAK() raise(SIGTRAP)
    #else
        #error "Platform doesn't support debugbreak yet!"
    #endif
    #define NQ_ENABLE_ASSERTS
#else
    #define NQ_DEBUGBREAK()
#endif

#define NQ_EXPAND_MACRO(x) x
#define NQ_STRINGIFY_MACRO(x) #x

#define NQ_BIT(x) (1 << x)


#endif