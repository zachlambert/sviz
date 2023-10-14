#pragma once

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

namespace ink {

unsigned int load_shader(const std::string &vs_code, const std::string &fs_code);

} // namespace ink
