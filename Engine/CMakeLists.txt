# Engine

set( PROJECT_HEADERS 
    Chimera/Application.h
    Chimera/Core.h
    Chimera/EntryPoint.h
    Chimera/Log.h
    Chimera/Events/Event.h
    Chimera/Events/KeyEvent.h
    Chimera/Events/MouseEvent.h
    Chimera/Events/ApplicationEvent.h
)

set( SOURCES
    Chimera/Application.cpp
    Chimera/Log.cpp
)

if ( APPLE )
    set( PROJECT_HEADERS
        ${PROJECT_HEADERS}
        Chimera/MacOS/ChimeraApplication.h
        Chimera/MacOS/AppDelegate.h
        Chimera/MacOS/GameViewController.h
        Chimera/MacOS/ShaderTypes.h
        Chimera/MacOS/Renderer.h
    )

    set( SOURCES
        ${SOURCES}
        Chimera/MacOS/AppDelegate.mm
        Chimera/MacOS/GameViewController.mm
        Chimera/MacOS/Renderer.mm
        Chimera/MacOS/ChimeraApplication.mm
    )

    set( ENGINE_SHADERS 
        ${CMAKE_CURRENT_SOURCE_DIR}/Chimera/MacOS/Shaders.metal
        PARENT_SCOPE
    )

    find_library( APPKIT AppKit )
    find_library( METAL Metal )
    find_library( METALKIT MetalKit )
    find_library( MODELIO ModelIO )

    set( DEPENDENCIES
        ${APPKIT}
        ${METAL}
        ${METALKIT}
        ${MODELIO}
    )
endif()

add_library( ChimeraEngine
    SHARED
    ${SOURCES}
    ${PROJECT_HEADERS}
    ${DEPENDENCIES}
)

target_link_libraries( ChimeraEngine
    ${DEPENDENCIES}
)

target_include_directories( ChimeraEngine PUBLIC External/spdlog/include ${CMAKE_CURRENT_SOURCE_DIR} )

target_compile_definitions( ChimeraEngine PUBLIC CH_BUILD_LIB )
target_compile_features( ChimeraEngine PUBLIC cxx_std_17 )

if (MSVC)
    target_compile_options( ChimeraEngine PRIVATE /W4 /WX /Za /permissive- )
else()
    # -pedantic
    target_compile_options( ChimeraEngine PRIVATE -Wall -Wextra -Werror )
endif()

if( UNIX AND APPLE )
    message( STATUS "The target platform is MacOS" )
    target_compile_definitions( ChimeraEngine PUBLIC CH_PLATFORM_MACOS )
    target_compile_options( ChimeraEngine PRIVATE -fobjc-arc )
elseif( WIN32 )
    message( STATUS "The target platform is Windows" )
    target_compile_definitions( ChimeraEngine PUBLIC CH_PLATFORM_WINDOWS )
endif()
