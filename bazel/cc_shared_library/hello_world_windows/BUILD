cc_library(
    name = "hello_greet",
    srcs = ["hello_greet.cc"],
    hdrs = ["hello_greet.h"],
)

cc_binary(
    name = "hello_greet_linkshared_no_exports",
    srcs = [
        "hello_greet.h",
        "hello_greet.cc",
    ],
    linkshared = True,
)

cc_binary(
    name = "hello_greet_linkshared_full",
    srcs = [
        "hello_greet.h",
        "hello_greet.cc",
    ],
    linkshared = True,
    win_def_file = "hello_greet_linkshared_full.def",
)

cc_shared_library(
    name = "hello_greet_shared_empty",
    roots = [":hello_greet"],
)

cc_shared_library(
    name = "hello_greet_shared_head",
    roots = [":hello_greet"],
    win_def_file = "hello_greet_shared_head.def",
)

cc_shared_library(
    name = "hello_greet_shared_full",
    roots = [":hello_greet"],
    win_def_file = "hello_greet_shared_full.def",
)

cc_shared_library(
    name = "hello_greet_shared_all_symbols",
    roots = [":hello_greet"],
    features = ["windows_export_all_symbols"],
)

cc_binary(  # Fails
    name = "hello_world_shared_empty",
    srcs = ["hello_world.cc"],
    dynamic_deps = ["hello_greet_shared_empty"],
    deps = ["hello_greet"],
)

cc_binary(  # Fails
    name = "hello_world_shared_head",
    srcs = ["hello_world.cc"],
    dynamic_deps = ["hello_greet_shared_head"],
    deps = ["hello_greet"],
)

cc_binary(  # Works
    name = "hello_world_shared_full",
    srcs = ["hello_world.cc"],
    dynamic_deps = ["hello_greet_shared_full"],
    deps = ["hello_greet"],
)

cc_binary(  # Works
    name = "hello_world_shared_all_symbols",
    srcs = ["hello_world.cc"],
    dynamic_deps = ["hello_greet_shared_all_symbols"],
    deps = ["hello_greet"],
)
