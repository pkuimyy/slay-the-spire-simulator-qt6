include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE TEST_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/unit/*.cpp
)

add_executable(test
        ${TEST_SOURCES}
        main.cpp
)

target_link_libraries(test
        PRIVATE
        core
        GTest::gtest
        GTest::gtest_main
)

copy_core_dll(test)

include(GoogleTest)

gtest_discover_tests(test)