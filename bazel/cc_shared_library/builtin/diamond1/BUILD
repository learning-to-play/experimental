cc_library(
    name = "center",
    srcs = ["center.cc"],
    hdrs = ["center.h"],
)

cc_library(
    name = "left",
    srcs = ["left.cc"],
    hdrs = ["left.h"],
    deps = ["center"],
)

cc_library(
    name = "right",
    srcs = ["right.cc"],
    hdrs = ["right.h"],
    deps = ["center"],
)

cc_shared_library(
    name = "center-so",
    roots = ["center"],
)

cc_shared_library(
    name = "left-so",
    roots = ["left"],
    dynamic_deps = ["center-so"],
)

cc_shared_library(
    name = "right-so",
    roots = ["right"],
    dynamic_deps = ["center-so"],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    dynamic_deps = [
        "left-so",
        "right-so",
    ],
    deps = [
        ":center",
        ":left",
        ":right",
    ],
)

