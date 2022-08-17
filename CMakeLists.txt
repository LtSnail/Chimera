cmake_minimum_required(VERSION 3.24)

project(Chimera)

if(UNIX AND APPLE)
    message(STATUS "Platform: MacOS")
    add_compile_definitions(CH_PLATFORM_MACOS)
elseif(WIN32)
    message(STATUS "Platform: Windows")
    add_compile_definitions(CH_PLATFORM_WINDOWS)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (MSVC)
    add_compile_options(/W4 /WX /Za /permissive-)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_subdirectory(Engine)
add_subdirectory(Sandbox)
