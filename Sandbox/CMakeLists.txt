include_directories(../Engine/src)
include_directories(../Engine/External/spdlog/include)

add_executable(Sandbox SandboxApp.cpp)
target_link_libraries(Sandbox ChimeraEngine)
