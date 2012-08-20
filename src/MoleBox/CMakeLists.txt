
set (HEADERS  
	  ${MB_INCLUDE_DIR}/MoleBox/Config.hpp
	  ${MB_INCLUDE_DIR}/MoleBox/Export.hpp
	  ${MB_INCLUDE_DIR}/MoleBox/GameObject.hpp
	  ${MB_INCLUDE_DIR}/MoleBox/Patterns.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Game.hpp
      ${MB_INCLUDE_DIR}/MoleBox/SMGame.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Types.hpp
	  ${MB_INCLUDE_DIR}/MoleBox/GameConfig.hpp
      ${MB_INCLUDE_DIR}/MoleBox/GameComponent.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Logger.hpp

      ${MB_INCLUDE_DIR}/MoleBox/Content/Container.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Content/ContainerTemplate.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Content/ID.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Content/ContentID.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Content/SpriteBatch.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Content/SpriteSheet.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Content/Content.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Content/Resources.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Content/SpriteSceneGraph/Node.hpp
      
      ${MB_INCLUDE_DIR}/MoleBox/Actions/Action.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Actions/Actions.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Actions/Keyboard.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Actions/Mouse.hpp
    )

set (SOURCES
  SMGame.cpp
  GameState.cpp
  GameObject.cpp
  GameComponent.cpp
  Game.cpp
  GameConfig.cpp
  Patterns.cpp
  Logger.cpp

  Content/ID.cpp
  Content/ContentID.cpp
  Content/ContainerTemplate.cpp
  Content/Container.cpp
  Content/SpriteBatch.cpp
  Content/SpriteSheet.cpp
  Content/Resources.cpp
  Content/SpriteSceneGraph/Node.cpp

  Actions/Action.cpp
  Actions/Actions.cpp
  Actions/Keyboard.cpp
  Actions/Mouse.cpp
  )

  if (SFML_FOUND)
    set( MB_LIBS ${SFML_LIBRARIES} ${OPENGL_gl_LIBRARY} ${GLU_LIBRARY} ${LUA_LIBRARIES} )
	if (BUILD_SHARED_LIBS)
		add_library(MoleBox-Core SHARED ${HEADERS} ${SOURCES})
	else()
		add_library(MoleBox-Core STATIC ${HEADERS} ${SOURCES})
	endif()
    set_target_properties(MoleBox-Core PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
    target_link_libraries(MoleBox-Core ${MB_LIBS})

    add_subdirectory(Content)
    add_subdirectory(Actions)
    if (INCLUDE_LUA)
      add_subdirectory(Lua)
      if (LUA_EDITOR_TOOL)
	add_subdirectory(ResourceUI)
      endif()
    endif()
  endif()

