cmake_minimum_required(VERSION 3.14)
project(sviz)

# Setup

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)

set(BUILD_ADDITIONAL_TARGETS OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(BUILD_ADDITIONAL_TARGETS ON)
endif()

if(BUILD_ADDITIONAL_TARGETS)
    FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip)
    include(GoogleTest)
    set(INSTALL_GTEST OFF)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    enable_testing()
    # subdirectories will add their own tests
endif()


# Dependencies

find_package(Eigen3 3.4 REQUIRED NO_MODULE)
find_package(cpp-utils REQUIRED)
find_package(datapack REQUIRED)
find_package(mbox REQUIRED)


# Library

add_subdirectory(gui)
# add_subdirectory(render)

add_library(sviz INTERFACE)
target_link_libraries(sviz INTERFACE
    sviz-gui
)
