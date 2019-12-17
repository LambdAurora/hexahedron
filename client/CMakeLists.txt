# All files:
# There is the C++ header files.
set(CLIENT_HEADERS include/hexahedron/client/window.hpp include/hexahedron/client/client.hpp)
# There is the C++ source files.
set(CLIENT_SOURCES src/client.cpp)

include_directories(../include)

# Now build the executable.
add_executable(hexahedron_client ${CLIENT_HEADERS} ${CLIENT_SOURCES})
target_link_libraries(hexahedron_client hexahedron GLFW::GLFW Vulkan::Vulkan)

# Let's ignore that for now, may delete later.
if (LAMBDA_WASM)
    set_target_properties(hexahedron_client PROPERTIES LINK_FLAGS "-s WASM=1 -s USE_WEBGL2=1 -s FULL_ES2=1 -s USE_GLFW=3")
endif ()
