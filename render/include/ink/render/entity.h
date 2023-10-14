#pragma once

#include "ink/render/renderer.h"

namespace ink {

class Entity {
public:
    virtual bool init(Renderers& renderers) = 0;
    virtual void render(Renderers& renderers) = 0;
};

} // namespace ink
