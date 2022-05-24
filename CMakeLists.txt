cmake_minimum_required(VERSION 3.22)

project(axolotl-engine CXX)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

include(cmake/CPM.cmake)

# packages
CPMAddPackage(
        NAME glad
        GITHUB_REPOSITORY Dav1dde/glad
        GIT_TAG v0.1.36
)
CPMFindPackage(
        NAME glfw3
        URL https://github.com/glfw/glfw/releases/download/3.3.2/glfw-3.3.2.zip
        URL_HASH SHA256=08a33a512f29d7dbf78eab39bd7858576adcc95228c9efe8e4bc5f0f3261efc7
        VERSION 3.2
        OPTIONS
        "ENKITS_BUILD_EXAMPLES OFF"
        "GLFW_BUILD_EXAMPLES OFF"
        "GLFW_BUILD_TESTS OFF"
        "GLFW_BUILD_DOCS OFF"
        "GLFW_BUILD_INSTALL OFF"
)

# library

file(GLOB_RECURSE CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)

add_library(${PROJECT_NAME}
        ${CPP_FILES})

add_library(axolotl-engine::axolotl-engine ALIAS axolotl-engine)

target_link_libraries(${PROJECT_NAME} glad glfw)

add_subdirectory(samples)