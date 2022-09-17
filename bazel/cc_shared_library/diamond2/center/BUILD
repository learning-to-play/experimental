# We don't want to make center a .so in itself (for various reasons)
# center doesn't want to know how the project will assemble shared libraries.
# Let's say that center is provided by a third_party for example.
cc_library(
    name = "center",
    srcs = ["center.cc"],
    hdrs = ["center.h"],
    visibility = ["//visibility:public"],
)
