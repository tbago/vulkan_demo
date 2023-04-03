#include "toy2d/context.hpp"
#include <vulkan/vulkan_core.h>
#include <vulkan/vulkan_handles.hpp>
#include <iostream>

namespace toy2d {

std::unique_ptr<Context> Context::instance_ = nullptr;

void Context::Init() {
    instance_.reset(new Context());
}

void Context::Quit() {
    instance_.reset();
}

Context &Context::Instance() {
    return *instance_;
}

Context::Context() {
    vk::InstanceCreateInfo create_info;

    std::vector<const char *> layers = {"VK_LAYER_KHRONOS_validation"};

    // auto layers = vk::enumerateInstanceLayerProperties();
    // for (auto layer : layers) {
    //     std::cout << layer.layerName << std::endl;
    // }
    vk::ApplicationInfo application_info;
    application_info.setApplicationVersion(VK_API_VERSION_1_2);
    create_info.setPApplicationInfo(&application_info)
        .setPEnabledLayerNames(layers);

    instance = vk::createInstance(create_info);
}

Context::~Context() {
    instance.destroy();
}

}  // namespace toy2d
