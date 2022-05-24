file(GLOB_RECURSE CPPS ./*.cpp)

add_executable(basic_window ${CPPS})

target_link_libraries(basic_window axolotl-engine)