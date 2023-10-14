#pragma once

#include <string>

namespace ink {

class Widget {
public:
    virtual bool init() { return true; }
    virtual void shutdown() {}
    virtual void render() {}
};

} // namespace ink
