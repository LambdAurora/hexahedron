#ifndef HEXAHEDRON_CLIENT_HPP
#define HEXAHEDRON_CLIENT_HPP

#include "window.hpp"
#include <memory>

namespace hexahedron
{
    class Client;

    // @TODO move that to its own file.
    class Renderer;

    class Client
    {
    private:
        std::unique_ptr<Renderer> _renderer;
        Window _window;

    public:
        Client();

        void init();

        void run();

        void update();

        void shutdown();

        /*!
         * Gets the window of the client.
         * @return The client's window.
         */
        const Window& get_window() const {
            return _window;
        }
    };

    class Renderer
    {
    private:
        Client& _client;
        VkInstance _vulkan;
        VkSurfaceKHR _surface;
        VkQueue _present_queue;

        void init_vulkan();

    public:
        Renderer(Client& client);

        void init();

        void cleanup();

        void create_surface();
    };
}

#endif //HEXAHEDRON_CLIENT_HPP
