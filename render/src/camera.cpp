#include "ink/render/camera.h"
#include <imgui.h>
#include <owl/transform/radians.h>


namespace ink {

Camera::Camera():
    clipping_near(0.01),
    clipping_far(100.0),
    fov_degrees(70)
{}

void Camera::update_projection(float aspect_ratio) {
    projection.setZero();
    float half_width = clipping_near * std::tan(owl::to_radians(fov_degrees) / 2);
    float half_height = half_width / aspect_ratio;
    projection(0, 0) = clipping_near / half_width;
    projection(1, 1) = clipping_near / half_height;
    projection(2, 2) = - (clipping_near + clipping_far) / (clipping_far - clipping_near);
    projection(2, 3) = - 2 * clipping_near * clipping_far / (clipping_far - clipping_near);
    projection(3, 2) = -1;
}

void Camera::update_view(const owl::Transform3d& pose) {
    owl::Matrix4f to_screen = owl::Matrix4f::Identity();
    to_screen.block<3, 1>(0, 0) = -owl::Vector3f::UnitZ();
    to_screen.block<3, 1>(0, 1) = -owl::Vector3f::UnitX();
    to_screen.block<3, 1>(0, 2) = owl::Vector3f::UnitY();
    view = to_screen * pose.inverse().cast<float>().matrix();
}

} // namespace gui
