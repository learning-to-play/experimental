cc_binary(
    name = "hello_world",
    srcs = ["hello_world.cc"],
    deps = ["greet"],
)
cc_test(
    name = "greet_test",
    size = "small",
    srcs = ["greet_test.cc"],
    deps = [
        ":greet",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)
cc_library(
    name = "greet",
    hdrs = ["greet.h"],
    srcs = ["greet.cc"],
)
