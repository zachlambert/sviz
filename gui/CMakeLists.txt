add_subdirectory(libs)

add_library(ink_gui SHARED
    src/font.cpp
    src/window.cpp
)
target_include_directories(ink_gui
    PRIVATE src
    PUBLIC include
)
target_link_libraries(ink_gui
    PUBLIC imgui cpp-utils GL glfw GLEW ${CMAKE_DL_LIBS}
)

add_executable(example_gui example/main.cpp)
target_link_libraries(example_gui PRIVATE ink_gui)
