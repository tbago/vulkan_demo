#include "toy2d/context.hpp"

#include <iostream>
#include <vulkan/vulkan_core.h>
#include <vulkan/vulkan_enums.hpp>
#include <vulkan/vulkan_handles.hpp>

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
    CreateInstance();
    PickupPhysicalDevice();
    QueryQueueFamilyIndices();
    CreateDevice();
    GetQueue();
}

Context::~Context() {
    device.destroy();
    instance.destroy();
}

void Context::CreateInstance() {
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

void Context::PickupPhysicalDevice() {
    auto devices = instance.enumeratePhysicalDevices();

    for (auto &device : devices) {
        // auto feature = device.getFeatures();
        std::cout << device.getProperties().deviceName << std::endl;
    }
    physical_device = devices[0];
}

void Context::CreateDevice() {
    vk::DeviceCreateInfo create_info;
    vk::DeviceQueueCreateInfo queue_create_info;
    float priorities = 1.0;
    queue_create_info.setPQueuePriorities(&priorities)
        .setQueueCount(1)
        .setQueueFamilyIndex(queue_family_indices.graphics_queue.value());

    create_info.setQueueCreateInfos(queue_create_info);

    device = physical_device.createDevice(create_info);
}

void Context::QueryQueueFamilyIndices() {
    auto properties = physical_device.getQueueFamilyProperties();
        for (int i = 0; i < properties.size(); i++) {
            auto &property = properties[i];
            if (property.queueFlags | vk::QueueFlagBits::eGraphics) {
                queue_family_indices.graphics_queue = i;
                break;
            }
        }
    }

void Context::GetQueue() {
    graphcis_queue = device.getQueue(queue_family_indices.graphics_queue.value(), 0);
}

}  // namespace toy2d
