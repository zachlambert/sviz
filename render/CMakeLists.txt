set(shader_list)
function(add_shader file label)
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_LIST_DIR}/shaders/headers/shader/${label}.h
        COMMAND ./gen_shader_h.sh ${file} ${label}
        DEPENDS ${CMAKE_CURRENT_LIST_DIR}/shaders/${file} ${CMAKE_CURRENT_LIST_DIR}/gen_shader_h.sh
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    )
    set(shader_list ${shader_list} shaders/headers/shader/${label}.h PARENT_SCOPE)
endfunction()

add_shader(grid.fs grid_fs)
add_shader(grid.vs grid_vs)
add_custom_target(generated_shaders ALL DEPENDS ${shader_list})

add_library(ink_render SHARED
    src/camera.cpp
    src/camera_controller.cpp
    src/grid_renderer.cpp
    src/shader.cpp
    src/viewport.cpp
)
target_include_directories(ink_render
    PRIVATE src shaders/headers
    PUBLIC include
)
target_link_libraries(ink_render
    PUBLIC ink_gui owl
)
add_dependencies(ink_render generated_shaders)

add_executable(example_render example/main.cpp)
target_link_libraries(example_render PRIVATE ink_render)
