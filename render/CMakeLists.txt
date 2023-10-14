add_library(ink_render SHARED
    src/camera.cpp
    src/camera_controller.cpp
    src/viewport.cpp
)
target_include_directories(ink_render
    PRIVATE src
    PUBLIC include
)
target_link_libraries(ink_render
    PUBLIC ink_gui owl
)

add_executable(example_render example/main.cpp)
target_link_libraries(example_render PRIVATE ink_render)
