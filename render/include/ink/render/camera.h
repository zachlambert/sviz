#pragma once

#include <owl/transform/transform.h>


namespace ink {

class Camera {
public:
    Camera();
    void update_view(const owl::Transform3d& pose);
    void update_projection(float aspect_ratio);

    const owl::Matrix4f& get_view()const { return view; }
    const owl::Matrix4f& get_projection()const { return projection; }

private:
    float clipping_near;
    float clipping_far;
    float fov_degrees;

    owl::Matrix4f view;
    owl::Matrix4f projection;

    friend class CameraController;
};

} // namespace ink
