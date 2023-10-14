#pragma once

#include "ink/render/renderer.h"
#include "owl/types/color.h"
#include "owl/geometry/visual_mesh.h"


namespace ink {

class MeshRenderer: public Renderer {
public:
    MeshRenderer();

    bool load_mesh(const owl::VisualMesh& mesh, const std::string& name);
    bool queue_mesh(
        const std::string& name,
        const owl::Transform3d& pose,
        bool wireframe);

    void render(
        const owl::Matrix4f& view,
        const owl::Matrix4f& projection) override;

private:
    struct Command {
        std::string mesh_name;
        owl::Matrix4f model;
        bool wireframe;
    };
    std::vector<Command> commands;

    unsigned int program_id;
    unsigned int mvp_loc;
    unsigned int m_loc;
    unsigned int static_VAO, static_VBO, static_EBO;

    owl::VisualMesh mesh_data;
    std::unordered_map<std::string, owl::MeshRange> mesh_ranges;
};

} // namespace ink
