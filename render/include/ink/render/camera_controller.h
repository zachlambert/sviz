#pragma once

#include <chrono>
#include <owl/transform/euler.h>
#include "ink/render/camera.h"


namespace ink {

class CameraController {
public:
    CameraController();

    void init(const owl::EulerTransform3d& start_pose, Camera& camera);
    void update_pose(float aspect_ratio, Camera& camera);
    bool is_clicked(owl::Vector3d& click_pos);

private:
    owl::Transform3d pose;

    enum class State {
        INACTIVE,
        INVALID,
        PAN,
        ROTATE,
        SCROLL
    } state;

    owl::Vector3d click_pos_cs;
    owl::Vector3d click_pos_ws;
    owl::Transform3d prev_camera_pose;

    float scroll_amount;
    typedef std::chrono::high_resolution_clock clock_t;
    clock_t::time_point scroll_start;
};

} // namespace ink
