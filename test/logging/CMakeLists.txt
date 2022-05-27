FILE(GLOB_RECURSE TEST_FILES ./*.cpp)

add_executable(logging ${TEST_FILES})

target_link_libraries(logging axolotl-engine)
