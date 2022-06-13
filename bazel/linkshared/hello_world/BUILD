cc_library(
    name = "hello_greet",
    srcs = ["hello_greet.cc"],
    hdrs = ["hello_greet.h"],
)

cc_binary(
    name = "hello_world_linkshared",
    srcs = ["hello_world.cc"],
    deps = ["hello_greet"],
    linkshared = True,
)

cc_binary(
    name = "hello_greet_linkshared",
    deps = [":hello_greet"],
    linkshared = True,
)

cc_shared_library(
    name = "hello_greet_cc_shared_library",
    roots = [":hello_greet"],
)

