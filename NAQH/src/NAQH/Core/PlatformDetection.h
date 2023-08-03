#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    #define NQ_PLATFORM_WINDOWS
    #ifdef _WIN64
        #define NQ_PLATFORM_WINDOWS_64
    #else
        #define NQ_PLATFORM_WINDOWS_32
    #endif
#elif defined(__APPLE__) || defined(__MACH__)
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR
        #define NQ_PLATFORM_IPHONE_SIMULATOR
    #elif TARGET_OS_MACCATALYST
        #define NQ_PLATFORM_MACCATALYST
    #elif TARGET_OS_IPHONE
        #define NQ_PLATFORM_IOS
    #elif TARGET_OS_MAC
        #define NQ_PLATFORM_MACOS
    #else
        #error "Unknown Apple platform"
    #endif
#elif defined(__ANDROID__)
// Below __linux__ check should be enough to handle Android,
// but something may be unique to Android.
#elif defined(__linux__) || defined(__linux)
// linux
#elif defined(__unix__) || defined(__unix)
// Unix
#elif defined(_POSIX_VERSION)
// POSIX
#else
    #error "Unknown compiler"
#endif
