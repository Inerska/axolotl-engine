cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

link_libraries(axolotl-engine)

add_executable(basic_window basic_window.cpp)


target_link_libraries(basic_window glad glfw)
