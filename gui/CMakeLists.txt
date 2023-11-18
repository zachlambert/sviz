add_subdirectory(libs)

add_library(sviz-gui SHARED
    src/font.cpp
    src/window.cpp
)
target_include_directories(sviz-gui
    PRIVATE src
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
target_link_libraries(sviz-gui
    PUBLIC imgui cpp-utils GL glfw GLEW ${CMAKE_DL_LIBS}
)

add_executable(example_gui example/main.cpp)
target_link_libraries(example_gui PRIVATE sviz-gui)
