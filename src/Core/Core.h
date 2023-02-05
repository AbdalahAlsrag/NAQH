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

#ifdef NQ_System_Windows
    #ifdef NQ_Build_Dll
        #define NQ_API __declspec(dllexport)
    #else
        #define NQ_API __declspec(dllimport)
    #endif
#endif