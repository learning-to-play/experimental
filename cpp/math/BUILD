cc_library(
    name = "math",
    hdrs = ["math.h"],
    srcs = ["math.cc"],
)

cc_test(
    name = "math_test",
    size = "small",
    srcs = ["math_test.cc"],
    deps = [
        ":math",
        "@com_google_googletest//:gtest_main",
    ]
)