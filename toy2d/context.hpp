#pragma once

#include <memory>
#include <vulkan/vulkan.hpp>

namespace toy2d {

class Context final {
public:
    static void Init();
    static void Quit();
    static Context &Instance();
    ~Context();

    vk::Instance instance;
private:
    Context();

    static std::unique_ptr<Context> instance_;
};

}  // namespace toy2d
