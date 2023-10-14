#pragma once

#include "ink/render/renderer.h"

namespace ink {

class Entity {
public:
    virtual void render(Renderers& renderers) const = 0;
};

} // namespace ink
