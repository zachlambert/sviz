#include <ink/gui/window.h>
#include <ink/render/viewport.h>

int main()
{
    ink::Window window("render");
    window.add_widget("viewport", std::make_unique<ink::Viewport>(1200, 900));
    window.run();
    return 0;
}
