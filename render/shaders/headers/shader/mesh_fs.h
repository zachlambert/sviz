#ifndef GEN_SHADER_mesh_fs_h
#define GEN_SHADER_mesh_fs_h
#include <string>

namespace shader {

static const std::string mesh_fs = R"V0G0N(
#version 330 core

in vec4 vertexColor;
in vec3 Normal_worldspace;
out vec4 color;

void main(){
    float cosTheta = clamp(dot(Normal_worldspace, vec3(0, 0, 1)), 0, 1);
    float factor = 0.5 + 0.5 * cosTheta;
    color = vertexColor * factor;
}
)V0G0N";

} //namespace shader

#endif
