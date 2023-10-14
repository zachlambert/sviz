#ifndef GEN_SHADER_grid_fs_h
#define GEN_SHADER_grid_fs_h
#include <string>

namespace shader {

static const std::string grid_fs = R"V0G0N(
#version 330 core

in vec4 vertexColor;
out vec4 color;

void main(){
    color = vertexColor;
}
)V0G0N";

} //namespace shader

#endif
