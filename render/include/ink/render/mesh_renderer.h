#pragma once

#include "ink/render/renderer.h"
#include "owl/types/color.h"
#include "owl/geometry/visual_mesh.h"


namespace ink {

class MeshRenderer: public Renderer {
public:
    MeshRenderer();

    int load_mesh(const owl::VisualMesh& mesh);
    bool queue_mesh(
        int mesh,
        const owl::Transform3d& pose,
        bool wireframe);

    void render(
        const owl::Matrix4f& view,
        const owl::Matrix4f& projection) override;

private:
    struct Command {
        int mesh_index;
        owl::Matrix4f model;
        bool wireframe;
    };
    std::vector<Command> commands;

    unsigned int program_id;
    unsigned int mvp_loc;
    unsigned int m_loc;
    unsigned int static_VAO, static_VBO, static_EBO;

    owl::VisualMesh mesh_data;
    std::vector<owl::MeshRange> mesh_ranges;
};

} // namespace ink
