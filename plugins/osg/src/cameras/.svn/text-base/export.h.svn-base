#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
    #if defined( CAMERAS_LIBRARY )
    #  define CAMERAS_EXPORT   __declspec(dllexport)
    #else
    #  define CAMERAS_EXPORT   __declspec(dllimport)
    #endif
#else
    #define CAMERAS_EXPORT
#endif
