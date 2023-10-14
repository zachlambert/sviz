#include <ink/gui/window.h>
#include <ink/render/viewport.h>
#include <ink/render/grid.h>

int main()
{
    ink::Window window("render");
    auto viewport = std::make_shared<ink::Viewport>(1200, 900);
    viewport->add_entity("grid", std::make_shared<ink::Grid>());
    window.add_widget("viewport", viewport);
    window.run();
    return 0;
}
