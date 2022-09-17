# `right` library depends on a third_party `center` library.
# It doesn't expose a shared library.
cc_library(
    name = "right",
    srcs = ["right.cc"],
    hdrs = ["right.h"],
    deps = ["@diamond2_center//:center"],
    visibility = ["//visibility:public"],
)
