add_compile_definitions(CH_BUILD_LIB)

include_directories(External/spdlog/include)

# add_subdirectory(External)

set(SOURCE_FILES
        src/Chimera/Application.cpp
        src/Chimera/Log.cpp
)

set(HEADER_FILES
        src/Chimera/Application.h
        src/Chimera/Core.h
        src/Chimera/EntryPoint.h
        src/Chimera/Log.h
        src/Chimera/Events/Event.h
        src/Chimera/Events/KeyEvent.h
)

add_library(ChimeraEngine SHARED ${SOURCE_FILES} ${HEADER_FILES})
