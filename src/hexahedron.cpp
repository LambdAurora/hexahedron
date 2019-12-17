#include "../include/hexahedron/hexahedron.hpp"
#include <GLFW/glfw3.h>
#include <algorithm>

namespace hexahedron
{
    void init() {
    }

    std::string get_version() {
        auto result = std::to_string(HEXAHEDRON_VERSION_MAJOR) + '.' + std::to_string(HEXAHEDRON_VERSION_MINOR) + '.' + std::to_string(HEXAHEDRON_VERSION_PATCH);
        if (std::string type{HEXAHEDRON_VERSION_TYPE}; type != "Release")
            result = type + result;
        return result;
    }
}

int main(int argc, char** argv) {
    return EXIT_SUCCESS;
}
