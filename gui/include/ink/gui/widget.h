#pragma once

#include <string>

namespace ink {

class Widget {
public:
    virtual const std::string& name() const = 0;
    virtual bool init() { return true; }
    virtual void shutdown() {}
    virtual void render() {}
};

} // namespace ink
