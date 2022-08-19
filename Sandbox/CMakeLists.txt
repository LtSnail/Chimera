# Client Application

set( SOURCES
    SandboxApp.cpp
)

set( DEPENDENCIES
    ChimeraEngine
)

if (APPLE)
    set( GLOBAL_RESOURCES
        Resources/MacOS/Assets.xcassets
    )

    set( BASE_RESOURCES
        Resources/MacOS/Base.lproj/Main.storyboard
        ${ENGINE_SHADERS}
    )
endif()

set( RESOURCES
    ${GLOBAL_RESOURCES}
    ${BASE_RESOURCES}
)

if (APPLE)
    add_executable( Sandbox MACOSX_BUNDLE
        ${SOURCES}
        ${PUBLIC_HEADERS}
        ${PROJECT_HEADERS}
        ${PRIVATE_HEADERS}
        ${RESOURCES}
    )

    set_source_files_properties(
        ${RESOURCES}
        PROPERTIES
        MACOSX_PACKAGE_LOCATION
        Resources
    )
    
    set( MACOSX_BUNDLE_GUI_IDENTIFIER Sandbox )
    set( MACOSX_BUNDLE_BUNDLE_NAME ${ORGANIZATION}.Sandbox )
    
    set_target_properties( Sandbox
        PROPERTIES
        MACOSX_BUNDLE_INFO_PLIST
        ${CMAKE_CURRENT_SOURCE_DIR}/Resources/MacOS/Sandbox-Info.plist.in
    )
endif()

target_link_libraries( Sandbox
    ${DEPENDENCIES}
)