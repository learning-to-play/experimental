cc_library(
    name = "a",
    srcs = ["a.cc"],
    hdrs = ["a.h"],
)

cc_library(
    name = "b",
    srcs = ["b.cc"],
    hdrs = ["b.h"],
    deps = [":a"],
)

cc_library(
    name = "c",
    srcs = ["c.cc"],
    hdrs = ["c.h"],
    deps = [":b"],
)

# $ nm bazel-bin/exports_filter/libb-so.so | c++filt
# >>> ...
#     0000000000000cea T a[abi:cxx11]()
#     0000000000000c09 T b[abi:cxx11]()
#     ...
cc_shared_library(
    name = "b-so",
    roots = [":b"],
    static_deps = [":a"],
)

# $ nm bazel-bin/exports_filter/libc-so.so | c++filt
# >>> ...
#                      U b[abi:cxx11]()
#     0000000000000b09 T c[abi:cxx11]()
#     ...
cc_shared_library(
    name = "c-so",
    roots = [":c"],
    dynamic_deps = [":b-so"],
    static_deps = [":c"],
)

# Error in fail: Trying to export a library already exported by a different shared library: //exports_filter:b
cc_shared_library(
    name = "c-so2",
    roots = [
        ":b",
        ":c"
    ],
    dynamic_deps = [":b-so"],
    static_deps = [":c"],
)
