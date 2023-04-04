#pragma once

#include <memory>
#include <vulkan/vulkan.hpp>
#include <optional>

namespace toy2d {

class Context final {
public:
    static void Init();
    static void Quit();
    static Context &Instance();
    ~Context();

    vk::Instance instance;
    vk::PhysicalDevice physical_device;
    vk::Device device;
    vk::Queue graphcis_queue;

    struct QueueFamilyIndices final {
        std::optional<uint32_t> graphics_queue;
    };

    QueueFamilyIndices queue_family_indices;
private:
    Context();
    void CreateInstance();
    void PickupPhysicalDevice();
    void CreateDevice();
    void QueryQueueFamilyIndices();
    void GetQueue();
private:
    static std::unique_ptr<Context> instance_;
};

}  // namespace toy2d
