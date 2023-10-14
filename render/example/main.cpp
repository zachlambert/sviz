#include <ink/gui/window.h>
#include <ink/render/viewport.h>
#include <ink/render/grid.h>
#include <ink/render/mesh.h>
#include <owl/geometry/primitive.h>
#include <owl/geometry/primitive_conversions.h>
#include <owl/geometry/visual_mesh.h>

int main()
{
    owl::Sphere3f sphere;
    sphere.radius = 1;
    auto mesh = std::make_shared<owl::VisualMesh>();
    owl::primitive_to_mesh(sphere, 0.3, *mesh);
    for (auto& vertex: mesh->vertices) {
        vertex.color = owl::ColorRGBf::Red();
    }


    ink::Window window("render");

    auto viewport = std::make_shared<ink::Viewport>(1200, 900);
    viewport->add_entity("grid", std::make_shared<ink::Grid>());
    viewport->add_entity("mesh", std::make_shared<ink::Mesh>(mesh));

    window.add_widget("viewport", viewport);
    window.run();
    return 0;
}
