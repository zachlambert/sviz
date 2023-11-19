# Tell imgui to use opengl and gl3 for the backend
add_compile_definitions(IMGUI_IMPL_OPENGL_LOADER_GL3)

add_library(imgui SHARED
    imgui/imgui.cpp
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    imgui/backends/imgui_impl_opengl3.cpp
    imgui/backends/imgui_impl_glfw.cpp
)
target_include_directories(imgui
    PUBLIC .
    PRIVATE imgui imgui/backends
)
