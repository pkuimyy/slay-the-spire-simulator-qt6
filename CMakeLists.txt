cmake_minimum_required(VERSION 3.31)
project(slay_the_spire_simulator_qt6 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define QT_INSTALL_PATH cache variable, user must provide
if (NOT DEFINED QT_INSTALL_PATH)
    message(STATUS "QT_INSTALL_PATH is not defined. UI will not be built.")
    set(QT_INSTALL_PATH "" CACHE PATH "Path to Qt6 installation (required for UI)")
else ()
    message(STATUS "QT_INSTALL_PATH is set to: ${QT_INSTALL_PATH}")
    set(QT_INSTALL_PATH ${QT_INSTALL_PATH} CACHE PATH "Path to Qt6 installation (required for UI)" FORCE)
    set(Qt6_DIR "${QT_INSTALL_PATH}/lib/cmake/Qt6" CACHE PATH "Qt6 cmake dir" FORCE)
    message(STATUS "Qt6_DIR is set to: ${Qt6_DIR}")
endif ()

function(copy_core_dll target)
    add_custom_command(TARGET ${target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:core>
            $<TARGET_FILE_DIR:${target}>
    )
endfunction()

# Always build core library
add_subdirectory(core)
add_subdirectory(tui)
add_subdirectory(tests)

# Conditionally build ui only if QT_INSTALL_PATH is set and non-empty
if (QT_INSTALL_PATH)
    add_subdirectory(gui)
else ()
    message(STATUS "Skipping UI build because QT_INSTALL_PATH is not set or empty.")
endif ()
