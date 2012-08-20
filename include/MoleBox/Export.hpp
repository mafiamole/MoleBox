#ifndef MOLEBOX_EXPORT_HPP
#define MOLEBOX_EXPORT_HPP

  #include <MoleBox/Config.hpp>

  #if defined(MOLEBOX_EXPORTS)
    #define MOLEBOX_API MB_API_EXPORT
  #else
    #define MOLEBOX_API MB_API_IMPORT
  #endif

#endif