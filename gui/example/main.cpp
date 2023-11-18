
#include <sviz/gui/window.h>


class MessageViewer: public sviz::Widget {
public:
    MessageViewer(const std::string& message):
        message_(message)
    {}
    void render() override
    {
        ImGui::Text("%s", message_.c_str());
    }

private:
    const std::string message_;
};

int main()
{
    sviz::Window window("ink example");
    window.add_widget("message a", std::make_shared<MessageViewer>("hello a"));
    window.add_widget("message b", std::make_shared<MessageViewer>("hello b"));
    window.run();
    return 0;
}
