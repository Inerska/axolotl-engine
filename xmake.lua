add_rules("mode.debug", "mode.release")

-- requires
add_requires("conan::flecs/2.4.8")

target(".")
    set_kind("binary")
    add_files("src/*.cpp")

    -- packages
    add_packages("conan::flecs/2.4.8")