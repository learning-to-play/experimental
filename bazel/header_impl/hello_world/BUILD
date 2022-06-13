cc_library(
    name = "hello_greet",
    srcs = ["hello_greet.cc"],
    hdrs = ["hello_greet.h"],
)

cc_library(
    name = "hello_greet_impl",
    srcs = [
        "hello_greet.h",
        "hello_greet.cc",
    ],
    alwayslink = True,
)

cc_library(
   name = "hello_greet_header",
   hdrs = ["hello_greet.h"],
)
