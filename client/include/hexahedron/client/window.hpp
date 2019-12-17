#ifndef HEXAHEDRON_WINDOW_HPP
#define HEXAHEDRON_WINDOW_HPP

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <hexahedron/hexahedron.hpp>

namespace hexahedron
{
    class Window
    {
    private:
        GLFWwindow* _handle;

    public:
        /*!
         * Initializes the window.
         * @param width Width of the window.
         * @param height Height of the window.
         * @param title Title of the window.
         */
        void init(i32 width, i32 height, const std::string& title) {
            glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            this->_handle = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

        }

        /*!
         * Returns whether this window should close or not.
         * @return True if this window should close, else false.
         */
        bool should_close() {
            return glfwWindowShouldClose(this->_handle);
        }

        /*!
         * Closes the window.
         */
        void close() {
            glfwDestroyWindow(this->_handle);
        }

        /*!
         * Gets this window's handle.
         * @return The window's handle.
         */
        GLFWwindow* get_handle() const {
            return this->_handle;
        }
    };
}

#endif //HEXAHEDRON_WINDOW_HPP
