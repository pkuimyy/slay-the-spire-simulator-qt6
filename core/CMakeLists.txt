add_library(core SHARED
        main.cpp
)

target_include_directories(core PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(core PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
)
