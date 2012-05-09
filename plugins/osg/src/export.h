#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
    #if defined( GUI_LIBRARY )
    #  define GUI_EXPORT   __declspec(dllexport)
    #else
    #  define GUI_EXPORT   __declspec(dllimport)
    #endif
#else
    #define GUI_EXPORT
#endif
