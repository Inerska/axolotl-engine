add_rules("mode.debug", "mode.release")

target(".")
    set_kind("binary")
    add_files("src/*.cpp")