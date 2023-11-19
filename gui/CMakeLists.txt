add_library(sviz-gui SHARED
    src/font.cpp
    src/window.cpp
    libs/imgui/imgui.cpp
    libs/imgui/imgui_demo.cpp
    libs/imgui/imgui_draw.cpp
    libs/imgui/imgui_tables.cpp
    libs/imgui/imgui_widgets.cpp
    libs/imgui/backends/imgui_impl_opengl3.cpp
    libs/imgui/backends/imgui_impl_glfw.cpp
)
target_include_directories(sviz-gui
    PRIVATE
        src
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui>
        $<INSTALL_INTERFACE:include>
)
target_link_libraries(sviz-gui
    PUBLIC cpp-utils GL glfw GLEW ${CMAKE_DL_LIBS}
)

add_executable(example_gui example/main.cpp)
target_link_libraries(example_gui PRIVATE sviz-gui)
