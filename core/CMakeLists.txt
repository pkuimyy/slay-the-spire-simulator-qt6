file(GLOB_RECURSE CORE_SOURCES
        entity/*.cpp
        include/event/*.cpp
        src/system/*.cpp
        manager/*.cpp
)

add_library(core SHARED ${CORE_SOURCES})

target_include_directories(core PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(FetchContent)

# entt
FetchContent_Declare(
        entt
        GIT_REPOSITORY https://github.com/skypjack/entt.git
        GIT_TAG v3.15.0
)
FetchContent_MakeAvailable(entt)

target_precompile_headers(core PUBLIC
        include/pch.h
)

target_link_libraries(core PUBLIC
        EnTT::EnTT
        spdlog::spdlog_header_only
)

set_target_properties(core PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
)

