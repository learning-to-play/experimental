cc_library(
    name = "hello_greet",
    srcs = ["hello_greet.cc"],
    hdrs = ["hello_greet.h"],
)

cc_library(
    name = "hello_greet2",
    srcs = ["hello_greet.cc"],
    hdrs = ["hello_greet.h"],
    alwayslink = True,
)

cc_library(
    name = "hello_greet_lib",
    deps = [":hello_greet"],
)

cc_library(
    name = "hello_greet_lib2",
    deps = [":hello_greet"],
    alwayslink = True,
)

cc_library(
    name = "hello_greet2_lib",
    deps = [":hello_greet2"],
)

cc_shared_library(  # Size if 57512 bytes and exports get_greet symbol.
    name = "hello_greet_so",
    roots = [":hello_greet"],
)

cc_shared_library(  # size is 7280 bytes and doesn't export get_greet symbol.
    name = "hello_greet_lib_so",
    roots = [":hello_greet_lib"],
    static_deps = ["@//:__subpackages__"],
)

cc_shared_library(  # size is 7280 bytes and doesn't export get_greet symbol. 
    name = "hello_greet_lib2_so",
    roots = [":hello_greet_lib2"],
    static_deps = ["@//:__subpackages__"],
)

cc_shared_library(  # size is 57512 bytes and exports get_greet symbol.
    name = "hello_greet2_lib_so",
    roots = [":hello_greet2_lib"],
    static_deps = ["@//:__subpackages__"],
)

cc_binary(  # binary size is 13600 bytes and dynamically links get_greet.
    name = "hello_world",
    srcs = ["hello_world.cc"],
    dynamic_deps = [":hello_greet_so"],
    deps = [":hello_greet"],
)

cc_binary(  # Works! binary size is 14616 bytes and statically links get_greet.
    name = "hello_world_lib",
    srcs = ["hello_world.cc"],
    dynamic_deps = [":hello_greet_lib_so"],
    deps = [":hello_greet"],
)