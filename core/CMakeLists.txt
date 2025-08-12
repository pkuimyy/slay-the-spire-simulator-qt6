file(GLOB_RECURSE CORE_SOURCES
        component/*.cpp
        entity/*.cpp
        event/*.cpp
        system/*.cpp
        manager/*.cpp
)

add_library(core SHARED ${CORE_SOURCES})

target_include_directories(core PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

include(FetchContent)

# entt
FetchContent_Declare(
        entt
        GIT_REPOSITORY https://github.com/skypjack/entt.git
        GIT_TAG v3.15.0
)
FetchContent_MakeAvailable(entt)

# fmt
#FetchContent_Declare(
#        fmt
#        GIT_REPOSITORY https://github.com/fmtlib/fmt
#        GIT_TAG 11.2.0
#)
#FetchContent_MakeAvailable(fmt)

# spdlog
#set(SPDLOG_FMT_EXTERNAL ON CACHE BOOL "Use external fmt" FORCE)
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.15.3
)
FetchContent_MakeAvailable(spdlog)

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

