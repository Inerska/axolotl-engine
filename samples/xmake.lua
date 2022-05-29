option("samples")
    set_default(false)
    set_showmenu(true)
    set_description("Build samples")
option_end()

set_languages("cxx20")

target("AxolotlEngineSamples")
    set_kind("binary")
    set_group("samples")
    add_files("**.cpp")
        add_deps("AxolotlEngine")