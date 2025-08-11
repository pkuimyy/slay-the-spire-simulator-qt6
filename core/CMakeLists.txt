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

include(FetchContent)
FetchContent_Declare(
        entt
        GIT_REPOSITORY https://github.com/skypjack/entt.git
        GIT_TAG v3.15.0
)
FetchContent_MakeAvailable(entt)

target_link_libraries(core PUBLIC EnTT::EnTT)

