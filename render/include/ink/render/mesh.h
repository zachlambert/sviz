#pragma once

#include "ink/render/entity.h"
#include "ink/render/mesh_renderer.h"
#include <owl/geometry/visual_mesh.h>

namespace ink {

class Mesh: public Entity {
public:
    Mesh(const std::shared_ptr<const owl::VisualMesh>& mesh):
        mesh(mesh),
        pose(owl::Transform3d::Identity()),
        mesh_index(-1)
    {}

    bool init(Renderers& renderers)
    {
        mesh_index = renderers.get<MeshRenderer>()->load_mesh(*mesh);
        return true;
    }
    void render(Renderers& renderers)
    {
        renderers.get<MeshRenderer>()->queue_mesh(mesh_index, pose, false);
    }

    void set_pose(const owl::Transform3d& pose)
    {
        this->pose = pose;
    }

private:
    std::shared_ptr<const owl::VisualMesh> mesh;
    int mesh_index;
    owl::Transform3d pose;
};

} // namespace ink
