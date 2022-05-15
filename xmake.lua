add_rules("mode.debug", "mode.release")

set_languages("cxx17")

-- requires
add_requires("conan::flecs/2.4.8")
add_requires("glfw", "glad")

target(".")
    set_kind("binary")
    add_files("src/**.cpp")
    add_headerfiles("src/**.h")

    -- packages
    add_packages("conan::flecs/2.4.8")
    add_packages("glfw", "glad")