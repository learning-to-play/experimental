cc_library(
    name = "hello_greet",
    srcs = ["hello_greet.cc"],
    hdrs = ["hello_greet.h"],
)

cc_shared_library(
    name = "hello_greet_so1",
    additional_linker_inputs = [
        "version_script1.lds",
    ],
    user_link_flags = [
        "-Wl,--version-script,$(location :version_script1.lds)",
    ],
    roots = [":hello_greet"],
)

cc_shared_library(
    name = "hello_greet_so2",
    additional_linker_inputs = [
        "version_script2.lds",
    ],
    user_link_flags = [
        "-Wl,--version-script,$(location :version_script2.lds)",
    ],
    roots = [":hello_greet"],
)

cc_binary(
    name = "hello_world1",
    srcs = ["hello_world.cc"],
    dynamic_deps = [":hello_greet_so1"],
    deps = [":hello_greet"],
)

cc_binary(  # Throws a linker error because `get_greet` is not exported.
    name = "hello_world2",
    srcs = ["hello_world.cc"],
    dynamic_deps = [":hello_greet_so2"],
    deps = [":hello_greet"],
)
