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
        ${CMAKE_CURRENT_SOURCE_DIR}/component
        ${CMAKE_CURRENT_SOURCE_DIR}/entity
        ${CMAKE_CURRENT_SOURCE_DIR}/system
        ${CMAKE_CURRENT_SOURCE_DIR}/manager
)

include(FetchContent)
FetchContent_Declare(
        entt
        GIT_REPOSITORY https://github.com/skypjack/entt.git
        GIT_TAG v3.15.0
)
FetchContent_MakeAvailable(entt)

target_link_libraries(core PUBLIC EnTT::EnTT)

set_target_properties(core PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
)

