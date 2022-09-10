cc_binary(
    name = "hello_world0",
    srcs = ["//:hello_world.cc"],
)

cc_binary(  # Note "T" in "0000000000000dd5 T _Z9get_greetB5cxx11v"
    name = "hello_world1",
    srcs = ["//:hello_world.cc"],
    additional_linker_inputs = [
        ":version_script1.lds",
    ],
    linkopts = [
        "-Wl,--version-script,$(location :version_script1.lds)",
    ],
)

cc_binary(  # Note "t" in "0000000000000dd5 t _Z9get_greetB5cxx11v"
    name = "hello_world2",
    srcs = ["//:hello_world.cc"],
    additional_linker_inputs = [
        ":version_script2.lds",
    ],
    linkopts = [
        "-Wl,--version-script,$(location :version_script2.lds)",
    ],
)
