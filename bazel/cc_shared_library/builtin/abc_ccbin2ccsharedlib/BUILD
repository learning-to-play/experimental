cc_library(
    name = "a",
    srcs = ["a.cc"],
    hdrs = ["a.h"],
)

cc_binary(
    name = "a.so",
    srcs = [
        "a.cc",
        "a.h",
    ],
    linkshared = True,
)

cc_shared_library(
    name = "a_so",
    roots = ["a"],
)

cc_library(
    name = "b",
    srcs = ["b.cc"],
    hdrs = ["b.h"],
    deps = ["a"],
)

cc_binary(
    name = "b.so",
    srcs = [
        "b.cc",
        "b.h",
        "a.h",
    ],
    linkshared = True,
)

cc_shared_library(
    name = "b_so",
    roots = ["b"],
    dynamic_deps = ["a_so"],
)

cc_library(
    name = "c",
    srcs = ["c.cc"],
    hdrs = ["c.h"],
    deps = ["b"],
)

cc_binary(
    name = "c.so",
    srcs = [
        "c.cc",
        "c.h",
        "b.h",
    ],
    linkshared = True,
)

cc_shared_library(
    name = "c_so",
    roots = ["c"],
    dynamic_deps = ["b_so"],
)

cc_binary(
    name = "main0",
    srcs = [
        "main.cc",
        "c.h",
        "c.so",
        "b.so",
        "a.so",
    ],
)

cc_binary(
    name = "main1",
    srcs = [
        "main.cc",
        "c.h",
        "c.so",
        "b.so",
        "a_so",
    ],
)

cc_binary(  # Running the binary raises error "cannot open shared object file: No such file or directory".
    name = "main1_error1",
    srcs = [
        "main.cc",
        "c.h",
        "c.so",
        "b_so",
        "a_so",
    ],
)

cc_binary(  # Running the binary raises error "cannot open shared object file: No such file or directory".
    name = "main1_error2",
    srcs = [
        "main.cc",
        "c.h",
        "c_so",
        "b_so",
        "a_so",
    ],
)

cc_binary(
    name = "main2",
    srcs = [
        "main.cc",
        "c.h",
        "c.so",
        "b_so",
    ],
    dynamic_deps = [
        "a_so",
    ],
)

cc_binary(
    name = "main3",
    srcs = ["main.cc"],
    dynamic_deps = [
        "a_so",
        "b_so",
        "c_so",
    ],
    deps = ["c"],
)

filegroup(
    name = "liba.so",
    srcs = ["a_so"],
    output_group = "main_shared_library_output",
)

cc_binary(
    name = "main1_2",
    srcs = [
        "main.cc",
        "c.h",
        "c.so",
        "b.so",
        "liba.so",
    ],
)

filegroup(
    name = "libb.so",
    srcs = ["b_so"],
    output_group = "main_shared_library_output",
)

cc_binary(
    name = "main2_2",
    srcs = [
        "main.cc",
        "c.h",
        "c.so",
        "libb.so",
    ],
    dynamic_deps = [
        "a_so",
    ],
)

cc_binary(
    name = "main3_2",
    srcs = ["main.cc"],
    dynamic_deps = [
        "a_so",
        "b_so",
        "c_so",
    ],
    deps = ["c"],
)