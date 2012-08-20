#include <MoleBox/Config.hpp>

#if defined(MB_LUA_EXPORTS)
  #define MOLEBOX_LUA_API MB_API_EXPORT
#else
  #define MOLEBOX_LUA_API MB_API_IMPORT
#endif
