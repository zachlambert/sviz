
#include <ink/gui/window.h>


class SimpleWidget: public ink::Widget {
public:
    const std::string& name() const override {
        return name_;
    }
    void render() override
    {
        ImGui::Text("Hello");
    }

private:
    const std::string name_ = "simple";
};

int main()
{
    ink::Window window("ink example");
    window.add_widget(std::make_shared<SimpleWidget>());
    window.run();
    return 0;
}
