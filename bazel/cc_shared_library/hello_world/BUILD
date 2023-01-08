cc_library(
    name = "hello_greet",
    srcs = ["hello_greet.cc"],
    hdrs = ["hello_greet.h"],
)

cc_shared_library(
    name = "hello_greet_cc_shared_library",
    roots = ["hello_greet"],
    features = ["windows_export_all_symbols"],
)

cc_binary(
    name = "hello_world",
    srcs = ["hello_world.cc"],
    dynamic_deps = ["hello_greet_cc_shared_library"],
    deps = ["hello_greet"],
)
