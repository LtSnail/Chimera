add_compile_definitions(CH_BUILD_LIB)

set(SOURCE_FILES
        src/Chimera/Application.cpp
)

set(HEADER_FILES
        src/Chimera/Application.h
        src/Chimera/Core.h
)

add_library(ChimeraEngine SHARED ${SOURCE_FILES} ${HEADER_FILES})
