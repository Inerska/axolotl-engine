set_project "AxolotlEngine"

add_requires("glad", "glfw", { system = false })
add_packages("glfw", "glad")

add_rules("mode.debug", "mode.release")

target "AxolotlEngine"

do
    set_kind "headeronly"
    set_warnings("all", "error")
    set_languages "cxx20"
    add_headerfiles "incl/**.h"
    add_includedirs("incl", { interface = true })

end
target_end()

includes "test"
