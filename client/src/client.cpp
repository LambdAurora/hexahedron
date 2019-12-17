#include "../include/hexahedron/client/client.hpp"
#include <memory>
#include <stdexcept>
#include <iostream>
#include <set>

namespace hexahedron
{
    void Renderer::create_surface() {
        if (glfwCreateWindowSurface(this->_vulkan, this->_client.get_window().get_handle(), nullptr, &_surface) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create window surface!");
        }
    }

    Renderer::Renderer(Client& client) : _client(client)
    {}

    void Renderer::init_vulkan() {
        VkApplicationInfo app_info = {};
        app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        app_info.pApplicationName = "Hexahedron";
        app_info.applicationVersion = VK_MAKE_VERSION(HEXAHEDRON_VERSION_MAJOR, HEXAHEDRON_VERSION_MINOR, HEXAHEDRON_VERSION_PATCH);
        app_info.pEngineName = "No engine";
        app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        app_info.apiVersion = VK_API_VERSION_1_1;

        VkInstanceCreateInfo create_info = {};
        create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        create_info.pApplicationInfo = &app_info;

        u32 glfw_extension_count = 0;
        const char** glfw_extensions;

        glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);

        create_info.enabledExtensionCount = glfw_extension_count;
        create_info.ppEnabledExtensionNames = glfw_extensions;

        create_info.enabledLayerCount = 0;

        if (vkCreateInstance(&create_info, nullptr, &this->_vulkan) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create Vulkan instance!");
        }
    }

    void Renderer::init() {
        this->init_vulkan();
        this->create_surface();
    }

    void Renderer::cleanup() {
        vkDestroySurfaceKHR(this->_vulkan, this->_surface, nullptr);
        vkDestroyInstance(this->_vulkan, nullptr);
    }

    Client::Client() : _window() {
        this->_renderer = std::make_unique<Renderer>(*this);
    }

    void Client::init() {
        glfwInit();
        this->_window.init(800, 600, "Hexahedron " + get_version());
        this->_renderer->init();
    }

    void Client::run() {
        while (!this->_window.should_close()) {
            glfwPollEvents();

            this->update();
        }

        this->shutdown();
    }

    void Client::update() {

    }

    void Client::shutdown() {
        this->_renderer->cleanup();
        this->_window.close();
        glfwTerminate();
    }
}

int main(int argc, char** argv) {
    hexahedron::Client client{};
    try {
        client.init();
        client.run();
    } catch (std::runtime_error& e) {
        std::cout << "Runtime error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
