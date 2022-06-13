cc_library(
    name = "a",
    srcs = ["a.cc"],
    hdrs = ["a.h"],
    alwayslink = True,
)

cc_library(
    name = "b",
    srcs = ["b.cc"],
    hdrs = ["b.h"],
    deps = [":a"],
)

# If alwayslink = False, libb-so.so links/exports only b and its size is 7856 B.
# If alwayslink = True, libb-so.so links/exports a and b and its size is 7952 B.
cc_shared_library(
    name = "b-so",
    roots = [":b"],
    static_deps = [":a"],
)
