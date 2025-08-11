set(SOURCES
        main.cpp
)

add_executable(tui main.cpp)

target_link_libraries(tui PRIVATE core)

copy_core_dll(tui)
