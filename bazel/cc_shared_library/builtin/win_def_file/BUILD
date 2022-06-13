cc_library(
    name = "hello_greet",
    srcs = ["hello_greet.cc"],
    hdrs = ["hello_greet.h"],
)

cc_binary(
    name = "hello_greet_linkshared_no_exports",
    srcs = [
        "hello_greet.h",
        "hello_greet.cc",
    ],
    linkshared = True,
)

cc_binary(
    name = "hello_greet_linkshared_full",
    srcs = [
        "hello_greet.h",
        "hello_greet.cc",
    ],
    linkshared = True,
    win_def_file = "hello_greet_linkshared_full.def",
)

cc_shared_library(
    name = "hello_greet_shared_all_exports",
    roots = [":hello_greet"],
)

cc_shared_library(
    name = "hello_greet_shared_head",
    roots = [":hello_greet"],
    win_def_file = "hello_greet_shared_head.def",
)
