cmake_minimum_required(VERSION 3.14)
project(ink)

# Setup

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)

set(BUILD_ADDITIONAL_TARGETS OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(BUILD_ADDITIONAL_TARGETS ON)
endif()

if(BUILD_ADDITIONAL_TARGETS)
    FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip DOWNLOAD_EXTRACT_TIMESTAMP false)
    include(GoogleTest)
    set(INSTALL_GTEST OFF)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    enable_testing()
    # subdirectories will add their own tests
endif()


# Dependencies

find_package(Eigen3 3.4 REQUIRED NO_MODULE)

FetchContent_Declare(cpp-utils
    GIT_REPOSITORY https://github.com/zachlambert/cpp-utils.git
    GIT_TAG master
)
FetchContent_MakeAvailable(cpp-utils)

FetchContent_Declare(parrot
    GIT_REPOSITORY https://github.com/zachlambert/parrot.git
    GIT_TAG master
)
FetchContent_MakeAvailable(parrot)

FetchContent_Declare(sentinel
    GIT_REPOSITORY https://github.com/zachlambert/sentinel.git
    GIT_TAG master
)
FetchContent_MakeAvailable(sentinel)

FetchContent_Declare(owl
    GIT_REPOSITORY https://github.com/zachlambert/owl.git
    GIT_TAG master
)
FetchContent_MakeAvailable(owl)


# Library

add_subdirectory(gui)
add_subdirectory(render)

add_library(ink INTERFACE)
target_link_libraries(ink INTERFACE
    ink_gui
)
