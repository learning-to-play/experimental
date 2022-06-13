load (":util.bzl", "center")

cc_library(
    name = "left",
    srcs = ["left.cc"],
    hdrs = ["left.h"],
    deps = [center()],
)

cc_library(
    name = "right",
    srcs = ["right.cc"],
    hdrs = ["right.h"],
    deps = [center()],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":left",
        ":right",
    ],
)

