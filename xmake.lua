set_project "AxolotlEngine"

add_rules("mode.asan", "mode.coverage", "mode.debug", "mode.releasedbg", "mode.release")

target "AxolotlEngine"

do
    set_kind "headeronly"
    set_warnings("all", "error")
    set_languages "cxx17"
    add_headerfiles "incl/**.h"
    add_includedirs("incl", { interface = true })
end
target_end()

includes "test"
