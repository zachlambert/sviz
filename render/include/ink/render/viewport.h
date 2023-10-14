#pragma once

#include "ink/gui/widget.h"
#if 0
#include <vector>
#include "gui/gui/widget.h"
#include "gui/render/viewer_item.h"
#include "gui/render/renderer.h"
#include "gui/render/frame_buffer.h"
#include "gui/render/camera_controller.h"
#include "gui/render/camera.h"
#include "gui/render/renderer_list.h"
#include "gui/render/grid_renderer.h"
#include "gui/render/marker_renderer.h"
#include "math/transform/euler.h"
#endif


namespace ink {

class Viewport: public Widget {
public:
    bool init() override
    {
        return true;
    }
    void shutdown() override
    {

    }
    void render() override
    {

    }
#if 0
    template <typename... ViewerItems>
    Viewport(
        const std::string_view& name,
        ViewerItems&& ...items
    ):
        name_(name),
        bg_color(math::ColorRGBf(1, 1, 1)),
        buffer_width(1200),
        buffer_height(1200),
        camera_start_pose(math::EulerTransform3d(math::EulerRotation3d(0, 0.9, 0), math::Vector3d(-10, 0, 10)))
    {
        create_items(std::forward<ViewerItems>(items)...);
    }

    void create_items() {}
    void create_items(ViewerItem& item) {
        children.emplace_back(item);
    }
    template <typename... ViewerItems>
    void create_items(ViewerItem& item, ViewerItems&&... items)
    {
        children.emplace_back(item);
        create_items(std::forward<ViewerItems>(items)...);
    }

    const std::string& name() const override { return name_; }

private:
    void gui_render(const gui::UserInput& user_input) override;
    bool init() override;
    bool from_json(core::JsonConstNode node) override;
    void to_json(core::JsonNode node) const override;
    bool gui_edit(const std::string& label) override;

    const std::string name_;

    struct Child {
        const std::string name;
        ViewerItem& item;
        bool enabled;
        Child(ViewerItem& item):
            name(item.name()),
            item(item),
            enabled(true)
        {}
    };
    std::vector<Child> children;

    math::ColorRGBf bg_color;
    int buffer_width;
    int buffer_height;
    math::EulerTransform3d camera_start_pose;

    std::shared_ptr<GridRenderer> grid_renderer;
    std::shared_ptr<MarkerRenderer> marker_renderer;

    RendererList renderer_list;
    Camera camera;
    CameraController camera_controller;
    FrameBuffer frame_buffer;
#endif
};

} // namespace ink
