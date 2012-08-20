/**
 *
 *   Config.hpp
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 **/

#if defined(_WIN32) || defined(__WIN32__)
#define MB_SYS_WINDOWS
#elif defined(linux) || defined(__linix)
#define MB_SYS_LINUX
#elif defined(__APPLE__) || defined(MACOSX) || defined(macintosh) || defined(Macintosh)
#define MB_SYS_MACOS
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#define MB_SYS_FREEBSD
#else
#error This operating system is not supported by one or more of Molebox`s dependencies
#endif


#if !defined(NDEBUG)
  #define MB_DEBUG
#endif

/**
 * Define helpers for import and export macros for each module
 */
#if !(MB_STATIC)
  #if defined(MB_SYS_WINDOWS)
    #define MB_API_EXPORT __declspec(dllexport)
    #define MB_API_IMPORT __declspec(dllimport)
  #else
    #if __GNUC__ >= 4
      #define MB_API_EXPORT
      #define MB_API_IMPORT
    #else
	#define SFML_API_EXPORT
	#define SFML_API_IMPORT
    #endif
  #endif
#else
  #define MB_API_EXPORT
  #define MB_API_IMPORT
#endif

 // #if defined(MB_SYS_WINDOWS)
 //   #define MB_API_EXPORT __declspec(dllexport)
 //   #define MB_API_IMPORT __declspec(dllimport)
 // #else
 //   #if __GNUC__ >= 4
 //     #define MB_API_EXPORT
 //     #define MB_API_IMPORT
 //   #else
	//#define SFML_API_EXPORT
	//#define SFML_API_IMPORT
 //   #endif
 // #endif