set_project "AxolotlEngine"

add_requires("glad", "glfw", "glew", "glm", "vcpkg::hypodermic", "flecs", { system = false })
add_packages("glfw", "glad", "glew", "glm", "vcpkg::hypodermic", "flecs")

add_rules("mode.debug", "mode.release")
add_rules("plugin.vsxmake.autoupdate")

target "AxolotlEngine"

do
    set_kind "headeronly"
    set_group "Library"
    set_warnings("all", "error")
    set_languages "cxx20"
    add_headerfiles "incl/**.hpp"
    add_headerfiles "incl/ApplicationContext.hpp"
    add_includedirs("incl", { interface = true })

end
target_end()

includes "samples"
includes "test"
