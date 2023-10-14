#pragma once

#include "ink/render/renderer.h"
#include "owl/geometry/primitive.h"
#include "owl/geometry/mesh.h"
#include "owl/types/matrix.h"
#include "owl/types/color.h"
#include "owl/types/interval.h"
#include <thread>


namespace ink {

class MarkerRenderer: public Renderer {
public:
    MarkerRenderer();
    ~MarkerRenderer();

    void queue_primitive(const owl::InstancedPrimitive3d& primitive, const owl::ColorRGBd& color);

    // Helper methods
    void queue_line(const owl::Vector3d& begin, const owl::Vector3d& end, double width, const owl::ColorRGBd& color);
    void queue_arrow(const owl::Vector3d& begin, const owl::Vector3d& end, double width, double head_length, double head_width, const owl::ColorRGBd& color);
    void queue_frame(const owl::Transform3d& pose, double axes_length, double axes_width);
    void queue_bounding_box(const owl::Transform3d& pose, const owl::BoundingBox3d& bounding_box, const owl::ColorRGBd& color);

    void render(
        const Eigen::Matrix4f& view,
        const Eigen::Matrix4f& projection) override;

private:
    void generate_meshes();
    bool init_opengl();

    std::jthread generate_meshes_thread;
    std::atomic<bool> running;
    std::atomic<bool> generate_done;
    bool init_done;

    float resolution;

    using Mesh = owl::Mesh<
        owl::make_vertex<float, 3,
            owl::vertex_attributes::position |
            owl::vertex_attributes::normal>,
        unsigned short,
        3
    >;

    struct Command {
        owl::ColorRGBf color;
        Eigen::Matrix4f model;
        std::size_t mesh_datas_index;
    };
    mutable std::vector<Command> commands;

    struct MeshData {
        std::size_t primitive;
        owl::MeshRange mesh_range;
    };
    std::vector<MeshData> mesh_datas;
    Mesh mesh_data;

    struct {
        // OpenGL shader parameter locations
        unsigned int program_id;
        unsigned int mvp_loc;
        unsigned int mv_loc;
        unsigned int color_loc;
        // OpenGL array/buffer objects
        unsigned int static_VAO, static_VBO, static_EBO;
    } glData;
};

} // namespace ink
