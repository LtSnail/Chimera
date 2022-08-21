cmake_minimum_required(VERSION 3.24)

project(
    Chimera
    VERSION 0.1
    DESCRIPTION "MacOS and Windows game engine"
    LANGUAGES CXX OBJCXX
)

if( CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME )
    set( CMAKE_CXX_EXTENSIONS OFF )
    set_property( GLOBAL PROPERTY USE_FOLDERS ON )
endif()

set( ORGANIZATION Organization )

add_subdirectory( Engine )
add_subdirectory( Sandbox )
