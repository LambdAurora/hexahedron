cmake_minimum_required(VERSION 3.6)
project(hexahedron)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(GenerateExportHeader)
include(utils/CompileUtility)
include(utils/VersionUtility)

set(CMAKE_CXX_STANDARD 17)
set(OpenGL_GL_PREFERENCE "GLVND")

# Options
option(HEXAHEDRON_INSTALL "Generate installation target" ON)

# Version
set(HEXAHEDRON_VERSION_MAJOR 0)
set(HEXAHEDRON_VERSION_MINOR 1)
set(HEXAHEDRON_VERSION_PATCH 0)
set(HEXAHEDRON_VERSION_TYPE "indev")

# Generate compile flags.
generate_flags(HEXAHEDRON_COMPILE_FLAGS "native" 2 true)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}${HEXAHEDRON_COMPILE_FLAGS}")

#find_package(lambdacommon REQUIRED)
find_package(GLM REQUIRED)
find_package(GLFW REQUIRED)
find_package(Vulkan REQUIRED)

include_directories(${LAMBDACOMMON_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS} ${Vulkan_INCLUDE_DIRS})

# All files:
# There is the C++ header files.
set(HEADER_FILES include/hexahedron/hexahedron.hpp)
# There is the C++ source files.
set(SOURCE_FILES src/hexahedron.cpp)

# Now build the executable.
add_library(hexahedron ${HEADER_FILES} ${SOURCE_FILES})
# Generate the version header and include it.
generate_version_header("HEXAHEDRON" "hexahedron" ${HEXAHEDRON_VERSION_MAJOR} ${HEXAHEDRON_VERSION_MINOR} ${HEXAHEDRON_VERSION_PATCH} "${HEXAHEDRON_VERSION_TYPE}")
target_include_directories(hexahedron PUBLIC ${CMAKE_BINARY_DIR}/exports)

# Let's ignore that for now, may delete later.
if (LAMBDA_WASM)
    set_target_properties(hexahedron PROPERTIES LINK_FLAGS "-s WASM=1 -s USE_WEBGL2=1 -s FULL_ES2=1 -s USE_GLFW=3")
endif ()

add_subdirectory(client)
