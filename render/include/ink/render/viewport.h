#pragma once

#include <unordered_map>
#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <owl/types/color.h>
#include "ink/gui/widget.h"
#include "ink/render/entity.h"
#include "ink/render/renderer.h"
#include "ink/render/camera_controller.h"


namespace ink {

class Viewport: public Widget {
public:
    Viewport(int width, int height);

    bool init() override;
    void render() override;
    void add_entity(const std::string& name, const std::shared_ptr<Entity>& entity);

private:
    int width;
    int height;
    owl::ColorRGBd bg_color;

    // Frame buffer data
    struct {
        unsigned int fbo;
        unsigned int rbo;
        unsigned int texture_id;
    } glData;

    Renderers renderers;
    std::unordered_map<std::string, std::shared_ptr<Entity>> entities;
    Camera camera;
    CameraController camera_controller;
};

} // namespace ink
