cc_library(
    name = "a",
    srcs = ["a.cc"],
    hdrs = ["a.h"],
)

cc_shared_library(
    name = "a-so",
    roots = ["a"],
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

cc_binary(
    name = "main_cc_shared_library",
    srcs = ["main.cc"],
    deps = ["c"],
    dynamic_deps = ["a-so"],
)

cc_binary(
    name = "main_cc_library",
    srcs = ["main.cc"],
    deps = ["c"],
)
