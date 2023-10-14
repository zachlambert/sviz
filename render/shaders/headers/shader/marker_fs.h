#ifndef GEN_SHADER_marker_fs_h
#define GEN_SHADER_marker_fs_h
#include <string>

namespace shader {

static const std::string marker_fs = R"V0G0N(
#version 330 core

in vec4 vertexColor;
in vec3 Position_cameraspace;
in vec3 Normal_cameraspace;
out vec4 color;

void main(){
    // Light as if the light comes from the camera view
    float cosTheta = clamp(dot(Normal_cameraspace, vec3(0, 0, 1)), 0, 1);
    color = vertexColor * cosTheta;
}
)V0G0N";

} //namespace shader

#endif
