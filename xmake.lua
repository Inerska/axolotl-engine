set_project "AxolotlEngine"

add_requires("glad", "glfw", "conan::flecs/2.4.8", { system = false })
add_packages("glfw", "glad", "flecs")

add_rules("mode.debug", "mode.release")

target "AxolotlEngine"

do
    set_kind "headeronly"
    set_warnings("all", "error")
    set_languages "cxx20"
    add_headerfiles "incl/**.hpp"
    add_includedirs("incl", { interface = true })

end
target_end()

includes "samples"
includes "test"
