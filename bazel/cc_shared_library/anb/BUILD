cc_library(
    name = "a",
    srcs = ["a.cc"],
    hdrs = ["a.h"],
)

cc_library(
    name = "b",
    srcs = ["b.cc"],
    hdrs = ["b.h"],
    deps = [":a"],  # Not really required.
)

cc_shared_library(
    name = "a-so",
    roots = [":a"],
    static_deps = [":a"],
)

cc_shared_library(  # Dynamically links liba-so.so
    name = "b-so",
    roots = [":b"],
    static_deps = [":b"],
    dynamic_deps = [":a-so"]  # Not required, but adds a dynamic dependency.
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    dynamic_deps = [
        "a-so",
        "b-so",
    ],
    deps = [
        "a",
        "b",
    ],
)

