#pragma once

#include <owl/types/matrix.h>
#include <memory>
#include <type_traits>

namespace ink {

class Renderer {
public:
    virtual void render(const owl::Matrix4f& view, const owl::Matrix4f& projection) = 0;
};

class Renderers {
public:
    template <typename T>
    std::shared_ptr<T> get_renderer()
    {
        static_assert(std::is_base_of_v<Renderer, T>);
        for (auto& renderer: renderers) {
            if (auto downcasted = std::dynamic_pointer_cast<T>(renderer)) {
                return downcasted;
            }
        }
        auto renderer = std::make_shared<T>();
        renderers.push_back(renderer);
        return renderer;
    }

    void render(const owl::Matrix4f& view, const owl::Matrix4f& projection)
    {
        for (auto& renderer: renderers) {
            renderer->render(view, projection);
        }
    }

private:
    std::vector<std::shared_ptr<Renderer>> renderers;
};

} // namespace ink
