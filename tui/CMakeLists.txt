set(SOURCES
        main.cpp
)

add_executable(tui main.cpp)

target_link_libraries(tui PRIVATE core)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftime-report")

copy_core_dll(tui)
