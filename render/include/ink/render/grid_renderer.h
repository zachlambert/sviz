#pragma once

#include "ink/render/renderer.h"


namespace ink {

class GridRenderer: public Renderer {
public:
    GridRenderer();

    void render(
        const Eigen::Matrix4f& view,
        const Eigen::Matrix4f& projection) override;

    int create_grid();
    void configure_grid(int grid, double width, double line_width, int num_major_divisions, int num_minor_divisions);
    void queue_grid(int grid);

private:
    struct Vertex {
        Eigen::Vector3f position;
        Eigen::Vector4f color;
        Vertex() {}
        Vertex(const Eigen::Vector3f& position, const Eigen::Vector4f& color):
            position(position),
            color(color)
        {}
    };

    unsigned int program_id;
    unsigned int mvp_loc;

    struct Grid {
        bool initialised = false;
        mutable bool queued = false;
        unsigned int static_VAO;
        unsigned int static_VBO;
        float line_width;
        std::vector<Vertex> vertices;
    };
    std::vector<Grid> grids;
};

} // namespace ink
