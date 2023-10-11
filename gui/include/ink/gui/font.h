#pragma once

#include <optional>
#include <string>

namespace ink {

enum class Font {
    DejaVuSans,
    DejaVuSerif,
    DejaVuSansMono
};

std::optional<std::string> find_font_path(Font font);

} // namespace ink
