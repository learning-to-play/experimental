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
    alwayslink = True,
)

# $ nm bazel-bin/link_static_libraries_once/libb-so.so | c++filt
# >>> ...
#     0000000000000d0a T a[abi:cxx11]()
#     0000000000000c29 T b[abi:cxx11]()
#     ...
cc_shared_library(
    name = "b-so",
    roots = [":b"],
    static_deps = [":a"],
)

cc_import(
    name = "b-so-import",
    shared_library = ":b-so",
)

cc_library(
    name = "c",
    srcs = ["c.cc"],
    hdrs = ["c.h"],
    deps = [
        ":a",
        ":b",
        ":b-so-import",
    ],
    alwayslink = True,
)

# $ nm bazel-bin/link_static_libraries_once/libc-so.so | c++filt
# >>> ...
#     000000000000160e T a[abi:cxx11]()
#     0000000000001584 T b[abi:cxx11]()
#     00000000000011f9 T c[abi:cxx11]()
#     ...
cc_shared_library(
    name = "c-so",
    roots = [":c"],
    static_deps = [
        ":c",
        ":b",
        ":a",
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
