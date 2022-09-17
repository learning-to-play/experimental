cc_library(
    name = "a",
    srcs = ["a.cc"],
    hdrs = ["a.h"],
)

cc_library(
    name = "b",
    srcs = ["b.cc"],
    hdrs = ["b.h"],
    deps = ["a"],
)

cc_library(
    name = "c",
    srcs = ["c.cc"],
    hdrs = ["c.h"],
    deps = ["b"],
)

cc_shared_library(
    name = "c-so",
    roots = ["c"],
    static_deps = [
        "a",
        "b",
        "c",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    dynamic_deps = [
        "c-so",
    ],
    deps = [
        "c",
    ],
)

