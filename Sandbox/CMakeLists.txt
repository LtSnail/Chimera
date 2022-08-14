include_directories(../Engine/src)

add_executable(Sandbox SandboxApp.cpp)
target_link_libraries(Sandbox ChimeraEngine)
